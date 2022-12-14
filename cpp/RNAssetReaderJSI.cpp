#include "RNAssetReaderJSI.hpp"
#include <string>

#ifdef __APPLE__
#include <CoreFoundation/CoreFoundation.h>
#include <fstream>
#include <sstream>
#elif __ANDROID__

#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

#endif

#ifdef __ANDROID__

#include <jni.h>
#include <android/log.h>

RNAssetReaderStorage assetReaderStorageInstance;

void RNAssetReaderStorage::init(AAssetManager *cAssetsManager) {
    assetsManager = cAssetsManager;
}

#define TAG "ASSET"
#define printLog(...) __android_log_print(ANDROID_LOG_ERROR,     TAG, __VA_ARGS__)
#else
#define printLog(...) printf(__VA_ARGS__)
#endif

//static int callbackId = 0;

namespace RNAssetReaderJSI {
    void install(Runtime &jsiRuntime, std::shared_ptr<CallInvoker> callInvoker) {
        auto moduleName = "RNAssetReaderTurboModule";
        auto nativeModule = std::make_shared<RNAssetReaderTurboModule>(jsiRuntime, callInvoker);
        auto object = Object::createFromHostObject(jsiRuntime, nativeModule);
        jsiRuntime.global().setProperty(jsiRuntime, moduleName, std::move(object));
    }

#ifdef __APPLE__
    static Value read(Runtime &rt, TurboModule &turboModule,
                             const Value *args, size_t arg_count){
        CFURLRef manifest_url = CFBundleCopyResourceURL(CFBundleGetMainBundle(), CFSTR("main"), CFSTR("json"), NULL);
        char manifest_path[PATH_MAX];

        CFURLGetFileSystemRepresentation(manifest_url, true, (UInt8 *)manifest_path, PATH_MAX);

        CFRelease(manifest_url);

        std::ifstream myfile(manifest_path);
        std::stringstream buffer;
        buffer << myfile.rdbuf();

        return String::createFromUtf8(rt, buffer.str());
    };
#elif __ANDROID__
    static Value read(Runtime &rt, TurboModule &turboModule,
                      const Value *args, size_t arg_count) {
        const char *mPath = "main.json";
        AAsset *asset = AAssetManager_open(assetReaderStorageInstance.assetsManager, mPath,
                                           AASSET_MODE_BUFFER);
        if (asset == NULL) {
            return 0;
        }
        long size = AAsset_getLength(asset);
        char *buffer = (char *) malloc(sizeof(char) * size);
        AAsset_read(asset, buffer, size);

        std::string str(buffer);

        AAsset_close(asset);

        return String::createFromUtf8(rt, buffer);
    }

#endif


    RNAssetReaderTurboModule::RNAssetReaderTurboModule(Runtime &jsiRuntime,
                                                       std::shared_ptr<CallInvoker> jsInvoker)
            : TurboModule("RNAssetReaderTurboModule", jsInvoker) {
        methodMap_["read"] = MethodMetadata{0, read};
    }
}

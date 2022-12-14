#include "RNAssetReaderJSI.hpp"
#include <string>
#include <CoreFoundation/CoreFoundation.h>
#include <fstream>
#include <sstream>

//#ifdef __ANDROID__
//
//#include <android/log.h>
//
//#define TAG "WEBSOCKET"
//
//#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,    TAG, __VA_ARGS__)
//#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,     TAG, __VA_ARGS__)
//#define printLog(...) __android_log_print(ANDROID_LOG_ERROR,     TAG, __VA_ARGS__)
//#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,    TAG, __VA_ARGS__)
//
//#else
//#define printLog(...) printf(__VA_ARGS__)
//#endif

//static int callbackId = 0;

namespace RNAssetReaderJSI {
void install(Runtime &jsiRuntime, std::shared_ptr<CallInvoker> callInvoker) {
	auto moduleName = "RNAssetReaderTurboModule";
	auto nativeModule = std::make_shared<RNAssetReaderTurboModule>(jsiRuntime, callInvoker);
	auto object = Object::createFromHostObject(jsiRuntime, nativeModule);
	jsiRuntime.global().setProperty(jsiRuntime, moduleName,  std::move(object));
}

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

RNAssetReaderTurboModule::RNAssetReaderTurboModule(Runtime &jsiRuntime, std::shared_ptr <CallInvoker> jsInvoker) : TurboModule("RNAssetReaderTurboModule", jsInvoker){
	methodMap_["read"] = MethodMetadata{0, read};
}
}

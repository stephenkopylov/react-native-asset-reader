#include <jni.h>
#include <CallInvokerHolder.h>
#include <fbjni/fbjni.h>
#include <jsi/jsi.h>
#include "RNAssetReaderJSI.hpp"
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

using namespace facebook;

extern "C" JNIEXPORT void JNICALL
Java_com_ibit_RNAssetReader_RNAssetReaderModule_installNativeJsi(
        JNIEnv *pEnv,
        jobject jthis, jlong jsiRuntimePtr,
        jobject cJsCallInvokerHolder,
        jobject assetsManager) {
    assetReaderStorageInstance.init(AAssetManager_fromJava(pEnv,assetsManager));;
    auto jsiRuntime = reinterpret_cast<jsi::Runtime *>(jsiRuntimePtr);
    jni::alias_ref<react::CallInvokerHolder::javaobject> jsCallInvokerHolder = reinterpret_cast<react::CallInvokerHolder::javaobject>(cJsCallInvokerHolder);

    RNAssetReaderJSI::install(*jsiRuntime, jsCallInvokerHolder->cthis()->getCallInvoker());
}

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *) {
    return jni::initialize(vm, [] {});
}

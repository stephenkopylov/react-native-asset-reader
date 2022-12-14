#include <jni.h>
#include <CallInvokerHolder.h>
#include <fbjni/fbjni.h>
#include <jsi/jsi.h>
#include "RNAssetReaderJSI.hpp"

using namespace facebook;

extern "C" JNIEXPORT void JNICALL
Java_com_ibit_RNAssetReader_RNAssetReaderModule_installNativeJsi(
        JNIEnv *pEnv,
        jobject jthis, jlong jsiRuntimePtr,
        jobject cJsCallInvokerHolder) {
    auto jsiRuntime = reinterpret_cast<jsi::Runtime *>(jsiRuntimePtr);
    jni::alias_ref<react::CallInvokerHolder::javaobject> jsCallInvokerHolder = reinterpret_cast<react::CallInvokerHolder::javaobject>(cJsCallInvokerHolder);

    RNAssetReaderJSI::install(*jsiRuntime, jsCallInvokerHolder->cthis()->getCallInvoker());
}

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *) {
    return jni::initialize(vm, [] {});
}

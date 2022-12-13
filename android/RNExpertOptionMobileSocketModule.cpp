#include <jni.h>
#include <CallInvokerHolder.h>
#include <fbjni/fbjni.h>
#include <jsi/jsi.h>
#include "RNExpertOptionMobileSocketJSI.hpp"

using namespace facebook;

extern "C" JNIEXPORT void JNICALL
Java_com_eo_RNExpertOptionMobileSocket_RNExpertOptionMobileSocketModule_installNativeJsi(
        JNIEnv *pEnv,
        jobject jthis, jlong jsiRuntimePtr,
        jobject cJsCallInvokerHolder) {
    auto jsiRuntime = reinterpret_cast<jsi::Runtime *>(jsiRuntimePtr);
    jni::alias_ref<react::CallInvokerHolder::javaobject> jsCallInvokerHolder = reinterpret_cast<react::CallInvokerHolder::javaobject>(cJsCallInvokerHolder);

    RNExpertOptionMobileSocketJSI::install(*jsiRuntime,
                                           jsCallInvokerHolder->cthis()->getCallInvoker());
}

//struct RNExpertOptionMobileSocketNativeProxy : jni::JavaClass<RNExpertOptionMobileSocketNativeProxy> {
//    static constexpr auto kJavaDescriptor = "Lcom/eo/RNExpertOptionMobileSocket/RNExpertOptionMobileSocketNativeProxy;";

//    static void registerNatives() {
//        javaClassStatic()->registerNatives({
//                                                   makeNativeMethod("installNativeJsi",
//                                                                    RNExpertOptionMobileSocketNativeProxy::installNativeJsi)
//                                           });
//    }

//private:
//    static void installNativeJsi(jni::alias_ref<jni::JObject> thiz,
//                                 jlong jsiRuntimePtr,
//                                 jni::alias_ref<react::CallInvokerHolder::javaobject> jsCallInvokerHolder) {
//
//        auto jsiRuntime = reinterpret_cast<jsi::Runtime *>(jsiRuntimePtr);
//        auto jsCallInvoker = jsCallInvokerHolder->cthis()->getCallInvoker();
//
//        RNExpertOptionMobileSocketJSI::install(*jsiRuntime, jsCallInvoker);
//    }
//};

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *) {
    return jni::initialize(vm, [] {});
}

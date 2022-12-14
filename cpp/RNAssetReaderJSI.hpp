#ifndef RNAssetReaderJSI_hpp
#define RNAssetReaderJSI_hpp
#include <stdio.h>
#include <jsi/jsi.h>
#include <ReactCommon/CallInvoker.h>
#include <ReactCommon/TurboModule.h>
#include <ReactCommon/TurboModuleUtils.h>
#include <map>

using namespace facebook::react;
using namespace facebook::jsi;
using namespace std;

#ifdef __ANDROID__
#include <jni.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

class RNAssetReaderStorage {
public:
	void init(AAssetManager* assetsManager);
	AAssetManager* assetsManager;
};

extern RNAssetReaderStorage assetReaderStorageInstance;
#endif

namespace RNAssetReaderJSI {
void install(Runtime & jsiRuntime, std::shared_ptr<CallInvoker> callInvoker) ;

class JSI_EXPORT RNAssetReaderTurboModule : public facebook::react::TurboModule {
public:
	RNAssetReaderTurboModule(Runtime &jsiRuntime, std::shared_ptr <CallInvoker> jsInvoker);
private:
};
};
#endif

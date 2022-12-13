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

namespace RNAssetReaderJSI {
void install(Runtime & jsiRuntime, std::shared_ptr<CallInvoker> callInvoker) ;

class JSI_EXPORT RNAssetReaderTurboModule : public facebook::react::TurboModule {
public:
	RNAssetReaderTurboModule(Runtime &jsiRuntime, std::shared_ptr <CallInvoker> jsInvoker);
	~RNAssetReaderTurboModule();
private:
};
};
#endif

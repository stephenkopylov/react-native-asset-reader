//
//  RNImageFetcherView.m
//  appcenter
//
//  Created by Stepan Kopylov on 25/10/2019.
//

#import "RNAssetReader.h"
#import <React/RCTBridge+Private.h>
#import <React/RCTUtils.h>
#import <ReactCommon/CallInvoker.h>
#import "RCTTurboModule.h"
#import <ReactCommon/RCTTurboModule.h>
#import "RNAssetReaderJSI.hpp"

@interface RNAssetReader()
@end

@implementation RNAssetReader

RCT_EXPORT_MODULE();

RCT_EXPORT_BLOCKING_SYNCHRONOUS_METHOD(installTurboModule)
{
	[self installLibrary];
	return NULL;
}

+(BOOL)requiresMainQueueSetup{
	return YES;
}

- (NSArray<NSString *> *)supportedEvents
{
	return @[];
}

- (void)installLibrary {
	RCTCxxBridge *cxxBridge = (RCTCxxBridge *)self.bridge;
	
	if (cxxBridge.runtime) {
		RNAssetReaderJSI::install(*(facebook::jsi::Runtime *)cxxBridge.runtime, cxxBridge.jsCallInvoker);
	}else{
		dispatch_after(100, dispatch_get_main_queue(), ^{
			[self installLibrary];
		});
	}
}

@end

package com.ibit.RNAssetReader;

import android.content.res.AssetManager;
import android.util.Log;

import androidx.annotation.NonNull;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.module.annotations.ReactModule;
import com.facebook.react.turbomodule.core.CallInvokerHolderImpl;

@ReactModule(name = RNAssetReaderModule.NAME)
public class RNAssetReaderModule extends ReactContextBaseJavaModule {
  public static final String NAME = "RNAssetReader";
  static {
    System.loadLibrary(NAME);
  }

  private native void installNativeJsi(long jsContextNativePointer, CallInvokerHolderImpl jsCallInvokerHolder, AssetManager assetMgr);

  public void installJsi(@NonNull ReactContext context) {
    AssetManager assetMgr = context.getAssets();
    CallInvokerHolderImpl holder = (CallInvokerHolderImpl)context.getCatalystInstance().getJSCallInvokerHolder();
    long contextPointer = context.getJavaScriptContextHolder().get();
    if (contextPointer != 0) {
      installNativeJsi(contextPointer, holder, assetMgr);
    }
  }

  @ReactMethod(isBlockingSynchronousMethod = true)
  public void installTurboModule() {
    boolean isChromeDebugger = getReactApplicationContext().getJavaScriptContextHolder().get() == 0;

    if (!isChromeDebugger) {
      this.installJsi(getReactApplicationContext());
    } else {
      Log.w(
              "[AssetReader]",
              "Unable to create RNAssetReader. You can ignore this message if you are using Chrome Debugger now.");
    }
  }

  public RNAssetReaderModule(ReactApplicationContext reactContext) {
    super(reactContext);
  }

  @Override
  @NonNull
  public String getName() {
    return NAME;
  }
}

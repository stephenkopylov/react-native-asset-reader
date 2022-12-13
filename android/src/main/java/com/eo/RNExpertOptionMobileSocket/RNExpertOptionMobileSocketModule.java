package com.eo.RNExpertOptionMobileSocket;

import android.util.Log;

import androidx.annotation.NonNull;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.module.annotations.ReactModule;
import com.facebook.react.turbomodule.core.CallInvokerHolderImpl;

@ReactModule(name = RNExpertOptionMobileSocketModule.NAME)
public class RNExpertOptionMobileSocketModule extends ReactContextBaseJavaModule {
  public static final String NAME = "RNExpertOptionMobileSocket";
  static {
    System.loadLibrary(NAME);
  }

  private native void installNativeJsi(long jsContextNativePointer, CallInvokerHolderImpl jsCallInvokerHolder);

  public void installJsi(@NonNull ReactContext context) {
    CallInvokerHolderImpl holder = (CallInvokerHolderImpl)context.getCatalystInstance().getJSCallInvokerHolder();
    long contextPointer = context.getJavaScriptContextHolder().get();
    if (contextPointer != 0) {
      installNativeJsi(contextPointer, holder);
    }
  }

  @ReactMethod(isBlockingSynchronousMethod = true)
  public void installTurboModule() {
    boolean isChromeDebugger = getReactApplicationContext().getJavaScriptContextHolder().get() == 0;

    if (!isChromeDebugger) {
      this.installJsi(getReactApplicationContext());
    } else {
      Log.w(
              "[Socket]",
              "Unable to create RNExpertOptionMobileSocketModule. You can ignore this message if you are using Chrome Debugger now.");
    }
  }

  public RNExpertOptionMobileSocketModule(ReactApplicationContext reactContext) {
    super(reactContext);
  }

  @Override
  @NonNull
  public String getName() {
    return NAME;
  }
}

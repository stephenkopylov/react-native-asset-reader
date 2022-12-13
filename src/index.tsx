import { NativeModules } from 'react-native';

// @ts-ignore
if (global.RNAssetReaderTurboModule === undefined) {
  NativeModules.RNAssetReader.installTurboModule();
}

export class RNAssetReader {
  static read(): any {
    // @ts-ignore
    return global.RNAssetReaderTurboModule.read();
  }
}

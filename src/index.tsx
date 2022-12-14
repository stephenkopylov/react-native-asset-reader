import {NativeModules} from 'react-native';

// @ts-ignore
if (global.RNAssetReaderTurboModule === undefined) {
    NativeModules.RNAssetReader.installTurboModule();
}

export class RNAssetReader {
    static readJson(filename: string): any {
        // @ts-ignore
        return global.RNAssetReaderTurboModule.readJson(filename);
    }
}

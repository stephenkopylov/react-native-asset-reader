const path = require('path');

const extraNodeModules = {
  'react-native-asset-reader': path.resolve(__dirname + '/..'),
};
const watchFolders = [
  path.resolve(__dirname + '/..')
];


const nodeModulesPaths = [path.resolve(path.join(__dirname, './node_modules'))];

module.exports = {
 resolver: {
    extraNodeModules,
    nodeModulesPaths
  },
  watchFolders,
  transformer: {
    getTransformOptions: async () => ({
      transform: {
        experimentalImportSupport: false,
        inlineRequires: true,
      },
    }),
  },
};

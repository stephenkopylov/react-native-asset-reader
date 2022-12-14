cmake_minimum_required(VERSION 3.9.0)

set(CMAKE_CXX_FLAGS  "-std=c++17")
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Ofast")
#set(CMAKE_CXX_FLAGS_RELESE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

set(build_DIR ${CMAKE_SOURCE_DIR}/build)
set(PACKAGE_NAME RNAssetReader)

include_directories(
        ../cpp
        ${REACT_NATIVE_DIR}/React
        ${REACT_NATIVE_DIR}/React/Base
        ${REACT_NATIVE_DIR}/ReactCommon
        ${REACT_NATIVE_DIR}/ReactCommon/react/nativemodule/core
        ${REACT_NATIVE_DIR}/ReactCommon/jsi
        ${REACT_NATIVE_DIR}/ReactCommon/callinvoker
        ${REACT_NATIVE_DIR}/ReactAndroid/src/main/java/com/facebook/react/turbomodule/core/jni/ReactCommon
        ${REACT_NATIVE_DIR}/ReactCommon/turbomodule/core
        ${REACT_NATIVE_DIR}/ReactCommon/turbomodule
        ${REACT_NATIVE_DIR}/React
        ${REACT_NATIVE_DIR}/React/Base
)

find_package(fbjni REQUIRED CONFIG)

add_library(
        ${PACKAGE_NAME}
        SHARED
        ${REACT_NATIVE_DIR}/ReactCommon/jsi/jsi/jsi.cpp
        ${REACT_NATIVE_DIR}/ReactAndroid/src/main/java/com/facebook/react/turbomodule/core/jni/ReactCommon/CallInvokerHolder.cpp
        ${REACT_NATIVE_DIR}/ReactCommon/react/nativemodule/core/ReactCommon/TurboModule.cpp
#${REACT_NATIVE_DIR}/ReactCommon/react/nativemodule/core/ReactCommon/LongLivedObject.cpp
        ../cpp/RNAssetReaderJSI.cpp
        ./RNAssetReaderModule.cpp
)

target_link_libraries(${PACKAGE_NAME} fbjni::fbjni android log)

add_library(
        turbomodulejsijni
        # Sets the library as a shared library.
        SHARED
        # an empty cpp file
        ../cpp/empty.cpp
)

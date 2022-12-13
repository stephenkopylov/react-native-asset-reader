cmake_minimum_required(VERSION 3.9.0)

set(CMAKE_CXX_FLAGS  "-std=c++17")
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Ofast")
#set(CMAKE_CXX_FLAGS_RELESE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

set(build_DIR ${CMAKE_SOURCE_DIR}/build)
set(PACKAGE_NAME RNExpertOptionMobileSocket)

include_directories(
        ../cpp
        ../../../node_modules/react-native/React
        ../../../node_modules/react-native/React/Base
        ../../../node_modules/react-native/ReactCommon
        ../../../node_modules/react-native/ReactCommon/react/nativemodule/core
        ../../../node_modules/react-native/ReactCommon/jsi
        ../../../node_modules/react-native/ReactCommon/callinvoker
        ../../../node_modules/react-native/ReactAndroid/src/main/java/com/facebook/react/turbomodule/core/jni/ReactCommon
        ../../../node_modules/react-native/ReactCommon/turbomodule/core
        ../../../node_modules/react-native/ReactCommon/turbomodule
        ../../../node_modules/react-native/React
        ../../../node_modules/react-native/React/Base
)

find_package(fbjni REQUIRED CONFIG)
find_package(ExpertOptionMobileSocket REQUIRED CONFIG)

add_library(
        ${PACKAGE_NAME}
        SHARED
        ../../../node_modules/react-native/ReactCommon/jsi/jsi/jsi.cpp
        ../../../node_modules/react-native/ReactAndroid/src/main/java/com/facebook/react/turbomodule/core/jni/ReactCommon/CallInvokerHolder.cpp
        ../../../node_modules/react-native/ReactCommon/react/nativemodule/core/ReactCommon/TurboModule.cpp
        ../../../node_modules/react-native/ReactCommon/react/nativemodule/core/ReactCommon/LongLivedObject.cpp
        ../cpp/RNExpertOptionMobileSocketJSI.cpp
        ./RNExpertOptionMobileSocketModule.cpp
)

target_link_libraries(${PACKAGE_NAME} fbjni::fbjni android log ExpertOptionMobileSocket::ExpertOptionMobileSocket)

add_library(
        turbomodulejsijni
        # Sets the library as a shared library.
        SHARED
        # an empty cpp file
        ../cpp/empty.cpp
)

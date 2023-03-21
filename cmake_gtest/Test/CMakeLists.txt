cmake_minimum_required(VERSION 3.15)
project(Test)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

# Debugging purposes
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-O0")

add_definitions(
    -DUE_BUILD_DEBUG=0
    -DUE_BUILD_DEVELOPMENT=1
    -DUE_BUILD_TEST=0
    -DUE_BUILD_SHIPPING=0
    -DIS_MONOLITHIC=0
    -DIS_PROGRAM=0
    -DWITH_ENGINE=1
    -DWITH_UNREAL_DEVELOPER_TOOLS=1
    -DWITH_PLUGIN_SUPPORT=0
    -DUBT_COMPILED_PLATFORM=Linux
    -D_AMD64_
    -DIS_TEST
    -DNO_LOGGING=1
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../external/googletest ${CMAKE_CURRENT_BINARY_DIR}/googletest)

set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/..)
set(APPLICATIONS_ROOT ${PROJECT_ROOT}/../..)
set(UE_LINUX_LIBS ${APPLICATIONS_ROOT}/epic/unreal-engine/Engine/Binaries/Linux/)
set(UE_ENGINE ${APPLICATIONS_ROOT}/epic/unreal-engine/Engine/)
set(UE_ENGINE_SOURCE ${UE_ENGINE}/Source/)

include_directories(
    PUBLIC
    ${UE_ENGINE_SOURCE}/Runtime/InputCore/Classes
    ${UE_ENGINE_SOURCE}/Runtime/Core/Public
    ${UE_ENGINE_SOURCE}/Runtime/CoreUObject/Public
    ${UE_ENGINE_SOURCE}/Runtime/TraceLog/Public
    ${UE_ENGINE_SOURCE}/Runtime/Net/Core/Public
    ${UE_ENGINE_SOURCE}/Runtime/RHI/Public
    ${UE_ENGINE_SOURCE}/Runtime/RenderCore/Public/
    ${PROJECT_ROOT}/Intermediate/Build/Linux/B4D820EA/UE4Editor/Development/ModuleA
)

link_directories(
    PUBLIC
    ${UE_LINUX_LIBS}
)

set(CMAKE_CXX_FLAGS "-fno-stack-protector -fno-rtti -Wno-error=invalid-offsetof -Wno-error=unused-local-typedefs -Wno-error=type-limits -Wno-error=unused-value -Wno-error=switch -Wno-error=extra -Wno-error=ignored-qualifiers -Wno-error=sign-compare -Wno-error=undef -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -Wno-error=int-in-bool-context -fPIC")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Unit/AExampleTest)
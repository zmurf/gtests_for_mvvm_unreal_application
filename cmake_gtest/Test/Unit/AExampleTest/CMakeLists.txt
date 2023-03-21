# Based on https://gamedevtricks.com/post/going-commando/
set(TEST_NAME AExampleTest)

# Test sources
add_executable(${TEST_NAME}
${CMAKE_CURRENT_SOURCE_DIR}/AExampleTest.cpp
${PROJECT_ROOT}/Source/common/ModuleB/FolderB/Private/Comm.cpp
${PROJECT_ROOT}/Source/common/ModuleB/FolderA/Private/AExample.cpp
${PROJECT_ROOT}/Source/common/ModuleB/FolderA/Private/AExampleBase.cpp
${PROJECT_ROOT}/Source/common/ModuleA/Private/AExample/AExampleModel.cpp
${PROJECT_ROOT}/Source/common/ModuleA/Private/AExample/AExampleViewModel.cpp
)

target_include_directories(${TEST_NAME}
PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../Defines
    ${CMAKE_CURRENT_SOURCE_DIR}/../Mock
    ${PROJECT_ROOT}/Source/common/ModuleB/FolderA/Public
    ${PROJECT_ROOT}/Source/common/ModuleB/FolderB/Public
    ${PROJECT_ROOT}/Source/common/ModuleB/FolderC/Public
    ${PROJECT_ROOT}/Source/common/ModuleB/FolderD/Public
    ${PROJECT_ROOT}/Source/common/ModuleA/Public
    ${PROJECT_ROOT}/Source/common/ModuleA/Public/AExample
)

target_link_libraries(${TEST_NAME}
PUBLIC
    UE4Editor-Core
    UE4Editor-CoreUObject
    gtest
    gtest_main
    gmock
)

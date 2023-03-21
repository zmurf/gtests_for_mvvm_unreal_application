
# Background

We needed a way to unit test all our application layer (cpp) code which drives our Unreal Engine based user interface. This is a PoC based on a similar MVVM setup as we use.

The Blueprint part of any Unreal Engine program is both hard to unit test and impossible to version handle. To get around this, you can decide to keep the bulk amount of functionality in the cpp application layer of your Unreal Engine program. This will let you easily version handle any behavior change and do headless unit testing of that code.

This PoC is set up for building and running the google tests in a CMake environment on Linux. But the entire PoC is based on a similar need done for Visual Studio and Windows
https://gamedevtricks.com/post/going-commando/

## How it is done

### Mocking the `AActor`
By mocking the game engine Actor class, we can altogether remove the dependency towards the Unreal game engine library (UE4Editor-Engine). This lets us build the cpp application part of our Unreal Engine program totally separately, making it possible to run headless testing .

### Mocking the delegates
By writing our own delegates and injecting these through hand written `xxxx.generated.h` files into the classes that inherits from `AActor`, we can add `EXPECT_CALL` to the `Broadcast` which would normally raise events up to the Blueprints. This lets us test the interface between our cpp application code and the Unreal game engine.

# Prerequisites

Unreal Engine must reside in *../epic/unreal-engine* relative to this folder

# Preparation

First generate the **Definitions.xxxxx.h** file. This is done by building the project

Build project, run
```
./scripts/build.py
```
(the cook will fail. But that is not important at this point. It's just this example not being a complete project)

# Build the tests

```
cd cmake_gtest/Test
rm -rf build/ ; mkdir build ; cmake -S ./ -B ./build ; cd build ; make
```

## Run the tests

```
./Unit/AExampleTest/AExampleTest
```

# Pros

* Fast rebuild of tests
*  Headless testing
*  Possibility to mock away parts we do not want to test
*  Possible to version handle
* Possible to use Test Driven Development to develop application layer

# Cons

* Tests separately build from the real project code. Meaning that we are not really testing the exact same thing as what is running in the Unreal project
* Still need to use Gauntlet to test Blueprint (view) layer of the program
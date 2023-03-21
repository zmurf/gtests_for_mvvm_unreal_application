
#pragma once

// This file is basically defining macros without any functionaliy which usally comes from the Unreal Engine libs and
// header files. Since the test does not bring in those files, we need to define them our self for the code to build. So
// when building the gtests, this file is used. When building the di_hmi_app,
// di_hmi_app/Source/common/Dal/Common/Public/Defines/Defines.h is used

#pragma once

#include "Definitions.ModuleA.h"

#ifdef MODULEA_API
    #undef MODULEA_API
#endif
#define MODULEA_API

// Defined in module CoreUObject
// UObject/ObjectMacros.h

#ifdef UMETA
    #undef UMETA
#endif
#define UMETA(...)

#ifdef UENUM
    #undef UENUM
#endif
#define UENUM(...)

#ifdef USTRUCT
    #undef USTRUCT
#endif
#define USTRUCT(...)

#ifdef UCLASS
    #undef UCLASS
#endif
#define UCLASS(...)

#ifdef UFUNCTION
    #undef UFUNCTION
#endif
#define UFUNCTION(...)

#ifdef GENERATED_BODY
    #undef GENERATED_BODY
#endif
#define GENERATED_BODY(...)

#ifdef UPROPERTY
    #undef UPROPERTY
#endif
#define UPROPERTY(...)

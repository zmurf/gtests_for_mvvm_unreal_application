#pragma once

#include <gmock/gmock.h>
#include "Delegates/DelegateCombinations.h"

using namespace testing;

// Defined in module Core
// Delegates/DelegateCombinations.h
#ifdef DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam
    #undef DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam
#endif
#define DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(...)

#ifdef DECLARE_MULTICAST_DELEGATE
    #undef DECLARE_MULTICAST_DELEGATE
#endif
#define DECLARE_MULTICAST_DELEGATE(...)

#ifdef DECLARE_MULTICAST_DELEGATE_OneParam
    #undef DECLARE_MULTICAST_DELEGATE_OneParam
#endif
#define DECLARE_MULTICAST_DELEGATE_OneParam(...)

class FDelegateHandle;

class DelegateMock
{
public:
    MOCK_METHOD(void, Add, (DelegateMock& InNewDelegate));
    MOCK_METHOD(void, Add, (const DelegateMock& InNewDelegate));
    MOCK_METHOD(void, Bind, (DelegateMock& InNewDelegate));
    MOCK_METHOD(void, BindRaw, (DelegateMock& InNewDelegate));
    MOCK_METHOD(void, Remove, (FDelegateHandle*  Handle));
    MOCK_METHOD(bool, IsBound, ());
};
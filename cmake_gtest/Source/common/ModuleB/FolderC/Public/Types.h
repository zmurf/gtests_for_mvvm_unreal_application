#pragma once

#include "GenericPlatform/GenericPlatformMisc.h"

struct FData
{
    int32 A{};
    int32 B{};
};

using SubscriptionFunction = TFunction<void(FData const& msg)>;
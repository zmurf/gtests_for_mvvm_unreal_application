#pragma once

#include "TimerManager.h"
#include <gmock/gmock.h>
using namespace testing;

class UWorld
{
public:
    UWorld() = default;
    MOCK_METHOD(FTimerManager&, GetTimerManager, (), (const));
};
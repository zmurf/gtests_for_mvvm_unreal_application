#pragma once
#include "Comm.h"
#include "Types.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace testing;

class FCommMock : public FComm
{
public:
    MOCK_METHOD(void, Subscribe, (SubscriptionFunction Callback), (override));
};
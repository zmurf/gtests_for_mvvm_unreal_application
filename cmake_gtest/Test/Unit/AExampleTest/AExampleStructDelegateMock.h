#pragma once

#include "DelegateMock.h"

using namespace testing;

class FAExampleStruct;

class FAExampleStructDelegateMock : public DelegateMock
{
public:
    MOCK_METHOD(void, Broadcast, (const FAExampleStruct& data));
};
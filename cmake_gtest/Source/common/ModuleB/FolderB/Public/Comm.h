#pragma once

#include "Defines.h"
#include "Types.h"
#include "Containers/Array.h"

class FComm
{
public:
    explicit FComm();

    FComm& operator=(FComm const&)& = delete;
    FComm& operator=(FComm&&)& = delete;
    FComm(FComm const&) = delete;
    FComm(FComm&&) = delete;
    virtual ~FComm() = default;

    virtual void Subscribe(SubscriptionFunction Callback);

private:
    TArray<SubscriptionFunction> Subscriptions;
};

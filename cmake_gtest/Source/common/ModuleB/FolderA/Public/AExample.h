#pragma once

#include "AExampleBase.h"
#include "Signal.h"
#include "Comm.h"

class FAExample : public FAExampleBase
{
public:
    struct FAExampleData
    {
        int32 ValueA{};
        int32 ValueB{};
    };

    explicit FAExample(FComm& Subscription);

    FAExample& operator=(FAExample const&)& = delete;
    FAExample& operator=(FAExample&&)& = delete;
    FAExample(FAExample const&) = delete;
    FAExample(FAExample&&) = delete;
    ~FAExample();

    void ProcessMessage(FData const Data);
    void ConnectAExampleChanged(TFunction<void(FAExampleData const)> Callback);

    void ServiceAvailabilityChanged(bool Status) override;

private:
    FAExampleData AExampleData;
    util::FSignal<FAExampleData const> AExampleChanged;
    FComm& Comm;
};

#include "AExample.h"

FAExample::FAExample(FComm& Comm) : FAExampleBase{}, AExampleData{}, Comm{Comm}
{
    Comm.Subscribe([this](FData const& Message)
                   { this->ProcessMessage(Message); });
}

FAExample::~FAExample() {}

void FAExample::ProcessMessage(FData const Data)
{
    FAExampleData aExampleData{};
    aExampleData.ValueA = Data.A;
    aExampleData.ValueB = Data.B;
    AExampleChanged.Emit(aExampleData);
}

void FAExample::ConnectAExampleChanged(TFunction<void(FAExampleData const)> Callback)
{
    AExampleChanged.Connect(Callback);
}

void FAExample::ServiceAvailabilityChanged(bool const Status) {}
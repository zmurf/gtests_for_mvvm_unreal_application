#include "Comm.h"
#include <algorithm>
#include "Containers/Array.h"

FComm::FComm() : Subscriptions{} {}

void FComm::Subscribe(SubscriptionFunction Callback)
{
    Subscriptions.Add(Callback);
}
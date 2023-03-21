#pragma once

// TODO: This should not need to be here. Just here to make tests build.
#include "Defines.h"

class FAExampleBase
{
public:
    explicit FAExampleBase();

    FAExampleBase& operator=(FAExampleBase const&)& = delete;
    FAExampleBase& operator=(FAExampleBase&&)& = delete;
    FAExampleBase(FAExampleBase const&) = delete;
    FAExampleBase(FAExampleBase&&) = delete;
    ~FAExampleBase() = default;

    virtual void ServiceAvailabilityChanged(bool Status) = 0;
};

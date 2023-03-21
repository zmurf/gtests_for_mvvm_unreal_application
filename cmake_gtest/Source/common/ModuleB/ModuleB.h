#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"

class FModuleB : public IModuleInterface
{
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
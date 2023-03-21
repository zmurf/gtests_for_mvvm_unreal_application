#pragma once

// TODO: Defines.h should not need to be here. Just here to make tests build.
#include "Defines.h"
#include "Structs.h"
#include <cstdint>
#include "GameFramework/Actor.h"
#include "AExampleViewModel.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAExampleState, const FAExampleStruct&, State);

UCLASS(Blueprintable, BlueprintType)
class MODULEA_API AAExampleViewModel : public AActor
{
    GENERATED_BODY()
public:
    AAExampleViewModel();
    ~AAExampleViewModel() = default;

    virtual void SetState(FAExampleStruct const state);

    UPROPERTY(BlueprintAssignable, Category = " Interface|State")
    FAExampleState OnAExampleUpdated;

    UFUNCTION(BlueprintCallable, Category = " Interface|State")
    virtual void GetState(FAExampleStruct& state);

private:
    void CopyAExampleStruct(FAExampleStruct& left, FAExampleStruct const& right);
    FAExampleStruct AExampleState;
};

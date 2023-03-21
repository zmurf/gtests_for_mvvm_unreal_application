#include "AExampleViewModel.h"

AAExampleViewModel::AAExampleViewModel() : AExampleState{} {}

void AAExampleViewModel::SetState(FAExampleStruct const state)
{
    CopyAExampleStruct(AExampleState, state);

    if (OnAExampleUpdated.IsBound())
    {
        OnAExampleUpdated.Broadcast(AExampleState);
    }
}

void AAExampleViewModel::CopyAExampleStruct(FAExampleStruct& left, FAExampleStruct const& right)
{
    left.valueA = right.valueA;
    left.valueB = right.valueB;
}

void AAExampleViewModel::GetState(FAExampleStruct& state)
{
    CopyAExampleStruct(state, AExampleState);
}

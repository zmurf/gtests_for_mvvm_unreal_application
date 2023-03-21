#include "AExampleModel.h"

// TODO: This should not need to be here. Just here to make tests build.
#include "Structs.h"

FAExampleModel::FAExampleModel(FAExample& AExampleDao, AAExampleViewModel* ViewModel)
    : AExample{AExampleDao}, AExampleViewModel{ViewModel}
{
    AExample.ConnectAExampleChanged(
        [this](FAExample::FAExampleData const AExampleData)
        { this->UpdateAExample(AExampleData); });
}

void FAExampleModel::UpdateAExample(FAExample::FAExampleData const AExampleData)
{
    FAExampleStruct AExampleStruct;

    AExampleStruct.valueA = AExampleData.ValueA;
    AExampleStruct.valueB = AExampleData.ValueB;

    AExampleViewModel->SetState(AExampleStruct);
}
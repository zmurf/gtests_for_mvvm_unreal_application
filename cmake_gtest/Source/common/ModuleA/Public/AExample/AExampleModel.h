#pragma once

#include "AExampleViewModel.h"
#include "AExample.h"

class FAExampleModel
{
public:
    FAExampleModel(FAExample& AExampleDao, AAExampleViewModel* ViewModel);

private:
    void UpdateAExample(FAExample::FAExampleData AExampleData);

    FAExample& AExample;
    AAExampleViewModel* AExampleViewModel;
};
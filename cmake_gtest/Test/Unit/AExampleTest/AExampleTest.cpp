// TODO: Figure out why it isn't enough to include the Defines.h file here. Why do we need to add this file in AExampleBase.h and Structs.h?
#include "Defines.h"

#include "AExampleStructDelegateMock.h"

// Including Mock version of Comm
#include "Comm.h"
#include "CommMock.h"

#include "AExample.h"
#include "AExampleModel.h"
#include "AExampleViewModel.h"

#include <gtest/gtest.h>

TEST(AExampleTestNoMockedViewModel, JustForShow)
{
    // Arrange
    TUniquePtr<FCommMock> CommMock = MakeUnique<FCommMock>();
    SubscriptionFunction CallBack{};
    EXPECT_CALL(*CommMock, Subscribe(testing::_))
            .WillOnce(DoAll(SaveArg<0>(&CallBack)));

    AAExampleViewModel AExampleViewModel{};
    
    FAExampleStructDelegateMock& AExampleStructDelegateMock = AExampleViewModel.OnAExampleUpdated;
    EXPECT_CALL(AExampleStructDelegateMock, IsBound).WillRepeatedly(Return(true));

    FAExampleStruct Result{};
    EXPECT_CALL(AExampleStructDelegateMock, Broadcast).WillRepeatedly(SaveArg<0>(&Result));

    FAExample AExample{*CommMock};
    FAExampleModel AExampleModel{AExample, &AExampleViewModel};

    FAExampleStruct const ExpectedResult{15,18};

    // Act
    CallBack({15,18});

    // Assert
    EXPECT_EQ(Result.valueA, ExpectedResult.valueA);
    EXPECT_EQ(Result.valueB, ExpectedResult.valueB);
}

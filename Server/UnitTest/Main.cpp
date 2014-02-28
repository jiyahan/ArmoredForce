#include <iostream>
#include <gtest/gtest.h>
#include "easylogging++.h"

_INITIALIZE_EASYLOGGINGPP

class MyTestingEnviroment : public testing::Environment
{
public:
    void SetUp()
    {
    }

    void TearDown()
    {
    }
};

int main(int argc, char* argv[])
{
    srand(time(0));
    testing::AddGlobalTestEnvironment(new MyTestingEnviroment);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

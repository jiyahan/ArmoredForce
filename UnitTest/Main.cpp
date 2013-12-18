#include <iostream>
#include <gtest/gtest.h>
#include <stdlib.h>
#include <time.h>

//class MyTestingEnviroment : public testing::Environment
//{
//public:
//    void SetUp()
//    {
//        CAtom::Presetup();
//        CElectron::Presetup();
//        CAtom::Initiate(1024*1024);        
//        CElectron::Initiate(1);
//    }
//
//    void TearDown()
//    {
//        CElectron::Shutdown();
//        CAtom::Shutdown();
//        CElectron::Destruct();
//        CAtom::Destruct();
//    }
//};

int main(int argc, char* argv[])
{
    srand(time(0));
    //testing::AddGlobalTestEnvironment(new MyTestingEnviroment);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

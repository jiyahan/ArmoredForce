#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "Utility.h"


using namespace std;

TEST(Utility, GetUniqueID) 
{
    const int count = 100000;
    vector<string> vec;
    vec.reserve(count);
    for (int i = 0; i < count; ++i)
    {
        vec.emplace_back(GetUniqueID());
    }
}
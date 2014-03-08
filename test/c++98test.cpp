#include <limits.h>
#include "gtest/gtest.h"
#include "c++98.h"

using namespace std;

TEST(C98Tests, populateContainer)
{
   myC98class myClass;

   myClass.populateContainer();

   EXPECT_EQ(10, myClass.containerSize());
}

TEST(C98Tests, increaseAllValuesBy1)
{
   myC98class myClass;
   myClass.populateContainer();

   myClass.increaseValues(2);

   EXPECT_EQ(myClass[4] , 10);
}

TEST(C98Tests, forLoop)
{
   myC98class myClass;
   myClass.populateContainer();

   EXPECT_EQ(271, myClass.sum());
}

TEST(C98Tests, testTypes)
{
   myC98class myClass;
   myClass.populateContainer();
   
   myClass.deleteValue(4);
   EXPECT_EQ(8, myClass.containerSize());
}

TEST(C98Tests, sumWithThreadTest)
{
   myC98class myClass;
   myClass.populateContainer();

   EXPECT_EQ(271, myClass.sumWithThread());   
}

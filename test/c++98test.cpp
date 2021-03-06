#include <limits.h>
#include "gtest/gtest.h"
#include "c++98.h"

using namespace std;

TEST(C98Tests, initializeContainer)
{
   myC98class myClass;

   EXPECT_EQ(10, myClass.containerSize());
}

TEST(C98Tests, templateReturnType)
{
   myC98class myClass1;
   myC98class myClass2;
   myC98class sum = addObjects<myC98class, myC98class>(myClass1, myClass2);
   EXPECT_EQ(20, sum.containerSize());
}

TEST(C98Tests, increaseAllValuesBy1)
{
   myC98class myClass;

   myClass.increaseValues(2);

   EXPECT_EQ(myClass[4] , 10);
}

TEST(C98Tests, forLoop)
{
   myC98class myClass;

   EXPECT_EQ(271, myClass.sum());
}

TEST(C98Tests, testTypes)
{
   myC98class myClass;
   
   myClass.deleteValue(4);
   EXPECT_EQ(8, myClass.containerSize());
}

TEST(C98Tests, sumWithThreadTest)
{
   myC98class myClass;

   EXPECT_EQ(271, myClass.sumWithThread());   
}

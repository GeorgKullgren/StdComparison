#include "gtest/gtest.h"
#include "c++11.h"

using namespace std;


TEST(C11Tests, populateContainer)
{
   myC11class myClass;

   myClass.populateContainer();

   EXPECT_EQ(10, myClass.containerSize());
}

TEST(C11Tests, increaseAllValuesBy1)
{
   myC11class myClass;
   myClass.populateContainer();

   myClass.increaseValues(2);

   EXPECT_EQ(myClass[4] , 10);
}

TEST(C11Tests, forLoop)
{
   myC11class myClass;
   myClass.populateContainer();

   EXPECT_EQ(271, myClass.sum());
}

TEST(C11Tests, testTypes)
{
   myC11class myClass;
   myClass.populateContainer();
   
   myClass.deleteValue(4);
   EXPECT_EQ(8, myClass.containerSize());
}

TEST(C11Tests, sumWithThreadTest)
{
   myC11class myClass;
   myClass.populateContainer();

   EXPECT_EQ(271, myClass.sumWithThread());   
}

TEST(C11Tests, sumWithAsyncTest)
{
   myC11class myClass;
   myClass.populateContainer();

   EXPECT_EQ(271, myClass.sumWithAsync());   
}

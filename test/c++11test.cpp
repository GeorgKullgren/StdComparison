#include "gtest/gtest.h"
#include "c++11.h"

using namespace std;


TEST(C11Tests, initializeContainer)
{
   myC11class myClass;

   EXPECT_EQ(10, myClass.containerSize());
}


TEST(C11Tests, templateReturnType)
{
   myC11class myClass1;
   myC11class myClass2;
   myC11class sum = addObjects<myC11class, myC11class>(myClass1, myClass2);
   EXPECT_EQ(20, sum.containerSize());
}


TEST(C11Tests, increaseAllValuesBy1)
{
   myC11class myClass;

   myClass.increaseValues(2);

   EXPECT_EQ(myClass[4] , 10);
}


TEST(C11Tests, moveAssignement)
{
   myC11class myClass;
   myClass.increaseValues(2);

   // Use move assignement
   myClass = addObjects(myClass, myClass);
}


TEST(C11Tests, forLoop)
{
   myC11class myClass;

   EXPECT_EQ(271, myClass.sum());
}

TEST(C11Tests, testTypes)
{
   myC11class myClass;
   
   myClass.deleteValue(4);
   EXPECT_EQ(8, myClass.containerSize());
}

TEST(C11Tests, sumWithThreadTest)
{
   myC11class myClass;

   EXPECT_EQ(271, myClass.sumWithThread());   
}

TEST(C11Tests, sumWithAsyncTest)
{
   myC11class myClass;

   EXPECT_EQ(271, myClass.sumWithAsync());   
}


TEST(C11Tests, variadicPrint)
{
   int x=10;
   float f=1.3f;
   string s="test string";
   printTypes(x, f, s);
}

TEST(C11Tests, expressivePrint)
{
   int x=10;
   float f=1.3f;
   string s="test string";
   separatePrint(x, f, s);
}


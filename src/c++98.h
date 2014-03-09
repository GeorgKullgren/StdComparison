#pragma once

#include <vector>


class myC98class
{
public:
   void populateContainer();
   int containerSize();
   void increaseValues(int i);
   int operator[](int i);
   int sum();
   void deleteValue(int i);
   int sumWithThread();

private:
   std::vector<int> myInts;
};




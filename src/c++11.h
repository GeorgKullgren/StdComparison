#pragma once

#include <vector>


class myC11class
{
public:
   void populateContainer();
   int containerSize();
   void increaseValues(int i);
   int operator[](int i);
   int sum();
   void deleteValue(int i);
   int sumWithThread();
   int sumWithAsync();
   
private:
   std::vector<int> myInts;
};




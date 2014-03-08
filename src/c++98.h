#pragma once

#include <vector>

using namespace std;

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
   vector<int> myInts;
};




#pragma once

#include <vector>

using namespace std;

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
   vector<int> myInts;
};




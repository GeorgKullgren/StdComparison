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
   
private:
   vector<int> myInts;
};




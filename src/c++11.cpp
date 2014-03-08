#include "c++11.h"
#include <algorithm>

void myC11class::populateContainer()
{
   myInts.push_back(7);
   myInts.push_back(3);
   myInts.push_back(2);
   myInts.push_back(4);
   myInts.push_back(8);
   myInts.push_back(4);
   myInts.push_back(22);
   myInts.push_back(211);
   myInts.push_back(1);
   myInts.push_back(9);   
}

int myC11class::containerSize()
{
   return myInts.size();
}

void myC11class::increaseValues(int i)
{
   for_each(begin(myInts), end(myInts), [i](int &value)
            {
               value += i;
            });
}

int myC11class::operator[](int i)
{
   return myInts[i];
}


int myC11class::sum()
{
   int total = 0;
   for (int i: myInts)
   {
      total += i;
   }
   return total;
}

void myC11class::deleteValue(int i)
{
   auto func = [](){};
   
   for (auto it = begin(myInts); it != end(myInts); )
   {
      if (*it == i)
      {
         it = myInts.erase(it);
      }
      else
      {
         ++it;
      }
   }  
}

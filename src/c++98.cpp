#include "c++98.h"
#include <algorithm>
#include <functional>


struct addValue: binary_function<int, int, void>
{
   void operator() (int &a, const int b) const { a += b;}
};



void myC98class::populateContainer()
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

int myC98class::containerSize()
{
   return myInts.size();
}

void myC98class::increaseValues(int i)
{
   for_each(myInts.begin(), myInts.end(), bind2nd<addValue>(addValue(), i));
}

int myC98class::operator[](int i)
{
   return myInts[i];
}

int myC98class::sum()
{
   int total = 0;

   for (vector<int>::iterator it = myInts.begin(); it != myInts.end(); ++it)
   {
      total += *it;
   }
   return total;
}




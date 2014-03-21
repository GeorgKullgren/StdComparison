#pragma once

#include <vector>


class myC98class
{
public:
   myC98class();
   myC98class(std::vector<int> vec);
   void populateContainer();
   int containerSize();
   void increaseValues(int i);
   int operator[](int i);
   myC98class operator+(myC98class rhs);
   int sum();
   void deleteValue(int i);
   int sumWithThread();

private:
   std::vector<int> myInts;
};


template<class Lhs, class Rhs>
Lhs addObjects(Lhs lhs, Rhs rhs)
{
   return lhs+rhs;
}




#pragma once

#include <vector>


class myC98class
{
public:
   myC98class();
   myC98class(const std::vector<int> vec);
   int containerSize();
   void increaseValues(int i);
   int operator[](int i);
   myC98class operator+(const myC98class& rhs);
   int sum();
   void deleteValue(int i);
   int sumWithThread();

private:
   std::vector<int> myInts;
};


template<class Lhs, class Rhs>
Lhs addObjects(Lhs& lhs, Rhs& rhs)
{
   return lhs+rhs;
}




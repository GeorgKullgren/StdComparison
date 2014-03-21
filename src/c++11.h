#pragma once

#include <vector>


class myC11class
{
public:
   myC11class();
   myC11class(std::vector<int> vec);
   void populateContainer();
   int containerSize();
   void increaseValues(int i);
   int operator[](int i);
   myC11class operator+(myC11class rhs);
   int sum();
   void deleteValue(int i);
   int sumWithThread();
   int sumWithAsync();
   
private:
   std::vector<int> myInts;
};


template<class Lhs, class Rhs>
auto addObjects(Lhs lhs, Rhs rhs) -> decltype(lhs+rhs)
{
   return lhs+rhs;
}


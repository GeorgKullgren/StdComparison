#pragma once

#include <vector>
#include <iostream>


class myC11class
{
public:
   myC11class();
   myC11class(const std::vector<int>& vector);
   myC11class(const myC11class& other);
   
   int containerSize();
   void increaseValues(int i);
   int operator[](int i);
   myC11class& operator=(const myC11class& rhs);
   myC11class& operator=(myC11class&& rhs);   
   myC11class operator+(const myC11class& rhs);
   int sum();
   void deleteValue(int i);
   int sumWithThread();
   int sumWithAsync();
   
private:
   std::vector<int> myInts;
};


template<class Lhs, class Rhs>
auto addObjects(Lhs& lhs, Rhs& rhs) -> decltype(lhs+rhs)
{
   return lhs+rhs;
}

template<typename Type>
int printTypes(Type value)
{
   std::cout << value << std::endl;
   return 0;
}

template<typename Type, typename... Tail>
int printTypes(Type value, Tail... tail)
{
   std::cout << value << " ";
   printTypes(tail...);
   return 0;
}


template<typename... Args>
void separatePrint(Args... args)
{
   int dummy[] = { printTypes(args)...};
}

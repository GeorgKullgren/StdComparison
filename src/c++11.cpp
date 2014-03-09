#include "c++11.h"
#include <algorithm>
#include <thread>
#include <future>

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
   for_each(std::begin(myInts), std::end(myInts), [i](int &value)
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
   for (auto it = std::begin(myInts); it != std::end(myInts); )
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

int partialSum(std::vector<int>::iterator it1, std::vector<int>::iterator it2)
{
   return std::accumulate(it1, it2, 0);
}

int myC11class::sumWithThread()
{
   std::packaged_task<int(std::vector<int>::iterator, std::vector<int>::iterator)> task1(partialSum);
   std::packaged_task<int(std::vector<int>::iterator, std::vector<int>::iterator)> task2(partialSum);

   std::future<int> ret1 = task1.get_future();
   std::future<int> ret2 = task2.get_future();
   
   std::thread th1(move(task1), std::begin(myInts), std::begin(myInts)+5);
   std::thread th2(move(task2), std::begin(myInts)+5, std::end(myInts));

   int sum = ret1.get();
   sum += ret2.get();

   th1.join();
   th2.join();
   
   return sum;
}

int myC11class::sumWithAsync()
{
   auto ret1 = std::async(std::launch::async, partialSum, std::begin(myInts), std::begin(myInts)+5);
   auto ret2 = std::async(std::launch::async, partialSum, std::begin(myInts)+5, std::end(myInts));

   return ret1.get() + ret2.get();
}


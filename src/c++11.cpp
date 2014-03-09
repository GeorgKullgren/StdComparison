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

int partialSum(vector<int>::iterator it1, vector<int>::iterator it2)
{
   return accumulate(it1, it2, 0);
}

int myC11class::sumWithThread()
{
   packaged_task<int(vector<int>::iterator, vector<int>::iterator)> task1(partialSum);
   packaged_task<int(vector<int>::iterator, vector<int>::iterator)> task2(partialSum);

   future<int> ret1 = task1.get_future();
   future<int> ret2 = task2.get_future();
   
   thread th1(move(task1), begin(myInts), begin(myInts)+5);
   thread th2(move(task2), begin(myInts)+5, end(myInts));

   int sum = ret1.get();
   sum += ret2.get();

   th1.join();
   th2.join();
   
   return sum;
}

int myC11class::sumWithAsync()
{
   auto ret1 = async(launch::async, partialSum, begin(myInts), begin(myInts)+5);
   auto ret2 = async(launch::async, partialSum, begin(myInts)+5, end(myInts));

   return ret1.get() + ret2.get();
}


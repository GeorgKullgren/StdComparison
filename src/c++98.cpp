#include "c++98.h"
#include <algorithm>
#include <functional>
#include <pthread.h>
#include <iostream>


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

void myC98class::deleteValue(int i)
{
   for (vector<int>::iterator it = myInts.begin(); it != myInts.end(); )
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

void *sumOfContainer(void *ptr)
{
   vector<int>::iterator *itPair = (vector<int>::iterator *)ptr;
   int *total = new int(0);

   for (vector<int>::iterator it = itPair[0]; it != itPair[1]; ++it)
   {
      *total += *it;
   }
   
   pthread_exit((void*)total);   
}


int myC98class::sumWithThread()
{
   pthread_t thread1, thread2;
   vector<int>::iterator itT1[2];
   vector<int>::iterator itT2[2];
   
   itT1[0] = myInts.begin();
   itT1[1] = itT1[0]+5;
   itT2[0] = itT1[1];
   itT2[1] = myInts.end();
   
   pthread_create(&thread1, NULL, &sumOfContainer, (void*)&itT1);
   pthread_create(&thread2, NULL, &sumOfContainer, (void*)&itT2);

   int *ret1, *ret2;
   pthread_join(thread1, (void **)&ret1);
   pthread_join(thread2, (void **)&ret2);

   int sum  = *ret1 + *ret2;
   delete ret1;
   delete ret2;
   return sum;
}

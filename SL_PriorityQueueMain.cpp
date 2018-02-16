//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** A driver that demonstrates the class PriorityQueue. */

#include "SL_PriorityQueue.h" // ADT Priority Queue operations
#include <iostream>
#include <string>

using namespace std;

void pqTester(PriorityQueueInterface<string>* pqPtr)
{
	string items[] = {"one", "two", "three", "four", "five", "six"};
	cout << "Empty: " << pqPtr->isEmpty() << endl;
	for (int i = 0; i < 6; i++)
   {
		cout<<"Adding " << items[i] << endl;
      bool success = pqPtr->add(items[i]);
      if (!success)
         cout << "Failed to add " << items[i] << " to the priority queue." << endl;
	}  // end for
   
	cout << "Empty?: " << pqPtr->isEmpty() << endl;
	
	for (int i = 0; i < 6; i++) 
   {
		cout << "Loop " << i << endl;
      
      try 
      {
         cout << "peek: " << pqPtr->peek() << endl;
      } 
      catch (PrecondViolatedExcep e) 
      {
         cout << e.what() << endl;
      }  // end try/catch
      
		cout << "Empty: " << pqPtr->isEmpty() << endl;
		cout << "Remove: " << pqPtr->remove() << endl;
	}  // end for
   
   cout << "remove with an empty priority queue: " << endl;
	cout << "Empty: " << pqPtr->isEmpty() << endl;
	cout << "remove: " << pqPtr->remove() << endl; // nothing to remove!
   
   try 
   {
      cout << "peek with an empty priority queue: " << endl;
	   cout << "peek: " << pqPtr->peek() << endl; // nothing to see!
   } 
   catch (PrecondViolatedExcep e) 
   {
      cout << e.what();
   }  // end try/catch
} // end pqTester

int main()
{
	PriorityQueueInterface<string>* pqPtr = new SL_PriorityQueue<string>();
	cout << "Testing the priority queue:" <<endl;
	pqTester(pqPtr);
	
   return 0;
}  // end main

/*
 Testing the priority queue:
 Empty: 1
 Adding one
 Adding two
 Adding three
 Adding four
 Adding five
 Adding six
 Empty?: 0
 Loop 0
 peek: two
 Empty: 0
 Remove: 1
 Loop 1
 peek: three
 Empty: 0
 Remove: 1
 Loop 2
 peek: six
 Empty: 0
 Remove: 1
 Loop 3
 peek: one
 Empty: 0
 Remove: 1
 Loop 4
 peek: four
 Empty: 0
 Remove: 1
 Loop 5
 peek: five
 Empty: 0
 Remove: 1
 remove with an empty priority queue:
 Empty: 1
 remove: 0
 peek with an empty priority queue:
 peek: Precondition Violated Exception: peekFront() called with empty queue.
 */

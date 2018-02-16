/*
Name: Daniel Tillmann
ID: cs301311
Class: 301-2
Date: November 21, 2017
File Location: /export/home/cs301/cs301311/Project9
*/

/**	@file Driver.cpp */

#include "SL_PriorityQueue.cpp"
#include "LinkedQueue.cpp"
#include "Event.cpp"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
using namespace std;


/** display() prints the items in the queue to the screen. used for debugging purposes only.
*@param
*@pre none
*@post The items in the queue are printed on screen and the queue is now empty
*@return none
**/
void display(SL_PriorityQueue<Event>& pQueue){
	while(!pQueue.isEmpty()){
		cout << pQueue.peek().getType() << " " << pQueue.peek().getTime() << " " << pQueue.peek().getLength() << " " << endl;
		pQueue.remove();
	}
}

/** printFinalStats() displays the total number of customers for the day and the average wait time
*@param total - the total number of customers
*@param waitTime - the total amount of wait time
*@pre none
*@post The total number of customers and the average wait time are displayed to the screen
*@return none
**/
void printFinalStats(const double& total, const double& waitTime){
	cout << endl << "Simulation has ended." << endl;
	for(int i = 1; i < 45; i++){
		cout << '-';
	}
	cout << endl << "FINAL STATISTICS: " << endl;
	cout << "Total number of customers processed: " <<  total << endl;
	cout << "Average amount of time spent waiting: ";
	cout <<  setprecision(3) << waitTime / total << endl;
}

/** loadEvents() takes a data file and populates Event objects and stores them in a priority queue.
* It also checks to see if the arrival times are valid. Does the customer arrive during normal business hours?
*@param pQueue - the reference parameter to store the Event objects
*@param in - the input file stream for the data file
*@pre none
*@post pQueue is filled with Event objects that contain the data from the file from in
*@return True if the load was successful, otherwise false.
**/
bool loadEvents(SL_PriorityQueue<Event>& pQueue, ifstream& in){
	string garbage;
	double arrival, length;
	int startOfDay = 0, endOfDay = 540;
	char eventType = 'A';
	bool loadSuccessful = true;
	while(!in.eof()){
		Event arrivalEvent;
		in >> arrival >> length;
		getline(in, garbage);
		
		//check to see if the customer arrives during normal business hours
		if((arrival > startOfDay) && (arrival <= endOfDay)){
		
			arrivalEvent.setType(eventType);
			arrivalEvent.setTime(arrival);
			arrivalEvent.setLength(length);
		
			if(!pQueue.add(arrivalEvent)){
				loadSuccessful = false;
			}
		}
		
	}
	in.close();
	in.clear();
	return loadSuccessful;
}

/** simulate() takes a priority queue and a queue and processes a simulation based on the Event objects 
* inside the priority queue.
*@param pQ - the priority queue holding all of the Event objects.
*@param bankLine - a regular queue to hold Events while the teller (boolean) is busy (false). 
*@pre loadEvents() must return true to begin simulation.
*@post The simulation is processed and printed to the screen.
*@return none
**/
void simulate(SL_PriorityQueue<Event>& pQ, LinkedQueue<Event>& bankLine){
	bool tellerIsFree = true;
	char arrivalChar = 'A', departureChar = 'D';
	Event departureEvent, customerAtTeller;
	double currentTime = 0.0, length = 0.0, custTransactionTime = 0.0, totalCustomers = 0.0, totalWaitTime = 0.0;
	
	
	while(!pQ.isEmpty()){
		Event customer = pQ.peek();
		//custTransactionTime = currentTime + length;
		
		if(customer.getType() == arrivalChar){
			
			//count the number of customers that visited the bank today
			totalCustomers++;
			
			//process the arrival event
			pQ.remove();
			
			currentTime = customer.getTime();
			length = customer.getLength();
			cout << "Processing an arrival event at time: " << currentTime << endl;
			
			if(bankLine.isEmpty() && tellerIsFree){
				custTransactionTime = currentTime + length;
				departureEvent.setType(departureChar); 
				departureEvent.setTime(custTransactionTime);
				pQ.add(departureEvent);
				tellerIsFree = false;
			}else{
				bankLine.enqueue(customer);
			}
			
		}else{
			//process the departure event
			
			double departureTime = pQ.peek().getTime();
			cout << "Processing a departure event at time: " << departureTime << endl;
			pQ.remove();
			if(!bankLine.isEmpty()){
				Event nextCustomer = bankLine.peekFront();
				//**
				totalWaitTime += (departureTime - nextCustomer.getTime());
				//**
				bankLine.dequeue();
				Event departureEvent(departureChar, departureTime + nextCustomer.getLength(), 0.0);
				pQ.add(departureEvent);
				
			}else{
				tellerIsFree = true;
			}
				
		}
	}
	printFinalStats(totalCustomers, totalWaitTime);
}

int main(){
	SL_PriorityQueue<Event> Events;// both arrival and departure
	LinkedQueue<Event> bankLine;
	string inFile = "";
	ifstream in_file;
	
	do{
		cout << "Enter the name of a data file: ";
		getline(cin, inFile);
		in_file.open(inFile.c_str());
	}while(!in_file);
	
	assert(loadEvents(Events, in_file));
	
	simulate(Events, bankLine);
		
	return 0;
}

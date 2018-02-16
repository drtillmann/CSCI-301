/*
Name: Daniel Tillmann
ID: cs301311
Class: 301-2
Date: November 21, 2017
File Location: /export/home/cs301/cs301311/Project9
*/

/**	@file Event.h */

#ifndef EVENT
#define EVENT

using namespace std;

class Event{
	private:
		/**
		* eventType - holds the character A or D depending on the type of the current Event.
		**/
		char eventType;
		/**
		* time - holds either the arrical time or the departure time, depending on the type of the Event.
		**/
		double time;
		/**
		* length - holds the amount of time the customer will be at the teller.
		**/
		double length;
		
	public:
		/**Default constructor
		@post initializes private data members to empty, 0, 0 respectively
		**/
		Event();
		
		/** Parametized constructor
		@param e - the event type to be stored in eventType
		@param t - the arrival time to be stored in time
		@param l - the transaction time to be store in length
		@pre none
		@post initializes private data members to the values of e, t, l respectively
		@return none
		**/
		Event(char e, double t, double l);
		
		/** setType() sets the value stored in eventType to the value in parameter type
		@param type - the value to be stored in eventType
		@pre none;
		@post eventType stores the value in type
		@return none
		**/
		void setType(char type);

		/**setLength() sets the value in transactionTime to the value held in parameter l
		@param l - the value to be stored in length
		@pre none
		@post length stores the value in l
		@return none
		**/
		void setLength(double l);

		/**setTime() sets the value in arrivalTime to the value held in parameter t
		@param t - the value to be stored in time
		@pre none
		@post time stores the value in t
		@return none
		**/
		void setTime(double t);

		/**getType() returns the value stored in eventType
		@param none
		@pre none
		@post none
		@return The value stored in eventType
		**/
		char getType() const;
		
		/**getTime() returns the value stored in time
		@param none
		@pre none
		@post none
		@return The value stored in time
		**/
		double getTime() const;

		/**getLength() returns the value stored in length
		@param none
		@pre none
		@post none
		@return The value stored in length
		**/		
		double getLength() const;
};

/** NONMEMBER FUNCTIONS **/

/** == compares two Event objects to see if they are equal.
*@param e1 - the LHS Event object.
*@param e2 - the RHS Event object.
*@pre none
*@post none
*@return true if they are equal, otherwise false.
**/
bool operator ==(const Event& e1, const Event& e2);

/** > compares two Event object to see if the LHS object is greater than the RHS object.
*@param e1 - the LHS Event object.
*@param e2 - the RHS Event object.
*@pre none
*@post none
*@return true if the LHS object is greater than the RHS object, otherwise false.
**/
bool operator > (const Event& e1, const Event& e2);

/** != compares two Event objects to see if they are not equal.
*@param e1 - the LHS Event object.
*@param e2 - the RHS Event object.
*@pre none
*@post none
*@return true if the LHS and RHS objects are not equal, otherwise false.
**/
bool operator != (const Event& e1, const Event& e2);


#endif

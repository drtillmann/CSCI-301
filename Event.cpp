/*
Name: Daniel Tillmann
ID: cs301311
Class: 301-2
Date: November 21, 2017
File Location: /export/home/cs301/cs301311/Project9
*/

/**	@file Event.cpp */

#include "Event.h"

using namespace std;

Event::Event(): eventType(' '), time(0), length(0){
	
}

Event::Event(char e, double t, double l): eventType(e), time(t), length(l){
	
}

char Event::getType() const{
		return eventType; 
}
	
void Event::setType(char type){
		eventType = type;
}
	
double Event::getTime() const{
		return time;
}

void Event::setTime(double t){
	time = t;
}

double Event::getLength() const{
		return length;
}

void Event::setLength(double l){
	length = l;
}

/** NONMEMBER FUNCTIONS **/

bool operator==(const Event& e1, const Event& e2){
	return ((e1.getType() == e2.getType()) && (e1.getTime() == e2.getTime()) && (e1.getLength() == e2.getLength()));
}

bool operator> (const Event& e1, const Event& e2){
	return (e1.getTime() > e2.getTime());
}

bool operator!= (const Event& e1, const Event& e2){
	return ((e1.getType() != e2.getType()) || (e1.getTime() != e2.getTime()) || (e1.getLength() != e2.getLength()));
}
/*
Name: Daniel Tillmann
ID: cs301311
Class: 301-2
Date: October 9, 2017
File Location: /export/home/cs301/cs301311/Project5
*/

/**	@file Node.h */
	
#ifndef _NODE
#define _NODE
#include <cstddef>
template<class ItemType>
class Node
{
private:

	/** item, the value being stored in the node. */
   ItemType        item;
   
   /** previous, the pointer to the previous node. */
   Node<ItemType>* previous;
   
   /** next, the pointer to the next node. */
   Node<ItemType>* next;
   
public:

	/** Default Constructor 
		@pre none
		@post Initializes private data members next and previous.
	*/
	Node() : next(NULL), previous(NULL){	}
   
   /** Constructor
		@param anItem - the item being stored in the node
		@pre none
		@post Initializes all private data members.
	*/
	Node(const ItemType& anItem) : item(anItem), next(NULL), previous(NULL){	}
	
	/** Constructor
		@param anItem - the item being stored in the node, nextNodePtr - pointer to next node, prevNodePtr - pointer to previous node
		@pre none
		@post Initializes all private data members via parameters.
	*/
	Node(const ItemType& anItem, Node<ItemType>* nextNodePtr, Node<ItemType>* prevNodePtr) :
                item(anItem), next(nextNodePtr), previous(prevNodePtr){	}
				
	Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) :
				item(anItem), next(nextNodePtr){	}
	
   /** To store an item in item
		@param anItem - the item being stored in the node
		@pre none
		@post item is set the value of anItem.
	*/
   void setItem(const ItemType& anItem);
   
   /** To store a pointer to the next node in the current node
		@param nextNodePtr - pointer to the next node
		@pre none
		@post next is set to the value of nextNodePtr.
	*/
   void setNext(Node<ItemType>* nextNodePtr);
   
   /** Return the value of item
		@param none
		@pre none
		@post none
		@return the value of item
	*/
   ItemType getItem() const ;

	/** Return the value of next
		@param none
		@pre none
		@post none
		@return the value of next
	*/
   Node<ItemType>* getNext() const ;
   
   /** To store a pointer to the previous node in the current node
		@param prevNodePtr - pointer to the next node
		@pre none
		@post previous is set to the value of prevNodePtr.
	*/
   void setPrevious(Node<ItemType>* prevNodePtr);
   
   /** Return the value of previous
		@param none
		@pre none
		@post none
		@return the value of previous
	*/
   Node<ItemType>* getPrevious() const;
   
}; // end Node
//#include "Node.cpp"
#endif
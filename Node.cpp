/*
Name: Daniel Tillmann
ID: cs301311
Class: 301-2
Date: October 9, 2017
File Location: /export/home/cs301/cs301311/Project5
*/

/**	@file Node.cpp */
	
#include "Node.h"
#include <cstddef>

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
   item = anItem;
} // end setItem

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
   next = nextNodePtr;
} // end setNext

template<class ItemType>
void Node<ItemType>::setPrevious(Node<ItemType>* prevNodePtr)
{
   previous = prevNodePtr;
} // end setPrevious

template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
   return item;
} // end getItem

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
   return next;
} // end getNext

template<class ItemType>
Node<ItemType>* Node<ItemType>::getPrevious() const{
	return previous;
}//  end getPrevious




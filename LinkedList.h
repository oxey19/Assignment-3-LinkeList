
/***********************************************************
* Author:				Raymond Berry
* Date Created:			10/16/2015
* Last Modification Date:	10/16/2015
* Lab Number:			CST 211 Assignment 3
* Filename:				LinkList.h
*/
#include "Node.h"
#include <iostream>
#include "Iterator.h"

using namespace std;



/************************************************************************
* Class: LinkedList
*
* Constructors:
*	LinkedList()
*		Allows the user to creates LinkedLists

	LinkedList(Node &original)
		allows the user to copy LinkedLists

*
* Mutators:
*	void Prepend(type* theElement)
		Allows the user to add nodes ot the linked list at the begining

	void Append(type* theElement)
		Allows the user to add nodes to the end of the link list
		
	void Purge()
		sets the linkedlist to null

	Node<type>& Extract(type theElement)
		Pops the first node of the given element out of the linkedlist

	void InsertAfter(type theElement, type* theOrigin)
		Allows the user to insert the ellement (theOrigin) after the specified value (theElement)

	void InsertBefore(type theElement, type* theOrigin)
		Allows the user to insert teh ellement (theOrigin) before the specified value (theElement)
*
* Methods:
*	LinkedList &operator = (const LinkedList &rhs);
		allows the user to assign LinkedLists to other LinkedLists

	~LinkedList();
		allows the node to be deconstructed

	bool isEmpty();
		returns if the list is empty or not

	const Node<type>& First();
		returns the first node in the LinkedList

	const Node<type>& Last();
		returns the last node in the LinkedList

	LinkedList subList(type startVal, type endVal);
		Returns a LinkedList that has a head with the value inputed,
		and a tail with the value of the secound perameter
		
	Iterator<type> Begin();
		Creates and returns an Iterator that starts at the begining of linkedlist

	Iterator<type> End();
		Creates and returns an iterator that starts at the end of a linkedlist
*************************************************************************/
template <class type> 
class LinkedList
{
public:
	LinkedList();
	LinkedList(LinkedList &original);
	LinkedList &operator = (const LinkedList &rhs);
	~LinkedList();

	//Inspectors
	bool isEmpty();
	const Node<type>& First();
	const Node<type>& Last();
	LinkedList subList(type startVal, type endVal);

	//Mutatoer
	void Prepend(type* theElement);
	void Append(type* theElement);
	void Purge();
	Node<type>& Extract(type theElement);
	void InsertAfter(type theElement, type* theOrigin);
	void InsertBefore(type theElement, type* theOrigin);

	Iterator<type> Begin();
	Iterator<type> End();

private:
	Node<type>* m_tail;
	Node<type>* m_head;
};

#include "LinkedList.inc"
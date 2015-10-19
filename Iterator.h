
/***********************************************************
* Author:				Raymond Berry
* Date Created:			10/16/2015
* Last Modification Date:	10/16/2015
* Lab Number:			CST 211 Assignment 3
* Filename:				Iterator.h
*/

/************************************************************************
* Class: Iterator
*
* Constructors:
*	Iterator()
*		does nothing (alows an Iterator to be created)

	Iterator(Node<tupe>* node) 
		allows the user to create an iterator giving it a start location


	Iterator(Iterator &original)
		allows the user to copy the iterator

*
* Mutators:
*	Iterator& operator++()
		increments to the next ellement in the link list

Iterator& operator++(int)
		increments to the next ellement in the link list

Iterator& operator--(int)
		decrements to the previous ellement in the link list

Iterator& operator--()
		decrements to the previous ellement in the link list
*
* Methods:
*	Iterator &operator = (const Iterator &rhs)
		Allows the user to set one iterator to another
*************************************************************************/

template <class type>
class Iterator
{
public:
	Iterator();

	Iterator(Node<type>* node);

	Iterator(Iterator &original);

	Iterator &operator = (const Iterator &rhs);

	~Iterator();

	//Accessers
	Iterator& operator++();
	Iterator operator++(int);

	Iterator& operator--();
	Iterator operator--(int);
private:
	Node<type>* m_node;
};

#include "Iterator.inc"

/***********************************************************
* Author:				Raymond Berry
* Date Created:			10/16/2015
* Last Modification Date:	10/16/2015
* Lab Number:			CST 211 Assignment 3
* Filename:				Iterator.inc
*/

/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  to allow the user to create an Iterator
**************************************************************/

template<class type> Iterator<type>::Iterator()
{
}

/**************************************************************
*   Entry:  Node<type>* which is the starting of the iterator
*
*    Exit:  none
*
* Purpose:  Allows the user to make an Iterator with a starting point
**************************************************************/

template<class type> Iterator<type>::Iterator(Node<type>* node) :
m_node(node)
{
}

/**************************************************************
*   Entry:  a Iterator &, allows the user to make a copy of an iteraotr
*
*    Exit: none
*
* Purpose: to allow the user to make copies of iterators
**************************************************************/

template<class type> Iterator<type>::Iterator(Iterator &original) :
m_node(original.m_node)
{
}

/**************************************************************
*   Entry:  none
*
*    Exit:  none
* Purpose: decunstruts the iterator object
**************************************************************/

template<class type> Iterator<type>::~Iterator()
{
}

/**************************************************************
*   Entry:  const Iterator (what is going to be copied)
*    Exit:  Iterator<type> (the newly assigned iterator)
*
* Purpose:  to allow the user to make iteraors equal to other iterators
**************************************************************/

template<class type> Iterator<type> &Iterator<type>::operator=(const Iterator &rhs)
{
	m_node = rhs.m_node;
	return *this;
}

/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  allows the user to increment through a link list
**************************************************************/

template<class type> Iterator<type> &Iterator<type>::operator++()
{
	m_node = (*m_node).getNext();
	return *this;
}

/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  allows the user to increment through a link list
**************************************************************/
template<class type> Iterator<type> Iterator<type>::operator++(int)
{
	m_node = (*m_node).getNext();
	return *this;
}

/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  allows the user to decrement through a link list
**************************************************************/
template<class type> Iterator<type> &Iterator<type>::operator--()
{
	m_node = (*m_node).getPrev();
	return *this;
}

/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  allows the user to decrement through a link list
**************************************************************/
template<class type> Iterator<type> Iterator<type>::operator--(int)
{
	m_node = (*m_node).getPrev();
	return *this;
}



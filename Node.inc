
/***********************************************************
* Author:				Raymond Berry
* Date Created:			10/16/2015
* Last Modification Date:	10/16/2015
* Lab Number:			CST 211 Assignment 3
* Filename:				Node.inc
*/


/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  allows the user to create nodes
**************************************************************/
template<class type> Node<type>::Node()
{
}

/**************************************************************
*   Entry:  Node&
*
*    Exit:  none
*
* Purpose:  allows the user to make copies of nodes
**************************************************************/
template<class type> Node<type>::Node(Node &ogriginal) :
m_data(ogriginal.m_data),
m_next(ogriginal.m_next),
m_prev(ogriginal.m_prev)
{
}

/**************************************************************
*   Entry:  Node&
*
*    Exit:  none
*
* Purpose:  allows the user to assign nodes to one another
**************************************************************/
template<class type> Node<type> &Node<type>::operator=(const Node &rhs)
{
	m_data = ogriginal.m_data;
	m_next = ogriginal.m_next;
	m_prev = ogriginal.m_prev;

	return *this;
}

/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  allows nodes to be deconstructed
**************************************************************/
template<class type> Node<type>::~Node()
{
}


/**************************************************************
*   Entry:  none
*
*    Exit:  the data
*
* Purpose:  allows the user to get the data in the node
**************************************************************/
template<class type> type Node<type>::getData()
{
	return m_data;
}

/**************************************************************
*   Entry:  none
*
*    Exit:  Node<type>*
*
* Purpose:  allows the user to get the pointer to the next node
in the linked list
**************************************************************/
template<class type> Node<type>* Node<type>::getNext()
{
	return m_next;
}

/**************************************************************
*   Entry:  none
*
*    Exit:  Node<type>*
*
* Purpose:  allows the user to get the pointer to the previous node
in the linked list
**************************************************************/
template<class type> Node<type>* Node<type>::getPrev()
{
	return m_prev;
}

/**************************************************************
*   Entry:  type Newdata (the new data that is wanted to make a node)
*
*    Exit:  node
*
* Purpose:  allows the user to change the data in the linked list
**************************************************************/
template<class type> void Node<type> ::setData(type newData)
{
	m_data = newData;
}

/**************************************************************
*   Entry:  Node* newPrev
*
*    Exit:  none
*
* Purpose:  allows the user to change the next node in the linked list
**************************************************************/
template<class type> void Node<type> ::setPrev(Node *newPrev)
{
	m_prev = newPrev;
}

/**************************************************************
*   Entry:  Node* newPrev
*
*    Exit:  none
*
* Purpose:  allows the user to change the previous node in the linked list
**************************************************************/
template<class type> void Node<type> ::setNext(Node *newNext)
{
	m_next = newNext;
}


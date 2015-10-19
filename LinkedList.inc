
/***********************************************************
* Author:				Raymond Berry
* Date Created:			10/16/2015
* Last Modification Date:	10/16/2015
* Lab Number:			CST 211 Assignment 3
* Filename:				LinkList.inc
*/


/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  allows the user to create LinkedLists
**************************************************************/
template<class type> LinkedList<type>::LinkedList()
{
	m_tail = NULL;
	m_head = NULL;
}

/**************************************************************
*   Entry:  LinkedList
*
*    Exit:  none
*
* Purpose:  allows the user to copy LinkedLists
**************************************************************/
template<class type> LinkedList<type>::LinkedList(LinkedList &original) :
m_tail(original.m_tail),
m_head(original.m_head)
{
}

/**************************************************************
*   Entry:  LinkedList
*
*    Exit:  none
*
* Purpose:  allows the user to set one LinkedList to another
**************************************************************/
template<class type> LinkedList<type> &LinkedList<type>::operator=(const LinkedList &rhs)
{
	m_tail = rhs.m_tail;
	m_head = rhs.m_head;

	return *this;
}

/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose: allows the LinkedList to be destructed
**************************************************************/
template<class type> LinkedList<type>::~LinkedList()
{
}

/**************************************************************
*   Entry:  none
*
*    Exit:  boolean true or false
*
* Purpose:  allows the user to check if the linkedList is empty or not
**************************************************************/
template<class type> bool LinkedList<type>::isEmpty()
{
	if (m_head == NULL && m_tail == NULL)
	{
		return true;
	}
	return false;
}

/**************************************************************
*   Entry:  none
*
*    Exit:  Node<type>& returns the addres of the fisrt node 
*
* Purpose:  allows the user to get the first node in the LinkeList 
**************************************************************/
template<class type> const Node<type>& LinkedList<type>::First()
{
	return m_head;
}

/**************************************************************
*   Entry:  none
*
*    Exit:   Node<type>& returns the addres of the lsat node  
*
* Purpose:  allows the user to get the last node in the LinkedList
**************************************************************/
template<class type> const Node<type>& LinkedList<type>::Last()
{
	return m_tail;
}

/**************************************************************
*   Entry:  a pointer to the ellement that is going to be added
*
*    Exit:   none
*
* Purpose:  allows the user to add nodes to the begining of the LinkedList
**************************************************************/
template<class type> void LinkedList<type>::Prepend(type* theElement)
{
	Node<type>* tempPtr;
	tempPtr = new Node<type>();

	(*tempPtr).setData(*theElement);
	if (m_head == NULL)
	{
		(*tempPtr).setNext(NULL);
		(*tempPtr).setPrev(NULL);

		m_head = tempPtr;
		m_tail = tempPtr;
	}
	else
	{
		(*tempPtr).setNext(m_head);
		(*tempPtr).setPrev(NULL);

		(*m_head).setPrev(tempPtr);

		m_head = tempPtr;
	}
}

/**************************************************************
*   Entry:  a pointer to the ellement the user wishes to add
*
*    Exit:   none
*
* Purpose:  allows the user to add nodes to the end of the linkedList
**************************************************************/
template<class type> void LinkedList<type>::Append(type* theElement)
{
	Node<type>* tempPtr;
	tempPtr = new Node<type>();

	(*tempPtr).setData(*theElement);

	if (m_head == NULL)
	{
		(*tempPtr).setNext(NULL);
		(*tempPtr).setPrev(NULL);

		m_head = tempPtr;
		m_tail = tempPtr;
	}
	else
	{
		(*tempPtr).setNext(NULL);
		(*tempPtr).setPrev(m_tail);

		(*m_tail).setNext(tempPtr);

		m_tail = tempPtr;
	}
}

/**************************************************************
*   Entry:  none
*
*    Exit:   none
*
* Purpose:  Allows the user to get rid of everything inside of
the LinkedList
**************************************************************/
template<class type> void LinkedList<type>::Purge()
{
	Node<type> *tempPtr = NULL;
	Node<type> *delPtr = NULL;

	while ((*m_head).getNext() != NULL)
	{
		delPtr = m_head;
		m_head = (*delPtr).getNext();
		delete delPtr;
	}

	delete m_head;
	m_head = NULL;
	m_tail = NULL;
}

/**************************************************************
*   Entry:  the ellement
*
*    Exit:   Node<type>&
*
* Purpose:  Allows the user to pop an ellement from the LinkedList out
of the linkedList and returns that node
**************************************************************/
template<class type> Node<type>& LinkedList<type>::Extract(type theElement)
{
	Node<type>* comparePtr;

	comparePtr = m_head;

	//searching for the ellemnt
	while ((*comparePtr).getData() != theElement && (*comparePtr).getNext() != NULL)
	{
		comparePtr = (*comparePtr).getNext();
	}
	//test if we got to the end and the value wasn't in there
	if ((*comparePtr).getData() != theElement)
	{
		(*comparePtr).setData(NULL);
		(*comparePtr).setNext(NULL);
		(*comparePtr).setPrev(NULL);
	}
	//this means we found the data we are looking ofr
	else
	{
		if (comparePtr == m_tail)
		{
			m_tail = (*m_tail).getPrev();
			return *comparePtr;
		}
		if (comparePtr == m_head)
		{
			m_head = (*m_head).getNext();
			return *comparePtr;
		}
		(*((*comparePtr).getPrev())).setNext((*comparePtr).getNext());

		(*((*comparePtr).getNext())).setPrev((*comparePtr).getPrev());
		//set the previous' next to this one next, and the next's previous to this one's previous
	}
	return *comparePtr;
}

/**************************************************************
*   Entry:  the value where the ellement will be placed after, a pointer to the data you want to insert
*
*    Exit:   none
*
* Purpose:  allows the user to insert an ellement after a given value in the linkedLIst
**************************************************************/
template<class type> void LinkedList<type>::InsertAfter(type theElement, type* theOrigin)
{
	//what is going to be the new added node
	Node<type>* tempPtr;
	tempPtr = new Node<type>();
	(*tempPtr).setData(*theOrigin);

	Node<type>* comparePtr;

	comparePtr = m_head;

	//searching for the ellemnt
	while ((*comparePtr).getData() != theElement && (*comparePtr).getNext() != NULL)
	{
		comparePtr = (*comparePtr).getNext();
	}

	if ((*comparePtr).getData() != theElement)
	{
	}
	else
	{
		//sets tempptr's next to comparePtr's next
		(*tempPtr).setNext((*comparePtr).getNext());
		//does the same for the previous
		(*tempPtr).setPrev(comparePtr);

		//get the nodes sureounding the one we insterted to point to it
		if ((*comparePtr).getNext() == NULL)
		{
			(*comparePtr).setNext(tempPtr);
			m_tail = tempPtr;
		}
		else
		{
			(*(*comparePtr).getNext()).setPrev(tempPtr);
			(*comparePtr).setNext(tempPtr);
		}
	}
}

/**************************************************************
*   Entry:  the value where the ellement will be placed before, a pointer to the data you want to insert
*
*    Exit:   none
*
* Purpose:  allows the user to insert an ellement before a given value in the linkedList
**************************************************************/
template<class type> void LinkedList<type>::InsertBefore(type theElement, type* theOrigin)
{
	//what is going to be the new added node
	Node<type>* tempPtr;
	tempPtr = new Node<type>();
	(*tempPtr).setData(*theOrigin);

	Node<type>* comparePtr;

	comparePtr = m_head;

	//searching for the ellemnt
	while ((*comparePtr).getData() != theElement && (*comparePtr).getNext() != NULL)
	{
		comparePtr = (*comparePtr).getNext();
	}

	if ((*comparePtr).getData() != theElement)
	{
	}
	else
	{
		//sets tempptr's next to comparePtr's next
		(*tempPtr).setNext(comparePtr);
		//does the same for the previous
		(*tempPtr).setPrev((*comparePtr).getPrev());

		if ((*comparePtr).getPrev() == NULL)
		{
			(*comparePtr).setPrev(tempPtr);
			m_head = tempPtr;
		}
		else
		{
			//get the nodes sureounding the one we insterted to point to it
			(*(*tempPtr).getPrev()).setNext(tempPtr);
			(*comparePtr).setPrev(tempPtr);
		}
	}
}

/**************************************************************
*   Entry:  none
*
*    Exit:   an Iterator of type <type>
*
* Purpose:  Allows the user to create an iterator that is at the
begining of the linked list
**************************************************************/
template<class type> Iterator<type> LinkedList<type>::Begin()
{
	Iterator<type> temp(m_head);
	return temp;
}

/**************************************************************
*   Entry:  none
*
*    Exit:   an Iterator of type <type>
*
* Purpose:  Allows the user to create an iterator that is at the
end of the linked list
**************************************************************/
template<class type> Iterator<type> LinkedList<type>::End()
{
	Iterator<type> temp(m_tail);
	return temp;
}

/**************************************************************
*   Entry:  the start Value of the new LinkLIst, the end value of the new LinkLIst
*
*    Exit:  the new LInkedLIst
*
* Purpose: Allows the user to create a sub linkList that starts at the value
specified, and end at the secound value specified
**************************************************************/
template<class type> LinkedList<type> LinkedList<type>::subList(type startVal, type endVal)
{
	LinkedList<type> newLinkList;
	type* ellement;

	ellement = &startVal;

	//searches for te first value
	Node<type>* comparePtr;
	comparePtr = m_head;
	while ((*comparePtr).getData() != startVal && (*comparePtr).getNext() != NULL)
	{
		comparePtr = (*comparePtr).getNext();
	}

	*ellement = (*comparePtr).getData();
	newLinkList.Append(ellement);

	while ((*comparePtr).getData() != endVal && (*comparePtr).getNext() != NULL)
	{
		*ellement = (*comparePtr).getData();
		newLinkList.Append(ellement);

		comparePtr = (*comparePtr).getNext();
	}
	*ellement = (*comparePtr).getData();
	newLinkList.Append(ellement);

	comparePtr = (*comparePtr).getNext();

	return newLinkList;
}
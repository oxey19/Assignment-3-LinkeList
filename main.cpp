
/***********************************************************
* Author:				Raymond Berry
* Date Created:			10/16/2015
* Last Modification Date:	10/16/2015
* Lab Number:			CST 211 Assignment 3
* Filename:				Node.h
*/

/*QUESTION TIME:
1) With an index, you can speccify exactly where you want to be in the data. With an iteratter you have to go through every ellement by incrementing or decrementing.

2) An Iterater knows it is at the end if waht it is pointing at is the tail. Or if what the iterater is pointing at points to a NULL value.

3) template<class type> LinkedList<type> LinkedList<type>::subList(type startVal, type endVal)
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
	//Iterator<type> theIterator(comparePtr);

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


4)The big o notation of this is just o(n)
*/

//#include "Node.h"
#include "LinkedList.h"
//#include "Iterator.h"
#include <iostream>

void testPreprend()
{
	LinkedList<int> my;
	int myVariable = 0;

	int* ellement;
	ellement = &myVariable;

	my.Prepend(ellement);

	*ellement = 1;

	my.Prepend(ellement);

	*ellement = 2;

	my.Prepend(ellement);
}

void testAppend()
{
	LinkedList<int> my;
	int myVariable = 0;

	int* ellement;
	ellement = &myVariable;

	my.Append(ellement);

	*ellement = 1;

	my.Append(ellement);

	*ellement = 2;

	my.Append(ellement);
}

void testPurge()
{
	LinkedList<int> my;
	int myVariable = 0;

	int* ellement;
	ellement = &myVariable;

	my.Append(ellement);

	*ellement = 1;

	my.Append(ellement);

	*ellement = 2;

	my.Append(ellement);

	cout << my.isEmpty();

	my.Purge();

	cout << my.isEmpty();

}

void testExtract()
{
	
	LinkedList<int> my;
	int myVariable = 0;

	int* ellement;
	ellement = &myVariable;

	my.Append(ellement);

	*ellement = 1;

	my.Append(ellement);

	*ellement = 2;

	my.Append(ellement);

	my.Extract(1);

	my.Extract(0);

}

void testInsertAfter()
{
	LinkedList<int> my;
	int myVariable = 0;

	int* ellement;
	ellement = &myVariable;

	my.Append(ellement);

	*ellement = 1;

	my.Append(ellement);

	*ellement = 2;

	my.Append(ellement);

	*ellement = 25;

	my.InsertAfter(2, ellement);



}

void testInsertBefore()
{
	LinkedList<int> my;
	int myVariable = 0;

	int* ellement;
	ellement = &myVariable;

	my.Append(ellement);

	*ellement = 1;

	my.Append(ellement);

	*ellement = 2;

	my.Append(ellement);

	*ellement = 25;

	my.InsertBefore(0, ellement);



}


void testBegin()
{
	Iterator<int> myIterator;

	LinkedList<int> my;
	int myVariable = 0;

	int* ellement;
	ellement = &myVariable;

	my.Append(ellement);

	*ellement = 1;

	my.Append(ellement);

	*ellement = 2;

	my.Append(ellement);

	*ellement = 25;

	myIterator = my.Begin();
	
}

void testEnd()
{
	Iterator<int> myIterator;

	LinkedList<int> my;
	int myVariable = 0;

	int* ellement;
	ellement = &myVariable;

	my.Append(ellement);

	*ellement = 1;

	my.Append(ellement);

	*ellement = 2;

	my.Append(ellement);

	*ellement = 25;

	myIterator = my.End();

}

void testSubList()
{
	LinkedList<int> mysub;
	LinkedList<int> my;
	int myVariable = 0;

	int* ellement;
	ellement = &myVariable;

	my.Append(ellement);

	*ellement = 1;

	my.Append(ellement);

	*ellement = 2;

	my.Append(ellement);

	*ellement = 3;

	my.Append(ellement);

	*ellement = 4;

	my.Append(ellement);

	mysub = my.subList(1, 3);


}

void testIncramentandDecrementPostandPref()
{
	Iterator<int> myIterator;

	LinkedList<int> my;
	int myVariable = 0;

	int* ellement;
	ellement = &myVariable;

	my.Append(ellement);

	*ellement = 1;

	my.Append(ellement);

	*ellement = 2;

	my.Append(ellement);

	*ellement = 25;

	myIterator = my.Begin();

	myIterator++;

	++myIterator;

	myIterator--;

	--myIterator;
}

int main()
{
	testPreprend();
	testAppend();
	testPurge();
	testExtract();
	testInsertAfter();
	testInsertBefore();
	testBegin();
	testEnd();
	testIncramentandDecrementPostandPref();
	testSubList();
	return 0;
}
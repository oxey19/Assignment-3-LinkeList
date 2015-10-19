
/***********************************************************
* Author:				Raymond Berry
* Date Created:			10/16/2015
* Last Modification Date:	10/18/2015
* Lab Number:			CST 211 Assignment 3
* Filename:				Node.h
*/


/************************************************************************
* Class: Node
*
* Constructors:
*	Node()
*		Allows the user to creates nodes

	Node(Node &original)
		allows the user to copy nodes

*
* Mutators:
*	void setData(type newData);
		Allows the user to change the data in the Node

	void setNext(Node* next);
		allows the user to chage what the next node is

	void setPrev(Node* prev);
		allows the user to change what the previous node is
		
*
* Methods:
*	Node &operator=(const Node &rhs);
		allows the user to assign nodes to other nodes

	~Node();
		allows the node to be deconstructed

	type getData();
		returns the data in the node

	Node* getNext();
		returns the pointer to the next node in the linked list

	Node* getPrev();
		returns the pointer to the previous node in the linked list
*************************************************************************/


template <class type>
class Node
{
public:

	Node();

	Node(Node &original);

	Node &operator=(const Node &rhs);

	~Node();

	//Accessers
	type getData();
	Node* getNext();
	Node* getPrev();

	//mutators
	void setData(type newData);
	void setNext(Node* next);
	void setPrev(Node* prev);
private:
	type m_data;
	Node* m_next;
	Node* m_prev;
};

#include "Node.inc"
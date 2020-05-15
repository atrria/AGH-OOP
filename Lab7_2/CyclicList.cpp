#include "CyclicList.h"

CyclicList& CyclicList::operator<<(Node* node)
{
	if (counter)
	{
		_node_end->next = node;
		_node_end = node;
		node->next = _node_start;
	}
	else
	{
		_node_start = _node_end = node->next = node;
	}
	++counter;
	return *this;
}

CyclicList::~CyclicList()
{
	_node_end->next = nullptr;
	while (_node_start)
	{
		Node* temp = _node_start->next;
		delete _node_start;
		_node_start = temp;
	}
}

CyclicList::CyclicList(const CyclicList& source)
	: _node_start(nullptr), _node_end(nullptr), counter(0)
{
	Node* current = source._node_start;
	for(int i=0; i<source.counter; i++)
	{
		*this << current->clone();
		current=current->next;
	}
}

int CyclicList::count() const
{
	return counter;
}

Node* CyclicList::operator()() const
{
	return _node_start;
}

CyclicList& CyclicList::rotate()
{
	_node_start = _node_start->next;
	_node_end = _node_end->next;
	return *this;
}

CyclicList& CyclicList::rotate_back()
{
	for (int i = 0; i < counter-1; i++)
	{
		_node_start = _node_start->next;
		_node_end = _node_end->next;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const CyclicList& cl)
{
	Node* current = cl._node_start;
	for (int i = 0; i < cl.counter; i++)
	{
		os << current->toString() << " ";
		current = current->next;
	}
	return os;
}

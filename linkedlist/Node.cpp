

#include "Node.h"
	
Node::Node() 
{
    data = strType();
    next = NULL;
    previous = NULL;
}

Node::Node(const strType& initData = strType()) 
{
    data = initData;
    next = NULL;
    previous = NULL;
}

Node::Node(const strType& initData, Node* initialNext, Node* initialPrevious) 
{
    data = initData;
    next = initialNext;
    previous = initialPrevious;
}

Node::~Node() {
    next = NULL;
    previous = NULL;
}

void Node::setData(const strType& val) 
{
    data = val;
}

void Node::setPrevious(Node* previousNode) 
{
    previous = previousNode;
}

void Node::setNext(Node* nextNode) 
{
    next = nextNode;
}

Node::strType Node::getData() const 
{
    return data;
}

Node* Node::getNext() const 
{
    return next;
}

Node* Node::getNext() 
{
    return next;
}

Node* Node::getPrevious() const 
{
    return previous;
}

Node* Node::getPrevious() 
{
    return previous; 
}
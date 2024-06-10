

#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{
    headNode = NULL;
    tailNode = NULL;
    currentNode = NULL;
    listSize = 0;
}

LinkedList::LinkedList(const strType& data)
{
    headNode = new Node(data);
    tailNode = headNode;
    currentNode = tailNode;
    listSize = 1;
}

LinkedList::~LinkedList()
{
    while(headNode != NULL)
    {
        Node* deleteNode = headNode;
        if(headNode == tailNode)
        {
            headNode = NULL; // Setting head to NULL.
            tailNode = NULL; // Setting tail to NULL.
            delete deleteNode; // delete the last Node.
        }
        else
        {
            headNode = headNode->getNext(); // Head node is moved to the next node in list.
            headNode->setPrevious(NULL);	// previous pointer is set to NULL.
            deleteNode->setNext(NULL);		// sets next pointer to NULL.
            delete deleteNode;				// deletes node.
            currentNode = NULL;				// currentNode = NULL;
        }
    }
    listSize = 0;
}


void LinkedList::add(const strType inputWord)
{
    std::istringstream inputStream(inputWord);
    while(inputStream)
    {
        strType str;
        inputStream >> str;
        addToTail(str);
    }

}

void LinkedList::addToHead(const strType& data)
{
    if(headNode == NULL)
    {
        headNode = new Node(data);
        tailNode = headNode;
        currentNode = headNode;
        listSize = 1;
    }
    else
    {
        Node* tempNode = new Node(data);
        headNode->setPrevious(tempNode);
        tempNode->setNext(headNode);
        headNode = tempNode;
        tempNode = NULL;
        listSize++;
    }
}

void LinkedList::addToTail(const strType& data)
{
    if(headNode == NULL) // If head is NULL.
    {
        headNode = new Node(data); // Head pointer is set to new node.
        tailNode = headNode;		// Tail pointer set to new node.
        currentNode = headNode;		// Current pointer is set to new node. 
        listSize = 1;				// List size +1.
    }
    else
    {
        Node* tempNode = new Node(data); // Creates a temporary node with data.
        tailNode->setNext(tempNode);		// Tail node -> next on the temp node.
        tempNode->setPrevious(tailNode);	// sets previous of temp node. 
        tailNode = tempNode; 				// Tail pointer to the new tail of the list.
        tempNode = NULL;
        listSize++;					// Temp is set to NULL.

    }
}

void LinkedList::remove(const strType inputWord)
{
    std::istringstream inputStream(inputWord); // Puts into a stringStream.
    std::vector<string> matchInput; // Declares a vector of valueType. 

    while(inputStream)
    {

        strType strWord;
        inputStream >> strWord;
        matchInput.push_back(strWord);
    }

    // Starting at head, iterate through nodes until NULL
    for(moveCurrentToHead(); currentNode != NULL; moveCurrent()) {

        if (currentNode->getData() == matchInput.at(0)) {
            if (currentNode == headNode) {
                removeFromHead();
            }
            else if (currentNode == tailNode){
                removeFromTail();
            }
            else {
                removeFromCurrent();
            }
        }
    }
}


void LinkedList::removeFromHead()
{
    if(listSize == 0)
    {
        return;
    }

    else if(listSize == 1)
    {
        delete headNode;
        headNode = NULL;
        tailNode = NULL;
        currentNode = NULL;
        listSize--;
        return;
    }

    else
    {
        currentNode = headNode;
        headNode = headNode->getNext();
        delete currentNode;
        if(headNode != NULL)
            headNode->setPrevious(NULL);
        currentNode = headNode;
    }
}

void LinkedList::removeFromTail()
{
    if(listSize == 0)
    {
        return;
    }

    else if(listSize == 1)
    {
        delete headNode;
        headNode = NULL;
        tailNode = NULL;
        currentNode = NULL;
        listSize--;
        return;
    }

    else
    {
        tailNode = tailNode->getPrevious();
        tailNode->setNext(NULL);
        delete tailNode->getNext();
        listSize--;
        currentNode = tailNode;
    }
}

void LinkedList::removeFromCurrent()
{
    Node* tempNode = currentNode->getNext();
    currentNode->getPrevious()->setNext(currentNode->getNext());
    currentNode->getNext()->setPrevious(currentNode->getPrevious());
    delete currentNode;
    currentNode = tempNode;
    tempNode = NULL;
    listSize--;
}

void LinkedList::moveCurrent()
{
    currentNode = currentNode->getNext();
}


void LinkedList::moveCurrentToHead()
{
    currentNode = headNode;
}


Node* LinkedList::getCurrentNode()
{
    return currentNode;
}

int LinkedList::count(const strType& data)
{
    int count = 0;
    moveCurrentToHead();
    while(currentNode !=NULL)
    {
        if(data == currentNode->getData())
        {
            count++;
        }
        moveCurrent();
    }
    return count;
}


void LinkedList::sort()
{
    Node *current, *bcurrent;
    strType temp;

    for (int i = 0; i < listSize-1; i++) {
        current = headNode;
        bcurrent = headNode->getNext();
        
        for (int j = 0; j < (listSize-i)-1; j++) {
            if (current->getData() > bcurrent->getData()) {
                temp = current->getData();
                current->setData(current->getNext()->getData());
                bcurrent->setData(temp);

            }
        current = bcurrent;
        bcurrent = bcurrent->getNext();
        } 
    }

}


LinkedList& LinkedList::operator += (LinkedList& inputList)
{
    inputList.moveCurrentToHead();
    while(inputList.getCurrentNode() != NULL)
    {
        this->addToTail(inputList.getCurrentNode()->getData());
        inputList.moveCurrent();
    }
    return *this;
}


std::ostream& operator << (std::ostream& output, LinkedList& inputList)
{
    inputList.moveCurrentToHead();
    ;
    while(inputList.getCurrentNode() != NULL)
    {
        output << inputList.getCurrentNode()->getData() << " ";
        inputList.moveCurrent();
    }
    return output;
}
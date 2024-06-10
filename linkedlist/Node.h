

#ifndef hNode
#define hNode

#include <iostream>
#include <cstdlib>


class Node
{

	public:

        typedef std::string strType;

        // Constructors:
		Node(); // Default.
		Node(const strType& initialString); // One input.
		Node(const strType& initialString, Node* initialNext, Node* initialPrevious); // Multiple inputs.

        // Destructor:
		~Node();

        // Member Functions:

		void setData(const strType& tempData);
			// Pre-condition: Data to input in node.
		    // Post-condition: Data set in the node.

		void setPrevious(Node* previousNode);
			// Pre-condition: Pointing previous Node or NULL.
			// Post-condition: Pointing desired Node.

		void setNext(Node* nextNode);
			// Pre-condition: Pointing next Node or NULL.
			// Post-condition: Pointing desired Node.

		strType getData() const;
			// Pre-condition: 'tempData' should have a string value.
			// Post-condition: Return value of 'tempData'.

		Node* getNext() const;
		Node* getNext();
			// Pre-condition: Pointing a Node or NULL.
			// Post-condition: Return value of next node.

		Node* getPrevious() const;
		Node* getPrevious();
			// Pre-condition: Pointing to previous node or NULL.
			// Post-condition: Return value of previous node.
	
	private:

		Node *next; // Points to next node
		Node *previous; // Points to previous node
		strType data; // Data to be stored

};


#endif
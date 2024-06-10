
#ifndef hLinkedList
#define hLinkedList

#include <sstream>
#include <vector>
#include "Node.h"


class LinkedList
{
	public:
		
		typedef std::string strType;

        // Constructors.
		LinkedList();   //Default.	
		LinkedList(const strType& data);   //Single strType input. 
		
        // Destructor.
		~LinkedList();
		
        // Member Functions
	
		void add(const strType inputWord);
			// Pre-condition: strType input.
			// Post-condition: Tokenize the strType and add to list.
			
		void addToHead(const strType& data);
			// Pre-condition: Pre-existing Linked-list.
			// Post-condition: Add new Node (Word) to Head-node.
		
		void addToTail(const strType& data);
			// Pre-condition: Pre-existing Linked-List.
			// Post-condition: Add new Node (Word) to Tail-node.
		
		
		void remove(const strType inputWord); 
			// Pre-condition: A continuous strType of words.
			// Post-condition: Removes Nodes that match the continuous strType data. 
			
		void removeFromHead();
			// Pre-condition: Existing Linked-list.
			// Post-condition: Head-node is removed.
		
		void removeFromTail();
			// Pre-condition: Existing Linked-list.
			// Post-condition: Tail-node is removed.
		
		void removeFromCurrent();
			// Pre-condition: Existing Linked-list, with more than head and tail-node
			// Post-condition: Removes the node from the list.
			
		void moveCurrent();
			// Pre-condition: Existing Linked-List, current-node is not NULL.
			// Post-condition: Iterate throught the list.
		
		void moveCurrentToHead();
			// Pre-condition: Existing Linked-List.
			// Post-condition: CurrentNode is placed at top of the LinkedList.
		
		Node* getCurrentNode();
			// Pre-condition: Existing Linked-List.
			// Post-condition: Return currentNode.
		
		int count(const strType& data);
			// Pre-condition: Existing Linked-List and contains data.
			// Post-condition: If the input matches LinkedList data then it is counted.
        
        void sort();
            // Pre-condition: Existing Linked-List.
            // Post-condition: Sort the Linked-list alphabetically.
			
		LinkedList& operator += (LinkedList& inputList);
			// Pre-condition: None.
			// Post-condition: Concatenate two Linked-lists.


	private:
		Node* currentNode; // Current pointer.
		Node* headNode;	   // Head pointer.
		Node* tailNode;	   // tail pointer.
		int listSize;	  // counts list.

};

	std::ostream& operator << (std::ostream& out, LinkedList& inputList);
			// Pre-condition: None.
			// Post-condition: Overloads the cout operator. 

#endif
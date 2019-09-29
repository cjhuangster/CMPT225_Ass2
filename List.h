/*
 * List.h
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - (For you to fill: Add a statement about the another characteristic of this List.)
 *
 * Author: (For you to fill)
 * Date: (For you to fill)
 */

#pragma once

// You can add #include statements if you wish.
//#includes for List.h
#include <string>
#include "Patient.h"

using namespace std;


class List  {

private:
/* 
 * To be completed.
 */

	int MAXELEMENT=0;					//Total Max Element
	int maxElement[10];					// MAX_ELEMENTS
	long int capacity=10000000000;      // Actual maximum capacity of element array   
	Patient PList [10][1000000000];     // Data structure of element with capacity of MAX_ELEMENTS
	int elementCount[10]={0};               // Current element count in element array
	int ELEMENTCOUNT=0;					//Total Element Count;	

public:

/* 
 * You can add more methods to this interface, 
 * but you cannot remove the methods below 
 * nor can you change their prototype.
 * 
 */

	// Default constructor
	List();

	// Description: Returns the total element count currently stored in List.
	int getElementCount() const;

	// Description: Insert an element.
	// Precondition: newElement must not already be in data collection.  
	// Postcondition: newElement inserted and elementCount has been incremented.   
	bool insert(const Patient& newElement);

	// Description: Remove an element. 
	// Postcondition: toBeRemoved is removed and elementCount has been decremented.	
	bool remove( const Patient& toBeRemoved );
	
	// Description: Remove all elements.
	void removeAll();
   
	// Description: Search for target element.
	//              Returns a pointer to the element if found,
	//              otherwise, returns NULL.
	Patient* search(const Patient& target);
	
	// Description: Prints all elements stored in List by descending order of care card numbers
	void printList();

}; // end List.h
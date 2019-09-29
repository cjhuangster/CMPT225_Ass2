/*
 * List.cpp
 * 
 * Class Description: Models the system that dialogues and manipulates patient information.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified. 
 *
 * Author: (Cheng Jie Huang)
 * Date: (Sep 16, 2019)
 */


//#includes for List.cpp
#include <string>
#include "Patient.cpp"
#include "List.h"
#include <iostream>
#include <iostream> 
#include <sstream> 
using namespace std; 

int main(){
  return 0;
}

// Default constructor
List::List(){

}
	// Description: Returns the total element count currently stored in List.
int List::getElementCount() const{
  return ELEMENTCOUNT;
}


	// Description: Insert an element.
	// Precondition: newElement must not already be in data collection.  
	// Postcondition: newElement inserted and elementCount has been incremented.   
bool List::insert(const Patient& newElement){
  bool inserted=false;
  int firstNumber=(stoi(newElement.getCareCard())/100000000);
  int newCareCard=(stoi(newElement.getCareCard()));
  int toPlace=0;
  //This statement checks if the given carecard number is 10 digits long
  if (newElement.getCareCard().size()!=10){
    cout<<"Error: The given patient carecard number is not 10 digits!"<<endl;
  }
  else {
    //This loop checks to see if newElement's carecard number is equivalent to any within the existing system
    for (int i=0;i<elementCount[firstNumber];i++){
    int currentCareCard=stoi(PList[firstNumber][i].getCareCard());
    if (currentCareCard==newCareCard){
      cout<<"Error: The given patient carecard number is already in the system!"<<endl;
    }
    else if (newCareCard>currentCareCard){
      toPlace=i;
      //break out of loop by maxing out i counter
      i=elementCount[firstNumber];
      //increase both counters to account for added element
      elementCount[firstNumber]++;  ELEMENTCOUNT++;
    }
  }
  //This statement checks if the location to be placed is occupied or not
  if (PList[firstNumber][toPlace].getCareCard()!="0000000000"){
    //if the location to be placed is not occupied, shift every element within the current elementCount right by 1
    for (int j=elementCount[firstNumber];j>toPlace;j++){
    PList[firstNumber][j].setCareCard(PList[firstNumber][j-1].getCareCard());
    PList[firstNumber][j].setAddress(PList[firstNumber][j-1].getAddress());
    PList[firstNumber][j].setName(PList[firstNumber][j-1].getName());
    PList[firstNumber][j].setEmail(PList[firstNumber][j-1].getEmail());
    PList[firstNumber][j].setPhone(PList[firstNumber][j-1].getPhone());
    }
  }
  //Insert the newElement at toPlace
  PList[firstNumber][toPlace].setCareCard(newElement.getCareCard());
  PList[firstNumber][toPlace].setAddress(newElement.getAddress());
  PList[firstNumber][toPlace].setName(newElement.getName());
  PList[firstNumber][toPlace].setEmail(newElement.getEmail());
  PList[firstNumber][toPlace].setPhone(newElement.getPhone());
  
  //checks for equivalence of toPlace with the given newElement
  if (PList[firstNumber][toPlace].getName()==newElement.getName()){
    inserted=true;
  }
  return inserted;

  }
}

	// Description: Remove an element. 
	// Postcondition: toBeRemoved is removed and elementCount has been decremented.	
bool List::remove( const Patient& toBeRemoved ){
  bool removed=false;
  int firstNumber=(stoi(toBeRemoved.getCareCard())/100000000);
  //Check for equivalence between elements of the existing list with toBeRemoved
  for (int i=0;i<elementCount[firstNumber];i++){
    if (PList[firstNumber][i].getName()==toBeRemoved.getName()){
      //Appropriately decrementing both elementcounts.
      elementCount[firstNumber--]; ELEMENTCOUNT--;
      //If toBeRemoved is matched with an element within the current list, every element to the right will shift left by 1.
      for (int j=i; j<=(elementCount[firstNumber]); j++){
        PList[firstNumber][j].setCareCard(PList[firstNumber][j+1].getCareCard());
        PList[firstNumber][j].setAddress(PList[firstNumber][j+1].getAddress());
        PList[firstNumber][j].setName(PList[firstNumber][j+1].getName());
        PList[firstNumber][j].setEmail(PList[firstNumber][j+1].getEmail());
        PList[firstNumber][j].setPhone(PList[firstNumber][j+1].getPhone());
      }
    }
    removed=true;
  }
  return removed;
}

// Description: Remove all elements.
// Postcondition: all elements removed and elementCount resets to 0
void List::removeAll(){
 for (int i=0; i<10;i++){
   elementCount[i]=0;
 }
 ELEMENTCOUNT=0;
}

// Description: Search for target element.
	//              Returns a pointer to the element if found,
	//              otherwise, returns NULL.
Patient* List::search(const Patient& target){
  int firstNumber=(stoi(target.getCareCard())/100000000);
  Patient *ptr;
  ptr=NULL;
  for (int i=0; i < elementCount[firstNumber]; i++)
     {
       //If target is equivalent to any element within the current list, return the ptr to that element
       if (PList[firstNumber][i].getName()==target.getName()){
      ptr=&PList[firstNumber][i];
      }
     }
  return ptr;
}

// Description: Prints all elements stored in List by descending order of care card numbers
void List::printList(){
  //Iterates through all of the current list and prints out every element.
 for (int i = 0; i < 10; i++) {
  for (int j = 0; j < elementCount[i]; j++){
    cout<<PList[i][j];
  }
 }
}

//end of List.cpp

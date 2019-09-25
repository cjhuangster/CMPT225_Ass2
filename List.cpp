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

//Description: sorts the existing list in descending order.
void List::sortDescending (const int firstNumber)  {
  int toCompare;
  long int largest=10000000000;
  int large=0;
  int order[elementCount[firstNumber]];
  for (int i=0;i<elementCount[firstNumber];i++){
    large=0;
    for (int j=0;j<elementCount[firstNumber];j++){
      toCompare=stoi(PList[firstNumber][j].Patient::getCareCard());
      if (toCompare>large&&toCompare<largest){
        large=toCompare;
        order[i]=j;
      }  
    }
    largest=large;  
  }
  Patient temp [elementCount[firstNumber]];
  for (int k = 0; k < elementCount[firstNumber]; k++)
  {
    temp[k]=PList[firstNumber][order[k]];
  }
  
  for (int l = 0; l < elementCount[firstNumber]; l++)
  {
    //am I able to directly input the elements into their place?
    PList[firstNumber][l]=temp[l];
  }
}

	// Description: Insert an element.
	// Precondition: newElement must not already be in data collection.  
	// Postcondition: newElement inserted and elementCount has been incremented.   
bool List::insert(const Patient& newElement){
  bool inserted;
  int firstNumber=(stoi(newElement.getCareCard())/100000000);

  //how do I add in a new patient careCard as a part of the new profile?
  PList[firstNumber][elementCount[firstNumber]]=Patient(newElement.getCareCard());
  PList[firstNumber][elementCount[firstNumber]].Patient::setCareCard(newElement.Patient::getCareCard());
  PList[firstNumber][elementCount[firstNumber]].Patient::setAddress(newElement.Patient::getAddress());
  PList[firstNumber][elementCount[firstNumber]].Patient::setName(newElement.Patient::getName());
  PList[firstNumber][elementCount[firstNumber]].Patient::setEmail(newElement.Patient::getEmail());
  PList[firstNumber][elementCount[firstNumber]].Patient::setPhone(newElement.Patient::getPhone());
  if (PList[firstNumber][elementCount[firstNumber]].Patient::getName()==newElement.Patient::getName()){
    inserted=true;
  }
  else {
    inserted=false;
  }
  sortDescending(firstNumber);
  elementCount[firstNumber]++;  ELEMENTCOUNT++;
  return inserted;
}

	// Description: Remove an element. 
	// Postcondition: toBeRemoved is removed and elementCount has been decremented.	
bool List::remove( const Patient& toBeRemoved ){
  bool removed;
  int firstNumber=(stoi(toBeRemoved.getCareCard())/100000000);

  for (int i=0;i<elementCount[firstNumber];i++){
    if (PList[firstNumber][i].getName()==toBeRemoved.getName()){
      for (int j = i; j < (elementCount[firstNumber]-1); j++){
        PList[firstNumber][j]=PList[firstNumber][j+1];//do we have to use insert() instead as PList cannot be openly accessed or can PList be modified?
        //PList[j+1]=NULL;
      }
    }
  }
  //should we make the last elementCount NULL?
  elementCount[firstNumber--]; ELEMENTCOUNT--;

  sortDescending(firstNumber);
  for (int i=0;i<elementCount[firstNumber];i++){
    if (PList[firstNumber][i].getName()==toBeRemoved.getName()){
      removed=false;
      i=elementCount[firstNumber];
    }
    else {
      removed=true;
    }
    return removed;
  }
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
   Patient *ptr;
   ptr=NULL;
   for (int i=0;i<10;i++){
     for (int j=0; j < elementCount[i]; j++)
     {
       if (PList[i][j].getName()==target.getName()){
      ptr=&PList[i][j];
      }
     }
    }
    return ptr;
}

// Description: Prints all elements stored in List by descending order of care card numbers
void List::printList(){
 for (int i = 0; i < 10; i++) {
  for (int j = 0; j < elementCount[i]; j++)
  {
    cout<<PList[i][j];
  }
 }
}

/*
 * Patient.cpp
 * 
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified. 
 *
 * Author: (Cheng Jie Huang)
 * Date: (Sep 16, 2019)
 */

// You can add #include statements if you wish.
//#includes for Patient.cpp
#include <iostream>
#include <string>
#include "Patient.h"

//Test code
// int main(){
// Patient *Michael = new Patient("6969696969");
// Michael->setName("Dumb dumb");
// cout<<Michael->getName()<<endl<<Michael->getCareCard()<<endl;
// }

// Default Constructor
// Description: Create a patient with a care card number of "0000000000". 
// Postcondition: All data members set to "To be entered", 
//                except the care card number which is set to "0000000000".       
Patient::Patient() {
careCard="0000000000";
phone="To be entered.";
name="To be entered.";
email="To be entered.";
address="To be entered.";
}

// Parameterized Constructor
// Description: Create a patient with the given care card number.
// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members set to "To be entered".
Patient::Patient(string aCareCard) {
// You need to complete this method.
if (aCareCard.size()!=10){
careCard="0000000000";	
}
else{
careCard=aCareCard;	
}
phone="To be entered.";
name="To be entered.";
email="To be entered.";
address="To be entered.";
}

// All other parameterized constructors -> You need to implement these methods.

// Getters and setters -> You need to implement these methods.
// Getters and setters
	// Description: Returns patient's name.
	string Patient::getName() const{
  return name;
  }

	// Description: Returns patient's address.
	string Patient::getAddress() const{
  return address;
  }

	// Description: Returns patient's phone.
	string Patient::getPhone() const{
  return phone;
  }

	// Description: Returns patient's email.
	string Patient::getEmail() const{
  return email;
  }

	// Description: Returns patient's care card.
	string Patient::getCareCard() const{
  return careCard;
  }
	
  	// Description: Sets the patient's name.
	void Patient::setName(const string aName){
  	name=aName;
  }

    // Description: Sets the patient's carecard.
	void Patient::setCareCard(const string aCareCard){
  	careCard=aCareCard;
  }
  
  // Description: Sets the patient's address.
	void Patient::setAddress(const string anAddress){
    address=anAddress;
  }
	// Description: Sets the patient's phone.
	void Patient::setPhone(const string aPhone){
    phone=aPhone;
  }

	// Description: Sets the patient's email.
	void Patient::setEmail(const string anEmail){
    email=anEmail;
  }
  
// Overloaded Operators
// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if both Patient objects have the same care card number.
bool Patient::operator == (const Patient & rhs) {
	
	// Compare both Patient objects
	return this->careCard == rhs.getCareCard();
	
} // end of operator ==

// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is > the care card 
//              number of "rhs" Patient object
bool Patient::operator > (const Patient & rhs) {
	
	// Compare both Patient objects
	return this->careCard > rhs.getCareCard();
	
} // end of operator >

// For testing purposes!
// Description: Prints the content of "this".
ostream & operator<<(ostream & os, const Patient & p) {
	
	os << p.careCard << ", Patient: " << p.name << ", "
	   << p.address << ", " << p.phone << ", " << p.email << endl;  
	     
	return os;

} // end of operator<<

// end of Patient.cpp
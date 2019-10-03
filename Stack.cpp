/* 
 * Stack.cpp
 *
 * Description: Stack data collection ADT class.
 *              Implementation of an int sequence with push/pop ...
 * Class Invariant: ... in a LIFO order
 *
 * Author: Cheng Jie Huang
 * Date: Sep 26, 2019
 */

#include <iostream>
#include <ostream>
#include "Stack.h"
using namespace std;

// Test Code
// int main(){
// 	Stack *myList=new Stack;
// 	myList->push(1);
// 	myList->push(2);
// 	myList->push(3);
// 	myList->push(4);
// 	myList->push(5);
// 	cout<<"Peek: "<<myList->peek()<<"Pop: "<<myList->pop()<<"Peek: "<<myList->peek()<<"isEmpty: "<<myList->isEmpty()<<endl
// 	<<"Peek: "<<myList->peek()<<"Pop: "<<myList->pop()<<"Peek: "<<myList->peek()<<"isEmpty: "<<myList->isEmpty()<<endl
// 	<<"Peek: "<<myList->peek()<<"Pop: "<<myList->pop()<<"Peek: "<<myList->peek()<<"isEmpty: "<<myList->isEmpty()<<endl
// 	<<"Peek: "<<myList->peek()<<"Pop: "<<myList->pop()<<"Peek: "<<myList->peek()<<"isEmpty: "<<myList->isEmpty()<<endl
// 	<<"Peek: "<<myList->peek()<<"Pop: "<<myList->pop()<<"Peek: "<<myList->peek()<<"isEmpty: "<<myList->isEmpty()<<endl
// 	<<"Peek: "<<myList->peek()<<"Pop: "<<myList->pop()<<"Peek: "<<myList->peek()<<"isEmpty: "<<myList->isEmpty()<<endl<<endl;
// 	return 0;
// }


        // Description: Constructor
        // Postcondition: Stack is empty
        Stack::Stack(){
		//initialize variables to NULL;
          head=NULL;
          tail=NULL;
        };


        // Description: Destructor 
        // Postcondition: All memory released
        Stack::~Stack(){
		//release memory associated with variables
				delete head;
				delete tail;
				}


        // Description: Insert newElement to the top of the stack. 
        void Stack::push(int newElement){
          StackNode *temp = new StackNode;
		  			//input element to current node, iterate
					temp->data = newElement;
					temp->next = NULL;

					//Check if stack is empty, if empty then the first element will become temp
					if(head==NULL){
						head=temp;
						tail=temp;
						temp=NULL;
					}

					//Else simply stack newElement as the next element.
					else{
						tail->next=temp;
						tail=temp;
						tail->next=NULL;
					}
        }


        // Description: Remove and return element at the top of the stack.
        // Precondition: Stack is not empty   
        int Stack::pop(){
					//initializing new StackNodes
						StackNode *current=new StackNode;
						StackNode *previous=new StackNode;
						StackNode *toPop=new StackNode;

					//checks if stack is empty
					if (head==NULL){
									cout<<"error: stack is empty!"<<endl;
									return 0;
					}

					//Starting from head, iterate until the next is NULL, set tail to the previous element, then dereference the current element. Repeat until the 2nd element is NULL
					else {
						current=head;
						while(current->next!=NULL){
							previous=current;
							current=current->next;
							}
						if (head==current){
							toPop=head;
							head=NULL;
						}
						else{
							toPop=current;
							tail=previous;
							tail->next=NULL;
							delete tail->next;
						}

					return toPop->data;
					}
				}


        // Description: Return the topmost element of the stack.
        // Precondition: Stack is not empty   
        int Stack::peek() const{
				//check if head is allocated memory, if yes then stack has at least one element, if not then stack is empty
				if (head==NULL){
					cout<<"error: stack is empty!"<<endl;
				return 0;
				}

				else return tail->data;       
        }


        // Description: Is stack empty? 
        bool Stack::isEmpty() const {
					//check if head is allocated memory, if yes then stack has at least one element, if not then stack is empty
					if (head==NULL)	{
						return true;
					}
					else return false;
        }


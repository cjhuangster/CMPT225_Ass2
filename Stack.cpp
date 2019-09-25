/* 
 * Stack.cpp
 *
 * Description: Stack data collection ADT class.
 *              Implementation of an int sequence with push/pop ...
 * Class Invariant: ... in a LIFO order
 *
 * Author:
 * Date:
 */

#include "Stack.h";

        // Description: Constructor
        // Postcondition: Stack is empty
        Stack::Stack(){

        };


        // Description: Destructor 
        // Postcondition: All memory released
        Stack::~Stack();


        // Description: Insert newElement to the top of the stack. 
        void Stack::push(int newElement);


        // Description: Remove and return element at the top of the stack.
        // Precondition: Stack is not empty   
        int Stack::pop();


        // Description: Return the topmost element of the stack.
        // Precondition: Stack is not empty   
        int Stack::peek() const;


        // Description: Is stack empty? 
        bool Stack::isEmpty() const;
};


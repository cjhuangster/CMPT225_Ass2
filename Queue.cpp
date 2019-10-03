/* 
 * Queue.cpp
 *
 * Description: Queue data collection ADT class.
 *              Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order
 *
 * Author:
 * Date:
 */
 
#include "Queue.h"
#include <iostream>
#include <ostream>
#include <stdio.h>
using namespace std;

int main () {
    Queue Q;
    // enqueue 1, 2, 3, 4, 5
    for (int i = 1; i <= 20; i++) {
        cout << "enqueue " << i << endl;
        Q.enqueue(i);
 
    }


    // dequeue 2x elements
    for (int i = 0; i < 5; i++) {
        int y = Q.peek();
        cout << "peek " << y << endl;
        Q.dequeue();
    }


    // enqueue 6, 7, 8, 9, 10
    for (int i = 20; i <= 40; i++) {
        cout << "enqueue " << i << endl;
        Q.enqueue(i);
    }


    // dequeue all elements
    while (!Q.isEmpty()) {
        int y = Q.peek();
        cout << "peek " << y << endl;
        Q.dequeue();
    }

    return 0;
}


// Description: Constructor
Queue::Queue()// : elementCount(0), capacity(INITIAL_SIZE), frontindex(0), backindex(0) {
{    
    for (int i=0;i<capacity;i++){
        elements[i]=0;
    }
} 


// Description: Inserts newElement at the back (O(1))
void Queue::enqueue(int newElement) {     
    //cout<<capacity<<endl<<backindex<<endl; 
    elements[backindex] = newElement;
    elementCount++;
    backindex = (backindex + 1) % capacity;

    if (elementCount>=capacity){
        resizeArray(elements,capacity,2);
        capacity*=2;
    }
} 

void Queue::resizeArray(int *&anArray, int size, float multiplier){
    int newSize=(int)size*multiplier;
    int *resized = new int [newSize];
    for (int i=0;i< elementCount;i++){
        resized[i]=anArray[(i+frontindex)%size];
    }
    delete[]anArray;
    anArray=resized;
    frontindex=0;
    backindex=elementCount;
}


// Description: Removes the frontmost element (O(1))
// Precondition: Queue not empty
void Queue::dequeue() {
    elements[frontindex]=0;
    elementCount--;
    frontindex = (frontindex+1) % capacity;
    if (elementCount<(capacity/4)&&((capacity/2)>INITIAL_SIZE)){
        resizeArray(elements, capacity, 0.5);
        capacity/=2;
    }
}


// Description: Returns a copy of the frontmost element (O(1))
// Precondition: Queue not empty
int Queue::peek() const {
    return elements[frontindex];
} 


// Description: Returns true if and only if queue empty (O(1))
bool Queue::isEmpty() const {
    return elementCount == 0;
} 

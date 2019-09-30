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
using namespace std;

int main () {
    Queue Q;

    // enqueue 1, 2, 3, 4, 5
    for (int i = 1; i <= 5; i++) {
        cout << "enqueue " << i << endl;
        Q.enqueue(i);
 
    }


    // dequeue 2x elements
    for (int i = 0; i < 2; i++) {
        int y = Q.peek();
        cout << "peek " << y << endl;
        Q.dequeue();
    }


    // enqueue 6, 7, 8, 9, 10
    for (int i = 6; i <= 10; i++) {
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

    //cout<<"current queue"<<endl;
    for (int i=0;i<capacity;i++){
    //    cout<<"iq: "<<i<<" "<<elements[i]<<endl;
    }

    if (elementCount>=capacity){
       biggerQueue();
    }
    // for (int i=0; i<capacity+2;i++){
    //     cout<< "i:q:"<<i<<elements[i]<<endl;
    // }
} 

void Queue::replaceElement(const int &anElement,int i){
    elements[i]=anElement;
}


void Queue::biggerQueue(){
        unsigned int newCapacity=capacity*2;
        int *temp = new int[newCapacity];
        //cout<<"temp:"<<endl;
        for (int i=0;i<elementCount;i++){
            temp[i]=elements[(i+frontindex)%capacity];
        }
        delete[]elements;
        //elements=NULL;
        capacity=capacity*2;
        int *elements=new int[capacity];
        for (int i=0;i<elementCount;i++){
            replaceElement(temp[i],i);
        }
        // cout<<"new queue:"<<endl;
        // for (int i=0;i<capacity;i++){
        //     cout<<" i:q: "<<i<<" "<<elements[i]<<endl;
        // }
        delete[]temp;
        temp=NULL;
        frontindex=0;
        backindex=elementCount;
}


void Queue::smallerQueue(){
        unsigned int newCapacity=capacity*2;
        int *temp = new int[newCapacity];
        //cout<<"temp:"<<endl;

}

// Description: Removes the frontmost element (O(1))
// Precondition: Queue not empty
void Queue::dequeue() {
    //elements[frontindex]=0;
    elementCount--;
    frontindex = (frontindex + 1) % capacity;
    //cout<<endl<<"elementCount: "<<elementCount<<endl;
    if (elementCount<(capacity/2)&&((capacity/2)>=INITIAL_SIZE)){
        cout<<"Queue needs to be smaller!"<<endl;
        smallerQueue();
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




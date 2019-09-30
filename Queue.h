/* 
 * Queue.h
 *
 * Description: Queue data collection ADT class.
 *              Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order
 *
 * Author:
 * Date:
 */
  
class Queue {
    private:
        static unsigned const INITIAL_SIZE = 6;
        int *elements=new int[INITIAL_SIZE];  

        unsigned int elementCount=0;  // number of elements in the queue
        unsigned int capacity=INITIAL_SIZE;      // number of cells in the array
        unsigned int frontindex=0;    // index the topmost element
        unsigned int backindex=0;     // index where the next element will be placed

    public:
        // Description: Constructor
        Queue();

        void replaceElement(const int &anElement,int i);
        void biggerQueue();
        void smallerQueue();

        // Description: Inserts newElement at the back (O(1))  
        void enqueue(int newElement);

 
        // Description: Removes the frontmost element (O(1))
        // Precondition: Queue not empty
        void dequeue();


        // Description: Returns a copy of the frontmost element (O(1))
        // Precondition: Queue not empty
        int peek() const;


        // Description: Returns true if and only if queue empty (O(1))
        bool isEmpty() const;
};


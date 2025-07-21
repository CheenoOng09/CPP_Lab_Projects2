#ifndef QUEUE_H
#define QUEUE_H

struct nQUEUE{
    int data;
    nQUEUE *link;
};

class Queue{
public:
    Queue(int = 10); // constructor with size initialized to 10
    ~Queue(); // destructor
    void enqueue(int); // Insert an element in the rear end of a Queue
    int dequeue(); // remove and then return the front most element in the Queue OR rescheduling waiting list based on the order
    int peek(); // return the front most element in the queue
    int getCount(); // return the number of elements stored in the Queue
    int getSize(); // return Queue Size
    bool isEmpty();
    bool isFull();
    void clearQueue(); // clear the content of queue and reset front, rear, and count
    void printQueue(); // print the content of a queue from front to rear
private:
    int Size; // the size of the queue
    int Count; // the number of elements in a queue
    nQUEUE *frontPtr;
    nQUEUE *rearPtr;
};
#endif // QUEUE_H

#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue(int s)
{
    Count = 0;
    Size = s;
    cout << "-- A Queue of " << Size << " is created." << endl;
    frontPtr = NULL;
    rearPtr = NULL;
} // constructor with size initialized to 10

Queue::~Queue()
{
    cout << "-- A Queue of size " << Size << " is destroyed." << endl;
} // destructor

void Queue::enqueue(int element) // this is where you insert an element from the back. if adding for the first time,
{
    if (frontPtr == NULL){ // Meaning there's no node that has been created yet
        nQUEUE *Node = new nQUEUE;
        //cout << "Inside Enqueue: First Time creating a node" << endl;
        Node->data = element;
        Node->link = NULL;
        frontPtr = rearPtr = Node;
        Count++;
    }
    else if (frontPtr != NULL){
        //cout << "Creating a 2nd node" << endl;
        nQUEUE *tempNode = new nQUEUE; // create a second node (Currently no link to other nodes)
        tempNode->data = element; // set the data of the new node to the data being passed
        tempNode->link = NULL; // set the new  node's link to NULL since it is currently the latest node
        rearPtr->link = tempNode; // attach the rear pointer to the temporary node pointer
        rearPtr = tempNode;
        Count++;
    }
    if (isFull()){
        cout << "-- Warning: Queue is FULL now." << endl;
    }
} // Insert an element in the rear end of a Queue

int Queue::dequeue() // remove and return front element (popping from the front)
{
    int temp = frontPtr->data;
    nQUEUE *tempPtr = frontPtr;
    frontPtr = frontPtr->link;
    Count--;
    if(isEmpty()){
        cout << "-- Warning: Queue is EMPTY now." << endl;
    }
    delete tempPtr;
    //cout << "Dequeue: Successfully deleted a node" << endl;
    return temp;
}

int Queue::peek()
{
    return frontPtr->data;
}

int Queue::getCount()// return the number of elements stored in the Queue
{
    return Count;
}

int Queue::getSize()// return Queue Size
{
    return Size;
}

bool Queue::isEmpty()// if empty, that means the program has finished processing all the waiting list
{
    if (getCount() == 0)
    {
        return true;
    }
    else
        return false;
}
bool Queue::isFull()
{
    if (getCount() == getSize())
    {
        return true;
    }
    else
        return false;
}

void Queue::clearQueue()
{
    frontPtr = NULL;
    rearPtr = NULL;
    Count = 0;
} // clear the content of queue and reset front, rear, and count

void Queue::printQueue()
{
    nQUEUE *tempPtr = frontPtr;
    while(tempPtr != NULL){
        //cout << tempPtr->data << " " << endl;
        tempPtr = tempPtr->link;
    }
    //cout << "Count " << getCount() << endl;
    //cout << "Peek of Queue Arriving/Ideal: " << peek() << endl;

} // print the content of a queue from front to rear

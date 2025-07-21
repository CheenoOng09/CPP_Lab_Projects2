#include <iostream>
#include "Queue.h"

using namespace std;
int main()
{
    int Count = 0;
    int testCase;
    int qSize;
    cin >> qSize;
    Queue *QueueArriving = new Queue(qSize);
    Queue *QueueIdeal = new Queue(qSize);

    cin >> testCase;

    for(int i = 0; i < testCase; i++){
        int numTasksArriving;
        int numTasksIdeal;
        int arrivingList[qSize];
        int idealList[qSize];
        int executionTime = 0;
        int missingInt;

        cin >> numTasksIdeal;
        cin >> numTasksArriving;
        for(int i = 0; i < numTasksArriving; i++){
            cin >> arrivingList[i];
            QueueArriving->enqueue(arrivingList[i]);
        }
        //cout << "Queue Arriving List: " << endl;
        //QueueArriving->printQueue();
        for(int i = 0; i < numTasksIdeal; i++){
            cin >> idealList[i];
            for(int j = 0; j < numTasksArriving;j++){
                if(idealList[i] == arrivingList[j]){
                    QueueIdeal->enqueue(idealList[i]);
                }
            }

        }
        //cout << "Queue ideal List: " << endl;
        //QueueIdeal->printQueue();
        cout << "*** Test: " << i + 1 << endl;

        while(QueueArriving->getCount() != 0){
            int temp1 = QueueArriving->peek();
            if(temp1 == QueueIdeal->peek()){
                //cout << "The task between ideal and arriving matches, executing task now..." << endl;
                QueueArriving->dequeue();
                QueueIdeal->dequeue();
                executionTime += 3;
            }
            else{
                //cout << "The task between Ideal and Arriving does not match, rescheduling the task in the arriving list now..." << endl;
                QueueArriving->enqueue(QueueArriving->dequeue());
                executionTime += 2;
            }
        }
        if(QueueArriving->isEmpty()){
            QueueArriving->clearQueue();
            QueueIdeal->clearQueue();
            //cout << "Successfully cleared the queues" << endl;
        }
    cout << "-- Total Time: " << executionTime << endl;
    }
    delete QueueArriving;
    delete QueueIdeal;
}

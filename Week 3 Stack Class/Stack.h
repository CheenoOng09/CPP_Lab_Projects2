#ifndef STACK_H
#define STACK_H

class Stack{
public:
    Stack(int = 10);
    void push(char);
    char pop();
    void reset();
    bool Empty();
    bool full();
    //charStack = new char[stackSize];
private:
    int stackSize;
    int stackPtr;
    char *charStack;
};

#endif

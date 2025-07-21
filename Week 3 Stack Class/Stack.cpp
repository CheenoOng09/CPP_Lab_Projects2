#include "Stack.h"
#include <cstddef>
using namespace std;

Stack::Stack(int s){
    stackSize = s;
    stackPtr = 0;
    charStack = NULL;
}

void Stack::push(char expressionChar){
    charStack = new char;
    charStack[stackPtr] = expressionChar;
    stackPtr++;
}

char Stack::pop(){
    charStack[stackPtr] = NULL;
    stackPtr--;
}

void Stack::reset(){
    stackPtr = 0;
}

bool Stack::Empty(){
    if(stackPtr == 0)
        return true;
    else
        return false;
}
bool Stack::full(){
    if(stackPtr == stackSize)
        return true;
    else
        return false;
}

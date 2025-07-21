#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

void checkExpression(string expression, Stack &stackExpr){ //global function
    for(int i = 0; expression[i] != NULL; i++){ //traverse the expression character per character
        if(expression[i] == '('){ //
            if(!stackExpr.full()){
                stackExpr.push(expression[i]);
            }
            else if (stackExpr.full()){
                cout << "Stack is full" << endl;
                stackExpr.reset();
                return;
            }
        }
        else if (expression[i] == ')'){
            if(stackExpr.Empty()){
                cout << "More )'s" << endl;
                return;
            }
            else
                stackExpr.pop();
        }
    }
    if (stackExpr.Empty()){
        cout << "Correct" << endl;
    }
    else if (!stackExpr.Empty())
        cout << "More ('s" << endl;

    stackExpr.reset();
}

int main()
{
    int numTest;
    int sizeOfStack;
    string arithExpr;

    cin >> sizeOfStack;
    cin >> numTest;

    Stack exprStack(sizeOfStack);

    for(int j = 0; j < numTest; j++){
        cin >> arithExpr;
        checkExpression(arithExpr, exprStack);

    }
    return 0;
}

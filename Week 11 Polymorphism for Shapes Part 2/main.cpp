#include "Shape.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    Pt p1(1, 2);
    Pt p2(5, 8);
    Pt p3(-2, 10);
    Pt p4(0, 0);
    Pt p5(1.5, 4);
    Pt p6(2, 8);
    Pt p7(10, 8);
    Pt p8(0,8); ///////////////////////////

    Triangle tr1(p1, p2, p3);
    Triangle tr2(p2, p3, p4);
    Triangle tr3(p2, p6, p7);
    Rectangle rect1(p1, p3);
    Rectangle rect2(p1, p1);
    Circle cir1(p4, 10.0);
    Circle cir2(p2, 4);
    Rectangle rect3(p1, p2);
    Triangle tr4(p5,p6,p8); /////////////////
    const int numShape = 9;
    vector<Shape*> baseShape(numShape);
    baseShape[0] = &tr1;
    baseShape[1] = &tr2;
    baseShape[2] = &rect1;
    baseShape[3] = &cir1;
    baseShape[4] = &tr3;
    baseShape[5] = &rect2;
    baseShape[6] = &cir2;
    baseShape[7] = &rect3;
    baseShape[8] = &tr4; ////////////////////

    for(int i = 0; i < numShape; i++)
    {
        for(int j = 0; j < numShape; j++)
        {
            if(baseShape[i]->intersection(baseShape[j]))
            {
                cout << i << ", " j << ": Yes." << endl;
            }
            else
            {
                cout << i << ", " j << ": No." << endl;
            }
        }
    }

    /*for (int i = 0; i < numShape; ++i)
    {
        baseShape[i]->print();
        p5.print();
        if (baseShape[i]->inside(p5))
        {
            cout << " is inside this shape." << endl;
        }
        else
        {
            cout << " is outside this shape." << endl;
        }
        Circle *cPtr = dynamic_cast<Circle *>(baseShape[i]);
        if (cPtr != 0)
        {
            cout << "## This shape is a circle." << endl;
        }
        Triangle *tPtr = dynamic_cast<Triangle *>(baseShape[i]);
        if (tPtr != 0)
        {
            cout << "## This shape is a triangle." << endl;
        }
        Rectangle *rPtr = dynamic_cast<Rectangle *>(baseShape[i]);
        if (rPtr != 0)
        {
            cout << "## This shape is a rectangle." << endl;
        }
    }*/
    return 0;
}

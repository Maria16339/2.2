#include <iostream>
#include "matrix.h"
using namespace std;

int main()
{
    int data1[] = { 10,100,10,100,10,100,10,100 };
    int data2[] = { 13,233,3,4,5,6 };
    int data3[] = { 10,100,10,100,10,100,10,100 };
    int data4[] = { 1,0,0,0,1,0,0,0,1 };

    Matrix mat1(4, 2, data1);
    Matrix mat2(2, 3, data2);
    Matrix mat3(4, 2, data3);
    Matrix mat4(3, 3, data4);


    
    cout << mat1 << endl;
    cout << mat2;
    cout << endl ;
    cout << mat3 << endl;
    cout << mat3;
    cout << endl ;

    //First

    cout << "mat1+mat3=" << endl;
    cout << mat1 + mat3 << endl;
    cout<< "mat1-mat3=" << endl << mat1-mat3<<endl;
    cout<< "mat1*mat3=" << endl << mat2*mat4<<endl;
    cout<< "mat1+4=" << endl <<mat1+4<<endl;
    cout<< "mat2-3=" << endl <<mat2-3<<endl;
    cout<< "mat1*1=" << endl << mat1*1<<endl;

    //Second

    cout<<"mat1+=mat3" << endl;
    mat1 += mat3;
    cout << "mat1-=mat3" << endl;
    mat1-=mat3;
    cout << " mat1+=2" << endl;
    mat1+=2;
    cout << " mat1-=2" << endl;
    mat1-=2;
    cout << "++mat1" << endl;
    ++mat1;
    cout << "--mat1" << endl;
    --mat1;
}
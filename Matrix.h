#ifndef MATRIX_H
#define MATRIX_H


#include <iostream>
using namespace std;

class Matrix
{
private:
   
    int row, column;
    int** matrix;
    //int **data;
    
public:

    /*������������*/
    Matrix();
    Matrix(int _row, int _column);
    Matrix(int _row, int _column, int* arr);
    Matrix(const Matrix& _m);
    Matrix operator= (Matrix mat);

    /*�������� �������� >> � �������� ��������� <<*/
    friend istream& operator>>(istream& input, const Matrix& obj);      
    friend ostream& operator<<(ostream& output, const Matrix& obj);      


    /*�������� ���������, �������� ��������, �������� �������� �� �������� ������*/
  

    Matrix operator+(const Matrix& obj);    
    Matrix operator-(const Matrix& obj);   
    Matrix operator*(const Matrix& obj);    
    Matrix operator+(int scalar);           
    Matrix operator-(int scalar);          
    Matrix operator*(int scalar); 
   

    Matrix operator+=(const Matrix& obj);   
    Matrix operator-=(const Matrix& obj);   
    Matrix operator+=(int scalar);          
    Matrix operator-=(int scalar);          
    void operator++ ();                     
    void operator-- (); 


    

  
};

#endif // MATRIX_H
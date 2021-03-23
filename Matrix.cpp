#include "matrix.h"
using namespace std;
/*Конструктори*/
Matrix::Matrix()
{
    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of columns: ";
    cin >> column;

    matrix = new int* [row];
    for (int i = 0; i < row; i++)
        matrix[i] = new int[column];
}

Matrix::Matrix(int _row, int _column)
{
    row = _row;
    column = _column;
    matrix = new int* [_row];
    for (int i = 0; i < _row; i++)
        matrix[i] = new int[_column];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            matrix[i][j] = 0;

}

Matrix::Matrix(int _row, int _column, int* arr)
{
    row = _row;
    column = _column;
    matrix = new int* [_row];
    for (int i = 0; i < _row; i++)
        matrix[i] = new int[_column];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            matrix[i][j] = arr[i * column + j];

}

Matrix::Matrix(const Matrix& _m)
{
    row = _m.row;
    column = _m.column;
    matrix = new int* [row];
    for (int i = 0; i < row; i++)
        matrix[i] = new int[column];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            matrix[i][j] = _m.matrix[i][j];

}


/*Оператор введення >> і оператор виведення <<*/

istream& operator>>(istream& input, const Matrix& obj)
{
    cout << "Enter elements: " << endl;
    for (int i = 0; i < obj.row; i++)
    {
        for (int j = 0; j < obj.column; j++)
            input >> obj.matrix[i][j];
    }
    return input;
}

ostream& operator<<(ostream& output, const Matrix& obj)
{
    for (int i = 0; i < obj.row; i++)
    {
        for (int j = 0; j < obj.column; j++)
            output << obj.matrix[i][j] << " ";
        output << endl;
    }
    return output;
}
//Оператор копіювання
Matrix Matrix:: operator= (Matrix obj)
{
    if (this == &obj)
        return *this;


    for (int i = 0; i < row; i++)
        delete[] matrix[i];
    delete[] matrix;

    row = obj.row;
    column = obj.column;
    matrix = new int* [row];

    for (int i = 0; i < row; i++)
        matrix[i] = new int[column];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            matrix[i][j] = obj.matrix[i][j];

    return *this;
}



/*оператор додавання*/
Matrix Matrix::operator+(const Matrix& obj)
{
    if (this->row == obj.row && this->column == obj.column)
    {

        Matrix m(row, column);
        for (int i = 0; i < m.row; i++)
        {
            for (int j = 0; j < m.column; j++)
                m.matrix[i][j] = matrix[i][j] + obj.matrix[i][j]; //підсумовування двох матриць в одній новій матриці
        }
        return m;
    }
    else
        cout << "Cannot sum due to different ROWS or COLS" << endl;
    exit(0);
}
/*оператор віднімання*/
Matrix Matrix::operator-(const Matrix& obj)
{
    if (this->row == obj.row && this->column == obj.column)
    {
        Matrix m(row, column);
        for (int i = 0; i < m.row; i++)
        {
            for (int j = 0; j < m.column; j++)
                m.matrix[i][j] = matrix[i][j] - obj.matrix[i][j];
        }
        return m;
    }
    else
        cout << "Cannot sum due to different ROWS or COLS" << endl;
    exit(0);
}

/*оператор множення*/
Matrix Matrix::operator*(const Matrix& obj)
{
    if (this->column == obj.row)
    {
        Matrix m(row, obj.column);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < obj.column; j++)
            {
                m.matrix[i][j] = 0;
                for (int k = 0; k < column; k++)
                {
                    m.matrix[i][j] += matrix[i][k] * obj.matrix[k][j];
                }
            }
        }
        return m;
    }
    else
        cout << "Cannot as COL of mat1 doesn't equal ROW in mat2" << endl;
    exit(0);
}
// Підсумовування матриці зі скалярним числом.
Matrix Matrix::operator+(int scalar)
{
    Matrix m(row, column);
    for (int i = 0; i < m.row; i++)
    {
        for (int j = 0; j < m.column; j++)
            m.matrix[i][j] = matrix[i][j] + scalar;
    }
    return m;
}
// Різниця матриці зі скалярним числом.
Matrix Matrix::operator-(int scalar)
{
    Matrix m(row, column);
    for (int i = 0; i < m.row; i++)
    {
        for (int j = 0; j < m.column; j++)
            m.matrix[i][j] = matrix[i][j] - scalar;
    }
    return m;
}
// Множення Матриці зі скалярним числом.
Matrix Matrix::operator*(int scalar)
{
    Matrix m(row, column);
    for (int i = 0; i < m.row; i++)
    {
        for (int j = 0; j < m.column; j++)
            m.matrix[i][j] = matrix[i][j] * scalar;
    }
    return m;
}


//Підсумовування 2 матриць у першій матриці

Matrix Matrix :: operator+=(const Matrix& obj)
{
    if (this->row == obj.row && this->column == obj.column)
    {
        for (int i = 0; i < this->row; i++)
            for (int j = 0; j < this->column; j++)
                this->matrix[i][j] += obj.matrix[i][j];
        cout << *this << endl;
        return *this;
    }
    else
        cout << "Cannot sum as ROWS or COLS aren't the same" << endl;
    exit(0);
}
//Різниця 2 матриць у першій матриці

Matrix Matrix :: operator-=(const Matrix& obj)
{
    if (this->row == obj.row && this->column == obj.column)
    {
        for (int i = 0; i < this->row; i++)
            for (int j = 0; j < this->column; j++)
                this->matrix[i][j] -= obj.matrix[i][j];
        cout << *this << endl;
        return *this;
    }
    else
        cout << "Cannot sum as ROWS or COLS aren't the same" << endl;
    exit(0);
}
// Підсумовування скаляра до матриці

Matrix Matrix :: operator+=(int scalar)
{
    for (int i = 0; i < this->row; i++)
        for (int j = 0; j < this->column; j++)
            this->matrix[i][j] += scalar;
    cout << *this << endl;
    return *this;
}
//Різниця скаляра до матриці

Matrix Matrix :: operator-=(int scalar)
{
    for (int i = 0; i < this->row; i++)
        for (int j = 0; j < this->column; j++)
            this->matrix[i][j] -= scalar;
    cout << *this << endl;
    return *this;
}

//Додавання 1 до кожного елемента в Matrix
void Matrix::operator++()
{
    for (int i = 0; i < this->row; i++)
        for (int j = 0; j < this->column; j++)
            this->matrix[i][j] += 1;
    cout << *this << endl;

}
// Віднімання 1 з кожного елемента в Matrix
void Matrix::operator--()
{
    for (int i = 0; i < this->row; i++)
        for (int j = 0; j < this->column; j++)
            this->matrix[i][j] -= 1;
    cout << *this << endl;

}



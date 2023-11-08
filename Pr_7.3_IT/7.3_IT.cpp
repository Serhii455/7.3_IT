#include <iostream>
#include <iomanip>


using namespace std;


void Input(int** A, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
        cout << endl;
    }
}


void Print(int** A, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << A[i][j];
        cout << endl;
    }
    cout << endl;
}


int FindZeroRow(int** A, const int rowCount, const int colCount)
{
    int zerorow = 0;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            if (A[i][j] == 0)
            {
                
                zerorow++;
            }
        }
    }
    return zerorow;
}


void RorateRight(int** A, const int rowCount, const int colCount, int k)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int rotate = A[i][colCount - 1];
            for (int l = colCount - 1; l > 0; l--)
            {
                A[i][l] = A[i][l - 1];
            }
            A[i][0] = rotate;
        }
    }
}


void RorateDown(int** A, const int rowCount, const int colCount, int k)
{
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            int rotate = A[rowCount - 1][j];
            for (int l = rowCount - 1; l > 0; l--)
            {
                A[l][j] = A[l-1][j];
            }
            A[0][j] = rotate;
        }
    }
}


void ChangeMode(int** A, const int rowCount, const int colCount, int mode) {
    int k;
    cout << "Enter the number by which the elements will shift" << endl;
    cout << "k = ";
    cin >> k;
    cout << setw(5) << endl;
    cout << "Updated Matrix A:" << endl;

    if (mode == 1) {
        RorateRight(A, rowCount, colCount, k);
    } else {
        RorateDown(A, rowCount, colCount, k);
    }
    Print(A, rowCount, colCount);
}


int main() 
{
    int rowCount, colCount;


    cout << "rowCount = ";
    cin >> rowCount;
    cout << "colCount = ";
    cin >> colCount;
    cout << setw(5) << endl;


    int** A = new int* [rowCount];


    for (int i = 0; i < rowCount; i++)
        A[i] = new int[colCount];


    Input(A, rowCount, colCount);


    cout << "Matrix A:" << endl;
    Print(A, rowCount, colCount);
    cout << setw(5) << endl;



    cout << "Number of zero row: " << FindZeroRow(A, rowCount, colCount) << endl;
    cout << setw(5) << endl;


    cout << "If you want the matrix to shift to the right, enter 1, if down - any other value" << endl;
    int mode;
    cout << "mode: ";
    cin >> mode;


    ChangeMode(A, rowCount, colCount, mode);






    for (int i = 0; i < rowCount; i++)
        delete[] A[i];
    delete[] A;

    return 0;
}

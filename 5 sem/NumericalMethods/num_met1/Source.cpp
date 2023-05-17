#include <iostream>
#include <fstream>

using namespace std;

float** matrix;
int order;
float buf;

void printMatrix()
{
    cout << "Matrix:";
    for (int i = 0; i < order; i++)
    {
        cout << '\n';
        for (int j = 0; j < order + 1; j++)
            cout << matrix[j][i] << ' ';
    }
    cout << "\n\n";
}

void enterValues() 
{
    ifstream file("matrix1.txt");
    file >> order;

    matrix = new float*[order + 1];

    for (int i = 0; i < order + 1; i++)
        matrix[i] = new float[order];

    for (int i = 0; i < order; i++) 
        for (int j = 0; j < order + 1; j++)
            file >> matrix[j][i];
    
    printMatrix();
}

void swap(float& a, float& b)
{
    float tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void solve() 
{
        enterValues();
        float* resolve = new float[order];
        for (int i = 0; i < order; i++) // номер диагонального элемента
            for (int j = i + 1; j < order; j++) // строка
            { 
                buf = matrix[i][j] / matrix[i][i];

                if(matrix[i][i] == 0)
                    for (int k = i + 1; k < order; k++)
                        if (matrix[i][k] != 0)
                            for (int m = 0; m < order + 1; m++)
                            {
                                swap(matrix[m][i], matrix[m][k]); // определитель меняет знак
                                break;
                            }

                for (int k = 0; k < order + 1; k++)
                    matrix[k][j] = matrix[k][j] - buf * matrix[k][i];
            }

        printMatrix();

        float s = 0;
        //обратный ход
        for (int i = order - 1; i >= 0; i--)
        {
            buf = 0;
            for (int j = i + 1; j < order; j++)
            {
                s = matrix[j][i] * resolve[j];
                buf += s;
            }
            resolve[i] = (matrix[order][i] - buf) / matrix[i][i];
        }
        
        cout << "Answer:" << endl;
        for (int i = 0; i < order; i++)
            cout << 'x' << i << " = " << resolve[i] << endl;
}



int main()
{
    solve();

	return 0;
}
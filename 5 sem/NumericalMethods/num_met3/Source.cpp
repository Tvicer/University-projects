#include <iostream>
#include <fstream>

using namespace std;

float** matrix;
int order;
float* core;
float* auther;

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
    ifstream file("matrix.txt");
    file >> order;

    matrix = new float* [order + 1];

    for (int i = 0; i < order + 1; i++)
        matrix[i] = new float[order];

    for (int i = 0; i < order; i++)
        for (int j = 0; j < order + 1; j++)
            file >> matrix[j][i];

    printMatrix();
}


void solve()
{
    enterValues();
    core = new float[order];
    auther = new float[order];


}



int main()
{
    solve();

    return 0;
}
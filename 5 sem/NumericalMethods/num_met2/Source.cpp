#include <iostream>
#include <fstream>

using namespace std;

float* arr_a;
float* arr_b;
float* arr_c;
float* arr_d;
float* arr_p;
float* arr_q;
float* arr_x;
int order;
float buf;

void printArrays()
{
    cout << "Arrays:" << endl;
    cout << "A: ";
    for (int i = 0; i < order; i++)
    {
        cout << arr_a[i] << ' ';
    }
    cout << "\nB: ";
    for (int i = 0; i < order; i++)
    {
        cout << arr_b[i] << ' ';
    }
    cout << "\nC: ";
    for (int i = 0; i < order; i++)
    {
        cout << arr_c[i] << ' ';
    }
    cout << "\nD: ";
    for (int i = 0; i < order; i++)
    {
        cout << arr_d[i] << ' ';
    }
    cout << "\n\n";
}

void printAns()
{
    cout << "Ans:" << endl;
    for (int i = 0; i < order; i++)
    {
        cout << "x" << i << "=" << arr_x[i] << ' ';
    }
    cout << "\n\n";
}

void enterValues()
{
    ifstream file("matrix.txt");
    file >> order;
    int tmp;
    arr_a = new float [order];
    arr_b = new float[order];
    arr_c = new float[order];
    arr_d = new float[order];

    for (int i = 0; i < order; i++)
    {
        if (i == 0)
        {
            arr_a[i] = 0;
            file >> arr_b[i];
            file >> arr_c[i];
            for (int j = 0; j < order - 2; j++)
                file >> tmp;
            file >> arr_d[i];
        }
        else if (i == order - 1)
        {
            for (int j = 0; j < order - 2; j++)
                file >> tmp;
                
            file >> arr_a[i];
            file >> arr_b[i];
            arr_c[i] = 0;
            file >> arr_d[i];
        }
        else
        {
            for (int j = 0; j < i - 1; j++)
                file >> tmp;
            file >> arr_a[i];
            file >> arr_b[i];
            file >> arr_c[i];
            for (int j = 0; j < order - i - 2; j++)
                file >> tmp;
            file >> arr_d[i];
        }
    }

    printArrays();
}

void solve()
{
    enterValues();

    arr_p = new float[order];
    arr_q = new float[order];
    arr_x = new float[order];

    for (int i = 0; i < order; i++)
    {
        if (i == 0)
        {
            arr_p[i] = -arr_c[i] / arr_b[i];
            arr_q[i] = arr_d[i] / arr_b[i];
        }
        else
        {
            arr_p[i] = -arr_c[i] / (arr_b[i] + (arr_a[i] * arr_p[i - 1]));
            arr_q[i] = (arr_d[i] - (arr_a[i] * arr_q[i - 1])) / (arr_b[i] + (arr_a[i] * arr_p[i - 1]));
        }
    }

    for (int i = order - 1; i >= 0; i--)
    {
        if (i == order - 1)
        {
            arr_x[i] = arr_q[i];
        }
        else
        {
            arr_x[i] = (arr_p[i] * arr_x[i + 1]) + arr_q[i];
        }
    }

    printAns();

}

int main()
{
    solve();

    return 0;
}
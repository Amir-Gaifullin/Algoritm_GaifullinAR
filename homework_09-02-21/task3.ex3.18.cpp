#include "iostream"

using namespace std;

void fill1(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        a[i] = i;
        cout << a[i] << " ";
    }
}

void fill2(int * a, int size)
{
    for (int * p = a; p < a + size; p++)
    {
        *p = p - a;
        cout << *p << " ";
    }
}

#include <iostream>


using namespace std;

void func(int* arr, int size, int* summ, int* mult)
{
    for (int i = 0; i < size; i++)
    {
        *summ += *(arr + i);
    }
    cout << "Sum: " << *summ << endl;
    for (int j = 0; j < size; j++)
    {
        *mult *= (*arr + j);
    }
    cout << "Mult: " << *mult << endl;
}

int main()
{
    srand(time(0));
    const int size = 5;
    int arr[size];
    int summ = 0, multi = 1;
    int* psumm = &summ;
    int* pmulti = &multi;
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
    int* pa = &arr[0];
    func(pa, size, psumm, pmulti);

    return 0;
}







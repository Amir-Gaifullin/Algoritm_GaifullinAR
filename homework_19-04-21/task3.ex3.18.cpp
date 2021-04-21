#include <iostream>
using std::cin;
using std::cout;

int Sqrt(int x)
{
    int left = 1, right = x + 1;
    int mid, val;
 
    while(right - left > 1)
    {
        mid = (left + right) / 2;
        val = x;
        for(int i = 1; i <= 1; ++i) val /= mid;
        if(val >= mid) left = mid;
        else right = mid;
    }
    return left;
}
int main()
 {
    int x;
    cout << "Введите число: ";
    cin >> x;
    cout << Sqrt(x);   
 }
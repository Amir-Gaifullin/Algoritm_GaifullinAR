#include <iostream>

using namespace std;


int * createArray(const int n)
{
    int a[n];
    return a;
}
int main()
{
    int x;
    cin >> x;
    
    int * a = createArray(x);
    
    return 0;
}

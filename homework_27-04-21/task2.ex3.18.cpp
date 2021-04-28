#include "iostream"
using namespace std;

int main() {
    int len_mas;
    cin >> len_mas;
    int shag_1, shag_2, mas[len_mas];
    mas[0] = 1;
    mas[1] = 1;
    for (int i = 2;i < len_mas;i++)
    {
        shag_1 = mas[i - 2];
        shag_2 = mas[i - 1];
        mas[i] = shag_1 + shag_2;
    }
    cout << mas[len_mas - 1]<< '\n';
    return 0;
}
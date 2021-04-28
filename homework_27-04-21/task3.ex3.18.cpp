#include "iostream"
using namespace std;



int main() {
    int rows, columns;
    cout << "\n\nВведите кол-во столбцов и строчек через пробел: ";
    cin >> rows >> columns;
    int mas[rows][columns];
    for (int row = rows - 1;row > - 1;row--) {
       for (int column = 0;column < columns;column++) {
            if (row == (rows - 1)) 
               mas[row][column] = 1;
            else if (column == 0)
                mas[row][column] = 1;
            else 
                mas[row][column] = mas[row][column - 1] + mas[row + 1][column];
        }
    }
    cout << mas[0][columns - 1];
    return 0;
}
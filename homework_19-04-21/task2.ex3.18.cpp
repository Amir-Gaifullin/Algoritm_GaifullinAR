#include <iostream>
#include <string>
using namespace std;
 
int Search_Binary_start(int **arr, int low, int high, int rows, int x) {
    for (int i = 0; i < rows; i++) {
    while(high - low > 1) {
        int mid = low + (high - low) / 2;
        if(x <= arr[i][mid]) {
            high = mid;
        } else if(x > arr[i][mid]) {
            low = mid;
        }
    }
    if(arr[i][low] == x) return true;
    if(arr[i][high] == x) return true;
    }
    return 0;
}
 
int main()
{
 int key, rows, columns;
 bool index;
 key = 0;   
 rows = 3;
 columns = 3;
//  int array[rows][columns] = {{1, 3, 4},
//                             {6, 8, 10},
//                             {45, 67, 68}};
                            
    // пришлось сделать динамические массив, иначе не мог закинуть в свою функцию
    // на stackoverflow сказали что поможет , так и получилось
 int **array = new int*[rows];
 for(int i = 0; i<rows; i++){
    array[i]  =   new int[columns];
 }
 for (int i = 0; i < rows; i++)
 {
    for(int j = 0; j < columns; j++)
    {
            array[i][j] = rand() % 5;
    }
 }
            

 cout << "\n\nВведите любое число: ";
 cin >> key;
 
 index = Search_Binary_start(array, 0, columns, rows, key);
 if (index){
  cout << "Такое число есть";
 }
 else
 cout << "Нихт!\n\n";
 
 return 0;
    
}
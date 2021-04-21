#include <iostream>
using namespace std;
 
int Search_Binary_start(int *arr, int low, int high, int x) {
    while(high - low > 1) {
        int mid = low + (high - low) / 2;
        if(x <= arr[mid]) {
            high = mid;
        } else if(x > arr[mid]) {
            low = mid;
        }
    }
    if(arr[low] == x) return low;
    if(arr[high] == x) return high;
    return -1;
}

int Search_Binary_end(int *arr, int low, int high, int x) {
    int endIndex = -1;
    while (low <= high) {
        int mid = (high - low) / 2 + low;
        if (arr[mid] > x) {
            high = mid - 1;
        } else if (arr[mid] == x) {
            endIndex = mid;
            low = mid + 1;
        } else
            low = mid + 1;
    }
    return endIndex;
    
}
 
int main()
{
 const int SIZE = 28;
 int array[SIZE] = {0,0,0,0,1,1,1,1,1,1,1,1,2,2,2,2,3,5,5,5,5,6,9,9,9,9,9,9};
 int key = 0;
 int index_start = 0;
 int index_end = 0;
 
 cout << "\n\nВведите любое число: ";
 cin >> key;
 
 index_start = Search_Binary_start (array, 0, SIZE, key);
 index_end = Search_Binary_end(array, 0, SIZE, key);
 
 if (index_start >= 0){
  cout << "Начало: указанное число находится в ячейке с индексом: " << index_start << "\n";
  cout << "Конец: указанное число находится в ячейке с индексом: " << index_end << "\n";
 }
 else
 cout << "В массиве нет такого числа!\n\n";
 
 return 0;
}
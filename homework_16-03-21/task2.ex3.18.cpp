#include <iostream>
using namespace std;


struct MaxHeap
{
    int * array;
    int size;
    int maxSize;
    int Parent(int i) { return (i - 1) / 2; }
    int LeftChild(int i) { return 2 * i + 1; }
    int RightChild(int i) { return 2 * i + 2; }

    MaxHeap(int maxSize){
        this->maxSize = maxSize;
        size = -1;
        array = new int [maxSize];
    }


    void SiftUp(int i)
    {
        int t;
        // пока i > 0 и array[i] > array[Parent(i)]:
        //    поменять местами родителя и ребёнка
        //    i = Parent(i)
        while (i > 0 && array[i] > array[Parent(i)]){
            array[i] = t;
            array[i] = array[Parent(i)];
            array[Parent(i)] = t;
            i = Parent(i);

        }
    }
    void SiftDown(int i)
    {
        // maxIndex = i
        // Если в LeftChild(i) значение больше, чем в maxIndex, и LeftChild(i) < size, то maxIndex=LeftChild(i)
        // Если в RightChild(i) значение больше, чем в maxIndex, и RightChild(i) < size, то maxIndex=RightChild(i)
        // Если maxIndex != i, то: поменять местами array[i] и array[maxIndex], вызвать SiftDown(maxIndex)

        int maxIndex;
        int t;
        maxIndex = i;

        if (array[LeftChild(i)] > array[i] && LeftChild(i) <= size){
            array[i] = t;
            array[i] = array[LeftChild(i)];
            array[LeftChild(i)] = t;
            maxIndex = LeftChild(i);
            SiftDown(maxIndex);
        }
        else if (array[RightChild(i)] > array[i] && RightChild(i) <= size){
            array[i] = t;
            array[i] = array[RightChild(i)];
            array[RightChild(i)] = t;
            maxIndex = RightChild(i);
            SiftDown(maxIndex);
        }
    }

    void Insert(int p)
    {
        // проверяем, что size < maxSize
        // size++;
        // array[size] = p;
        // SiftUp(size)
        if (size < (maxSize - 1)){
            size++;
            array[size] = p;
            SiftUp(size);
        }
    }

    int ExtractMax()
    {
        // Записываем 0 элемент в result
        // Меняем 0 элемент с элементом под номером size
        // Уменьшаем size
        // SiftDown(0)
        // return result
        int result;
        int t;
        result, t = array[0];
        array[0] = array[size];
        array[size] = t;
        size--;

        SiftDown(0);
        return result;
    }

    void printAll(){
        for (int i = 0;i <= size;i++){
            cout << array[i] << " ";
        }
    }

};

int two_deg(int num){
    int iter = 0;
    while (num > 1){

        num = num / 2;
        iter ++;

    }

    return iter + 1;

};

int power(int a, int b)
{
    int cntr = 1;
    for (int i = 0; i < b; i++){
        cntr = cntr * a;

    }

    return cntr;
};

int * HeapSort(int * array, int size) {

    int size2 = 0;
    int mid = 1;
    while (size > 1){
        size = size / 2;
        size2 ++;
    }
    size = size2 + 1;
    for (int i = 0; i < size; i++){
        mid = mid * 2;
    }
    MaxHeap * heap = new MaxHeap(cntr);
    int * heap_res = new int[15];
    for (int i = 0;i<size;i++){
        heap->Insert(array[i]);
    }
    for (int i = 0;i<size;i++){
        heap_res[i] = heap->ExtractMax();
    }

    return heap_res;
}

//void * HeapSort(int * array, int size){
//    MaxHeap * heap = new MaxHeap(size);
//    {
//        for (int i = size / 2 - 1; i >= 0; i--)
//            heap->Insert(array[i]);
//        for (int i = size - 1; i >= 0; i--)
//        {
//            swap(array[0], array[i]);
//            heap->Insert(arr(i))
//        }
//    }
//}

int main()
{
    int size = 4;
    int * array_1 = new int [size]{11,5,6,7};

    int * array_2 = HeapSort(array_1,size);

    //   array_2->printAll();
    //  for (int i = 0;i < size;i++){
    //     cout << array_2[i] << endl;
    // }


    return 0;

}
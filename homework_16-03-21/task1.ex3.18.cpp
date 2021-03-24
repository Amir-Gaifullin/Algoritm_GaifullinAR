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

int main()
{
    MaxHeap * heap = new MaxHeap(3);

    heap->Insert(11);
    heap->Insert(5);
    heap->Insert(4);
    heap->printAll();

    return 0;

}
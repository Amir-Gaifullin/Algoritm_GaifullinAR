#include <iostream> 
#include <stack> 
using namespace std;

struct Node
{
    int item;
    Node* next;
};

struct Stack
{
    Node* pHead;

    
    void Push(int item)
    {
        Node* node = new Node;
        node->item = item;
        node->next = pHead;
        pHead = node;
    }

    int Pop()
    {
        if (!pHead)
            throw 1;

        Node* temp = pHead;
        int x = temp->item;
        pHead = temp->next;
        delete temp;
        return x;
    }

    int Peek()
    {
        if (!pHead)
            throw 1;

        return pHead->item;
    }

    int printAll()
    {
        Node* top = pHead;
        while (top) {
            cout << top->item << " ";
            top = top->next;
        }
    }

};
int main()
{
    Stack* stack = new Stack;

    stack->Push(10);
    stack->Push(20);

    stack->printAll();

    delete stack;
    return 0;
}
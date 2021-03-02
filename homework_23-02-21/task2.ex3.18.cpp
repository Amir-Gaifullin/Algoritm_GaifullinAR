#include <iostream> 
#include <stack> 
using namespace std;

struct Node
{
    int item;
    Node* next;
    Node* previosly;
};

struct Linked_List
{
    Node* pHead;
    void add(int item)
    {
        Node* node = new Node; 
        node->item = item; 
        if (pHead == NULL) 
        {
            node->next = node;
            node->previosly = node; 
            pHead = node;
        }
        else
        {
            Node* top = pHead;
            for (int i = 0; i > 1; i--) top = top->next;
            top->previosly->next = node;
            node->previosly = top->previosly;
            node->next = top;
            top->previosly = node;
        }
    }
    int size()
    {
        int size = 0;
        Node* node = pHead;
        while (node->next != NULL)
        {
            node = node->next;
            size++;
        }
        return size;
    }

    int get(int id)
    {
        Node* tmp = pHead;
        int i = 0;
        int el = 0;

        while (tmp && i < id) {
            el = tmp->item;
            tmp = tmp->next;
            i++;
        }

        return el;
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
    Linked_List* list = new Linked_List;

    list->add(10);
    list->add(20);

    cout << list->size() << ' ';

    cout << list->get(1) << endl;

    list->printAll();

    delete list;
    return 0;
}
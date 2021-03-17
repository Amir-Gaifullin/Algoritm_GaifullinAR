#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

struct List
{
    Node* pHead;
    Node* pLast;
    List()
    {
        pHead = NULL;
        pLast = NULL;
    }

    void add(int item){
        Node * head = pHead;
        int i = 0;
        bool flag = true;


        if (!pHead){
            Node * node = new Node;
            node->data = item;
            node->next = 0;
            node->prev = 0;
            pHead = node;
            pLast = node;
        }
        else if (item <= head->data){
            Node * node = new Node;
            node->data = item;
            head->prev = node;
            node->next = head;
            pHead = node;
        }

        else{
            while (head && flag){

                if (item <= head->data && flag){
                    Node * node = new Node;
                    node->data = item;
                    node->next = head;
                    node->prev = head->prev;
                    head->prev->next = node;
                    head->prev = node;
                    flag = false;
                }

                if (head->next && flag){
                    head = head->next;
                }
                else if(flag){
                    Node * node = new Node;
                    node->data = item;
                    head->next = node;
                    node->prev = head;
                    pLast = node;
                    flag = false;

                }
            };
        }
    }

    int size()
    {
        if (pHead == NULL)
            return 0;
        else
        {

            int i = 1;
            for (Node* temp = pHead; temp->next != NULL; i++)
            {
                temp = temp->next;
            }
            return i;
        }


    }

    struct Node get(int id)
    {
        if (pHead != NULL)
        {
            Node* temp = pHead;
            for (int i = 0; i < id; i++)
            {
                temp = temp->next;
            }
            return *temp;
        }
    }
    int printAll()
    {
        Node* top = pHead;
        while (top) {
            cout << top->data << " ";
            top = top->next;
        }
    }
};


int main()
{
    List* list = new List;
    list->add(10);
    list->add(1);
    list->add(3);
    list->add(3);
    list->printAll();

    return 0;
}

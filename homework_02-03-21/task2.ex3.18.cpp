#include <iostream>

using namespace std;


struct Node
{
    int item;
    Node* next;
    Node* previosly;
};
Node* pHead = NULL;
Node* pTail = NULL;
struct LinkedList {

    void add(int item) {

        Node* temp = new Node;
        temp->item = item;
        temp->previosly = pHead;
        temp->next = (pHead == NULL) ? NULL : pHead->next;
        if (pHead != NULL) {
            pHead->next = temp;
            if (temp->next != NULL)
                temp->next->previosly = temp;

        }
        if (temp->previosly == NULL) pHead = temp;
        if (temp->next == NULL) pTail = temp;

    }
    void printAll() {
        Node* p = pHead;
        while (p != NULL) {
            cout << p->item << endl;
            p = p->next;
        }
    }
    // void Remove()
    // {
    //     Node* tmp = pHead;
        
    //     tmp = pHead->next;
    //     pHead->item = pHead->next->item;
    //     pHead->next = pHead->next->next;
    //     return tmp;
    //     delete tmp;
    //   }
};


int main() {
    LinkedList* lst = new LinkedList;
    
    lst->add(31);
    lst->add(56);
    lst->add(29);
//    lst->Remove();
    lst->printAll();

    delete lst;
}
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

    void add(Node* place, int item) {

        Node* temp = new Node;
        temp->item = item;
        temp->previosly = place;
        temp->next = (place == NULL) ? NULL : place->next;
        if (place != NULL) {
            place->next = temp;
            if (temp->next != NULL)
                temp->next->previosly = temp;

        }
        if (temp->previosly == NULL) pHead = temp;
        if (temp->next == NULL) pTail = temp;

    }
    int size() {
        int size = 0;
        Node* p = pHead;
        while (p != NULL) {
            size++;
            p = p->next;

        }
        return size;
    }

    int get(int id)
    {
        Node* tmp = pHead;
        int i = 0;
        int el = 0;

        while (tmp && i < id + 1) {
            el = tmp->item;
            tmp = tmp->next;
            i++;
        }

        return el;
    }

    void printAll() {
        Node* p = pHead;
        while (p != NULL) {
            cout << p->item << endl;
            p = p->next;
        }
    }
    void removeAt(unsigned int index)
    {
        Node* tmp = pHead;

        if (!index)
        {
            tmp = pHead->next;

            pHead->item = pHead->next->item;
            pHead->next = pHead->next->next;

            delete tmp;

            return;
        }

        Node* tmpDeleted;

        for (int i = 0; i < index - 1; ++i)
            tmp = tmp->next;

        tmpDeleted = tmp->next;
        tmp->next = tmp->next->next;

        delete tmpDeleted;
    }
    void insertAt(int item, int index) {
        Node* temp = new Node;
        if (!index)
        {
            temp->item = pHead->item;
            temp->next = pHead->next;

            pHead->item = item;
            pHead->next = temp;

            return;
        }

        Node* tmpa = pHead;
        --index;

        for (unsigned int i = 0; i < index; ++i)
            tmpa = tmpa->next;

        temp->next = tmpa->next;
        tmpa->next = temp;
    }
};


int main() {
    LinkedList* lst = new LinkedList;
    Node* f = new Node;

    lst->add(pTail, 31);
    lst->add(pTail, 56);
    lst->add(pHead, 29);
    lst->insertAt(345, 3);

    cout << "size " << lst->size() << endl;

    cout << "id " << lst->get(1) << endl;
    lst->removeAt(3);
    lst->printAll();

    delete lst;
}
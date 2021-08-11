//
// Created by shivam tripathi on 10/08/21.
//
#include <iostream>
using namespace std;
class LinkedList{
public:
    int data;
    LinkedList* next;
};
LinkedList *NewNode(int data){
    LinkedList * temp = new LinkedList();
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void addAfter(LinkedList **head_ref, int data){
    if(*head_ref == NULL) *head_ref = NewNode(data);
    else{
        LinkedList *temp = *head_ref;
        while (temp->next != NULL)temp = temp->next;
        temp->next = NewNode(data);
    }
}
void addBefore(LinkedList **head_ref, int data){
    if(*head_ref == NULL) *head_ref = NewNode(data);
    else{
        LinkedList *temp = *head_ref;
        LinkedList *first = NewNode(data);
        first->next = temp;
        *head_ref = first;
    }
}

void printLinkedList(LinkedList **head_ref){
    LinkedList *temp = *head_ref;
    while (temp != NULL){
        cout<<temp->data<<" --> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}


int main() {
    std::cout << "Linked list : Hello, World!" << std::endl;

    LinkedList *l = NULL;

    addAfter(&l, 23);
    addAfter(&l, 24);
    addAfter(&l, 25);

    printLinkedList(&l);

    addBefore(&l, 26);
    addBefore(&l, 27);

    printLinkedList(&l);

    return 0;
}


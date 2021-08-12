//
// Created by shivam tripathi on 10/08/21.
//
#include <iostream>
#include "unordered_set"
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
//adding value at the end
void addAfter(LinkedList **head_ref, int data){
    if(*head_ref == NULL) *head_ref = NewNode(data);
    else{
        LinkedList *temp = *head_ref;
        while (temp->next != NULL)temp = temp->next;
        temp->next = NewNode(data);
    }
}
//adding value at the begning
void addBefore(LinkedList **head_ref, int data){
    if(*head_ref == NULL) *head_ref = NewNode(data);
    else{
        LinkedList *temp = *head_ref;
        LinkedList *first = NewNode(data);
        first->next = temp;
        *head_ref = first;
    }
}
//adding value at given position
void addAt(LinkedList **head_ref, int data, int position){
    if(position <= 1) addBefore(head_ref, data);
    else{
        LinkedList *temp = *head_ref;
        int count = 2;
        while(temp != NULL){
            if(count == position){
                LinkedList *tempA;
                LinkedList *newN = NewNode(data);
                tempA = temp->next;
                temp->next = newN;
                newN->next = tempA;
                break;
            }
            temp = temp->next;
            count++;
        }
    }
}
// delete at given position
void deleteAt(LinkedList **head_ref, int position){
    if(*head_ref != NULL){
        LinkedList *temp = *head_ref;
        if(position == 1){
            *head_ref = temp->next;
            free(temp);
            return;
        }
        int count = 1;
        while(temp != NULL){
            if(count+1 == position){
                LinkedList *next = temp->next->next;
                temp->next = next;
                break;
            }
            temp = temp->next;
            count++;
        }
    }
}
//delete at given key
void deleteData(LinkedList **head_ref, int data){
    if(*head_ref != NULL){
        LinkedList *temp = *head_ref;
        if(temp->data == data){
            deleteAt(head_ref, 1);
        }
        while(temp->next != NULL){
            if(temp->next->data == data){
                LinkedList *next = temp->next->next;
                temp->next = next;
                break;
            }
            temp = temp->next;
        }
    }
}
//reversing the linked list
void reverse(LinkedList **head_ref){
    if(*head_ref != NULL){
        LinkedList *curr = *head_ref;
        LinkedList *next = NULL; LinkedList *prev = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        *head_ref = prev;
    }
}
//swap node of given two inputs // not values --> screen shots
//detect loop
bool detectLoop(LinkedList* h)
{
    unordered_set<LinkedList*> s;
    while (h != NULL) {
        if (s.find(h) != s.end())
            return true;

        s.insert(h);

        h = h->next;
    }

    return false;
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

    addAt(&l, 26, 2);
    addAt(&l, 32, 4);
    addAt(&l, 30, 6);
    printLinkedList(&l);
    deleteData(&l, 23);
    printLinkedList(&l);


    return 0;
}


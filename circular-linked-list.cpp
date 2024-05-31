// Created by AMR on 03/04/2024.
#include <iostream>
using namespace std;

class Node{
public:
    int value;
    Node *next;
    Node(){
        this->value=0;
        this->next = nullptr;
    }
    Node(int value, Node* next){
        this->value=value;
        this->next= next;
    }

    int getValue() const {
        return value;
    }

    void setValue(int value) {
        this->value = value;
    }

    Node* getNext() const {
        return next;
    }

    void setNext(Node* next) {
        this->next = next;
    }
};

class CircularLinkedList{
private:
    Node* head;

public:
    CircularLinkedList(){
        this->head = nullptr;
    }

//    Methods
    void addToFirst(int value){
        Node* n = new Node(value, head);
        Node* p = head;

        if (head == nullptr) {
            n->next = n;
            head = n;
            return;
        }

        while (p->next != head){
            p = p->next;
        }
        p->next = n;
        head = n;
    }

    void removeFirst(){
        if (head == nullptr) return;

        Node* p = head;
        while (p->next != head){
            p = p->next;
        }
        head = head->next;
        p->next = head;
    }

    void addToLast(int value){
        if(head == nullptr) {
            addToFirst(value);
            return;
        }

        Node* n = new Node(value, head);
        Node* p = head;
        while (p->next != head) {
            p = p->next;
        }
        p->next = n;
    }

    void removeFromLast(){
        if(head == nullptr) return;
        if(head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node *p = head;
        Node *pa = head;
        while(p->next != head){
            pa = p;
            p = p->next;
        }
        delete p;
        pa->next= head;
    }

    void print(){
        if (head == nullptr) return;

        Node* p = head;
        do {
            cout << p->value << " -> ";
            p = p->next;
        } while (p != head);
        cout << "(head)" << endl;
    }

    bool search(int value){
        Node* p = head;
        do{
            if (p->value == value){
                return true;
            }
            p = p->next;
        }while (p != head);
        return false;
    }

    void addAfter(int searchedVal, int addedVal){
        if(search(searchedVal)){
            Node* p = head;

            Node* added = new Node(addedVal, nullptr);

            do{
                if(p->value == searchedVal){
                    added->next = p->next;
                    p->next = added;
                    return;
                }
                p = p->next;
            }
            while (p != head);
        }
        else
            return;
    }

};

int main(){
    CircularLinkedList cl;
    for (int i = 10; i <= 100; i+=10) {
        cl.addToLast(i);
    }
    cl.print();
    cl.addToFirst(1);
    cl.print();
    cl.addToLast(2);
    cl.print();

    cl.addAfter(50, 55);
    cl.print();

}

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

class LinkedList{
private:
    Node* head;

public:
    LinkedList(){
        this->head = nullptr;
    }

//    Methods
    void addToFirst(int value){
        Node* n = new Node(value, head);
        head = n;
    }

    void removeFirst(){
        if (head == nullptr) return;
        head = head->next;
    }

    void addToLast(int value){
        if(head == nullptr) {
            addToFirst(value);
            return;
        }
        Node* n = new Node(value, nullptr);
        Node* p = head;
        while(p->next != nullptr){
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
        while(p->next != nullptr){
            pa = p;
            p = p->next;
        }
        delete p;
        pa->next= nullptr;
    }

    void print(){
        Node* p = head;
        while (p != nullptr){
            cout << p->value << "->";
            p = p->next;
        }
        cout << "NULL" << endl;
    }

    bool search(int value){
        Node* p = head;
        while (p!= nullptr){
            if (p->value == value){
                return true;
            }
            p = p->next;
        }
        return false;
    }

    void addAfter(int searchedVal, int addedVal){
        if(search(searchedVal)){
            Node* p = head;

            Node* added = new Node(addedVal, nullptr);

            while (p != nullptr){
                if(p->value == searchedVal){
                    added->next = p->next;
                    p->next = added;
                    return;
                }
                p = p->next;
            }
        }
        else
            return;
    }

};

int main(){
    LinkedList l;
    for (int i = 10; i <= 100; i+=10) {
        l.addToLast(i);
    }
    l.print();
    l.addToFirst(1);
    l.print();
    l.addToLast(2);
    l.print();

    l.addAfter(50, 55);
    l.print();

}

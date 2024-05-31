#include <iostream>
using namespace std;

template <class T>
class Node{
public:
    T value;
    Node* next;
    Node* previous;

    Node(){
        value = 0;
        this->next = nullptr;
        this->previous = nullptr;
    }

    Node(T value, Node* next, Node* previous){
        this->value = value;
        this->next = next;
        this->previous = previous;
    }
};

template <class T>
class DoubleLinkedList{
    Node<T>* head;
    Node<T>* tail;
public:
    DoubleLinkedList(){
        this->head = nullptr;
        this->tail = nullptr;
    }
    void addToFirst(T value){
        Node<T> *n = new Node<T>(value, head, nullptr);
        if (head == nullptr){
            tail = n;
        }
        head = n;
    }

    void addToLast(int value){
        if (head == nullptr){
            addToFirst(value);
            return;
        }
        Node<T> *n = new Node<T>(value, nullptr, tail);
        tail->next = n;
        tail = n;

    }

    bool search(T value){
        if(head == nullptr){
            return false;
        }
        Node<T>* p = head;
        while (p != nullptr){
            if(p->value == value){
                return true;
            }
            p = p->next;
        }
        return  false;
    }

    void print(){
        Node<T> *p = head;
        while (p != nullptr){
            cout << p->value << "->";
            p = p->next;
        }
        cout << "NULL" <<  endl;
    }
};

int main(){
    DoubleLinkedList<int> dl;
    dl.addToLast(5);
    dl.addToLast(10);
    dl.addToLast(15);
    dl.print();

    dl.addToFirst(10);

    dl.print();

    int search;
    cout << "Enter value to search:\n Enter 0 for exit" << endl;
    cin >> search;
    while (search){
        cout << "Value " << search << " is: " << dl.search(search) <<endl;

        cout << "Enter value to search:\n Enter 0 for exit" << endl;
        cin >> search;
    }
}

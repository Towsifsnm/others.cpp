#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;
};

// Linked list class
class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = NULL;
    }

    // Insert a new node at the beginning of the list
    void insertAtBeginning(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    // Insert a new node at the end of the list
    void insertAtEnd(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Insert a new node at a given position in the list
    void insertAtPosition(int data, int position) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;

        if (position == 1) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 0; i < position - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Print the list
    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function
int main() {
    LinkedList list;

    cout << "Inserting 1 to 5 at the beginning of the list" << endl;
    list.insertAtBeginning(5);
    list.insertAtBeginning(4);
    list.insertAtBeginning(3);
    list.insertAtBeginning(2);
    list.insertAtBeginning(1);
    list.print();

    /*cout << "Inserting 6 to 10 at the end of the list" << endl;
    list.insertAtEnd(6);
    list.insertAtEnd(7);
    list.insertAtEnd(8);
    list.insertAtEnd(9);
    list.insertAtEnd(10);
    list.print();*/

    cout << "Inserting 7 at position 2" << endl;
    list.insertAtPosition(7, 2);
    list.print();

    return 0;
}

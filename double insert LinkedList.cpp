User
#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;
    Node* prev; // Pointer to the previous node
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
        newNode->prev = NULL; // Set previous pointer to NULL for the new head

        if (head != NULL) {
            head->prev = newNode; // Update previous pointer of the current head
        }

        head = newNode;
    }

    // Insert a new node at the end of the list
    void insertAtEnd(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Insert a new node at a given position in the list
    void insertAtPosition(int data, int position) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (position == 0) {
            newNode->next = head;
            if (head != NULL) {
                head->prev = newNode;
            }
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 0; i < position - 1; i++) {
                if (temp == NULL) {
                    cout << "Invalid position." << endl;
                    return;
                }
                temp = temp->next;
            }
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != NULL) {
                temp->next->prev = newNode;
            }
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
    cout << "after insert:" << endl;

    list.insertAtPosition(45, 0);
    list.insertAtPosition(98, 1);
    list.insertAtPosition(3, 2);
    list.insertAtPosition(4, 3);

    list.print();

    cout << "Inserting 7 at position 2" << endl;
    list.insertAtPosition(7, 2);
    list.print();

    return 0;
}

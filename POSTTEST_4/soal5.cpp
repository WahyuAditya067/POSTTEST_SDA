#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void exchangeHeadAndTail(Node*& head_ref) {
    // Hanya berjalan jika ada 2 node atau lebih dan tidak perlu tukar jika kurang dari 2 node
    if (head_ref == nullptr || head_ref->next == head_ref) return;

    Node* head = head_ref;
    Node* tail = head_ref->prev;

    // Kondisi jika hanya ada 2 node
    if (head->next == tail && tail->prev == head) {
        // tukar pointer 
        tail->next = head;
        tail->prev = head;
        head->next = tail;
        head->prev = tail;
        head_ref = tail;
        return;
    }

    // Simpan neighbor (head_next dan tail_prev) sebekum mengubah pointer
    Node* headNext = head->next;
    Node* tailPrev = tail->prev;

    // Update tail_prev <-> head <-> tail
    tailPrev->next = head;
    headNext->prev = tail;

    head->prev = tailPrev;
    head->next = tail;

    tail->prev = head;
    tail->next = headNext;

    //update head ref (tail lama menjadi head baru)
    head_ref = tail;
}

void printList(Node* head_ref) {
    if (head_ref == nullptr) {
        cout << "List kosong" << endl;
        return;
    }
    Node* current = head_ref;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

void insertEnd(Node*& head_ref, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    
    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }
    Node* tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    tail->next = newNode;
    head_ref->prev = newNode;
}

int main() {
    Node* head = nullptr;
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "List sebelum exchange: ";
    printList(head);

    exchangeHeadAndTail(head);

    cout << "List setelah exchange head dan tail: ";
    printList(head);

    return 0;
}
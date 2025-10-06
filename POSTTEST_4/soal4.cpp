#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void sortedInsert(Node*& head_ref, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    //Kasus 1 : jika list kosong, next dan prev node pertama akan menunjuk diri sendiri
    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    Node* current = head_ref;

    // Kasus 2 : data baru lebih kecil dari head jadi dimasukan ke awal (insert first) dan update head_ref
    if (data < head_ref->data) {
        newNode->next = head_ref;
        newNode->prev = head_ref->prev;
        head_ref->prev->next = newNode;
        head_ref->prev = newNode;
        head_ref = newNode;
        return;
    }

    // Kasus 3 : cari posisi sisip
    //1,2. menggunakan pointer current dari head ref dan loop while untuk pencarian posisi sesuai urutan elemem dari terkecil
    while (current->next != head_ref && current->next->data < data) {
        current = current->next;
    }

    // 3. Jika posisi sudah ditemukan, sisipkan new node di posisinya
    // 4. Update semua next dan prev 
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
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

int main() {
    Node* head = nullptr;
    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 40);
    sortedInsert(head, 20);
    cout << "Circular Doubly Linked List (sorted): ";
    printList(head);
    return 0;
}
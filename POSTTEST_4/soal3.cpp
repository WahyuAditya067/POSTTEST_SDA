#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;
    Node* next;
};

void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node();
    newNode->document = document;
    newNode->next = nullptr;

    //1. Jika queue kosong, node pertama menjadi front dan rear
    if (front == nullptr) {
        front = rear = newNode;
    //2. Jika tidak, sambungkan rear->next newnode dan update rear
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return "";

    //1. Simpan data dari front node sebelum menghapusnya
    Node* temp = front;
    string doc = temp->document;
    //2, Geser front ke front->next untuk memindahkan front ke node berikutnya
    front = front->next;

    //3. Jika queue kosong, set rear menjadi nullptr
    if (front == nullptr) {
        rear = nullptr;
    }

    //4. Hapus node lama dan kembalikan data 
    delete temp;
    return doc;
}

void processAllDocuments(Node*& front, Node*& rear) {
    //Loop hingga queue kosong lalu dequeue dan print setiap dokumen yang ada
    while (front != nullptr) {
        string doc = dequeue(front, rear);
        cout << "Memproses: " << doc << endl;
    }
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    return 0;
}
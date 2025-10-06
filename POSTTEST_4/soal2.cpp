#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

void push(Node*& top, char data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

char pop(Node*& top) {
    if (top == nullptr) return '\0';
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;

    //1. Periksa setiap karakter dalam expr 
    for (char c : expr) {
        // 2. Jika karakter adalah kurung buka, push karakter ke stack
        if (c == '(' || c == '{' || c == '[') {
            push(stackTop, c);
        }
        //3. Jika karakter adalah kurung tutup periksa :
        else if (c == ')' || c == '}' || c == ']') {
            //a. jika stack kosong, teturn false
            if (stackTop == nullptr) return false;
            //b. pop stack untuk mengecek apakah kurung buka cocok dengan kurung tutup
            //jika tidak sesuai, return false
            char topChar = pop(stackTop);
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false;
            }
        }
    }

    //4. Setelah loop selesai, jika stack kosong, return true
    //dan jika stack ada isinya, return false
    return stackTop == nullptr;
}

int main() {
    string expr1 = "{(())}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;

    string expr2 = "{(())}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;

    return 0;
}
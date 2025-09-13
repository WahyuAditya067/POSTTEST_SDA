#include <iostream>
using namespace std;

void tukar(int **a, int **b) {
    int temp = **a;
    **a = **b;
    **b = temp;
}

int main() {
    int x, y;
    cout << "Masukkan nilai x: ";
    cin >> x;
    cout << "Masukkan nilai y: ";
    cin >> y;

    int *px = &x;
    int *py = &y;

    cout << "Sebelum Tukar : " << endl;
    cout << " x = " << x << endl;
    cout << " y = " << y << endl;

    tukar(&px, &py);

    cout << "Sesudah Tukar : " << endl;
    cout << " x = " << x << endl;
    cout << " y = " << y << endl;

    return 0;
}

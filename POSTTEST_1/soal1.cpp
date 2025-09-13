#include <iostream>
using namespace std;

void balikarray(int *arr, int n) {
    int *awal = arr;
    int *akhir = arr + n - 1;
    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        awal++;
        akhir--;
    }
}

int main() {
    int data[7];
    for (int i = 0; i < 7; i++) {
        data[i] = (i + 1) * 3; 
    }

    cout << "Sebelum dibalik: ";
    for (int i = 0; i < 7; i++) cout << data[i] << " ";
    cout << endl;

    balikarray(data, 7);

    cout << "Sesudah dibalik: ";
    for (int i = 0; i < 7; i++) cout << data[i] << " ";
    cout << endl;

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int matriks[3][3];

    cout << "Masukkan elemen matriks 3x3:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Elemen [" << i + 1 << "][" << j + 1 << "] = ";
            cin >> matriks[i][j];
        }
    }

    int jumlahdiagonalutama = 0;
    int jumlahdiagonalsekunder = 0;

    for (int i = 0; i < 3; i++) {
        jumlahdiagonalutama += matriks[i][i];
        jumlahdiagonalsekunder += matriks[i][2 - i];
    }

    cout << "\nMatriks 3x3:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nJumlah diagonal utama   : " << jumlahdiagonalutama << endl;
    cout << "Jumlah diagonal sekunder: " << jumlahdiagonalsekunder << endl;
    cout << "Total keduanya          : " << jumlahdiagonalutama + jumlahdiagonalsekunder << endl;

    return 0;
}
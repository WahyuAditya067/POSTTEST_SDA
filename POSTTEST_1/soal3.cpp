#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
    float ipk;
};

int main() {
    Mahasiswa mhs[5];

    cout << "Input data 5 mahasiswa:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Mahasiswa ke-" << i+1 << endl;
        cout << "Nama : "; cin >> mhs[i].nama;
        cout << "NIM  : "; cin >> mhs[i].nim;
        cout << "IPK  : "; cin >> mhs[i].ipk;
    }

    int idxMax = 0;
    for (int i = 1; i < 5; i++) {
        if (mhs[i].ipk > mhs[idxMax].ipk) {
            idxMax = i;
        }
    }

    cout << "\nMahasiswa dengan IPK tertinggi:\n";
    cout << "Nama : " << mhs[idxMax].nama << endl;
    cout << "NIM  : " << mhs[idxMax].nim << endl;
    cout << "IPK  : " << mhs[idxMax].ipk << endl;

    return 0;
}

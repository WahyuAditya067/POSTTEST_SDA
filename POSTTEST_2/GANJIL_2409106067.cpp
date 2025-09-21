#include <iostream>
#include <string>
using namespace std;

struct Item {
    string namaitem;
    int jumlah;
    string tipe;
    Item * next;
};

void enter() {
    string lanjut;
    cout << "Enter Untuk Melanjutkan...";
    cin.ignore();
    cin.get();
    system("cls");
}

Item * head = nullptr;

const int jumlahawal = 67; 
const int posisitambah = 8; 

bool kosong() {
    return head == nullptr;
}

void tambahitem(string nama, string tipe) {
    Item * itembaru = new Item;
    itembaru->namaitem = nama;
    itembaru->tipe = tipe;
    itembaru->jumlah = jumlahawal;
    itembaru->next = nullptr;

    if (kosong()) {
        head = itembaru;
    } else {
        Item * temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = itembaru;
    }
    cout << "Item " << nama << " berhasil ditambahkan dengan jumlah " << jumlahawal << endl;
    enter();
}

void sisipkanitem(string nama, string tipe) {
    Item * itembaru = new Item;
    itembaru->namaitem = nama;
    itembaru->tipe = tipe;
    itembaru->jumlah = jumlahawal;
    itembaru->next = nullptr;

    if (posisitambah <= 1 || kosong()) {
        itembaru->next = head;
        head = itembaru;
        return;
    }

    Item * temp = head;
    int hitung = 1;
    while (temp != nullptr && hitung < posisitambah - 1) {
        temp = temp->next;
        hitung++;
    }

    if (temp == nullptr) {
        cout << ">> Item Masih Terlalu Sedikit <<" << endl;
    } else {
        itembaru->next = temp->next;
        temp->next = itembaru;
    }
    enter();
}

void hapusitem() {
    if (kosong()) {
        cout << "Inventory kosong" << endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        cout << "Item terakhir berhasil dihapus" << endl;
        return;
    }
    Item * temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    cout << "Item terakhir berhasil dihapus" << endl;
    enter();
}

void pakaiitem(string nama) {
    if (kosong()) {
        cout << "Inventory kosong" << endl;
        return;
    }

    Item * temp = head;
    Item * prev = nullptr;

    while (temp != nullptr && temp->namaitem != nama) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Item " << nama << " tidak ditemukan." << endl;
        return;
    }

    temp->jumlah--;

    cout << "Menggunakan 1 " << temp->namaitem << ". Sisa: " << temp->jumlah << endl;

    if (temp->jumlah <= 0) {
        cout << "Item " << temp->namaitem << " habis dan dihapus dari inventory." << endl;
        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
    }
    enter();
}

void tampilkaninventory() {
    if (kosong()) {
        cout << "Inventory kosong" << endl;
        return;
    }
    Item * temp = head;
    cout << "\n=== INVENTORY ===" << endl;
    while (temp != nullptr) {
        cout << temp->namaitem << " | Jumlah: " << temp->jumlah 
            << " | Tipe: " << temp->tipe << endl;
        temp = temp->next;
    }
    cout << "=================\n";
    enter();
}

void menu() {
    string pilihan;
    string nama, tipe;
    do {
        cout << "\n+---------------------------------------+" << endl;
        cout << "|      GAME INVENTORY MANAGEMENT        |" << endl;
        cout << "|          [ Wahyu - 067 ]              |" << endl;
        cout << "+---------------------------------------+" << endl;
        cout << "| 1. Tambah Item Baru                   |" << endl;
        cout << "| 2. Sisipkan Item                      |" << endl;
        cout << "| 3. Hapus Item Terakhir                |" << endl;
        cout << "| 4. Gunakan Item                       |" << endl;
        cout << "| 5. Tampilkan Inventory                |" << endl;
        cout << "| 0. Keluar                             |" << endl;
        cout << "+---------------------------------------+" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        enter();

        if (pilihan == "1") {
            cout << "Masukkan nama item: ";
            cin >> nama;
            cout << "Masukkan tipe item: ";
            cin >> tipe;
            tambahitem(nama, tipe);
        }
        else if (pilihan == "2") {
            cout << "Masukkan nama item: ";
            cin >> nama;
            cout << "Masukkan tipe item: ";
            cin >> tipe;
            sisipkanitem(nama, tipe);
        }
        else if (pilihan == "3") {        
            hapusitem();
        }
        else if (pilihan == "4") {
            cout << "Masukkan nama item yang ingin digunakan: ";
            cin >> nama;
            pakaiitem(nama);
        }
        else if (pilihan == "5") {
            tampilkaninventory();
        }
        else if (pilihan == "0") {
            cout << "Keluar dari program." << endl;
        }
        else {
            cout << "Pilihan tidak valid!" << endl;
            enter();
        }
    } while (pilihan != "0");
}

int main() {
    menu();
    return 0;
}

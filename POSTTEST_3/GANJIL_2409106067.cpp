#include <iostream>
#include <string>
using namespace std;

struct Item {
    string namaitem;
    int jumlah;
    string tipe;
    Item *next;
    Item *prev; 
};

Item *head = nullptr;
Item *tail = nullptr; 

const int jumlahawal = 67; 
const int posisitambah = 8;
int panjangList = 0; 

void enter() {
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.get();
    system("cls");
}

bool kosong() {
    return head == nullptr;
}

void tambahitem(string nama, string tipe) {
    Item *itembaru = new Item;
    itembaru->namaitem = nama;
    itembaru->tipe = tipe;
    itembaru->jumlah = jumlahawal;
    itembaru->next = nullptr;
    itembaru->prev = nullptr;

    if (kosong()) {
        head = itembaru;
        tail = itembaru;
    } else {
        tail->next = itembaru;
        itembaru->prev = tail;
        tail = itembaru;
    }
    
    panjangList++;
    cout << "\nItem '" << nama << "' berhasil ditambahkan dengan jumlah " << jumlahawal << endl;
    enter();
}

void sisipkanitem(string nama, string tipe) {
    if (posisitambah < 1 || posisitambah > panjangList + 1) {
        cout << "\nPosisi sisip tidak valid!" << endl;
        enter();
        return;
    }

    Item *itembaru = new Item;
    itembaru->namaitem = nama;
    itembaru->tipe = tipe;
    itembaru->jumlah = jumlahawal;
    itembaru->next = nullptr;
    itembaru->prev = nullptr;

    if (kosong() || posisitambah == 1) {
        itembaru->next = head;
        if (head != nullptr) {
            head->prev = itembaru;
        }
        head = itembaru;
        if (tail == nullptr) {
            tail = itembaru;
        }
    } else if (posisitambah == panjangList + 1) {
        tail->next = itembaru;
        itembaru->prev = tail;
        tail = itembaru;
    } else {
        Item *temp = head;
        for (int i = 1; i < posisitambah - 1; i++) {
            temp = temp->next;
        }
        itembaru->next = temp->next;
        itembaru->prev = temp;
        if (temp->next != nullptr) {
            temp->next->prev = itembaru;
        }
        temp->next = itembaru;
    }
    
    panjangList++;
    cout << "\nItem '" << nama << "' berhasil disisipkan di posisi " << posisitambah << endl;
    enter();
}

void hapusitem() {
    if (kosong()) {
        cout << "\nInventory kosong!" << endl;
        enter();
        return;
    }
    
    if (head == tail) {
        cout << "\nItem '" << tail->namaitem << "' berhasil dihapus" << endl;
        delete tail;
        head = nullptr;
        tail = nullptr;
    } else {
        Item *del = tail;
        tail = tail->prev;
        tail->next = nullptr;
        cout << "\nItem '" << del->namaitem << "' berhasil dihapus" << endl;
        delete del;
    }
    
    panjangList--;
    enter();
}

void pakaiitem(string nama) {
    if (kosong()) {
        cout << "\nInventory kosong!" << endl;
        enter();
        return;
    }

    Item *temp = head;

    while (temp != nullptr && temp->namaitem != nama) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "\nItem '" << nama << "' tidak ditemukan!" << endl;
        enter();
        return;
    }

    temp->jumlah--;

    cout << "\nMenggunakan 1 " << temp->namaitem << ". Sisa: " << temp->jumlah << endl;

    if (temp->jumlah <= 0) {
        cout << "Item '" << temp->namaitem << "' habis dan dihapus dari inventory!" << endl;
        
        if (temp == head && temp == tail) {
            head = nullptr;
            tail = nullptr;
        } else if (temp == head) {
            head = head->next;
            head->prev = nullptr;
        } else if (temp == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        
        delete temp;
        panjangList--;
    }
    enter();
}

void tampilkaninventory() {
    if (kosong()) {
        cout << "\nInventory kosong!" << endl;
        enter();
        return;
    }
    
    Item *temp = head;
    int i = 1;
    
    cout << "\n=== INVENTORY ===" << endl;
    while (temp != nullptr) {
        cout << i++ << ". " << temp->namaitem 
            << " | Jumlah: " << temp->jumlah 
            << " | Tipe: " << temp->tipe << endl;
        temp = temp->next;
    }
    cout << "=================" << endl;
    enter();
}

void tampilkanmundur() {
    if (kosong()) {
        cout << "\nInventory kosong!" << endl;
        enter();
        return;
    }
    
    Item *temp = tail;
    int i = panjangList;
    
    cout << "\n=== INVENTORY (MUNDUR) ===" << endl;
    while (temp != nullptr) {
        cout << i-- << ". " << temp->namaitem 
            << " | Jumlah: " << temp->jumlah 
            << " | Tipe: " << temp->tipe << endl;
        temp = temp->prev;
    }
    cout << "==========================" << endl;
    enter();
}

void tampilkandetail(string nama) {
    if (kosong()) {
        cout << "\nInventory kosong!" << endl;
        enter();
        return;
    }

    Item *temp = head;
    int posisi = 1;

    while (temp != nullptr && temp->namaitem != nama) {
        temp = temp->next;
        posisi++;
    }

    if (temp == nullptr) {
        cout << "\nItem '" << nama << "' tidak ditemukan!" << endl;
        enter();
        return;
    }

    cout << "\n=== DETAIL ITEM ===" << endl;
    cout << "Nama Item  : " << temp->namaitem << endl;
    cout << "Tipe       : " << temp->tipe << endl;
    cout << "Jumlah     : " << temp->jumlah << endl;
    cout << "Posisi     : " << posisi << endl;
    cout << "===================" << endl;
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
        cout << "| 6. Tampilkan Inventory (Mundur)       |" << endl;
        cout << "| 7. Cari Detail Item                   |" << endl;
        cout << "| 0. Keluar                             |" << endl;
        cout << "+---------------------------------------+" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == "1") {
            cout << "\n[ Tambah Item Baru ]" << endl;
            cout << "Masukkan nama item: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan tipe item: ";
            getline(cin, tipe);
            tambahitem(nama, tipe);
        }
        else if (pilihan == "2") {
            if (panjangList < posisitambah - 1) {
                cout << "\nItem masih terlalu sedikit untuk sisip di posisi " << posisitambah << endl;
                cout << "Minimal diperlukan " << (posisitambah - 1) << " item" << endl;
                cin.ignore();
                enter();
            } else {
                cout << "\n[ Sisipkan Item di Posisi " << posisitambah << " ]" << endl;
                cout << "Masukkan nama item: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan tipe item: ";
                getline(cin, tipe);
                sisipkanitem(nama, tipe);
            }
        }
        else if (pilihan == "3") {
            cin.ignore();
            hapusitem();
        }
        else if (pilihan == "4") {
            cout << "\n[ Gunakan Item ]" << endl;
            cout << "Masukkan nama item: ";
            cin.ignore();
            getline(cin, nama);
            pakaiitem(nama);
        }
        else if (pilihan == "5") {
            cin.ignore();
            tampilkaninventory();
        }
        else if (pilihan == "6") {
            cin.ignore();
            tampilkanmundur();
        }
        else if (pilihan == "7") {
            cout << "\n[ Cari Detail Item ]" << endl;
            cout << "Masukkan nama item: ";
            cin.ignore();
            getline(cin, nama);
            tampilkandetail(nama);
        }
        else if (pilihan == "0") {
            cout << "\nTerima kasih telah menggunakan program!" << endl;
        }
        else {
            cout << "\nPilihan tidak valid!" << endl;
            cin.ignore();
            enter();
        }
    } while (pilihan != "0");
}

int main() {
    menu();
    return 0;
}
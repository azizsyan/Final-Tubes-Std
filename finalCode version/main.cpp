#include "TuBes.h"
#include <iostream>

using namespace std;

int main() {
    Pegawai* head = NULL;
    int pilihan = 0;
    while (true){
        cout << "*****MENU MANAJEMEN PEGAWAI*****" << endl;
        cout << "--------------------------------" << endl;
        cout << "1. Tambah Pegawai" << endl;
        cout << "2. Edit Pegawai" << endl;
        cout << "3. Hapus Pegawai" << endl;
        cout << "4. Tampilkan Pegawai" << endl;
        cout << "5. Cari Pegawai berdasarkan ID" << endl;
        cout << "6. Cari Pegawai berdasarkan Nama" << endl;
        cout << "7. Keluar" << endl;
        cout << "--------------------------------" << endl;
        cout << "Pilih opsi : ";
        cin >> pilihan;

        if (pilihan < 1 || pilihan > 7) {
            cout << "Pilihan tidak valid! Silakan coba lagi." << endl;
        }

        if (pilihan == 1) {
            tambahPegawai(head);
        } else if (pilihan == 2) {
            cout << "Masukkan ID Pegawai yang ingin diedit: ";
            int id;
            cin >> id;
            editPegawai(head, id);
        } else if (pilihan == 3) {
            cout << "Masukkan ID Pegawai yang ingin dihapus: ";
            int id;
            cin >> id;
            hapusPegawai(head, id);
        } else if (pilihan == 4) {
            tampilkanPegawai(head);
        } else if (pilihan == 5) {
            cout << "Masukkan ID Pegawai yang ingin dicari: ";
            int id;
            cin >> id;
            cariPegawaiByID(head, id);
        } else if (pilihan == 6) {
            cout << "Masukkan Nama Pegawai yang ingin dicari: ";
            string nama;
            cin >> nama;
            cariPegawaiByName(head, nama);
        } else if (pilihan == 7) {
            cout <<  "Keluar dari program." << endl;
        }
    }
    return 0;
}

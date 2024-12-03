#include "TuBes.h"
#include <iostream>

using namespace std;

void tambahPegawai(Pegawai* &head) {
    Pegawai* newPegawai = new Pegawai;
    cout << "Masukkan Nama Pegawai: ";
    cin >> newPegawai->nama;
    cout << "Masukkan ID Pegawai: ";
    cin >> newPegawai->id;
    cout << "Masukkan Jabatan: ";
    cin >> newPegawai->jabatan;
    cout << "Masukkan Gaji: ";
    cin >> newPegawai->gaji;
    cout << "Masukkan Tanggal Bergabung (DD/MM/YYYY): ";
    cin >> newPegawai->tanggalBergabung;

    newPegawai->next = head;
    head = newPegawai;
}

Pegawai* cariPegawai(Pegawai* head, int id) {
    Pegawai* p = head;
    while (p != NULL) {
        if (p->id == id) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void editPegawai(Pegawai* head, int id) {
    Pegawai* pegawai = cariPegawai(head, id);
    if (pegawai) {
        cout << "Edit Nama Pegawai: ";
        cin >> pegawai->nama;
        cout << "Edit Jabatan: ";
        cin >> pegawai->jabatan;
        cout << "Edit Gaji: ";
        cin >> pegawai->gaji;
        cout << "Edit Tanggal Bergabung: ";
        cin >> pegawai->tanggalBergabung;
    } else {
        cout << "Pegawai tidak ditemukan!" << endl;
    }
}

void hapusPegawai(Pegawai* &head, int id) {
    Pegawai* p = head;
    Pegawai* q = NULL;

    while (p != NULL && p->id != id) {
        q = p;
        p = p->next;
    }

    if (p == NULL) {
        cout << "Pegawai tidak ditemukan!" << endl;
        return;
    }

    if (q == NULL) {
        head = p->next;
    } else {
        q->next = p->next;
    }

    p->next = NULL;
    cout << "Pegawai berhasil dihapus!" << endl;
}

void tampilkanPegawai(Pegawai* head) {
    Pegawai* p = head;
    cout << "Daftar Pegawai:" << endl;
    cout << "Nama                ID      Jabatan            Gaji       Tanggal Bergabung" << endl;
    cout << "---------------------------------------------------------------------------" << endl;

    while (p != NULL) {

        cout << p->nama;
        cout << string(20 - p->nama.length(), ' ');

        cout << p->id;
        cout << string(8 - to_string(p->id).length(), ' ');

        cout << p->jabatan;
        cout << string(20 - p->jabatan.length(), ' ');

        cout << (int)p->gaji << " ";
        cout << string(12 - (to_string((int)p->gaji).length() + 3), ' ');

        cout << p->tanggalBergabung << endl;
        p = p->next;
    }
    cout << endl;
}


void cariPegawaiByID(Pegawai* head, int id) {
    Pegawai* p = head;
    while (p != NULL) {
        if (p->id == id) {
            cout << "Pegawai ditemukan!" << endl;
            cout << "Nama: " << p->nama << endl;
            cout << "ID: " << p->id << endl;
            cout << "Jabatan: " << p->jabatan << endl;
            cout << "Gaji: " << p->gaji << endl;
            cout << "Tanggal Bergabung: " << p->tanggalBergabung << endl;
            return;
        }
        p = p->next;
    }
    cout << "Pegawai dengan ID " << id << " tidak ditemukan!" << endl;
}

void cariPegawaiByName(Pegawai* head, string &nama) {
    Pegawai* p = head;
    bool found = false;
    while (p != NULL) {
        if (p->nama == nama) {
            cout << "Pegawai ditemukan!" << endl;
            cout << "Nama: " << p->nama << endl;
            cout << "ID: " << p->id << endl;
            cout << "Jabatan: " << p->jabatan << endl;
            cout << "Gaji: " << p->gaji << endl;
            cout << "Tanggal Bergabung: " << p->tanggalBergabung << endl;
            found = true;
        }
        p = p->next;
    }
    if (!found) {
        cout << "Pegawai dengan nama " << nama << " tidak ditemukan!" << endl;
    }
}

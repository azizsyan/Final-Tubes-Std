#ifndef TUBES_H
#define TUBES_H

#include <iostream>
#include <string>

using namespace std;

struct Pegawai {
    string nama;
    int id;
    string jabatan;
    float gaji;
    string tanggalBergabung;
    Pegawai* next;
};

void tambahPegawai(Pegawai* &head);
void editPegawai(Pegawai* head, int id);
void hapusPegawai(Pegawai* &head, int id);
void tampilkanPegawai(Pegawai* head);
Pegawai* cariPegawai(Pegawai* head, int id);
void cariPegawaiByID(Pegawai* head, int id);
void cariPegawaiByName(Pegawai* head, string &nama);

#endif // TUBES_H

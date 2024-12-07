#include <iostream>

using namespace std;

// Address Initiator

typedef struct infotypeEmployee *adrEmployee;
typedef struct infotypeShift *adrShift;
typedef struct connector *adrConnector;

// Linked List initiator

struct shiftList {
    adrShift prev;
    infotypeShift info;
    adrShift next;
};

struct employeeList{
    infotypeEmployee info;
    adrEmployee next;
};

struct connectorList {
    adrEmployee employeeConnector;
    adrShift shiftConnector;
    adrConnector nextConnector;
};

// Infotype initiator 

struct infotypeEmployee {
    string name;
    int ID;
    string position;
    string salary;
    string joinedDate;
    bool isAdmin;
    string password;
};

struct infotypeShift {
    int date;
    int month;
    int year;
    timeFormat hourFrom;
    timeFormat hourTo;
};

// Extended Struct

struct timeFormat {
    int jam;
    int menit;
};

// Screen Function

int baseScreen() {
    cout << "====================================" << endl;
    cout << "    APLIKASI PENCATATAN PEGAWAI     " << endl;
    cout << "       PT. STRUKTUR DATA JAYA       " << endl;
    cout << "====================================" << endl;

    return 0;
}

int loginScreen(adrEmployee chunkUser){    
    if (chunkUser -> ID == NULL) {
        cout << "Saat ini anda belum login sebagai User" << endl;
        cout << "Harap login terlebih dahulu untuk menggunakan fitur yang lengkap";
    } else {
        cout << "Halo, saat ini anda masuk sebagai" << chunkUser -> name << endl;
    }

    // if (chunkUser -> position == NULL || chunkUser -> salary == NULL) {
    //     cout << "Data belum lengkap, harap lengkapi data" << endl;
    // }

    return 0;
}

int mainScreen() {
    cout << "Silahkan masukkan menu aplikasi yang ingin di gunakkan :" << endl;
    cout << "1. Menu Akun (Login/ Register)" << endl;
    cout << "2. Menu Pegawai" << endl;
    cout << "3. Menu Shift" << endl;
    cout << "4. Logout Instant" << endl;
    cout << "5. Keluar Aplikasi" << endl;
    cout << "Masukkan pilihan menu : " << endl;

    return 0;
}

int accountScreen() {
    cout << "Silahkan masukkan menu akun yang ingin di gunakkan :" << endl;
    cout << "1. Masuk" << endl;
    cout << "2. Register" << endl;
    cout << "3. Jadikan user admin (perlu akses akun admin)" << endl;
    cout << "4. Logout" << endl;
    cout << "5. Kembali ke halaman utama" << endl;
    cout << "Masukkan pilihan menu : " << endl;

    return 0;
}
int employeeScreen() {
    cout << "Silahkan masukkan menu pegawai yang ingin di gunakkan :" << endl;
    cout << "1. Tambah Pegawai" << endl;
    cout << "2. Edit data pegawai" << endl;
    cout << "3. Hapus data pegawai" << endl;
    cout << "4. Tampilkan pegawai" << endl;
    cout << "5. Cari data Pegawai" << endl;
    cout << "6. Kembali ke halaman utama" << endl;
    cout << "Masukkan pilihan menu : " << endl;

    return 0;
}

int shiftScreen() {
    cout << "Silahkan masukkan menu shift yang ingin di gunakkan :" << endl;
    cout << "1. Tambah shift" << endl;
    cout << "2. Hapus shift" << endl;
    cout << "3. Ubah data shift" << endl;
    cout << "4. Menambahkan orang ke shift" << endl;
    cout << "5. Kembali ke halaman utama" << endl;
    cout << "Masukkan pilihan menu : " << endl;
    cout << "" << endl;
    
    return 0;
}

// Login & Register Function Initiator

void loginUser(employeeList* &list, adrEmployee &session);

void registerUser(employeeList* &list, adrEmployee &session);

void logoutUser(employeeList* &List);

void adminModeratoring(employeeList* &List);

bool isLogin(adrEmployee chunkAccount);

// Employee Menu Function & Procedure Header Inititator

void addEmployee(employeeList* &list);

void deleteEmployee(employeeList* &list);

void editEmployee(employeeList* &list);

void searchEmployee(employeeList* &list);

void showEmployeeData(employeeList* &List);

// Shift Menu Function & Procedure Header Initiator

void addShift(shiftList* &shift);

void deleteShift(shiftList* &shift);

void showShiftData(shiftList* &shift);

void connectShiftEmployee(shiftList* &shift);

// Login & Register Function & Procedure 

void registerUser(employeeList &list, adrEmployee &session) {
    string chunkName;

    cout << "Silahkan masukkan data diri yang ingin di daftarkan : " << endl;
    cout << "Nama : ";
    cin >> 
}   
void loginUser(employeeList &list, adrEmployee &session) {

}
// Main

int main() {
    int serviceCode = 1;

    while (serviceCode >= 1 && serviceCode <= 3) {
        mainScreen();
        cin >> serviceCode;
        if (serviceCode == 1) {
            while (serviceCode >= 1 && serviceCode <= 4) {
                accountScreen();
                cin >> serviceCode;
                if (serviceCode == 1) {
                    registerUser()
                }
            }
        }

    }


    return 0;
}
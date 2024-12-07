#include <iostream>

using namespace std;

// Address Initiator

typedef struct employeElement *adrEmployee;
typedef struct shiftElement *adrShift;
typedef struct connectorElement *adrConnector;

// Linked List initiator

struct shiftElement {
    adrShift prev;
    infotypeShift info;
    adrShift next;
};

struct employeElement {
    infotypeEmployee info;
    adrEmployee* next;
};

struct connectorElement {
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
    if (chunkUser -> info.ID == NULL) {
        cout << "Saat ini anda belum login sebagai User" << endl;
        cout << "Harap login terlebih dahulu untuk menggunakan fitur yang lengkap";
    } else {
        cout << "Halo, saat ini anda masuk sebagai" << chunkUser -> info.name << endl;
    }

    // if (chunkUser -> info.position ==  NULL) {
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

// Basic SLL implementation - Employee

void createListEmployee(employeElement &list);

adrEmployee createElementEmployee(infotypeEmployee chunkInfo);

bool isEmptyEmployee(employeElement &list);

bool isDuplcateEmployee (employeElement &list, int &id);

void insertLast(employeElement &list, adrEmployee addedElement);

adrEmployee searchEmployeebyID (employeElement &list, int &id);

// Basic DLL implementation - Employee




// Login & Register Function Initiator

void registerUser(employeElement &list, adrEmployee &session);

void loginUser(employeElement &list, adrEmployee &session);

void logoutUser(employeElement &list, adrEmployee &session);

void adminModeratoring (employeElement &list, adrEmployee &session);

// bool isLogin(adrEmployee chunkAccount);

// Employee Menu Function & Procedure Header Inititator

void addEmployee(employeElement* &list);

void deleteEmployee(employeElement* &list);

void editEmployee(employeElement* &list);

void searchEmployee(employeElement* &list);

void showEmployeeData(employeElement* &List);

// Shift Menu Function & Procedure Header Initiator

void addShift(shiftElement* &shift);

void deleteShift(shiftElement* &shift);

void showShiftData(shiftElement* &shift);

void connectShiftEmployee(shiftElement* &shift);

// Basic SLL implementation - Employee

adrEmployee createElementEmployee(infotypeEmployee chunkInfo);



// Login & Register Function & Procedure

void registerUser(employeElement &list, adrEmployee &session) {
    infotypeEmployee chunkInfotype;
    string chunkPassword, chunkPassword2;
    int passwordCheckerSession = 1;
    bool duplicateStatus;
    adrEmployee chunkNewDataEmployee;
    
    // Input Phase
    
    cout << "Silahkan masukkan data diri yang ingin di daftarkan : " << endl;
    cout << "Nama : ";
    getline(cin, chunkInfotype.name);
    cout << "ID pegawai : ";
    cin >> chunkInfotype.ID;
    cout << "Password : ";
    getline(cin, chunkPassword);
    cout << "Masukkan kembali password : ";
    getline(cin, chunkPassword2);
    
    // Checking Password Phase
    while (chunkPassword != chunkPassword2 && passwordCheckerSession <= 3) {
        getline(cin, chunkPassword);
        cout << "Masukkan kembali password : ";
        getline(cin, chunkPassword2);
        passwordCheckerSession = passwordCheckerSession + 1;
    }
    
    // Check if there duplicate data or no

    duplicateStatus = isDuplcateEmployee(list, chunkInfotype.ID);
    
    // If Data password right

    if (chunkPassword == chunkPassword2 && passwordCheckerSession <= 3) {
        chunkInfotype.isAdmin = false;
        chunkInfotype.password = chunkPassword;
        
        chunkNewDataEmployee = createElementEmployee(chunkInfotype);
        
        session = chunkNewDataEmployee;

        cout << "Data berhasil tersimpan, dan user bisa menggunakan aplikasi" << endl;
        cout << "User harap melengkapi data diri di menu ubah data" << endl;
    } 
    
    // If data password data wrong

    else if (passwordCheckerSession >= 4) {
        cout << "Anda memasukkan password yang salah sebanyak 3 kali" << endl;
        cout << "Data tidak terfdaftar, silahkan kembali ke menu register user" << endl;
    }

    // if data duplicated

    else if (duplicateStatus == true) {
        cout << "Data ID yang dimasukkan sudah terdaftar" << endl;
        cout << "Silahkan masuk dengan ID tersebut, atau hubungi teknisi/ admin jika lupa password" << endl;
    }
}   
void loginUser(employeElement &list, adrEmployee &session) {
    int chunkEmployeeID;
    string chunkPassword;
    adrEmployee dataFound;

    // Input phase
    cout << "Masukkan ID pegawai : " << endl;
    cin >> chunkEmployeeID;
    cout << "Masukkan Password : " << endl;
    getline(cin, chunkPassword);

    // Check Phase

    dataFound = searchEmployeebyID(list, chunkEmployeeID);

    // Login Phase

    if (dataFound != NULL) {
        
        // If password right
        
        if (dataFound -> info.password == chunkPassword) {
            session = dataFound;

            cout << "Login berhasil, halo " << dataFound -> info.name << endl;
        } 

        // If password false

        else {
            cout << "Password salah silahkan coba lagi" << endl;
        }
    } 

    // If data not found

    else {
        cout << "Data dengan ID yang di masukkan tidak ditemukan" << endl;
        cout << "Silahkan daftar dengan menu daftar atau menu tambah pegawai" << endl;
    }
}

void logoutUser(employeElement &list, adrEmployee session) {
    // Logout phase

    session = NULL;
    cout << "Logout Sukses, untuk login gunakan fitur login kembali" << endl;
}

void adminModeratoring (employeElement &list, adrEmployee &session){
    // Check is admin or not
    if (session -> info.isAdmin == true) {
        cout << "Masukkan ID employee yang ingin di jadikan admin : " << endl;
        cin << chunkEmployeeID;
        
        dataFound = searchEmployeebyID(list, e)
    }
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
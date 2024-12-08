#include <iostream>

using namespace std;

// Address Initiator

typedef struct employeElement *adrEmployee;
typedef struct shiftElement *adrShift;
typedef struct connectorElement *adrConnector;

// Default variable 

string defaultPasswword = "Admin0"; 

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

    if (chunkUser -> info.position == "") {
        cout << "Data belum lengkap, harap lengkapi data" << endl;
    }

    if (chunkUser -> info.password == defaultPasswword) {
        cout << "Data kata sandi anda masih default, harap untuk segera mengganti kata sandi anda" << endl;
    }

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

int adminModeratoringScreen() {
    cout << "======================= !! KONFIRMASI !! ========================" << endl;
    cout << "          USER ID YANG DIMASUKKAN AKAN DI JADIKAN ADMIN          " << endl;
    cout << "   ID TERSEBUT AKAN BISA MENGUBAH SELURUH DATA PEGAWAI & SHIFT   " << endl;
    cout << " HARAP KONFIRMASI DENGAN MENULIS PASSWORD ANDA UNTUK MELANJUTKAN " << endl;
    cout << "=================================================================" << endl;
    cout << "Silahkan Masukkan Password anda : ";

    return 0;
}
// Basic SLL implementation - Employee

void createListEmployee(employeElement &list);

adrEmployee createElementEmployee(infotypeEmployee chunkInfo);

bool isEmptyEmployee(employeElement &list);

bool isDuplcateEmployee(employeElement &list, int &id);

void insertLastEmployee(employeElement &list, adrEmployee addedElement);

adrEmployee searchEmployeebyID(employeElement &list, int &id);

void deleteAfterEmployee(employeElement &list, adrEmployee prev);

// Basic DLL implementation - Employee




// Login & Register Function Initiator

void registerUser(employeElement &list, adrEmployee &session);

void loginUser(employeElement &list, adrEmployee &session);

void logoutUser(employeElement &list, adrEmployee session);

void adminModeratoring (employeElement &list, adrEmployee &session);

// bool isLogin(adrEmployee chunkAccount);

// Employee Menu Function & Procedure Header Inititator

void addEmployee(employeElement &list, adrEmployee &session);

void deleteEmployee(employeElement &list, adrEmployee &session);

void editEmployee(employeElement &list, adrEmployee &session);

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
    
    // Input Password Phase
    while (chunkPassword != chunkPassword2 && passwordCheckerSession <= 3) {
        getline(cin, chunkPassword);
        cout << "Masukkan kembali password : ";
        getline(cin, chunkPassword2);
        passwordCheckerSession = passwordCheckerSession + 1;
    }
    
    // Check if there duplicate data or no
    duplicateStatus = isDuplcateEmployee(list, chunkInfotype.ID);

    // Checking Password phase 
    if (chunkPassword == chunkPassword2 && passwordCheckerSession <= 3) { // If Data password right
        chunkInfotype.isAdmin = false;
        chunkInfotype.password = chunkPassword;
        
        chunkNewDataEmployee = createElementEmployee(chunkInfotype);
        
        session = chunkNewDataEmployee;

        cout << "Data berhasil tersimpan, dan user bisa menggunakan aplikasi" << endl;
        cout << "User harap melengkapi data diri di menu ubah data" << endl;
    } else if (passwordCheckerSession >= 4) { // If data password data wrong
        cout << "Anda memasukkan password yang salah sebanyak 3 kali" << endl;
        cout << "Data tidak terfdaftar, silahkan kembali ke menu register user" << endl;
    } else if (duplicateStatus == true) { // if data duplicated
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
        if (dataFound -> info.password == chunkPassword) { // If password right
            session = dataFound;

            cout << "Login berhasil, halo " << dataFound -> info.name << endl;
        } else { // If password false
            cout << "Password salah silahkan coba lagi" << endl;
        }
    } else { // If data not found
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
    int chunkEmployeeID;
    adrEmployee dataFound;
    string passwordConfirmation;

    // Check is admin or not
    if (session -> info.isAdmin == true) {
        cout << "Masukkan ID employee yang ingin di jadikan admin : " << endl;
        cin >> chunkEmployeeID;
        
        // Confirmation Policy
        adminModeratoringScreen();

        // Input password 
        cin >> passwordConfirmation;
        
        // Check Password
        if (passwordConfirmation == session -> info.password){
            // Searching data 
            dataFound = searchEmployeebyID(list, chunkEmployeeID);

            if (dataFound != NULL) { // If data found 
                session -> info.isAdmin = true;
                cout << "Data dengan ID : " << dataFound -> info.ID << " dan Nama : " << dataFound -> info.name << " Sudah menjadi admin" << endl;
                cout << "Jika itu adalah kesalahan, hapus data dan buat kembali" << endl;
            } else { // If data didn't found
                cout << "Data tidak di temukan, silahkan coba lagi" << endl;
            }
        } else { // If password admin false
            cout << "Password salah silahkan ulangi lagi" << endl;
        }
    } else { // IF session not admin
        cout << "Fitur ini hanya admin yang boleh menggunakan" << endl;
    }
}

// Employee Menu Function & Procedure 

void addEmployee(employeElement &list, adrEmployee &session) {
    infotypeEmployee chunkInfotype;
    adrEmployee chunkNewDataEmployee;

    // Check is in login condition
    if (session != NULL) {
        // Check is user can add employee
        if (session -> info.isAdmin != NULL) {
            // Input phase by Admin
            cout << "Silahkan masukkan data diri yang ingin di daftarkan : " << endl;
            cout << "Nama : ";
            getline(cin, chunkInfotype.name);
            cout << "ID pegawai : ";
            cin >> chunkInfotype.ID;
            cout << "Jabatan : ";
            cin >> chunkInfotype.position;
            cout << "Gaji : ";
            cin >> chunkInfotype.salary;
            cout << "Tanggal Bergabung : ";
            cin >> chunkInfotype.joinedDate;

            // Default value input
            chunkInfotype.password = defaultPasswword;
            chunkInfotype.isAdmin = false;
            
            // Make new element
            chunkNewDataEmployee = createElementEmployee(chunkInfotype);

            // Insert phase
            insertLastEmployee(list, chunkNewDataEmployee);

            // Message completed
            cout << "Data tersimpan, dan bisa langsung digunakan" << endl;
        } else { //If user cannot add employee
            cout << "Maaf sekali, untuk menambah pegawai, harus admin yang masuk" << endl;
        }
    } else { // If condition not login
        cout << "Anda harus login terlebih dahulu untuk menambah pegawai" << endl;
    }
}

void deleteEmployee(employeElement &list, adrEmployee &session) {
    string chunkPassword;
    int chunkEmployeeID;
    adrEmployee chunkAccount;

    // Check if login condition
    if (session == NULL) {
        // Input session
        cout << "Masukkan data pegawai yang datanya ingin di hapus : " << endl;
        cout << "ID Pegawai : ";
        cin >> chunkEmployeeID;
        
        // Search session
        chunkAccount = searchEmployeebyID(list, chunkEmployeeID);

        // If data founded
        if (chunkAccount != NULL) {
            // Check if user admin or not
            if (session -> info.isAdmin == true || chunkAccount == session) {
                // Confirmation phase
                cout << "Konfirmasi data akan di hapus dengan memasukkan password anda : " << endl;
                cin >> chunkPassword;
                
                // Check is the password same?
                if (chunkPassword == session -> info.password) {
                    deleteAfterEmployee(list, chunkAccount);
                } else { // If the password false
                    cout << "Password salah, konfirmasi gagal, harap coba lagi" << endl;
                }
            } else { // or user want to selfdelete the account
                cout << "Maaf untuk menghapus data pegawai yang dimasukkan perlu akses admin, silahkan hubungi admin IT" << endl;
            }
        } else { // If data didn't found
            cout << "Data tidak di temukan, harap coba lagi" << endl;
        }
    }
}   

void editEmployee(employeElement &list, adrEmployee &session) {
    // Check is user login or not
    if (session != NULL) {

    } else { // If user didnt login
        cout << "Anda harus login terlebih dahulu untuk mengubah data diri pegawai" << endl;
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
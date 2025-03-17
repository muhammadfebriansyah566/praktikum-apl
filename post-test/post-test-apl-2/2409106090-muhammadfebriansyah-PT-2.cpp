#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#define MAX_DATA 100 // Maksimum data yang bisa disimpan

// Array untuk menyimpan data robux
string robux[MAX_DATA][2]; // Kolom: Item, Harga
int totalRobux = 0;

// Fungsi untuk menampilkan robux (User & Admin View)
int tampilkanRobux() {
    if (totalRobux == 0) {
        cout << "\nTidak ada item robux tersedia.\n";
        return 0;
    }
    cout << "\n=======================================\n";
    cout << "| No |     Item      |    Harga     |";
    cout << "\n=======================================\n";
    for (int i = 0; i < totalRobux; i++) {
        cout << "| " << setw(2) << i + 1 << " | "
             << setw(12) << robux[i][0] << " | "
             << setw(12) << robux[i][1] << " |\n";
    }
    cout << "=======================================\n";
    return 1;
}

// Fungsi untuk menambahkan robux (Admin Only)
int tambahRobux() {
    if (totalRobux >= MAX_DATA) {
        cout << "Data penuh! Tidak bisa menambahkan lagi.\n";
        return 0;
    }
    cout << "\nMasukkan item robux: ";
    cin >> robux[totalRobux][0];
    cout << "Masukkan harga: ";
    cin >> robux[totalRobux][1];
    totalRobux++;
    cout << "Item robux berhasil ditambahkan!\n";
    return 1;
}

// Fungsi untuk menghapus robux (Admin Only)
int hapusRobux() {
    if (totalRobux == 0) {
        cout << "Tidak ada item yang bisa dihapus!\n";
        return 0;
    }
    int index;
    tampilkanRobux();
    cout << "Masukkan nomor item yang ingin dihapus: ";
    cin >> index;
    if (index > 0 && index <= totalRobux) {
        for (int i = index - 1; i < totalRobux - 1; i++) {
            robux[i][0] = robux[i + 1][0];
            robux[i][1] = robux[i + 1][1];
        }
        totalRobux--;
        cout << "Item robux berhasil dihapus!\n";
        return 1;
    } else {
        cout << "Nomor tidak valid!\n";
        return 0;
    }
}

// Fungsi untuk mengedit robux (Admin Only)
int editRobux() {
    if (totalRobux == 0) {
        cout << "Tidak ada item yang bisa diedit!\n";
        return 0;
    }
    int index;
    tampilkanRobux();
    cout << "Masukkan nomor item yang ingin diedit: ";
    cin >> index;
    if (index > 0 && index <= totalRobux) {
        cout << "Masukkan item baru: ";
        cin >> robux[index - 1][0];
        cout << "Masukkan harga baru: ";
        cin >> robux[index - 1][1];
        cout << "Item robux berhasil diperbarui!\n";
        return 1;
    } else {
        cout << "Nomor tidak valid!\n";
        return 0;
    }
}

// Fungsi untuk membeli robux (User Only)
int beliRobux() {
    if (totalRobux == 0) {
        cout << "Tidak ada item robux yang tersedia untuk dibeli.\n";
        return 0;
    }
    tampilkanRobux();
    int index;
    cout << "Masukkan nomor item yang ingin dibeli: ";
    cin >> index;
    if (index > 0 && index <= totalRobux) {
        cout << "Anda telah membeli " << robux[index - 1][0] << " seharga " << robux[index - 1][1] << " Robux.\n";
        return 1;
    } else {
        cout << "Nomor tidak valid!\n";
        return 0;
    }
}

int main() {
    string username, password;
    int kesempatan;
    bool loginSukses;
    bool isAdmin;
    
    while (true) {
        kesempatan = 3;
        loginSukses = false;
        isAdmin = false;
        
        while (kesempatan > 0) {
            cout << "\nMasukkan Username: ";
            cin >> username;
            cout << "Masukkan Password: ";
            cin >> password;
            
            if (username == "febri" && password == "2409106090") {
                loginSukses = true;
                isAdmin = true;
                break;
            } else if (username == "user" && password == "user123") {
                loginSukses = true;
                isAdmin = false;
                break;
            } else {
                kesempatan--;
                cout << "Username atau Password salah! Kesempatan tersisa: " << kesempatan << "\n";
            }
        }
        
        if (!loginSukses) {
            cout << "Anda telah gagal login 3 kali. Program berhenti.\n";
            return 0;
        }
        
        int pilihan;
        if (isAdmin) {
            do {
                cout << "\n===== Menu Admin =====\n";
                cout << "1. Tambah Robux\n";
                cout << "2. Tampilkan Robux\n";
                cout << "3. Edit Robux\n";
                cout << "4. Hapus Robux\n";
                cout << "5. Logout\n";
                cout << "6. Keluar dari Program\n";
                cout << "Pilihan Anda: ";
                cin >> pilihan;
                
                switch (pilihan) {
                    case 1: tambahRobux(); break;
                    case 2: tampilkanRobux(); break;
                    case 3: editRobux(); break;
                    case 4: hapusRobux(); break;
                    case 5: cout << "Logout... Kembali ke halaman login.\n"; break;
                    case 6: cout << "Keluar dari program...\n"; return 0;
                    default: cout << "Pilihan tidak valid!\n";
                }
            } while (pilihan != 5);
        } else {
            do {
                cout << "\n===== Menu User =====\n";
                cout << "1. Lihat Robux\n";
                cout << "2. Beli Robux\n";
                cout << "3. Logout dan Keluar Program\n";
                cout << "Pilihan Anda: ";
                cin >> pilihan;
                
                switch (pilihan) {
                    case 1: tampilkanRobux(); break;
                    case 2: beliRobux(); break;
                    case 3: cout << "Keluar dari program...\n"; return 0;
                    default: cout << "Pilihan tidak valid!\n";
                }
            } while (pilihan != 3);
        }
    }
}

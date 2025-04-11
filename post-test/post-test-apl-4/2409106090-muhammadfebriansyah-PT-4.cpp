#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#define MAX_DATA 100

struct RobuxItem {
    string nama;
    int harga;
    int stok;
};

RobuxItem robux[MAX_DATA];
int totalRobux = 0;

// ===== PROSEDUR DAN FUNGSI =====
void tambahRobux(RobuxItem data[], int &total) {
    if (total >= MAX_DATA) {
        cout << "Data penuh! Tidak bisa menambahkan lagi.\n";
        return;
    }
    cout << "\nMasukkan item robux: ";
    cin >> data[total].nama;
    cout << "Masukkan harga: ";
    cin >> data[total].harga;
    cout << "Masukkan stok: ";
    cin >> data[total].stok;
    total++;
    cout << "Item robux berhasil ditambahkan!\n";
}

void tampilkanRobux(const RobuxItem data[], int total) {
    if (total == 0) {
        cout << "\nTidak ada item robux tersedia.\n";
        return;
    }
    cout << "\n=================================================\n";
    cout << "| No |     Item      |   Harga   |   Stok   |\n";
    cout << "=================================================\n";
    for (int i = 0; i < total; i++) {
        cout << "| " << setw(2) << i + 1 << " | "
             << setw(12) << data[i].nama << " | "
             << setw(8) << data[i].harga << " | "
             << setw(7) << data[i].stok << " |\n";
    }
    cout << "=================================================\n";
}

void editRobux(RobuxItem data[], int total) {
    if (total == 0) {
        cout << "Tidak ada item yang bisa diedit!\n";
        return;
    }
    int index;
    cout << "Masukkan nomor item yang ingin diedit: ";
    cin >> index;
    if (index > 0 && index <= total) {
        cout << "Masukkan item baru: ";
        cin >> data[index - 1].nama;
        cout << "Masukkan harga baru: ";
        cin >> data[index - 1].harga;
        cout << "Masukkan stok baru: ";
        cin >> data[index - 1].stok;
        cout << "Item robux berhasil diperbarui!\n";
    } else {
        cout << "Nomor tidak valid!\n";
    }
}

void hapusRobux(RobuxItem data[], int &total) {
    if (total == 0) {
        cout << "Tidak ada item yang bisa dihapus!\n";
        return;
    }
    int index;
    cout << "Masukkan nomor item yang ingin dihapus: ";
    cin >> index;
    if (index > 0 && index <= total) {
        for (int i = index - 1; i < total - 1; i++) {
            data[i] = data[i + 1];
        }
        total--;
        cout << "Item robux berhasil dihapus!\n";
    } else {
        cout << "Nomor tidak valid!\n";
    }
}

void beliRobux(RobuxItem data[], int total) {
    if (total == 0) {
        cout << "Tidak ada item robux yang tersedia untuk dibeli.\n";
        return;
    }
    int index, jumlahBeli;
    cout << "Masukkan nomor item yang ingin dibeli: ";
    cin >> index;
    if (index > 0 && index <= total) {
        cout << "Masukkan jumlah yang ingin dibeli: ";
        cin >> jumlahBeli;
        if (jumlahBeli > 0 && jumlahBeli <= data[index - 1].stok) {
            data[index - 1].stok -= jumlahBeli;
            cout << "Anda telah membeli " << jumlahBeli << " " << data[index - 1].nama
                 << " seharga " << (data[index - 1].harga * jumlahBeli) << " Robux.\n";
        } else {
            cout << "Jumlah tidak valid atau stok tidak mencukupi!\n";
        }
    } else {
        cout << "Nomor tidak valid!\n";
    }
}

// ===== FUNGSI LOGIN =====
bool login(string user, string pass, bool &isAdmin) {
    if (user == "admin" && pass == "admin123") {
        isAdmin = true;
        return true;
    } else if (user == "febri" && pass == "2409106090") {
        isAdmin = false;
        return true;
    }
    return false;
}

// ===== MAIN PROGRAM =====
int main() {
    string username, password;
    int kesempatan;
    bool loginSukses;
    bool isAdmin;

    while (true) {
        kesempatan = 3;
        loginSukses = false;

        while (kesempatan > 0) {
            cout << "\nMasukkan Username: ";
            cin >> username;
            cout << "Masukkan Password: ";
            cin >> password;

            if (login(username, password, isAdmin)) {
                loginSukses = true;
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
                cout << "5. Logout dan Kembali ke Login\n";
                cout << "6. Keluar dari Program\n";
                cout << "Pilihan Anda: ";
                cin >> pilihan;

                switch (pilihan) {
                    case 1: tambahRobux(robux, totalRobux); break;
                    case 2: tampilkanRobux(robux, totalRobux); break;
                    case 3: editRobux(robux, totalRobux); break;
                    case 4: hapusRobux(robux, totalRobux); break;
                    case 5: cout << "Logout... Kembali ke halaman login.\n"; break;
                    case 6: cout << "Keluar dari program...\n"; return 0;
                    default: cout << "Pilihan tidak valid!\n"; break;
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
                    case 1: tampilkanRobux(robux, totalRobux); break;
                    case 2: beliRobux(robux, totalRobux); break;
                    case 3: cout << "Keluar dari program...\n"; return 0;
                    default: cout << "Pilihan tidak valid!\n"; break;
                }
            } while (pilihan != 3);
        }
    }
}

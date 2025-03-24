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

            if (username == "admin" && password == "admin123") {
                loginSukses = true;
                isAdmin = true;
                break;
            } else if (username == "febri" && password == "2409106090") {
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
                cout << "5. Logout dan Kembali ke Login\n";
                cout << "6. Keluar dari Program\n";
                cout << "Pilihan Anda: ";
                cin >> pilihan;

                if (pilihan == 1) {
                    if (totalRobux >= MAX_DATA) {
                        cout << "Data penuh! Tidak bisa menambahkan lagi.\n";
                    } else {
                        cout << "\nMasukkan item robux: ";
                        cin >> robux[totalRobux].nama;
                        cout << "Masukkan harga: ";
                        cin >> robux[totalRobux].harga;
                        cout << "Masukkan stok: ";
                        cin >> robux[totalRobux].stok;
                        totalRobux++;
                        cout << "Item robux berhasil ditambahkan!\n";
                    }
                } else if (pilihan == 2) {
                    if (totalRobux == 0) {
                        cout << "\nTidak ada item robux tersedia.\n";
                    } else {
                        cout << "\n=================================================\n";
                        cout << "| No |     Item      |   Harga   |   Stok   |\n";
                        cout << "=================================================\n";
                        for (int i = 0; i < totalRobux; i++) {
                            cout << "| " << setw(2) << i + 1 << " | "
                                 << setw(12) << robux[i].nama << " | "
                                 << setw(8) << robux[i].harga << " | "
                                 << setw(7) << robux[i].stok << " |\n";
                        }
                        cout << "=================================================\n";
                    }
                } else if (pilihan == 3) {
                    if (totalRobux == 0) {
                        cout << "Tidak ada item yang bisa diedit!\n";
                    } else {
                        int index;
                        cout << "Masukkan nomor item yang ingin diedit: ";
                        cin >> index;
                        if (index > 0 && index <= totalRobux) {
                            cout << "Masukkan item baru: ";
                            cin >> robux[index - 1].nama;
                            cout << "Masukkan harga baru: ";
                            cin >> robux[index - 1].harga;
                            cout << "Masukkan stok baru: ";
                            cin >> robux[index - 1].stok;
                            cout << "Item robux berhasil diperbarui!\n";
                        } else {
                            cout << "Nomor tidak valid!\n";
                        }
                    }
                } else if (pilihan == 4) {
                    if (totalRobux == 0) {
                        cout << "Tidak ada item yang bisa dihapus!\n";
                    } else {
                        int index;
                        cout << "Masukkan nomor item yang ingin dihapus: ";
                        cin >> index;
                        if (index > 0 && index <= totalRobux) {
                            for (int i = index - 1; i < totalRobux - 1; i++) {
                                robux[i] = robux[i + 1];
                            }
                            totalRobux--;
                            cout << "Item robux berhasil dihapus!\n";
                        } else {
                            cout << "Nomor tidak valid!\n";
                        }
                    }
                } else if (pilihan == 5) {
                    cout << "Logout... Kembali ke halaman login.\n";
                } else if (pilihan == 6) {
                    cout << "Keluar dari program...\n";
                    return 0;
                } else {
                    cout << "Pilihan tidak valid!\n";
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

                if (pilihan == 1) {
                    if (totalRobux == 0) {
                        cout << "\nTidak ada item robux tersedia.\n";
                    } else {
                        cout << "\n=================================================\n";
                        cout << "| No |     Item      |   Harga   |   Stok   |\n";
                        cout << "=================================================\n";
                        for (int i = 0; i < totalRobux; i++) {
                            cout << "| " << setw(2) << i + 1 << " | "
                                 << setw(12) << robux[i].nama << " | "
                                 << setw(8) << robux[i].harga << " | "
                                 << setw(7) << robux[i].stok << " |\n";
                        }
                        cout << "=================================================\n";
                    }
                } else if (pilihan == 2) {
                    if (totalRobux == 0) {
                        cout << "Tidak ada item robux yang tersedia untuk dibeli.\n";
                    } else {
                        int index, jumlahBeli;
                        cout << "Masukkan nomor item yang ingin dibeli: ";
                        cin >> index;
                        if (index > 0 && index <= totalRobux) {
                            cout << "Masukkan jumlah yang ingin dibeli: ";
                            cin >> jumlahBeli;
                            if (jumlahBeli > 0 && jumlahBeli <= robux[index - 1].stok) {
                                robux[index - 1].stok -= jumlahBeli;
                                cout << "Anda telah membeli " << jumlahBeli << " " << robux[index - 1].nama
                                     << " seharga " << (robux[index - 1].harga * jumlahBeli) << " Robux.\n";
                            } else {
                                cout << "Jumlah tidak valid atau stok tidak mencukupi!\n";
                            }
                        } else {
                            cout << "Nomor tidak valid!\n";
                        }
                    }
                } else if (pilihan == 3) {
                    cout << "Keluar dari program...\n";
                    return 0;
                } else {
                    cout << "Pilihan tidak valid!\n";
                }
            } while (pilihan != 3);
        }
    }
}

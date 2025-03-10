#include <iostream>
using namespace std;

bool login() {
    string username = "febri";
    string password = "2409106090";
    string user, pass;
    int attempts = 3;

    while (attempts > 0) {
        cout << "Masukkan Username: ";
        cin >> user;

        cout << "Masukkan Password: ";
        cin >> pass;

        if (user == username && pass == password) {
            cout << "Login Berhasil!\n" << endl;
            return true;
        } else {
            attempts--;
            cout << "Login Gagal! Sisa percobaan: " << attempts << "\n" << endl;
        }
    }

    cout << "Anda telah gagal login 3 kali. Program berhenti." << endl;
    return false;
}

int konversi_mata_uang() {
    int pilihan;
    double jumlah, hasil;
    const double kurs_usd = 0.000065; // 1 Rupiah = 0.000065 USD (contoh)
    const double kurs_euro = 0.000059; // 1 Rupiah = 0.000059 Euro (contoh)

    while (true) {
        cout << "\nKonversi Mata Uang:\n";
        cout << "1. Rupiah ke Dolar AS\n";
        cout << "2. Rupiah ke Euro\n";
        cout << "3. Dolar AS ke Rupiah\n";
        cout << "4. Dolar AS ke Euro\n";
        cout << "5. Euro ke Rupiah\n";
        cout << "6. Euro ke Dolar AS\n";
        cout << "7. Kembali\n";

        cout << "Pilih opsi: ";
        cin >> pilihan;
        if (pilihan == 7) return 0;

        cout << "Masukkan jumlah: ";
        cin >> jumlah;

        switch (pilihan) {
            case 1: hasil = jumlah * kurs_usd; cout << "Hasil: $" << hasil << " USD\n"; break;
            case 2: hasil = jumlah * kurs_euro; cout << "Hasil: €" << hasil << " Euro\n"; break;
            case 3: hasil = jumlah / kurs_usd; cout << "Hasil: " << hasil << " Rupiah\n"; break;
            case 4: hasil = (jumlah / kurs_usd) * kurs_euro; cout << "Hasil: €" << hasil << " Euro\n"; break;
            case 5: hasil = jumlah / kurs_euro; cout << "Hasil: " << hasil << " Rupiah\n"; break;
            case 6: hasil = (jumlah / kurs_euro) * kurs_usd; cout << "Hasil: $" << hasil << " USD\n"; break;
            default: cout << "Pilihan tidak valid.\n";
        }
    }
}

int konversi_jarak() {
    int pilihan;
    double jumlah, hasil;

    while (true) {
        cout << "\nKonversi Jarak:\n";
        cout << "1. Kilometer ke Meter\n";
        cout << "2. Kilometer ke Centimeter\n";
        cout << "3. Meter ke Kilometer\n";
        cout << "4. Meter ke Centimeter\n";
        cout << "5. Centimeter ke Kilometer\n";
        cout << "6. Centimeter ke Meter\n";
        cout << "7. Kembali\n";

        cout << "Pilih opsi: ";
        cin >> pilihan;
        if (pilihan == 7) return 0;

        cout << "Masukkan jumlah: ";
        cin >> jumlah;

        switch (pilihan) {
            case 1: hasil = jumlah * 1000; cout << "Hasil: " << hasil << " Meter\n"; break;
            case 2: hasil = jumlah * 100000; cout << "Hasil: " << hasil << " Centimeter\n"; break;
            case 3: hasil = jumlah / 1000; cout << "Hasil: " << hasil << " Kilometer\n"; break;
            case 4: hasil = jumlah * 100; cout << "Hasil: " << hasil << " Centimeter\n"; break;
            case 5: hasil = jumlah / 100000; cout << "Hasil: " << hasil << " Kilometer\n"; break;
            case 6: hasil = jumlah / 100; cout << "Hasil: " << hasil << " Meter\n"; break;
            default: cout << "Pilihan tidak valid.\n";
        }
    }
}

int konversi_waktu() {
    int pilihan;
    double jumlah, hasil;

    while (true) {
        cout << "\nKonversi Waktu:\n";
        cout << "1. Jam ke Menit\n";
        cout << "2. Jam ke Detik\n";
        cout << "3. Menit ke Jam\n";
        cout << "4. Menit ke Detik\n";
        cout << "5. Detik ke Jam\n";
        cout << "6. Detik ke Menit\n";
        cout << "7. Kembali\n";

        cout << "Pilih opsi: ";
        cin >> pilihan;
        if (pilihan == 7) return 0;

        cout << "Masukkan jumlah: ";
        cin >> jumlah;

        switch (pilihan) {
            case 1: hasil = jumlah * 60; cout << "Hasil: " << hasil << " Menit\n"; break;
            case 2: hasil = jumlah * 3600; cout << "Hasil: " << hasil << " Detik\n"; break;
            case 3: hasil = jumlah / 60; cout << "Hasil: " << hasil << " Jam\n"; break;
            case 4: hasil = jumlah * 60; cout << "Hasil: " << hasil << " Detik\n"; break;
            case 5: hasil = jumlah / 3600; cout << "Hasil: " << hasil << " Jam\n"; break;
            case 6: hasil = jumlah / 60; cout << "Hasil: " << hasil << " Menit\n"; break;
            default: cout << "Pilihan tidak valid.\n";
        }
    }
}

int menu_utama() {
    int pilihan;
    while (true) {
        cout << "\nMenu Utama:\n";
        cout << "1. Konversi Mata Uang\n";
        cout << "2. Konversi Jarak\n";
        cout << "3. Konversi Waktu\n";
        cout << "4. Logout\n";

        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) konversi_mata_uang();
        else if (pilihan == 2) konversi_jarak();
        else if (pilihan == 3) konversi_waktu();
        else if (pilihan == 4) {
            cout << "Logout Berhasil. Terima kasih!\n";
            return 0;
        } else {
            cout << "Pilihan tidak valid, silakan coba lagi.\n";
        }
    }
}

int main() {
    if (login()) {
        menu_utama();
    }
    return 0;
}

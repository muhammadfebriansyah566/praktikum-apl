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
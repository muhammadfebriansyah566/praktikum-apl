#include "iostream"

using namespace std;
#define MAX_BUAH 100 // Ukuran maksimum array buah
int panjang = 0; // Jumlah elemen saat ini
int arr [max];
int pilihan, index;





int main() {
    while(true){
        cout << "Menu Program" << endl;
        cout << "1. Tampilkan Buah" << endl;
        cout << "2. Tambah Buah" << endl;
        cout << "3. Ubah Buah" << endl;
        cout << "4. Hapus Buah" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
    
        cin >> pilihan;

    
        if (pilihan == 1){
            if (panjangarey < max){
                cout << "masukkan data : "
                cin >> arr[panjangarey]
            }
        }
        
    
    }

    



   // string name[]={"andi","budi","caca","deni","evis"}
   // int panjang - sizeof(name) / sizeof (name[0]);

    //cout << name[-5] << endl

   // for (string x : name){
   //     cout << x << endl;
   // }

   int matriks[2][2] = {
    {1, 2},
    {3, 4}
    };
    
    cout << matriks[0][0] << endl;

    int main() {
        int arr[3][3][3] = {
        {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
        },
        {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
        },
        {
        {19, 20, 21},
        {22, 23, 24},
        {25, 26, 27}
        }
        };
        cout << arr[1][2][1] << endl; // Output: 17
        return 0;
        }
        





    return 0;
}
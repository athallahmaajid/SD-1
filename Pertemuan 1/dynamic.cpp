#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Masukkan " << n << " Angka: " << endl;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Isi array: " << endl;
    for (int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }

    delete[] arr;
    return 0;
}
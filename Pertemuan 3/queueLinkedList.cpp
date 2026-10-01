#include <iostream>
#include <queue>
using namespace std;


int main() {
    queue<int> q;
    int input;

    // Input berhenti ketika input bukan angka
    while (cin >> input) {
        q.push(input);
    }

    // Mengeluarkan semua data dari queue
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;

    return 0;
}
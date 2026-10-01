#include <iostream>
#include <string>
using namespace std;

#define MAX 100
char stack[MAX];
int top = -1;

void push (char value) {
    if (top == MAX - 1){
        cout << "Stack Penuh !\n";
    } else {
        top++;
        stack[top] = value;
        cout << value << " ditambahkan dlm stack\n";
    }
}

void display () {
    if (top == -1 ){
        cout << "Stack kosong\n";
    } else {
        cout << "\nIsi dari stack:\n";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main () {
    string a;
    cin >> a;
    for (int i=0; i < a.length(); i++) {
        push(a[i]);
    }
    // push('A');
    // push('L');
    // push('Y');
    // push('A');

    display();

    return 0;
}

#include <iostream>
using namespace std;

#define MAX 5
int stack[MAX];
int top = -1;

void push (int value) {
    if (top == MAX - 1){
        cout << "Stack Penuh !\n";
    } else {
        top++;
        stack[top] = value;
        cout << value << " ditambahkan dlm stack\n";
    }
}
void pop () {
    if (top == -1) {
        cout << "Stack kosong! \n";
    } else {
        cout << "\n" << stack[top] << " dihapus dari stack\n";
        top--;
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
    push(50);
    push(40);
    push(30);
    push(20);
    push(10);

    display();
    pop();
    display();

    return 0;
}

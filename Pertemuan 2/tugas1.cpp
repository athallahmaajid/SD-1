#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void insertFirst(int n) {
    Node *newNode = new Node;
    newNode -> value = n;
    newNode -> next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    }
    else {
        newNode -> next = head;
        head = newNode;
    }
}

void insertLast(int n) {
    Node *newNode = new Node;
    newNode -> value = n;
    newNode -> next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    }
    else {
        tail -> next = newNode;
        tail = newNode;
    }
}

void insertAfter(int n, int check) {
    if (head == NULL) {
        cout << "List kosong, silahkan insert di depan \n";
        return;
    }
    Node *newNode = new Node;
    newNode -> value = n;
    newNode -> next = NULL;

    Node *temp = head;
    while(temp != NULL && temp -> value != check) {
        temp = temp -> next;
    }
    if (temp == NULL) {
        cout << "Node dengan nilai " << check << " tdk ketemu\n";
        delete newNode;
    } else {
        newNode -> next = temp -> next;
        temp -> next = newNode;
        if (temp == tail) {
            tail = newNode;
        }
    }
}

void printList() {
    Node *temp = head;
    cout << "Isi dari linked list : ";
    while(temp != NULL) {
        cout << temp -> value << " -> ";
        temp = temp -> next;
    }
    cout << "NULL\n";
}

void deleteFirst() {
    if (head == NULL) {
        cout << "gbs" << endl;
        return;
    }
    Node *temp = head;
    head = head -> next;
    if (head == NULL) tail = NULL;
    delete temp;
}

void deleteLast() {
    if (head == NULL) {
        cout << "gbs" << endl;
        return;
    }
    if (head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }
    Node *temp = head;
    while(temp -> next != tail) {
        temp = temp -> next;
    }
    delete tail;
    tail = temp;
    tail -> next = NULL;
}

void deleteMiddle(int value) {
    if (head == NULL) {
        cout << "gbs" << endl;
        return;
    }

    if (head -> value == value) {
        deleteFirst();
        return;
    }
    if (tail -> value == value) {
        deleteLast();
        return;
    }
    Node *p = head;
    while(p -> next != NULL && p -> next -> value != value) {
        p = p -> next;
    }
    
    if (p -> next == NULL) {
        cout << "Node dengan nilai " << value << " tidak ketemu" << endl;
        return;
    } else {
        Node *temp = p -> next;
        p -> next = temp -> next;
        if (temp == tail) tail = p;
        delete temp;
    }
}

void menu() {
    cout << "\n========== MENU LINKED LIST ==========\n";
    cout << "1. Insert First\n";
    cout << "2. Insert Last\n";
    cout << "3. Insert After\n";
    cout << "4. Delete First\n";
    cout << "5. Delete Last\n";
    cout << "6. Delete Middle (berdasarkan nilai)\n";
    cout << "7. Print List\n";
    cout << "0. Keluar\n";
    cout << "======================================\n";
    cout << "Pilih menu: ";
}

int main () {
int pilihan;
    int nilai;
    int check;

    do {
        menu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;

                insertFirst(nilai);
                cout << "Node berhasil ditambahkan di depan.\n";
                break;

            case 2:
                cout << "Masukkan nilai: ";
                cin >> nilai;

                insertLast(nilai);
                cout << "Node berhasil ditambahkan di belakang.\n";
                break;

            case 3:
                cout << "Masukkan nilai node baru: ";
                cin >> nilai;

                cout << "Masukkan nilai node yang dicari: ";
                cin >> check;

                insertAfter(nilai, check);
                break;

            case 4:
                deleteFirst();
                cout << "Node pertama berhasil dihapus.\n";
                break;

            case 5:
                deleteLast();
                cout << "Node terakhir berhasil dihapus.\n";
                break;

            case 6:
                cout << "Masukkan nilai node yang ingin dihapus: ";
                cin >> nilai;

                deleteMiddle(nilai);
                break;

            case 7:
                printList();
                break;

            case 0:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    return 0;
}
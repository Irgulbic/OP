//Matyukhin Pavel 
//�����-02-22

#include <iostream>
#include <string>
using namespace std;

// ��������� ������
struct Item {
    string name;
    int quantity;
    double price;
};

// ����� ��� ������ �� �������
class List {
private:
    // ��������� ���� ������
    struct Node {
        Item data;
        Node* next;
    };
    Node* head; // ��������� �� ������ ������
public:
    // �����������
    List() {
        head = nullptr; // �������������� ������ ������ ��� nullptr
    }

    // ����������
    ~List() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    // ������� ���������� �������� � ����� ������
    void addItem(Item data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // ������� ���������� �������� � ������ ������
    void addItemAtStart(Item data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    // ������� ���������� �������� ����� ��������� ��������
    void addItemAfter(string name, Item data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        Node* current = head;
        while (current != nullptr) {
            if (current->data.name == name) {
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        cout << "Element with name " << name << " not found" << endl;
    }

    // ������� ���������� �������� ����� �������� ���������
    void addItemBefore(string name, Item data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        if (head->data.name == name) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->data.name == name) {
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        cout << "Element with name " << name << " not found" << endl;
    }

    // ������� �������� �������� � �������� ������
    void deleteItem(string name) {
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr) {
            if (current->data.name == name) {
                if (previous == nullptr) {
                    head = current->next;
                }
                else {
                    previous->next = current->next;
                }
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        }
        cout << "Element with name " << name << " not found" << endl;
    }

    // ������� ������ ���������� ������ �� �����
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << "Name: " << current->data.name << endl;
            cout << "Quantity: " << current->data.quantity << endl;
            cout << "Price: " << current->data.price << endl;
            cout << "------------------------" << endl;
            current = current->next;
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    List myList;

    // ��������� �������� � ������
    Item item1 = { "��� ������������", 10, 80.5 };
    myList.addItem(item1);

    Item item2 = { "������", 5, 45.3 };
    myList.addItem(item2);

    Item item3 = { "����", 2, 30.0 };
    myList.addItemAfter("������", item3);

    Item item4 = { "���", 1, 250.7 };
    myList.addItemBefore("����", item4);

    // ������� ���������� ������
    myList.display();

    // ������� ������� �� ������
    myList.deleteItem("������");

    // ������� ���������� ������ �����
    myList.display();

    return 0;
}
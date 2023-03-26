//Matyukhin Pavel 
//НПИбд-02-22

#include <iostream>
#include <string>
using namespace std;

// Структура данных
struct Item {
    string name;
    int quantity;
    double price;
};

// Класс для работы со списком
class List {
private:
    // Структура узла списка
    struct Node {
        Item data;
        Node* next;
    };
    Node* head; // Указатель на начало списка
public:
    // Конструктор
    List() {
        head = nullptr; // Инициализируем голову списка как nullptr
    }

    // Деструктор
    ~List() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    // Функция добавления элемента в конец списка
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

    // Функция добавления элемента в начало списка
    void addItemAtStart(Item data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    // Функция добавления элемента после заданного элемента
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

    // Функция добавления элемента перед заданным элементом
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

    // Функция удаления элемента с заданным именем
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

    // Функция вывода содержания списка на экран
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

    // Добавляем элементы в список
    Item item1 = { "Сок апельсиновый", 10, 80.5 };
    myList.addItem(item1);

    Item item2 = { "Молоко", 5, 45.3 };
    myList.addItem(item2);

    Item item3 = { "Хлеб", 2, 30.0 };
    myList.addItemAfter("Молоко", item3);

    Item item4 = { "Сыр", 1, 250.7 };
    myList.addItemBefore("Хлеб", item4);

    // Выводим содержание списка
    myList.display();

    // Удаляем элемент из списка
    myList.deleteItem("Молоко");

    // Выводим содержание списка снова
    myList.display();

    return 0;
}
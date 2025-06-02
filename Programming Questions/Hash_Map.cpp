#include <iostream>
#include <vector>
using namespace std;

// Custom node structure for each entry
struct Node {
    int key, value;
    Node* next;
    Node(int k, int v) {
        key = k;
        value = v;
        next = nullptr;
    }
};

class MyHashMap {
private:
    static const int SIZE = 10007; // A prime number to reduce collisions
    vector<Node*> table;

    // Hash function
    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashMap() {
        table.resize(SIZE, nullptr);
    }

    void put(int key, int value) {
        int idx = hash(key);
        Node* head = table[idx];

        Node* temp = head;
        while (temp != nullptr) {
            if (temp->key == key) {
                temp->value = value; // Update existing key
                return;
            }
            temp = temp->next;
        }

        // Insert new node at beginning
        Node* newNode = new Node(key, value);
        newNode->next = head;
        table[idx] = newNode;
    }

    int get(int key) {
        int idx = hash(key);
        Node* temp = table[idx];

        while (temp != nullptr) {
            if (temp->key == key) return temp->value;
            temp = temp->next;
        }

        return -1; // Key not found
    }

    void remove(int key) {
        int idx = hash(key);
        Node* temp = table[idx];
        Node* prev = nullptr;

        while (temp != nullptr) {
            if (temp->key == key) {
                if (prev == nullptr) {
                    table[idx] = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }
};

int main() {
    MyHashMap obj;

    obj.put(1, 10);
    obj.put(2, 20);

    cout << obj.get(1) << endl;  // Output: 10
    cout << obj.get(3) << endl;  // Output: -1 (not found)

    obj.put(2, 30);              // Update key 2
    cout << obj.get(2) << endl;  // Output: 30

    obj.remove(2);               // Remove key 2
    cout << obj.get(2) << endl;  // Output: -1 (now removed)

    return 0;
}

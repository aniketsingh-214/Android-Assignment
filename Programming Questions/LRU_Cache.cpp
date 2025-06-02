#include <iostream>
#include <unordered_map>
using namespace std;

// Doubly linked list node
struct Node {
    int key, value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cacheMap;
    Node* head;
    Node* tail;

    // Helper to remove a node from the list
    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* afterNode = node->next;

        prevNode->next = afterNode;
        afterNode->prev = prevNode;
    }

    // Helper to insert a node right after head (most recently used)
    void insertAfterHead(Node* node) {
        Node* currAfterHead = head->next;

        head->next = node;
        node->prev = head;

        node->next = currAfterHead;
        currAfterHead->prev = node;
    }

public:
    // Constructor
    LRUCache(int cap) {
        capacity = cap;

        // Create dummy head and tail nodes
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;

        cacheMap.clear();
    }

    // Get the value from the cache
    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1;
        }

        Node* node = cacheMap[key];
        deleteNode(node);           // Remove from current position
        insertAfterHead(node);      // Move to front as most recently used

        return node->value;
    }

    // Put key-value pair into cache
    void put(int key, int value) {
        // If key already exists, update and move to front
        if (cacheMap.find(key) != cacheMap.end()) {
            Node* node = cacheMap[key];
            node->value = value;

            deleteNode(node);
            insertAfterHead(node);
        }
        else {
            // Check if capacity exceeded
            if (cacheMap.size() == capacity) {
                Node* lruNode = tail->prev; // Least recently used node
                cacheMap.erase(lruNode->key);
                deleteNode(lruNode);
                delete lruNode;
            }

            // Insert new node at front
            Node* newNode = new Node(key, value);
            insertAfterHead(newNode);
            cacheMap[key] = newNode;
        }
    }
};

int main() {
    LRUCache lru(2);

    lru.put(1, 1);
    lru.put(2, 2);
    cout << lru.get(1) << endl;  // returns 1

    lru.put(3, 3);               // evicts key 2
    cout << lru.get(2) << endl;  // returns -1 (not found)

    lru.put(4, 4);               // evicts key 1
    cout << lru.get(1) << endl;  // returns -1 (not found)
    cout << lru.get(3) << endl;  // returns 3
    cout << lru.get(4) << endl;  // returns 4

    return 0;
}

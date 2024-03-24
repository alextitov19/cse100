#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Node structure for linked list
struct Node
{
    int key;
    Node *next;
    Node(int k) : key(k), next(nullptr) {}
};

// Chained hash table class
class ChainedHashTable
{
private:
    vector<Node *> table;
    int size;

public:
    // Constructor to initialize hash table with given size
    ChainedHashTable(int m) : size(m)
    {
        table.resize(size, nullptr);
    }

    // Destructor to free memory
    ~ChainedHashTable()
    {
        for (int i = 0; i < size; ++i)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
    }

    // Hash function
    int hash(int key)
    {
        return key % size;
    }

    // Insert operation
    void insert(int key)
    {
        int index = hash(key);
        Node *newNode = new Node(key);
        newNode->next = table[index];
        table[index] = newNode;
    }

    // Delete operation
    void remove(int key)
    {
        int index = hash(key);
        Node *current = table[index];
        Node *prev = nullptr;

        while (current != nullptr && current->key != key)
        {
            prev = current;
            current = current->next;
        }

        if (current != nullptr)
        {
            if (prev != nullptr)
                prev->next = current->next;
            else
                table[index] = current->next;

            delete current;
            cout << key << ":DELETED;" << endl;
        }
        else
        {
            cout << key << ":DELETE_FAILED;" << endl;
        }
    }

    // Search operation
    void search(int key)
    {
        int index = hash(key);
        Node *current = table[index];
        int count = 0;

        while (current != nullptr && current->key != key)
        {
            current = current->next;
            count++;
        }

        if (current != nullptr)
        {
            cout << key << ":FOUND_AT" << index << "," << count << ";" << endl;
        }
        else
        {
            cout << key << ":NOT_FOUND;" << endl;
        }
    }

    // Output operation
    void output()
    {
        for (int i = 0; i < size; ++i)
        {
            cout << i << ":";
            Node *current = table[i];
            while (current != nullptr)
            {
                cout << current->key << "->";
                current = current->next;
            }
            cout << ";" << endl;
        }
    }
};

int main()
{
    int m;
    cin >> m;
    cin.ignore(); // Clear the newline character from input buffer
    ChainedHashTable hashTable(m);
    string line;

    while (getline(cin, line))
    {
        istringstream iss(line);
        char op;
        int key;
        iss >> op >> key;

        switch (op)
        {
        case 'i':
            hashTable.insert(key);
            break;
        case 'd':
            hashTable.remove(key);
            break;
        case 's':
            hashTable.search(key);
            break;
        case 'o':
            hashTable.output();
            break;
        case 'e':
            return 0;
        }
    }

    return 0;
}

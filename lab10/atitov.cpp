#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

struct Node
{
    char data;
    int freq;
    Node *left, *right;

    Node(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

struct compare
{
    bool operator()(Node *l, Node *r)
    {
        return l->freq > r->freq;
    }
};

void generateCodes(Node *root, string code, map<char, string> &codes)
{
    if (root == nullptr)
        return;

    if (!root->left && !root->right)
    {
        codes[root->data] = code;
    }

    generateCodes(root->left, code + "0", codes);

    generateCodes(root->right, code + "1", codes);
}

map<char, string> buildHuffmanTree(int freq[])
{
    priority_queue<Node *, vector<Node *>, compare> pq;

    for (int i = 0; i < 6; ++i)
    {
        if (freq[i] > 0)
        {
            Node *newNode = new Node('A' + i, freq[i]);
            pq.push(newNode);
        }
    }

    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        Node *newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    map<char, string> codes;
    generateCodes(pq.top(), "", codes);

    return codes;
}

int main()
{
    int freq[6];
    for (int i = 0; i < 6; ++i)
    {
        cin >> freq[i];
    }

    map<char, string> huffmanCodes = buildHuffmanTree(freq);

    for (auto it = huffmanCodes.begin(); it != huffmanCodes.end(); ++it)
    {
        cout << it->first << ":" << it->second << endl;
    }

    return 0;
}

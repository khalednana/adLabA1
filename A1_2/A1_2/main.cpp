//
//  main.cpp
//  A1_2
//
//  Created by Khaled  Nana  on 04/03/2024.
//

#include <iostream>
#include <queue>
#include <stack>
#include <map>
using namespace std;

#define MAX_SIZE 100 // Maximum Height of Huffman Tree.
class HuffmanTreeNode {
public:
    
    char data; // Stores character
    int freq; // Stores frequency of the character
    HuffmanTreeNode* left; // Left child of the current node
    HuffmanTreeNode* right; // Right child of the current node

    HuffmanTreeNode(char character, int frequency) // Initializing the current node
    {
        data = character;
        freq = frequency;
        left = right = NULL;
    }
};

// Custom compare class
class Compare {
public:
    bool operator()(HuffmanTreeNode* a, HuffmanTreeNode* b)
    {   // Defining priority on the basis of frequency
        return a->freq > b->freq;
    }
};

// Function to generate Huffman Encoding Tree

HuffmanTreeNode* generateTree(priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, Compare> pq)
{
    // We keep on looping till only one node remains in the Priority Queue
    while (pq.size() != 1) {
        HuffmanTreeNode* ni = pq.top();
        pq.pop();
        
        HuffmanTreeNode* nj = pq.top();
        pq.pop();
        // Create a new symbol (could be anything, it won't be used)
        char newSymbol = '$'; // Or any other character
        // with the new frequency = pi+pj (we are only concerned with the frequency)
        int newFreq = ni->freq + nj->freq;

        
        // A new node is formed with the new symbol and frequency

        HuffmanTreeNode* newNode = new HuffmanTreeNode(newSymbol, newFreq);

        // set the left and right children of the newly formed node to be ni and nj
        newNode->left = ni;
        newNode->right = nj;

        // Push back node created to the Priority Queue
        pq.push(newNode);
    }
    // The Priority Queue should have one element: the entire Tree
    return pq.top();
}




void printCodes(HuffmanTreeNode* root) {
    if (!root)
        return;

    // Create a map to store Huffman codes
    map<HuffmanTreeNode*, string> huffmanCodes;

    // Initialize the stack for iterative traversal
    stack<HuffmanTreeNode*> stk;
    stk.push(root);
    huffmanCodes[root] = ""; // Initialize root's code as empty

    while (!stk.empty()) {
        HuffmanTreeNode* curr = stk.top();
        stk.pop();

        // If it's a leaf node, print the character and its code
        if (!curr->left && !curr->right) {
            cout << curr->data << ": " << huffmanCodes[curr] << endl;
        }

         // Push left child (if exists) with updated code
        if (curr->left) {
            huffmanCodes[curr->left] = huffmanCodes[curr] + "0";
            stk.push(curr->left);
        }
        // Push right child (if exists) with updated code
        if (curr->right) {
            huffmanCodes[curr->right] = huffmanCodes[curr] + "1";
            stk.push(curr->right);
        }
    }
}

void HuffmanCodes(char data[], int freq[], int size)
{
    // Declaring priority queue using custom comparator
    priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, Compare> pq;

    // Populating the priority queue
    for (int i = 0; i < size; i++) {
        HuffmanTreeNode* newNode = new HuffmanTreeNode(data[i], freq[i]);
        pq.push(newNode);
    }

    // Generate Huffman Encoding Tree and get the root node
    HuffmanTreeNode* root = generateTree(pq);

    // Print Huffman Codes
    int arr[MAX_SIZE], top = 0;
    printCodes(root);//, arr, top);
}

// Driver Code
int main()
{
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(data) / sizeof(data[0]);

    HuffmanCodes(data, freq, size);
    return 0;
}

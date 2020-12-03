#pragma once
#include <iostream> 
#include <cstdlib> 

using namespace std;

// This constant can be avoided by explicitly 
// calculating height of Huffman Tree 
#define MAX_TREE_HT 100 

struct Node {

    char data;
    unsigned freq;
    struct Node* left, * right;
};

struct HufTree {

    unsigned size;
    unsigned capacity;
    struct Node** array;
};

struct Node* newNode(char data, unsigned freq);

struct HufTree* createMinHeap(unsigned capacity);

void swapMinHeapNode(struct Node** a, struct Node** b);

void minHeapify(struct HufTree* minHeap, int idx);

int isSizeOne(struct HufTree* minHeap);

struct Node* extractMin(struct HufTree* minHeap);

void insertMinHeap(struct HufTree* minHeap, struct Node* minHeapNode);

void buildMinHeap(struct HufTree* minHeap);

void printArr(int arr[], int n);

int isLeaf(struct Node* root);

struct HufTree* createAndBuildMinHeap(char data[], int freq[], int size);
 
struct Node* buildHuffmanTree(char data[], int freq[], int size);

void printCodes(struct Node* root, int arr[], int top);

void HuffmanCodes(char data[], int freq[], int size);
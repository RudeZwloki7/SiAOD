#include "HufTree.h"


struct Node* newNode(char data, unsigned freq){

    struct Node* temp
        = (struct Node*)malloc
        (sizeof(struct Node));

    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;

    return temp;
}

struct HufTree* createMinHeap(unsigned capacity) {

    struct HufTree* minHeap
        = (struct HufTree*)malloc(sizeof(struct HufTree));

    minHeap->size = 0;

    minHeap->capacity = capacity;

    minHeap->array
        = (struct Node**)malloc(minHeap->
            capacity * sizeof(struct Node*));
    return minHeap;
}

void swapMinHeapNode(struct Node** a, struct Node** b) {

    struct Node* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct HufTree* minHeap, int idx) {

    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->
        freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->
        freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest],
            &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(struct HufTree* minHeap){

    return (minHeap->size == 1);
}

struct Node* extractMin(struct HufTree* minHeap){

    struct Node* temp = minHeap->array[0];
    minHeap->array[0]
        = minHeap->array[minHeap->size - 1];

    --minHeap->size;
    minHeapify(minHeap, 0);

    return temp;
}

void insertMinHeap(struct HufTree* minHeap, struct Node* minHeapNode){

    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {

        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct HufTree* minHeap){

    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

void printArr(int arr[], int n){
    int i;
    for (i = 0; i < n; ++i)
        cout << arr[i];

    cout << "\n";
}

int isLeaf(struct Node* root) {

    return !(root->left) && !(root->right);
}

struct HufTree* createAndBuildMinHeap(char data[], int freq[], int size) {

    struct HufTree* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}

struct Node* buildHuffmanTree(char data[], int freq[], int size) {

    struct Node* left, * right, * top;

    struct HufTree* minHeap = createAndBuildMinHeap(data, freq, size);

    while (!isSizeOne(minHeap)) {

        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

void printCodes(struct Node* root, int arr[], int top) {

    if (root->left) {

        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {

        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (isLeaf(root)) {

        cout << root->data << ": ";
        printArr(arr, top);
    }
}

void HuffmanCodes(char data[], int freq[], int size) {

    struct Node* root = buildHuffmanTree(data, freq, size);

    int arr[MAX_TREE_HT], top = 0;

    printCodes(root, arr, top);
}

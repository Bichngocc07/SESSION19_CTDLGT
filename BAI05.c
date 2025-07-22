//
// Created by Owner on 7/22/2025.
//
#include <stdio.h>
#include <stdlib.h>

// Cấu trúc node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Tạo node mới
Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Hàm tìm giá trị lớn nhất (đệ quy)
int findMax(Node* root) {
    if (root == NULL)
        return -999999; // giá trị nhỏ để so sánh

    int maxLeft = findMax(root->left);
    int maxRight = findMax(root->right);
    int maxRoot = root->data;

    // Trả về giá trị lớn nhất trong 3 nhánh
    int max = maxLeft > maxRight ? maxLeft : maxRight;
    return maxRoot > max ? maxRoot : max;
}

int main() {
    // Tạo cây theo bài 1
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    // Tìm giá trị lớn nhất
    int maxValue = findMax(root);
    printf("Max value: %d\n", maxValue);

    return 0;
}

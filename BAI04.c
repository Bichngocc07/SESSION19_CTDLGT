//
// Created by Owner on 7/22/2025.
//
#include <stdio.h>
#include <stdlib.h>

// Cấu trúc Node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Hàm tạo node mới
Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàm đếm số lá (node không có con)
int countLeaves(Node* root) {
    if (root == NULL) return 0;

    // Nếu không có con trái và con phải => là node lá
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Gọi đệ quy cho nhánh trái và phải
    return countLeaves(root->left) + countLeaves(root->right);
}

// Duyệt theo mức để hiển thị cây (tuỳ chọn)
void levelOrder(Node* root) {
    if (root == NULL) return;

    Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        Node* current = queue[front++];
        printf("%d ", current->data);
        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }
}

int main() {
    // Tạo cây theo hình ảnh đề bài
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    // Hiển thị cây (tuỳ chọn)
    printf("Cay theo thu tu muc: ");
    levelOrder(root);
    printf("\n");

    // Đếm số lá
    int leaves = countLeaves(root);
    printf("Number of leaves: %d\n", leaves);

    return 0;
}

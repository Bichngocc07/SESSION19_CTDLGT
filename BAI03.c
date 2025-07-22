//
// Created by Owner on 7/22/2025.
//
#include <stdio.h>
#include <stdlib.h>

// Cấu trúc Node của cây nhị phân
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Tạo node mới
Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàm thêm phần tử vào cây (Level-order)
void addValue(Node* root, int value) {
    if (root == NULL) return;

    // Tạo queue đơn giản
    Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        Node* current = queue[front++];

        // Nếu trái trống → thêm tại đây
        if (current->left == NULL) {
            current->left = createNode(value);
            return;
        } else {
            queue[rear++] = current->left;
        }

        // Nếu phải trống → thêm tại đây
        if (current->right == NULL) {
            current->right = createNode(value);
            return;
        } else {
            queue[rear++] = current->right;
        }
    }
}

// Hàm duyệt theo mức để kiểm tra kết quả
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
    // Dữ liệu đầu vào ban đầu từ bài 1
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    printf("Truoc khi them:\n");
    levelOrder(root);
    printf("\n");

    // Thêm giá trị mới
    addValue(root, 6);

    printf("Sau khi them:\n");
    levelOrder(root);
    printf("\n");

    return 0;
}

//
// Created by Owner on 7/22/2025.
//

Linh
//KHỞI TẠO CÂY NHỊ PHÂN
//CÁC BƯỚC KHỞI TẠO CÂY NHỊ PHÂN
//BƯỚC 1 : XAC ĐỊNH CẤU TRÚC NODE
//BƯỚC 2 : HÀM TẠO NODE MỚI
//BƯỚC 3 : TẠO GỐC CHO CÂY NHỊ PHÂN
//BƯỚC 4 : LIÊN KET CÁC NHÁNH CUẢ CÂY
//BƯỚC 5 : DUYỆT CÂY ĐÊ HIỂN THỊ CÁC NÚT TRONG CÂY


//BƯỚC 1 : XAC ĐỊNH CẤU TRÚC NODE
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

//BƯỚC 2 : HÀM TẠO NODE MỚI
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}
int main (){
    //BƯỚC 3 : TẠO GỐC CHO CÂY NHỊ PHÂN
    Node* root = createNode(2);
    //BƯỚC 4 : LIÊN KET CÁC NHÁNH CUẢ CÂY
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    //BƯỚC 5 : DUYỆT CÂY ĐÊ HIỂN THỊ CÁC NÚT TRONG CÂY
    printf(" Duyet cay dung DFS theo cach inOder\n");
    inOrder(root);
    //in : vào , out : ra , last : muộn , first : trước => LIFO : vào muộn ra trước


}
//Duyet cay có 2 cách duyệt : duyệt theo chiều rộng và sâu
//DFS : là duyệt theo chiều sâu có 3 cách : preorder : gốc -> trái -> phải
//inorder : trái -> gốc -> phải
//postorder : trái -> phải-> gốc
//BFS : là duyệt theo chiều rộng (duyet theo từng cấp level)
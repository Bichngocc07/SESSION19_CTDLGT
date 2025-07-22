//
// Created by Owner on 7/22/2025.
//
#include <stdio.h>
#include <stdlib.h>

// Buoc 1: Khai bao cau truc Node
typedef struct Node {
    int gia_tri;
    struct Node* trai;
    struct Node* phai;
} Node;

// Buoc 2: Tao Node moi
Node* taoNode(int gia_tri) {
    Node* moi = (Node*) malloc(sizeof(Node));
    moi->gia_tri = gia_tri;
    moi->trai = NULL;
    moi->phai = NULL;
    return moi;
}

// Buoc 3: Chen gia tri vao cay nhi phan theo BST
Node* chen(Node* goc, int gia_tri) {
    if (goc == NULL) return taoNode(gia_tri);
    if (gia_tri < goc->gia_tri)
        goc->trai = chen(goc->trai, gia_tri);
    else if (gia_tri > goc->gia_tri)
        goc->phai = chen(goc->phai, gia_tri);
    return goc;
}

// Buoc 4: Duyet tien tu (Goc → Trai → Phai)
void duyetTienTu(Node* goc) {
    if (goc != NULL) {
        printf("%d ", goc->gia_tri);
        duyetTienTu(goc->trai);
        duyetTienTu(goc->phai);
    }
}

// Buoc 4: Duyet trung tu (Trai → Goc → Phai)
void duyetTrungTu(Node* goc) {
    if (goc != NULL) {
        duyetTrungTu(goc->trai);
        printf("%d ", goc->gia_tri);
        duyetTrungTu(goc->phai);
    }
}

// Buoc 4: Duyet hau tu (Trai → Phai → Goc)
void duyetHauTu(Node* goc) {
    if (goc != NULL) {
        duyetHauTu(goc->trai);
        duyetHauTu(goc->phai);
        printf("%d ", goc->gia_tri);
    }
}

// Buoc 4d: Duyet theo muc (Breadth-First Search)
typedef struct HangDoi {
    Node* du_lieu[100];
    int dau, cuoi;
} HangDoi;

void khoiTaoHangDoi(HangDoi* q) {
    q->dau = q->cuoi = 0;
}

int rong(HangDoi* q) {
    return q->dau == q->cuoi;
}

void them(HangDoi* q, Node* node) {
    q->du_lieu[q->cuoi++] = node;
}

Node* layRa(HangDoi* q) {
    return q->du_lieu[q->dau++];
}

void duyetTheoMuc(Node* goc) {
    HangDoi q;
    khoiTaoHangDoi(&q);
    if (goc != NULL) them(&q, goc);
    while (!rong(&q)) {
        Node* hien_tai = layRa(&q);
        printf("%d ", hien_tai->gia_tri);
        if (hien_tai->trai) them(&q, hien_tai->trai);
        if (hien_tai->phai) them(&q, hien_tai->phai);
    }
}

// Ham main
int main() {
    Node* goc = NULL;
    int mang[] = {10, 6, 15, 3, 8, 12, 20};
    int n = sizeof(mang) / sizeof(mang[0]);

    for (int i = 0; i < n; i++) {
        goc = chen(goc, mang[i]);
    }

    printf("Duyet tien tu: ");
    duyetTienTu(goc);
    printf("\n");

    printf("Duyet trung tu: ");
    duyetTrungTu(goc);
    printf("\n");

    printf("Duyet hau tu: ");
    duyetHauTu(goc);
    printf("\n");

    printf("Duyet theo muc: ");
    duyetTheoMuc(goc);
    printf("\n");

    return 0;
}

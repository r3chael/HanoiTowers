#include <iostream>
#include <stdio.h>
#define BOYUT 5

int kule1[BOYUT], kule2[BOYUT], kule3[BOYUT];
int top1 = -1, top2 = -1, top3 = -1; 

void push(int kule[], int* top, int disk) {
    if (*top == BOYUT - 1) {
        printf("Hata: Kule dolu!\n");
    }
    else {
        (*top)++;
        kule[*top] = disk;
    }
}


int pop(int kule[], int* top) {
    if (*top == -1) {
        printf("Hata: Kule bos!\n");
        return -1;
    }
    else {
        int disk = kule[*top];
        (*top)--;
        return disk;
    }
}

int bak(int kule[], int top) {
    if (top == -1) return 999;
    return kule[top];
}

void goster(int kule[], int top) {
    for (int i = 0; i <= top; i++) {
        printf("%d ", kule[i]);
    }
    printf("\n");
}

int main() {

    printf("Hanoi Kulelerine Hosgeldiniz...\nAmaciniz 1. kuledeki halkalari 3. kuleye tasimak!\nNot: Kucuk halkanin ustune buyuk halka gelemez...\n");

    push(kule1, &top1, 5);
    push(kule1, &top1, 4);
    push(kule1, &top1, 3);
    push(kule1, &top1, 2);
    push(kule1, &top1, 1);
    goster(kule1, top1);
    goster(kule2, top2);
    goster(kule3, top3);

    
    while (true) {
        if (kule3[0] == 5 && kule3[1] == 4 && kule3[2] == 3 && kule3[3] == 2 && kule3[4] == 1) {
            printf("Tebrikler! Kazandiniz!!!");
            break;
        }

        int alSecim, verSecim;
        printf("\nAlinacak Kule (1-3): ");
        scanf_s("%d", &alSecim);
        printf("Verilecek Kule (1-3): ");
        scanf_s("%d", &verSecim);

        int* alTop, * verTop, * alKule, * verKule;

        if (alSecim == 1) { alKule = kule1; alTop = &top1; }
        else if (alSecim == 2) { alKule = kule2; alTop = &top2; }
        else if (alSecim == 3) { alKule = kule3; alTop = &top3; }
        else { printf("Gecersiz kule!\n"); continue; }

        if (verSecim == 1) { verKule = kule1; verTop = &top1; }
        else if (verSecim == 2) { verKule = kule2; verTop = &top2; }
        else if (verSecim == 3) { verKule = kule3; verTop = &top3; }
        else { printf("Gecersiz kule!\n"); continue; }

        if (*alTop == -1) {
            printf("HATA: Sectiginiz kule bos!\n");
        }
        else {
            int tasinan = alKule[*alTop]; 
            int hedefUst = bak(verKule, *verTop); 

            if (tasinan < hedefUst) { 
                pop(alKule, alTop);
                push(verKule, verTop, tasinan);
                printf("Hamle Basarili!\n");
            }
            else {
                printf("HATA: Buyuk disk, kucuk diskin uzerine gelemez!\n");
            }
        }
        printf("\nHamle sonrasi:\n");
        goster(kule1, top1);
        goster(kule2, top2);
        goster(kule3, top3);

    }

    return 0;
}



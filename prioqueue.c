/*
Rizky Ramadhana P. K.
13520151
Kamis, 7 Oktober 2021
File ini merupakan realisasi dari prioqueue.h
*/

#include <stdio.h>
#include <stdlib.h>
#include "prioqueue.h"
#include "boolean.h"

/* *** Kreator *** */
void CreatePrioQueue(PrioQueue *pq){
/* I.S. sembarang */
/* F.S. Sebuah pq kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah pq kosong */
    IDX_HEAD(*pq) = IDX_UNDEF;
    IDX_TAIL(*pq) = IDX_UNDEF;
}

boolean isEmpty(PrioQueue pq){
/* Mengirim true jika pq kosong: lihat definisi di atas */
    return (IDX_HEAD(pq)==IDX_UNDEF) && (IDX_TAIL(pq)==IDX_UNDEF);
}

boolean isFull(PrioQueue pq){
/* Mengirim true jika tabel penampung elemen pq sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */
    return (IDX_HEAD(pq)==0) && (IDX_TAIL(pq)==CAPACITY-1);
}

int length(PrioQueue pq){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika pq kosong. */
    //kamus
    int l;
    //algoritma
    if(isEmpty(pq)){
        l=0;
    } else {
        l=IDX_TAIL(pq)-IDX_HEAD(pq)+1;
    }
    return l;
}

/*** Primitif Add/Delete ***/
void enqueue(PrioQueue *pq, ElType val){
/* Proses: Menambahkan val pada pq dengan aturan FIFO */
/* I.S. pq mungkin kosong, tabel penampung elemen pq TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen pq
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
    //kamus
    int geser,i,j;
    boolean found;
    //algoritma
    if(isEmpty(*pq)){ //queue kosong
        IDX_HEAD(*pq)=0;
        IDX_TAIL(*pq)=0;
        (*pq).buffer[0]=val;
    } else if(!isFull(*pq) && IDX_TAIL(*pq)==CAPACITY-1){ //queue penuh semu
        geser = IDX_HEAD(*pq);
        for(i=IDX_HEAD(*pq);i<CAPACITY;i++){
            (*pq).buffer[i-geser] = (*pq).buffer[i]; //menggeser ke kiri sebanyak "geser"
        }
        IDX_HEAD(*pq)=0;
        IDX_TAIL(*pq)=IDX_TAIL(*pq)-geser+1;
        //TAIL(*q)=val;
        j = IDX_HEAD(*pq);
        found=false;
        while(!found && j<=IDX_TAIL(*pq)){
            if((*pq).buffer[j].score > val.score || (((*pq).buffer[j].score==val.score) && ((*pq).buffer[j].tArrival <val.tArrival))){
                j++;
            } else {
                found = true;
            }
        }
        geser = 1;
        for(i=IDX_TAIL(*pq);i>=j;i--){
            (*pq).buffer[i+geser] = (*pq).buffer[i]; //menggeser ke kiri sebanyak "geser"
        }
        (*pq).buffer[j] = val;

    } else {
        IDX_TAIL(*pq)+=1;
        //TAIL(*q)=val;
        j = IDX_HEAD(*pq);
        //printf("%d",j);
        found=false;
        while(!found && j<IDX_TAIL(*pq)){
            if((*pq).buffer[j].score > val.score || (((*pq).buffer[j].score==val.score) && ((*pq).buffer[j].tArrival <val.tArrival))){
                j++;
            } else {
                found = true;
            }
        }
        geser = 1;
        for(i=IDX_TAIL(*pq);i>=j;i--){
            (*pq).buffer[i+geser] = (*pq).buffer[i]; //menggeser ke kiri sebanyak "geser"
        }
        (*pq).buffer[j] = val;
        //printf("%d",j);
    }
}

void dequeue(PrioQueue * pq, ElType *val){
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. pq tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd
I.S., HEAD dan IDX_HEAD "mundur";
        pq mungkin kosong */
    *val = HEAD(*pq);
    if(IDX_HEAD(*pq)==IDX_TAIL(*pq)){//hanya terdiri dari satu elemen
        IDX_HEAD(*pq)=IDX_UNDEF;
        IDX_TAIL(*pq)=IDX_UNDEF;
    } else {
        IDX_HEAD(*pq)+=1;
    }
}

void displayQueue(PrioQueue q){
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
    //kamus
    int i;
    //algoritma
    printf("[");
    if(!isEmpty(q)){
        for(i=IDX_HEAD(q);i<IDX_TAIL(q);i++){
            printf("%d %d %d %d,",q.buffer[i].tArrival, q.buffer[i].id, q.buffer[i].score, q.buffer[i].dService);
        }
        printf("%d %d %d %d", TAIL(q).tArrival, TAIL(q).id, TAIL(q).score, TAIL(q).dService);
    }
    printf("]");
}

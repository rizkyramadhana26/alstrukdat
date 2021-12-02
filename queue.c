/*
Rizky Ramadhana P. K.
13520151
File ini merupakan realisasi dari queue.h
Rabu, 6 September 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "boolean.h"

/* *** Kreator *** */
void CreateQueue(Queue *q){
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
    IDX_HEAD(*q)=IDX_UNDEF;
    IDX_TAIL(*q)=IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmpty(Queue q){
/* Mengirim true jika q kosong: lihat definisi di atas */
    return (IDX_HEAD(q)==IDX_UNDEF) && (IDX_TAIL(q)==IDX_UNDEF);
}
boolean isFull(Queue q){
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */
    return (IDX_HEAD(q)==0) && (IDX_TAIL(q)==CAPACITY-1);
}
int length(Queue q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    //kamus
    int l;
    //algoritma
    if(isEmpty(q)){
        l=0;
    } else {
        l=IDX_TAIL(q)-IDX_HEAD(q)+1;
    }
    return l;
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val){
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
    //kamus
    int geser,i;
    //algoritma
    if(isEmpty(*q)){ //queue kosong
        IDX_HEAD(*q)=0;
        IDX_TAIL(*q)=0;
        (*q).buffer[0]=val;
    } else if(!isFull(*q) && IDX_TAIL(*q)==CAPACITY-1){ //queue penuh semu
        geser = IDX_HEAD(*q);
        for(i=IDX_HEAD(*q);i<CAPACITY;i++){
            (*q).buffer[i-geser] = (*q).buffer[i]; //menggeser ke kiri sebanyak "geser"
        }
        IDX_HEAD(*q)=0;
        IDX_TAIL(*q)=IDX_TAIL(*q)-geser+1;
        TAIL(*q)=val;
    } else {
        IDX_TAIL(*q)+=1;
        TAIL(*q)=val;
    }
}

void dequeue(Queue *q, ElType *val){
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEAD "mundur";
        q mungkin kosong */
    *val = HEAD(*q);
    if(IDX_HEAD(*q)==IDX_TAIL(*q)){//hanya terdiri dari satu elemen
        IDX_HEAD(*q)=IDX_UNDEF;
        IDX_TAIL(*q)=IDX_UNDEF;
    } else {
        IDX_HEAD(*q)+=1;
    }
}

/* *** Display Queue *** */
void displayQueue(Queue q){
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
            printf("%d,",q.buffer[i]);
        }
        printf("%d", TAIL(q));
    }
    printf("]");
}

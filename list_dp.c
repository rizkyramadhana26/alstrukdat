/*
Rizky Ramadhana P. K.
13520151
Jumat, 29 Oktober 2021
File ini merupakan realisasi dari list_dp.
*/

#include <stdio.h>
#include <stdlib.h>
#include "list_dp.h"
#include "boolean.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
/* Mengirim true jika list kosong. Lihat definisi di atas. */
    return (FIRST(l)==NULL) && (LAST(l)==NULL);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
/* I.S. l sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
    FIRST(*l)=NULL;
    LAST(*l)=NULL;
}

/****************** Manajemen Memori ******************/
Address allocate(ElType val){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NULL. */
/* Misalnya: menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL, PREV(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL. */
    Address alamatbaru = (Address) malloc(sizeof(Node));
    if(alamatbaru!=NULL){
        INFO(alamatbaru)=val;
        NEXT(alamatbaru)=NULL;
        PREV(alamatbaru)=NULL;
    }
    return alamatbaru;
}

void deallocate (Address p){
/* I.S. p terdefinisi */
/* F.S. p dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Address P */
    free(p);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val){
/* Mencari apakah ada elemen list dengan INFO(P)=val */
/* Jika ada, mengirimkan Address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */
    Address saatini;
    boolean found = false;
    saatini = FIRST(l);
    while(saatini != NULL && !found) {
        if(INFO(saatini) == val) {
            found = true;
        }
        else{
            saatini = NEXT(saatini);
        }
    }
    return saatini;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
/* I.S. List l terdefinisi */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    Address alamatbaru = allocate(val);
    if(alamatbaru!=NULL){
        if(isEmpty(*l)){
            FIRST(*l)=alamatbaru;
            LAST(*l)=alamatbaru;
        }else{
            NEXT(alamatbaru)=FIRST(*l);
            PREV(FIRST(*l))=alamatbaru;
            FIRST(*l)=alamatbaru;
        }
    }
}

void insertLast(List *l, ElType val){
/* I.S. List l terdefinisi */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    Address alamatbaru;
    if(isEmpty(*l)){
        insertFirst(l,val);
    }else{
        alamatbaru=allocate(val);
        if(alamatbaru!=NULL){
            PREV(alamatbaru)=LAST(*l);
            NEXT(LAST(*l))=alamatbaru;
            LAST(*l)=alamatbaru;
        }
    }
}

void insertAfter(List *L, Address p, Address pRec){
/* I.S. pRec pasti elemen list; p sudah dialokasi */
/* F.S. Insert p sebagai elemen sesudah elemen beralamat pRec */
    if (NEXT(pRec) != NULL) {
        PREV(NEXT(pRec)) = p;
    }
    else {
        LAST(*L) = p;
    }
    PREV(p)=pRec;
    NEXT(p)=NEXT(pRec);
    NEXT(pRec)=p;
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val){
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada val */
/*      dan alamat elemen pertama di-dealokasi */
    *val=INFO(FIRST(*l));
    Address alamatlama=FIRST(*l);
    if(NEXT(FIRST(*l))==NULL){
        FIRST(*l) = NULL;
        LAST(*l) = NULL;
        deallocate(alamatlama);
    }else {
        FIRST(*l) = NEXT(alamatlama);
        PREV(NEXT(alamatlama)) = NULL;
        deallocate(alamatlama);
    }
}

void deleteLast(List *l, ElType *val){
/* I.S. list l tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada val */
/*      dan alamat elemen terakhir di-dealokasi */
    Address alamatlama = LAST(*l);
    *val = INFO(alamatlama);
    if (PREV(alamatlama) == NULL) {
        FIRST(*l) = NULL;
        LAST(*l) = NULL;
        free(alamatlama);
    }
    else {
        LAST(*l) = PREV(alamatlama);
        NEXT(PREV(alamatlama)) = NULL;
        free(alamatlama);
    }
}

void deleteAfter(List *l, Address *pDel, Address pRec){
/* I.S. List tidak kosong. pRec adalah anggota list.
        NEXT(pRec)!=NULL */
/* F.S. Menghapus NEXT(pRec): */
    *pDel=NEXT(pRec);
    Address alamatlama=NEXT(pRec);
    NEXT(pRec)=NEXT(NEXT(pRec));
    if (NEXT(*pDel) != NULL) {
        PREV(NEXT(*pDel)) = pRec;
    }
    else {
        LAST(*l) = pRec;
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    Address saatini=FIRST(l);
    printf("[");
    if(!isEmpty(l)){
        while(saatini!=LAST(l)){
            printf("%d,", INFO(saatini));
            saatini=NEXT(saatini);
        }
        printf("%d",INFO(saatini));
    }
    printf("]");
}

void displayListBackwards(List l){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    Address saatini=LAST(l);
    printf("[");
    if(!isEmpty(l)){
        while(saatini!=FIRST(l)){
            printf("%d,", INFO(saatini));
            saatini=PREV(saatini);
        }
        printf("%d",INFO(saatini));
    }
    printf("]");
}


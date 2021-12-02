/*
Rizky Ramadhana P. K.
13520151
Jumat, 29 Oktober 2021
File ini merupakan realisasi dari list_circular.
*/

#include "list_circular.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>


/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
/* Mengirim true jika list kosong. Lihat definisi di atas. */
    return FIRST(l)==NULL;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
/* I.S. l sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
    FIRST(*l)=NULL;
}

/****************** Manajemen Memori ******************/
Address allocate(ElType val){
/* Mengirimkan Address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka Address tidak NULL, dan misalnya */
/* menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
    Address alamat;
    alamat= (Address) malloc(sizeof(ElmtList));
    if(alamat!=NULL){
        INFO(alamat)=val;
        NEXT(alamat)=NULL;
    }
    return alamat;
}

void deallocate(Address P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Address P */
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val){
/* Mencari apakah ada elemen list dengan INFO(P)= val */
/* Jika ada, mengirimkan Address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */
    boolean found=false;
    Address saatini=FIRST(l);
    if(saatini!=NULL){
        do{
            if(INFO(saatini)==val){
                found=true;
            }else{
                saatini=NEXT(saatini);
            }
        }while(saatini!=FIRST(l) && !found);
    }
    if(!found){
        saatini=NULL;
    }
    return saatini;
}

boolean addrSearch(List l, Address p){
/* Mencari apakah ada elemen list l yang beralamat p */
/* Mengirimkan true jika ada, false jika tidak ada */
    boolean found=false;
    Address saatini=FIRST(l);
    if(saatini!=NULL){
        do{
            if(saatini==p){
                found=true;
            }else{
                saatini=NEXT(saatini);
            }
        }while(saatini!=FIRST(l) && !found);
    }
    return found;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
/* I.S. List l terdefinisi, mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil */
/* Elemen terakhir list menunjuk ke address dari elemen pertama baru list */
    Address alamatbaru=allocate(val),saatini=FIRST(*l);
    if(alamatbaru!=NULL){
        if(isEmpty(*l)){
            FIRST(*l)=alamatbaru;
            NEXT(alamatbaru)=FIRST(*l);
        } else{
            while(NEXT(saatini)!=FIRST(*l)){
                saatini=NEXT(saatini);
            }
            NEXT(alamatbaru)=FIRST(*l);
            FIRST(*l)=alamatbaru;
            NEXT(saatini)=FIRST(*l);
        }
    }
}

void insertLast(List *l, ElType val){
/* I.S. List l terdefinisi, mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
/* Elemen terakhir baru list menunjuk ke address dari elemen pertama list */
    Address alamatbaru=allocate(val),saatini=FIRST(*l);
    if(alamatbaru!=NULL){
        if(isEmpty(*l)){
            insertFirst(l,val);
        }else{
            while(NEXT(saatini)!=FIRST(*l)){
                saatini=NEXT(saatini);
            }
            NEXT(alamatbaru)=FIRST(*l);
            NEXT(saatini)=alamatbaru;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType * val){
/* I.S. List l tidak kosong  */
/* F.S. val adalah elemen pertama List l sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      First element yg baru adalah suksesor elemen pertama yang lama */
/*      Jika list baru tidak kosong, Last element menunjuk ke First element baru */
/*      Jika list baru kosong, maka FIRST(*l) = NULL */
/*      Alamat elemen pertama list lama di-dealokasi */
    *val=INFO(FIRST(*l));
    Address alamatlama=FIRST(*l),saatini=FIRST(*l);
    if(NEXT(FIRST(*l))==FIRST(*l)){
        FIRST(*l)=NULL;
        free(alamatlama);
    } else{
        while(NEXT(saatini)!=FIRST(*l)){
            saatini=NEXT(saatini);
        }
        FIRST(*l)=NEXT(FIRST(*l));
        NEXT(saatini)=FIRST(*l);
        free(alamatlama);
    }
}

void deleteLast(List *l, ElType * val){
/* I.S. List l tidak kosong */
/* F.S. val adalah elemen terakhir list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      Last element baru adalah predesesor elemen terakhir yg lama, jika ada */
/*      Jika list baru tidak kosong, Last element baru menunjuk ke First element */
/*      Jika list baru kosong, maka FIRST(*l) = NULL */
/*      Alamat elemen terakhir list lama di-dealokasi */
    Address saatini=FIRST(*l),sebelumnya=NULL;
    if(NEXT(FIRST(*l))==FIRST(*l)){
        deleteFirst(l,val);
    }else{
        while(NEXT(saatini)!=FIRST(*l)){
            sebelumnya=saatini;
            saatini=NEXT(saatini);
        }
        NEXT(sebelumnya)=FIRST(*l);
        *val=INFO(saatini);
        free(saatini);
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    Address sebelumnya=NULL,saatini=FIRST(l);
    printf("[");
    if(!isEmpty(l)){
        while(NEXT(saatini)!=FIRST(l)){
            sebelumnya=saatini;
            saatini=NEXT(saatini);
            printf("%d,", INFO(sebelumnya));
        }
        printf("%d",INFO(saatini));
    }
    printf("]");
}

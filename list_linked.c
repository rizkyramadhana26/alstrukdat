/*
Rizky Ramadhana P. K. 13520151
Senin, 25 Oktober 2021
File ini merupakan realisasi dari list_linked.h
*/

#include "boolean.h"
#include "node.h"
#include "list_linked.h"
#include <stdio.h>

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    *l=NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
/* Mengirim true jika list kosong */
    return l==NULL;
}

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
    //KAMUS
    int counter=0;
    Address saatini=l;
    //ALGORITMA
    while(counter<idx){
        saatini=NEXT(saatini);
        counter++;
    }
    return INFO(saatini);
}

void setElmt(List *l, int idx, ElType val){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
    //KAMUS
    int counter=0;
    Address saatini=*l;
    //ALGORITMA
    while(counter<idx){
        saatini=NEXT(saatini);
        counter++;
    }
    INFO(saatini)=val;
}

int indexOf(List l, ElType val){
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
    //KAMUS
    int indeks=IDX_UNDEF,counter=0;
    boolean found=false;
    Address saatini=l;
    //ALGORITMA
    do{
        if(INFO(saatini)==val){
            found=true;
            indeks=counter;
        } else {
            counter++;
            saatini=NEXT(saatini);
        }
    }while(!found && NEXT(saatini)!=NULL);
    return indeks;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
    //KAMUS
    Address alamatbaru;
    //ALGORITMA
    alamatbaru = newNode(val);
    if(alamatbaru!=NULL){
        NEXT(alamatbaru)=*l;
        *l=alamatbaru;
    }
}

void insertLast(List *l, ElType val){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    //KAMUS
    Address alamatbaru,saatini=*l;
    //ALGORITMA
    if(saatini==NULL){
        insertFirst(l,val);
    } else{
        while(NEXT(saatini)!=NULL){
            saatini=NEXT(saatini);
        }
        alamatbaru=newNode(val);
        if(alamatbaru!=NULL){
            NEXT(saatini)=alamatbaru;
        }
    }

}

void insertAt(List *l, ElType val, int idx){
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    //KAMUS
    int counter=0;
    Address saatini=*l,alamatbaru;
    //ALGORITMA
    if(idx==0){
        insertFirst(l,val);
    } else{
        while(counter<idx-1){
            saatini=NEXT(saatini);
            counter++;
        }
        alamatbaru=newNode(val);
        if(alamatbaru!=NULL){
            NEXT(alamatbaru)=NEXT(saatini);
            NEXT(saatini)=alamatbaru;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val){
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
    //KAMUS
    Address alamatlama;
    //ALGORITMA
    alamatlama=*l;
    *val=INFO(alamatlama);
    *l=NEXT(alamatlama);
    free(alamatlama);
}
void deleteLast(List *l, ElType *val){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
    //KAMUS
    Address sebelumnya=NULL,saatini=*l;
    //ALGORITMA
    while(NEXT(saatini)!=NULL){
        sebelumnya = saatini;
        saatini=NEXT(saatini);
    }
    if(sebelumnya==NULL){
        *l=NULL;
        *val=INFO(saatini);
        free(saatini);
    } else{
        NEXT(sebelumnya)=NULL;
        *val=INFO(saatini);
        free(saatini);
    }
}
void deleteAt(List *l, int idx, ElType *val){
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
    //KAMUS
    int counter=0;
    Address sebelumnya=NULL, saatini=*l;
    //ALGORITMA
    if(idx==0){
        deleteFirst(l,val);
    } else {
        while(counter<idx){
            sebelumnya=saatini;
            saatini=NEXT(saatini);
            counter++;
        }
        *val=INFO(saatini);
        NEXT(sebelumnya)=NEXT(saatini);
        free(saatini);
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    //KAMUS
    Address saatini=l;
    //ALGORITMA
    printf("[");
    do{
        printf("%d,",INFO(saatini));
        saatini=NEXT(saatini);
    }while(NEXT(saatini)!=NULL);
    printf("%d]",INFO(saatini));
}

int length(List l){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    //KAMUS
    int counter=0;
    Address saatini=l;
    //ALGORITMA
    while(saatini!=NULL){
        counter++;
        saatini=NEXT(saatini);
    }
    return counter;
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean fSearch(List L, Address P){
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
    //KAMUS
    boolean found=false;
    Address l=FIRST(L);
    //ALGORITMA
    while(!found && l!=NULL){
        if(l==P){
            found=true;
        }else{
            l=NEXT(l);
        }
    }
    return found;
}
Address searchPrec(List L, ElType X){
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
    //KAMUS
    Address saatini=FIRST(L),sebelumnya=NULL,jawaban=NULL;
    boolean found=false;
    //ALGORITMA
    while(!found && saatini!=NULL){
        if(INFO(saatini)==X){
            found=true;
            jawaban=sebelumnya;
        }else{
            sebelumnya=saatini;
            saatini=NEXT(saatini);
        }
    }
    return jawaban;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
ElType max(List l){
/* Mengirimkan nilai info(P) yang maksimum */
    int maks=INFO(FIRST(l));
    Address saatini = NEXT(FIRST(l));
    while(saatini!=NULL){
        if (maks<INFO(saatini)){
            maks=INFO(saatini);
        }
        saatini=NEXT(saatini);
    }
    return maks;
}
Address adrMax(List l){
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
    int maks=INFO(FIRST(l));
    Address alamat=FIRST(l);
    Address saatini = NEXT(FIRST(l));
    while(saatini!=NULL){
        if (maks<INFO(saatini)){
            maks=INFO(saatini);
            alamat=saatini;
        }
        saatini=NEXT(saatini);
    }
    return alamat;
}

ElType min(List l){
/* Mengirimkan nilai info(P) yang minimum */
    int min=INFO(FIRST(l));
    Address saatini = NEXT(FIRST(l));
    while(saatini!=NULL){
        if (min>INFO(saatini)){
            min=INFO(saatini);
        }
        saatini=NEXT(saatini);
    }
    return min;
}
Address adrMin(List l){
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
    int min=INFO(FIRST(l));
    Address alamat=FIRST(l);
    Address saatini = NEXT(FIRST(l));
    while(saatini!=NULL){
        if (min>INFO(saatini)){
            min=INFO(saatini);
            alamat=saatini;
        }
        saatini=NEXT(saatini);
    }
    return alamat;
}
float average(List l){
/* Mengirimkan nilai rata-rata info(P) */
    float sum=0;
    Address saatini = FIRST(l);
    while(saatini!=NULL){
        sum+=INFO(saatini);
        saatini=NEXT(saatini);
    }
    return sum/length(l);
}

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) {
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
    //KAMUS
    Address saatini;
    List l3;
    //ALGORITMA
    CreateList(&l3);
    saatini=l1;
    while(saatini!=NULL){
        insertLast(&l3,INFO(saatini));
        saatini=NEXT(saatini);
    }
    saatini=l2;
    while(saatini!=NULL){
        insertLast(&l3,INFO(saatini));
        saatini=NEXT(saatini);
    }
    return l3;
}

void delAll(List *l){
/* Delete semua elemen list dan alamat elemen di-dealokasi */
    ElType temp;
    while(!isEmpty(*l)){
        deleteFirst(l, &temp);
    }
}

void inverseList(List *l){
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
    /*Address saatini=FIRST(*l), sebelumnya=NULL;
    if(saatini!=NULL){
        while(saatini!=NULL){
            NEXT(saatini)=sebelumnya;
            sebelumnya=saatini;
            saatini=NEXT(saatini);
        }
        *l=sebelumnya;
    }*/
    *l=fInverseList(*l);
}

List fInverseList(List l){
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
    List hasil;
    Address saatini=l;
    CreateList(&hasil);
    while(saatini!=NULL){
        insertFirst(&hasil, INFO(saatini));
        saatini=NEXT(saatini);
    }
    return hasil;
}

void copyList(List *l1, List *l2){
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
    *l2=*l1;
}

List fCopyList(List l){
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
    List hasil;
    Address saatini=l;
    CreateList(&hasil);
    while(saatini!=NULL){
        insertLast(&hasil, INFO(saatini));
        saatini=NEXT(saatini);
    }
    return hasil;
}

void cpAllocList(List lIn, List *lOut){
/* I.S. lIn sembarang. */
/* F.S. Jika semua alokasi berhasil,maka lOut berisi hasil copy lIn */
/* Jika ada alokasi yang gagal, maka lOut=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* lOut adalah list kosong jika ada alokasi elemen yang gagal */
    Address saatini=lIn;
    while(saatini!=NULL){
        insertLast(lOut, INFO(saatini));
        saatini=NEXT(saatini);
    }
}

void splitList(List *l1, List *l2, List l){
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list l1 dan l2 */
/* L tidak berubah: untuk membentuk l1 dan l2 harus alokasi */
/* l1 berisi separuh elemen L dan l2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah length(L) div 2 */
    int panjang1=length(l)/2;
    Address saatini=l;
    while(saatini!=NULL){
        if(length(*l1)<panjang1){
            insertLast(l1,INFO(saatini));
            saatini=NEXT(saatini);
        }else{
            insertLast(l2,INFO(saatini));
            saatini=NEXT(saatini);
        }
    }
}

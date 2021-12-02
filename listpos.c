/*
13520151 Rizky Ramadhana P. K.
7 September 2021
ADT List Positif
File ini berisi realisasi fungsi dan prosedur pada header listpos.h
*/

#include "listpos.h"
#include <stdio.h>
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListPos(ListPos *l){
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */
    //kamus
    int i;
    //algoritma
    for(i=0;i<CAPACITY;i++){
        ELMT(*l,i)=VAL_UNDEF;
    }
}

int length(ListPos l){
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
    //kamus
    boolean mark = true;
    int length = 0;
    //algoritma
    while (length<CAPACITY && mark){
        if(ELMT(l,length)!=VAL_UNDEF){
            length++;
        } else {
            mark = false;
        }
    }
    return length;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListPos l, int i){
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
    return (0<=i) && (i<=CAPACITY-1);
}
boolean isIdxEff(ListPos l, int i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
    return (0<=i) && (i<=(length(l)-1));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListPos l){
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
    return ELMT(l,0)==VAL_UNDEF;
}
/* *** Test List penuh *** */
boolean isFull(ListPos l){
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    return ELMT(l,CAPACITY-1)!=VAL_UNDEF;
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListPos *l){
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali:
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
    //kamus
    int n, i, elemen;
    boolean n_valid = false;
    //algoritma
    while (!n_valid){
        scanf("%d", &n);
        n_valid = ((0<=n)&&(n<=CAPACITY));
    }
    CreateListPos(&*l);
    for(i=0;i<n;i++){
        scanf("%d", &elemen);
        ELMT(*l, i)=elemen;
    }
}

void displayList(ListPos l){
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
    //kamus
    int i;
    //algoritma
    printf("[");
    if(!isEmpty(l)){
        printf("%d", ELMT(l,0));
        for(i=1;i<length(l);i++){
            printf(",%d", ELMT(l,i));
        }
    }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListPos plusMinusTab(ListPos l1, ListPos l2, boolean plus){
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi
       elemen l2 pada indeks yang sama */
       //kamus
       int i;
       ListPos hasil;
       //algoritma
       CreateListPos(&hasil);
       if(plus){
            for(i=0;i<length(l1);i++){
                ELMT(hasil, i)=ELMT(l1,i)+ELMT(l2,i);
            }
       } else {
            for(i=0;i<length(l1);i++){
                ELMT(hasil, i)=ELMT(l1,i)-ELMT(l2,i);
            }
       }
       return hasil;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListPos l1, ListPos l2){
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua
   elemennya sama */
   //kamus
   boolean equal=true;
   int i=0, panjang=length(l1);
   //algoritma
   if (length(l1)!=length(l2)){
    equal=false;
   } else {
    while(equal && i<panjang){
        if(ELMT(l1,i)!=ELMT(l2,i)){
            equal=false;
        } else {
            i++;
        }
    }
   }
   return equal;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListPos l, ElType val){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
    //kamus
    boolean found=false;
    int i=0, hasil=IDX_UNDEF, panjang=length(l);
    //algoritma
    while(!found && i<panjang){
        if(ELMT(l, i)==val){
            found = true;
            hasil =i;
        } else {
            i++;
        }
    }
    return hasil;
}

/* ********** NILAI EKSTREM ********** */
void extremes(ListPos l, ElType *max, ElType *min){
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */
        //kamus
        int i, panjang = length(l);
        //algoritma
        *min = ELMT(l,0);
        *max = ELMT(l,0);
        for(i=0;i<panjang;i++){
            if(ELMT(l,i)<*min){
                *min=ELMT(l,i);
            }
            if(ELMT(l,i)>*max){
                *max=ELMT(l,i);
            }
            i++;
        }

}

/* ********** OPERASI LAIN ********** */
boolean isAllEven(ListPos l){
/* Menghailkan true jika semua elemen l genap */
    //kamus
    boolean hasil=true;
    int i=0, panjang=length(l);
    //algoritma
    while(hasil && i<panjang){
        if(ELMT(l,i)%2!=0){
            hasil=false;
        } else {
            i++;
        }
    }
    return hasil;
}

/* ********** SORTING ********** */
void sort(ListPos *l, boolean asc){
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
   //kamus
   int temp,i, panjang=length(*l);
   boolean sorted=false,swapped;
   //algoritma
   //menggunakan bubble sort
    if(asc){
        while(!sorted){
            swapped=false;
            for(i=0;i<panjang-1;i++){
                if(ELMT(*l, i)>ELMT(*l,i+1)){
                    temp=ELMT(*l,i);
                    ELMT(*l,i)=ELMT(*l,i+1);
                    ELMT(*l,i+1)=temp;
                    swapped = true;
                }
            }
            if(!swapped){
                sorted=true;
            }
        }
    } else {
        while(!sorted){
            swapped=false;
            for(i=0;i<panjang-1;i++){
                if(ELMT(*l, i)<ELMT(*l,i+1)){
                    temp=ELMT(*l,i);
                    ELMT(*l,i)=ELMT(*l,i+1);
                    ELMT(*l,i+1)=temp;
                    swapped = true;
                }
            }
            if(!swapped){
                sorted=true;
            }
        }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListPos *l, ElType val){
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    ELMT(*l, length(*l))=val;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListPos *l, ElType *val){
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
    *val = ELMT(*l,length(*l)-1);
    ELMT(*l,length(*l)-1)=VAL_UNDEF;
}

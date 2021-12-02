/*
13520151 Rizjy Ramadhana P. K.
16 September 2021
List Dinamis
File ini merupakan realisasi dari fungsi dan prosedur yang telah dideklarasi di file listdinpos.h
*/

#include <stdlib.h>
#include <stdio.h>
#include "listdinpos.h"
#include "boolean.h"


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity){
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list l kosong dengan kapasitas capacity + 1 */
/* Proses: Inisialisasi semua elemen list l dengan VAL_UNDEF */
    //kamus
    int i;
    //algoritma
    BUFFER(*l)=(ElType*) malloc (capacity+1 * sizeof(ElType));
    CAPACITY(*l)=capacity+1;
    for(i=0;i<capacity+1;i++){
        ELMT(*l,i)=VAL_UNDEF;
    }
}

void dealocate(ListDin *l){
/* I.S. l terdefinisi; */
/* F.S. TI(l) dikembalikan ke system, CAPACITY(l)=0; nEff(l)=0 */
    free(BUFFER(*l));
    CAPACITY(*l)=0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListDin l){
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */
    //kamus
    boolean mark = true;
    int length = 0;
    //algoritma
    while (length<CAPACITY(l) && mark){
        if(ELMT(l,length)!=VAL_UNDEF){
            length++;
        } else {
            mark = false;
        }
    }
    return length;
}

/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
    return length(l)-1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi utk container*/
    return (0<=i)&&(i<=CAPACITY(l)-1);
}
boolean isIdxEff(ListDin l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..getLastIdx(l) */
    return (0<=i)&&(i<=length(l)-1);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l){
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
    return ELMT(l,0)==VAL_UNDEF;
}
boolean isFull(ListDin l){
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    return ELMT(l,CAPACITY(l)-1)!=VAL_UNDEF;
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l){
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
    //kamus
    boolean valid=false;
    int n,i=0,elemen;
    //algoritma
    while (!valid){
        scanf("%d",&n);
        if((0<=n)&&(n<=CAPACITY(*l))){
            valid = true;
        }
    }
    for(i=0;i<CAPACITY(*l);i++){
        ELMT(*l,i)=VAL_UNDEF;
    }
    while(i<n){
        scanf("%d",&elemen);
        ELMT(*l,i)=elemen;
        i++;
    }
}
void displayList(ListDin l){
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
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
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
/* Prekondisi : l1 dan l2 memiliki nEff sama dan tidak kosong */
/*              Jika plus=false, tidak ada elemen l1-l2 yang menghasilkan nilai <= 0 */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
    //kamus
    ListDin hasil;
    int i;
    //algoritma
    CreateListDin(&hasil, CAPACITY(l1));
    if(plus){
        for(i=0;i<length(l1);i++){
            ELMT(hasil,i)=ELMT(l1,i)+ELMT(l2,i);
        }
    } else {
        for(i=0;i<length(l1);i++){
            ELMT(hasil,i)=(ELMT(l1,i)>=ELMT(l2,i) ? ELMT(l1,i)-ELMT(l2,i) : 0);
        }
    }
    return hasil;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2){
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
    //kamus
    boolean equal=true;
    int i=0;
    //algoritma
    if(length(l1)!=length(l2)){
        equal=false;
    } else {
        while(equal && isIdxEff(l1,i)){
            if(ELMT(l1,i)==ELMT(l2,i)){
                i++;
            } else {
                equal=false;
            }
        }
    }
    return equal;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val){
/* Search apakah ada elemen list l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan VAL_UNDEF */
/* Menghasilkan indeks tak terdefinisi (VAL_UNDEF) jika list l kosong */
/* Skema Searching yang digunakan bebas */
    //kamus
    boolean found=false;
    int i=0;
    IdxType indeks=VAL_UNDEF;
    //algoritma
    while(!found && isIdxEff(l,i)){
        if(ELMT(l,i)==val){
            indeks=i;
            found=true;
        } else {
            i++;
        }
    }
    return indeks;
}

/* ********** NILAI EKSTREM ********** */
void extremes(ListDin l, ElType *max, ElType *min){
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
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
        }
}

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut){
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan Capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
    //kamus
    int i;
    //algoritma
    CreateListDin(lOut, CAPACITY(lIn));
    for(i=0;i<length(lIn);i++){
        insertLast(lOut, ELMT(lIn, i));
    }
}
ElType sumList(ListDin l){
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
    //kamus
    int i,jumlah=0;
    //algoritma
    for(i=0;i<length(l);i++){
        jumlah+=ELMT(l,i);
    }
    return jumlah;
}
int countVal(ListDin l, ElType val){
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
    //kamus
    int i, count=0;
    //algoritma
    for(i=0;i<length(l);i++){
        if(ELMT(l,i)==val){
            count++;
        }
    }
    return count;
}
boolean isAllEven(ListDin l){
/* Menghailkan true jika semua elemen l genap. l boleh kosong */
    //kamus
    boolean even=true;
    int i=0;
    //algoritma
    while(even && isIdxEff(l,i)){
        if(ELMT(l,i)%2!=0){
            even=false;
        } else {
            i++;
        }
    }
    return even;
}

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc){
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
void insertLast(ListDin *l, ElType val){
/* Proses: Menambahkan X sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    ELMT(*l,length(*l))=val;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val){
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
    *val=ELMT(*l,length(*l)-1);
    ELMT(*l,length(*l)-1)=VAL_UNDEF;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList(ListDin *l, int num){
/* Proses : Menambahkan kapasitas sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
    //kamus
    ListDin temp;
    int i;
    //algoritma
    copyList(*l, &temp);
    dealocate(l);
    CreateListDin(l, CAPACITY(temp)+num);
    for(i=0;i<length(temp);i++){
        insertLast(l, ELMT(temp,i));
    }
}

void shrinkList(ListDin *l, int num){
/* Proses : Mengurangi kapasitas sebanyak num */
/* I.S. List sudah terdefinisi, ukuran Capacity > num, dan nEff < Capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
    //kamus
    ListDin temp;
    int i;
    //algoritma
    copyList(*l, &temp);
    dealocate(l);
    CreateListDin(l,CAPACITY(temp)-num);
    for(i=0;i<length(temp);i++){
        insertLast(l, ELMT(temp,i));
    }
}

void compactList(ListDin *l){
/* Proses : Mengurangi kapasitas sehingga nEff = Capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran Capacity = nEff */
        ListDin temp;
    int i;
    //algoritma
    copyList(*l, &temp);
    dealocate(l);
    CreateListDin(l,length(temp));
    for(i=0;i<length(temp);i++){
        insertLast(l, ELMT(temp,i));
    }
}

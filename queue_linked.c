#include "queue_linked.h"

/* Prototype manajemen memori */
Address newNode(ElType x)
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x,
   atau NULL jika alokasi gagal */
{
    Address alamatBaru = (Address) malloc (sizeof(Node));
    if (alamatBaru!=NULL){
        INFO(alamatBaru)=x;
        NEXT(alamatBaru)=NULL;
    }
    return alamatBaru;
}
boolean isEmpty(Queue q)
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NULL and ADDR_TAIL(q)=NULL */
{
    return (ADDR_HEAD(q)==NULL)&&(ADDR_TAIL(q)==NULL);
}
int length(Queue q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */
{
    int l=0;
    Address saatini=ADDR_HEAD(q);
    while(saatini!=NULL){
        l++;
        saatini=NEXT(saatini);
    }
    return l;
}

/*** Kreator ***/
void CreateQueue(Queue *q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */
{
    ADDR_HEAD(*q)=NULL;
    ADDR_TAIL(*q)=NULL;
}

/*** Primitif Enqueue/Dequeue ***/
void enqueue(Queue *q, ElType x)
/* Proses: Mengalokasi x dan menambahkan x pada bagian Tail dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi Tail, Tail "maju" */
{
    Address alamatBaru=newNode(x);
    if(alamatBaru!=NULL){
        if(isEmpty(*q)){
            ADDR_HEAD(*q)=alamatBaru;
        }else{
            NEXT(ADDR_TAIL(*q))=alamatBaru;
        }
        ADDR_TAIL(*q)=alamatBaru;
    }
}
void dequeue(Queue *q, ElType *x)
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
{
    Address alamatLama;
    *x=HEAD(*q);
    alamatLama=ADDR_HEAD(*q);
    ADDR_HEAD(*q)=NEXT(ADDR_HEAD(*q));
    if(ADDR_HEAD(*q)==NULL){
        ADDR_TAIL(*q)=NULL;
    }
    free(alamatLama);
}

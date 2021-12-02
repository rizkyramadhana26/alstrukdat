#include "listrec.h"
#include <stdio.h>
#include <stdlib.h>

Address newNode(ElType x)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NULL, dan misalnya
   menghasilkan p, maka INFO(p)=x, NEXT(p)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
{
    Address alamatbaru = (Address) malloc(sizeof(Node));
    if(alamatbaru!=NULL){
        INFO(alamatbaru)=x;
        NEXT(alamatbaru)=NULL;
    }
    return alamatbaru;
}
/* Pemeriksaan Kondisi List */
boolean isEmpty(List l)
/* Mengirimkan true jika l kosong dan false jika l tidak kosong */
{
    return l==NULL;
}
int isOneElmt(List l)
/* Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau kosong */
{
    return (l!=NULL) && (NEXT(l)==NULL);
}
/* Primitif-Primitif Pemrosesan List */
ElType head(List l)
/* Mengirimkan elemen pertama sebuah list l yang tidak kosong */
{
    return INFO(l);
}
List tail(List l)
/* Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong */
{
    return NEXT(l);
}
List konso(List l, ElType e)
/* Mengirimkan list l dengan tambahan e sebagai elemen pertamanya. e dialokasi terlebih dahulu.
   Jika alokasi gagal, mengirimkan l */
{
    Address alamatbaru=newNode(e);
    if(alamatbaru!=NULL){
        NEXT(alamatbaru)=l;
        return alamatbaru;
    }else{
        return l;
    }
}
List konsb(List l, ElType e)
/* Mengirimkan list l dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */
{
    if(isEmpty(l)){
        return newNode(e);
    }else{
        NEXT(l)=konsb(tail(l),e);
        return l;
    }
}
/* Fungsi dan Prosedur Lain */
int length(List l)
/* Mengirimkan banyaknya elemen list l, mengembalikan 0 jika l kosong */
{
    if(isEmpty(l)){
        return 0;
    }else{
        return length(tail(l))+1;
    }
}
void displayList(List l)
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke bawah */
/*      Dipisahkan dengan newline (\n) dan diakhiri dengan newline */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak:
  1
  20
  30
 */
/* Jika list kosong, tidak menuliskan apa-apa  */
{
    if(!isEmpty(l)){
        printf("%d\n",head(l));
        displayList(tail(l));
    }
}

ElType maxList(List l){
    if(isOneElmt(l)){
        return head(l);
    }else if(head(l)>=maxList(tail(l))){
        return head(l);
    }else if(maxList(tail(l))>head(l)){
        return maxList(tail(l));
    }
}

ElType minList(List l){
    if(isOneElmt(l)){
        return head(l);
    }else if(head(l)>=minList(tail(l))){
        return minList(tail(l));
    }else if(minList(tail(l))>head(l)){
        return head(l);
    }
}

ElType sumList(List l){
    if(isOneElmt(l)){
        return head(l);
    }else{
        return head(l)+sumList(tail(l));
    }
}

float averageList(List l){
    return ((float) sumList(l))/((float) length(l));
}

List inverseList(List l){
    if(isEmpty(l)){
        return l;
    }else{
        return konsb(inverseList(tail(l)),head(l));
    }
}

void splitPosNeg(List l, List *l1, List *l2){
    if(!isEmpty(l)){
        if(head(l)>=0){
            *l1=konsb(*l1,head(l));
            splitPosNeg(tail(l),l1,l2);
        }else{
            *l2=konsb(*l2,head(l));
            splitPosNeg(tail(l),l1,l2);
        }
    }
}

void splitOnX(List l, ElType x, List *l1, List *l2){
    if(!isEmpty(l)){
        if(head(l)<x){
            *l1=konsb(*l1,head(l));
        }else{
            *l2=konsb(*l2,head(l));
        }
        splitOnX(tail(l),x,l1,l2);
    }
}

int compareList(List l1, List l2){
    if (isEmpty(l1) && isEmpty(l2)) {
        return 0;
    } else if (isEmpty(l1)) {
        return -1;
    } else if (isEmpty(l2)) {
        return 1;
    }

	if (head(l1) > head(l2)) {
        return 1;
    }
    if (head(l1) < head(l2)) {
        return -1;
    }
	return compareList(tail(l1), tail(l2));
}

//boolean isExist(ElType x, List l){
//    if(isEmpty(l)){
//        return false;
//    }else{
//        if(head(l)==x){
//            return true;
//        }else{
//            return isExist(x, tail(l));
//        }
//    }
//}

boolean isAllExist(List l1, List l2){
    if(!isEmpty(l1) && !isEmpty(l2)){
        if(isOneElmt(l1)){
            return isExist(head(l1),l2);
        }else{
            return isExist(head(l1),l2) && isAllExist(tail(l1),l2);
        }
    }else{
        return false;
    }

}

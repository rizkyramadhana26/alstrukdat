#include <stdio.h>
#include <math.h>
#include "point.h"
#include "boolean.h"

POINT MakePOINT (float X, float Y){
/* Membentuk sebuah POINT dari komponen-komponennya */
    //Kamus Lokal
    POINT point;
    //Algoritma
    Absis(point) = X;
    Ordinat(point) = Y;
    return point;
}
/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P){
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
    //Kamus
    float x, y ;
    //Algoritma
    scanf('%f %f',&x,&y);
    Absis(*P) = x;
    Ordinat(*P) = y;
}
void TulisPOINT (POINT P){
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
    //Kamus
    float x,y;
    //Algoritma
    x = Absis(P);
    y = Ordinat(P);
    printf("(%.2f,%.2f)",x,y);
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
    return (Absis(P1)==Absis(P2)) && (Ordinat(P1)==Ordinat(P2));
}
boolean NEQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 tidak sama dengan P2 */
    return !((Absis(P1)==Absis(P2)) && (Ordinat(P1)==Ordinat(P2)));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
/* Menghasilkan true jika P adalah titik origin */
    return (Absis(P)==0) && (Ordinat(P)==0);
}
boolean IsOnSbX (POINT P){
/* Menghasilkan true jika P terletak Pada sumbu X */
    return Ordinat(P)==0;
}
boolean IsOnSbY (POINT P){
/* Menghasilkan true jika P terletak pada sumbu Y */
    return Absis(P)==0;
}
int Kuadran (POINT P){
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
    //Kamus
    float x,y;
    int kuadran;
    //Algoritma
    x = Absis(P);
    y = Ordinat(P);
    if(x<0){
        if(y<0){
            kuadran=3;
        } else{
            kuadran=2;
        }
    } else {
        if(y<0){
            kuadran=4;
        } else{
            kuadran=1;
        }
    }
    return kuadran;
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX (POINT P){
/* Mengirim salinan P dengan absis ditambah satu */
    Absis(P)=Absis(P)+1;
    return P;
}
POINT NextY (POINT P){
/* Mengirim salinan P dengan ordinat ditambah satu */
    Ordinat(P)=Ordinat(P)+1;
    return P;
}
POINT PlusDelta (POINT P, float deltaX, float deltaY){
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
    Absis(P)=Absis(P)+deltaX;
    Ordinat(P)=Ordinat(P)+deltaY;
    return P;
}
POINT MirrorOf (POINT P, boolean SbX){
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
    if(SbX){
        Ordinat(P)=Ordinat(P)*-1;
    } else{
        Absis(P)=Absis(P)*-1;
    }
    return P;
}
float Jarak0 (POINT P){
/* Menghitung jarak P ke (0,0) */
    //Kamus
    float x,y;
    //Algoritma
    x=Absis(P);
    y=Ordinat(P);
    return sqrt((x*x)+(y*y));
}
float Panjang (POINT P1, POINT P2){
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
/*Mengembalikan jarak antara P1 dan P2*/
    //Kamus
    float x1,x2,y1,y2,selisihX,selisihY;
    //Algoritma
    x1=Absis(P1);
    x2=Absis(P2);
    y1=Ordinat(P1);
    y2=Ordinat(P2);
    selisihX = x1-x2;
    selisihY = y1-y2;
    return sqrt((selisihX*selisihX+selisihY*selisihY));
}
void Geser (POINT *P, float deltaX, float deltaY){
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
    Absis(*P)=Absis(*P)+deltaX;
    Ordinat(*P)=Ordinat(*P)+deltaY;
}
void GeserKeSbX (POINT *P){
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
    Ordinat(*P)=0;
}
void GeserKeSbY (POINT *P){
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
    Absis(*P)=0;
}
void Mirror (POINT *P, boolean SbX){
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
    Absis(*P)*=-1;
    Ordinat(*P)*=-1;
}
void Putar (POINT *P, float Sudut){
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
    //Kamus
    float x,y;
    //Algoritma
    Sudut = Sudut*M_PI/180;
    x=Absis(*P);
    y=Ordinat(*P);
    Absis(*P)=x*cos(Sudut)+y*sin(Sudut);
    Ordinat(*P)=-1*x*sin(Sudut)+y*cos(Sudut);
}

/*
Rizky Ramadhana P. K.
13520151
Kamis, 2 September 2021
*/
#include "garis.h"
#include "point.h"
#include "boolean.h"
#include <stdio.h>
#include <math.h>


/* ***************************************************************** */
/* PRIMITIVE DEFINITION                                              */ 
/* ***************************************************************** */
/* *** Constructor to make GARIS *** */
void MakeGARIS (POINT P1, POINT P2, GARIS * L){
/* I.S. P1 and P2 are defined */
/* F.S. L defined with L.PAw = P1 and L.PAkh = P2 */
/* Build L based one its component */
    PAwal(*L)=P1;
    PAkhir(*L)=P2;
}
/* ***************************************************************** */
/* READ/WRITE                                                        */
/* ***************************************************************** */
void BacaGARIS (GARIS * L){
/* I.S. anything */
/* F.S. L defines as valid GARIS */
/* Process : reading two points until it makes a valid GARIS 
   GARIS is valid if the first point is not equal with the second point */
/* If failed, print error message: 
   "Garis tidak valid" */
/* Example:
   2 3
   2 3
   Garis tidak valid
   2 3
   3 3 
   --> L is formed with L.PAw = <2,3> and L.PAkh = <3,3> */
   //Kamus
   POINT p1,p2;
   boolean valid=false;
   //Algoritma
   while(!valid){
        BacaPOINT(&p1);
        BacaPOINT(&p2);
        valid=NEQ(p1,p2);
        if(!valid){
            printf("Garis tidak valid\n");
        }
   }
    MakeGARIS(p1, p2, L);
}

void TulisGARIS (GARIS L){
/* I.S. L is defined */
/* F.S. L is printed with format "((x1,y1),(x2,y2))"  */
   //Kamus
   float x1,x2,y1,y2;
   //Algoritma
   x1=Absis(PAwal(L));
   y1=Ordinat(PAwal(L));
   x2=Absis(PAkhir(L));
   y2=Ordinat(PAkhir(L));
   printf("((%f,%f),(%f,%f))",x1,y1,x2,y2);

}

/* *** Operation between GARIS *** */
float PanjangGARIS (GARIS L){
/* return the length of a GARIS */
    //Kamus
    float selisihX, selisihY;
    //Algoritma
    selisihX = Absis(PAkhir(L))-Absis(PAwal(L));
    selisihY = Ordinat(PAkhir(L))-Ordinat(PAwal(L));
    return sqrt(selisihX*selisihX+selisihY*selisihY);

}
float Gradien (GARIS L){
/* return the gradient (m) of L */
/* Gradient of a line that pass through (x1,y1) and (x2,y2) is: (y2-y1)/(x2-x1) */
/* Precondition : x1 != x2 */
    return (Ordinat(PAkhir(L))-Ordinat(PAwal(L)))/(Absis(PAkhir(L))-Absis(PAwal(L)));
}

void GeserGARIS (GARIS * L, float deltaX, float deltaY){
/* I.S. L is defined */
/* F.S. L is translated deltaX parallel with X axes and deltaY parallel with Y axes */
    PAwal(*L)= PlusDelta(PAwal(*L), deltaX, deltaY);
    PAkhir(*L)= PlusDelta(PAkhir(*L), deltaX, deltaY);
}


/* *** Predicate *** */
boolean IsTegakLurus (GARIS L1, GARIS L2){
/* Return true if two lines are perpendicular*/
    return fabs(Gradien(L1)*Gradien(L2)+1)<1e-5;

}

boolean IsSejajar (GARIS L1, GARIS L2){
/* Return true if two lines are parallel*/
    return fabs(Gradien(L1)-Gradien(L2))<1e-5;
}

/* File: garis.h */
/* Definition of line using point */
#ifndef GARIS_H
#define GARIS_H

/* *** Other used ADT *** */
#include "boolean.h"
#include "point.h"

/* *** Definition TYPE GARIS *** */
typedef struct {
  POINT PAw;  /* First Point  */
  POINT PAkh; /* Last Point */
} GARIS;

/* *** Selector GARIS *** */
#define PAwal(L) (L).PAw
#define PAkhir(L) (L).PAkh
        
/* ***************************************************************** */
/* PRIMITIVE DEFINITION                                              */ 
/* ***************************************************************** */
/* *** Constructor to make GARIS *** */
void MakeGARIS (POINT P1, POINT P2, GARIS * L);
/* I.S. P1 and P2 are defined */
/* F.S. L defined with L.PAw = P1 and L.PAkh = P2 */
/* Build L based one its component */

/* ***************************************************************** */
/* READ/WRITE                                                        */
/* ***************************************************************** */
void BacaGARIS (GARIS * L);
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
void TulisGARIS (GARIS L);
/* I.S. L is defined */
/* F.S. L is printed with format "((x1,y1),(x2,y2))"  */

/* *** Kelompok operasi garis *** */
float PanjangGARIS (GARIS L); 
/* return the length of a GARIS */
float Gradien (GARIS L); 
/* return the gradient (m) of L */
/* Gradient of a line that pass through (x1,y1) and (x2,y2) is: (y2-y1)/(x2-x1) */
/* Precondition : x1 != x2 */
void GeserGARIS (GARIS * L, float deltaX, float deltaY);
/* I.S. L is defined */
/* F.S. L is translated deltaX parallel with X axes and deltaY parallel with Y axes */

/* *** Kelompok predikat *** */
boolean IsTegakLurus (GARIS L1, GARIS L2);
/* Return true if two lines are perpendicular*/
boolean IsSejajar (GARIS L1, GARIS L2);
/* Return true if two lines are parallel*/

#endif

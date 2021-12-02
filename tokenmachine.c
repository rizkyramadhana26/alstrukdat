/*
Rizky Ramadhana P. K.
13520151
Kamis, 20 September 2021
File ini merupakan realisasi dari file tokenmachine.h
*/
#include <stdio.h>
#include <stdlib.h>
#include "charmachine.h"
#include "tokenmachine.h"

Token currentToken;
char currentChar;
boolean endToken;

void ignoreBlank1(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
   while(!(currentChar!=BLANK || currentChar==MARK)){
        adv();
   }
}

void startToken(){
/* I.S. : currentChar sembarang
   F.S. : endToken = true, dan currentChar = MARK;
          atau endToken = false, currentToken adalah Token yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir Token */
    start();
    ignoreBlank();
    if(currentChar==MARK){
        endToken=true;
    } else {
        endToken=false;
        salinToken();
    }
}

void advToken(){
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentToken adalah Token terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, maka endToken = true
   Proses : Akuisisi kata menggunakan procedure salinToken */
   ignoreBlank();
   if(currentChar==MARK){
    endToken=true;
   } else {
        endToken=false;
        salinToken();
        ignoreBlank();
   }
}

void salinToken(){
/* Mengakuisisi Token dan menyimpan hasilnya dalam currentToken
   I.S. : currentChar adalah karakter pertama dari Token
   F.S. : currentToken berisi Token yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata "dipotong" */
    if(currentChar=='+' || currentChar=='-' || currentChar=='*' || currentChar=='/' || currentChar=='^'){
        currentToken.tkn = currentChar;
        currentToken.val=-1;
        adv();
    } else {
        currentToken.tkn = 'b';
        currentToken.val=0;
        do {
            currentToken.val = currentToken.val*10+currentChar-'0';
            adv();
        } while (!(currentChar==BLANK || currentChar == MARK));
    }
}

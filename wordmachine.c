/*
Rizky Ramadhana P. K.
13520151
29 September 2021
File ini merupakan realisasi dari wordmachine.h
*/
#include "charmachine.h"
#include "wordmachine.h"
#include "boolean.h"

boolean endWord;
Word currentWord;

void ignoreBlank(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while(currentChar==BLANK){
        adv();
    }
}

void startWord(){
/* I.S. : currentChar sembarang
   F.S. : endWord = true, dan currentChar = MARK;
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
    //kamus
    //algoritma
    start();
    ignoreBlank();
    if(currentChar==MARK){
        endWord=true;
    } else {
        endWord=false;
        copyWord();
    }
}

void advWord(){
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.
   Proses : Akuisisi kata menggunakan procedure copyWord */
   ignoreBlank();
   if(currentChar==MARK){
        endWord=true;
   } else {
    copyWord();
    ignoreBlank();
   }
}

void copyWord(){
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    //kamus
    int i=1;
    //algoritma
    currentWord.contents[0]=currentChar;
    adv();
    while(i<CAPACITY && currentChar != MARK && currentChar != BLANK){
        currentWord.contents[i]=currentChar;
        adv();
        i++;
    }
    currentWord.length = i;
}

/*
13520151 Rizky Ramadhana P. K.
21 September 20021
Topik : Matriks
File ini merupakan realisasi dari file matrix.h
*/

#include "matrix.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void CreateMatrix(int nRow, int nCol, Matrix *m){
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
    //kamus
    int i,j;
    //algoritma
    //inisialisasi semua elemen dengan 0
    for(i=0;i<ROW_CAP;i++){
        for(j=0;j<COL_CAP;j++){
            ELMT(*m,i,j)=0;
        }
    }
    ROWS(*m)=nRow;
    COLS(*m)=nCol;
}

/* *** Selektor "DUNIA Matrix" *** */
boolean isIdxValid(int i, int j){
/* Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */
    return (0<=i) && (i<ROW_CAP) && (0<=j) &&(j<COL_CAP);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
Index getLastIdxRow(Matrix m){
/* Mengirimkan Index baris terbesar m */
    return ROWS(m)-1;
}
Index getLastIdxCol(Matrix m){
/* Mengirimkan Index kolom terbesar m */
    return COLS(m)-1;
}
boolean isIdxEff(Matrix m, Index i, Index j){
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
    return (0<=i) && (i<ROWS(m)) && (0<=j) &&(j<COLS(m));
}
ElType getElmtDiagonal(Matrix m, Index i){
/* Mengirimkan elemen m(i,i) */
    return ELMT(m,i,i);
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mRes){
/* Melakukan assignment MRes = MIn */
    //kamus
    int i,j,bar,kol;
    //algoritma
    bar=ROWS(mIn);
    kol=COLS(mIn);
    CreateMatrix(bar, kol, mRes);
    for(i=0;i<bar;i++){
        for(j=0;j<kol;j++){
            ELMT(*mRes,i,j)=ELMT(mIn,i,j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol){
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
    //kamus
    int i,j;
    //algoritma
    CreateMatrix(nRow, nCol, m);
    for(i=0;i<nRow;i++){
        for(j=0;j<nCol;j++){
            scanf("%d", &ELMT(*m,i,j));
        }
    }
}
void displayMatrix(Matrix m){
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: Menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
    //kamus
    int i,j,bar,kol;
    //algoritma
    bar=ROWS(m);
    kol=COLS(m);
    for(i=0;i<bar-1;i++){
        for(j=0;j<kol-1;j++){
            printf("%d ", ELMT(m,i,j));
        }
        printf("%d\n", ELMT(m,i,kol-1));
    }
    if(bar!=0){
    for(j=0;j<kol-1;j++){
        printf("%d ", ELMT(m,bar-1,j));
    }
    printf("%d", ELMT(m,bar-1,kol-1));
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2){
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
    //kamus
    Matrix m;
    int i,j,bar,kol;
    //algoritma
    bar=ROWS(m1);
    kol=COLS(m1);
    CreateMatrix(bar,kol,&m);
    for(i=0;i<bar;i++){
        for(j=0;j<kol;j++){
            ELMT(m,i,j)=ELMT(m1,i,j)+ELMT(m2,i,j);
        }
    }
    return m;
}
Matrix subtractMatrix(Matrix m1, Matrix m2){
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
    //kamus
    Matrix m;
    int i,j,bar,kol;
    //algoritma
    bar=ROWS(m1);
    kol=COLS(m1);
    CreateMatrix(bar,kol,&m);
    for(i=0;i<bar;i++){
        for(j=0;j<kol;j++){
            ELMT(m,i,j)=ELMT(m1,i,j)-ELMT(m2,i,j);
        }
    }
    return m;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2){
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
    //kamus
    Matrix m;
    int i,j,k,bar1,kol1,bar2,kol2,elemen;
    //algoritma
    bar1=ROWS(m1);
    kol1=COLS(m1);
    bar2=ROWS(m2);
    kol2=COLS(m2);
    CreateMatrix(bar1,kol2,&m);
    for(i=0;i<bar1;i++){
        for(j=0;j<kol2;j++){
            elemen=0;
            for(k=0;k<kol1;k++){
                elemen+=ELMT(m1,i,k)*ELMT(m2,k,j);
            }
            ELMT(m,i,j)=elemen;
        }
    }
    return m;
}
Matrix multiplyConst(Matrix m, ElType x){
/* Mengirim hasil perkalian setiap elemen m dengan x */
    //kamus
    Matrix result;
    int i,j,bar,kol;
    //algoritma
    bar=ROWS(m);
    kol=COLS(m);
    CreateMatrix(bar,kol,&result);
    for(i=0;i<bar;i++){
        for(j=0;j<kol;j++){
            ELMT(result,i,j)=x*ELMT(m,i,j);
        }
    }
    return result;
}
void pMultiplyConst(Matrix *m, ElType k){
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */
    //kamus
    int i,j,bar,kol;
    //algoritma
    bar=ROWS(*m);
    kol=COLS(*m);
    for(i=0;i<bar;i++){
        for(j=0;j<kol;j++){
            ELMT(*m,i,j)=k*ELMT(*m,i,j);
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isEqual(Matrix m1, Matrix m2){
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
    //kamus
    int i=0,j=0,bar,kol;
    boolean equal=true;
    //algoritma
    if(isSizeEqual(m1,m2)){
        bar=ROWS(m1);
        kol=COLS(m1);
        while(i<bar && equal){
            j=0;
            while(j<kol && equal){
                if(ELMT(m1,i,j)!=ELMT(m2,i,j)){
                    equal=false;
                } else {
                    j++;
                }
            }
            i++;
        }
    } else {
        equal = false;
    }
    return equal;
}
boolean isNotEqual(Matrix m1, Matrix m2){
/* Mengirimkan true jika m1 tidak sama dengan m2 */
    return !(isEqual(m1,m2));
}
boolean isSizeEqual(Matrix m1, Matrix m2){
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
    return (ROWS(m1)==ROWS(m2))&&(COLS(m1)==COLS(m2));
}

/* ********** Operasi lain ********** */
int count(Matrix m){
/* Mengirimkan banyaknya elemen m */
    return ROWS(m)*COLS(m);
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m){
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
    return ROWS(m)==COLS(m);
}
boolean isSymmetric(Matrix m){
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m)
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
   //kamus
   int i=0,j,bar,kol;
   boolean simetris=true;
   //algoritma
   bar=ROWS(m);
   kol=COLS(m);
   if(isSquare(m)){
       while(i<bar && simetris){
            j=i+1;
            while(j<kol && simetris){
                if(ELMT(m,i,j)==ELMT(m,j,i)){
                    j++;
                } else {
                    simetris=false;
                }
            }
            i++;
       }
   } else {
        simetris=false;
   }
   return simetris;
}
boolean isIdentity(Matrix m){
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
   //kamus
   int i=0,j,bar,kol;
   boolean identitas=true;
   //algoritma
   bar=ROWS(m);
   kol=COLS(m);
   while(i<bar && identitas){
        j=i+1;
        while(j<kol && identitas){
            if((i!=j && ELMT(m,i,j)==0)|(i==j && ELMT(m,i,j)==1)){
                j++;
            } else {
                identitas=false;
            }
        }
        i++;
    }
   return identitas;
}
boolean isSparse(Matrix m){
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
   //kamus
   int i,j,bar,kol,bukan0;
   //algoritma
    bar=ROWS(m);
    kol=COLS(m);
    for(i=0;i<bar;i++){
        for(j=0;j<kol;j++){
            if(ELMT(m,i,j)!=0){
                bukan0++;
            }
        }
    }
    return bukan0 <= 0.05*count(m);
}
Matrix inverse1(Matrix m){
/* Menghasilkan salinan m dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
    return multiplyConst(m, -1);
}
void pInverse1(Matrix *m){
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
    pMultiplyConst(m, -1);
}
float determinant(Matrix m){
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
    //kamus
    Matrix kofaktor;
    int i,j,k,kol,det=0,tanda=1;

    //algoritma
    if(COLS(m)==1){
        det = ELMT(m,0,0);
    } else {
        kol=COLS(m);
        for(i=0;i<kol;i++){
            CreateMatrix(kol-1,kol-1,&kofaktor);
            for(j=0;j<kol-1;j++){
                for(k=0;k<kol-1;k++){
                        ELMT(kofaktor,j,k)= (k<i) ? ELMT(m,j+1,k) : ELMT(m,j+1,k+1);
                }
            }
            det+=tanda*ELMT(m,0,i)*determinant(kofaktor);
            tanda=tanda*-1;
        }
    }
    return det;
}
void transpose(Matrix *m){
/* I.S. m terdefinisi dan isSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
   //kamus
   int i,j,bar,kol,temp,max;
   //algoritma
    bar=ROWS(*m);
    kol=COLS(*m);
    ROWS(*m)=kol;
    COLS(*m)=bar;
    max = (bar<kol) ? kol : bar;
    for(i=0;i<max;i++){
        for(j=i+1;j<max;j++){
            temp = ELMT(*m,j,i);
            ELMT(*m,j,i)=ELMT(*m,i,j);
            ELMT(*m,i,j)=temp;
        }
    }
}


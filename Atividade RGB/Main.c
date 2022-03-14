#include <stdio.h>
#include <stdlib.h>

#define N 10
#define M 15

typedef struct {
    int r, g, b;
} Pixel;

Pixel** alocaMemoriaMatrizDinamicaPixel(int, int);
int** alocaMemoriaMatrizDinamicaInt(int, int);
void carregaMatrizDinamica(Pixel**, int, int);
void carregaMatrizGray(int**, Pixel**, int, int);
void escreveMatrizDinamica(Pixel**, int, int);
void escreveMatrizGray(int**, int, int);

int main(void) {
    Pixel** rgb;
    int** gray;
    rgb = alocaMemoriaMatrizDinamicaPixel(N, M);
    carregaMatrizDinamica(rgb, N, M);
    escreveMatrizDinamica(rgb, N, M);
    gray = alocaMemoriaMatrizDinamicaInt(N, M);
    carregaMatrizGray(gray, rgb, N, M);
    escreveMatrizGray(gray, N, M);
    return 0;
}









Pixel** alocaMemoriaMatrizDinamicaPixel(int n, int m) {
    //Procedimento para alocar memoria da matriz
    Pixel** ma;
    int i;
    ma = (Pixel**)malloc(sizeof(Pixel*) * n);
    for (i = 0; i < N; i++) {
        ma[i] = (Pixel*)malloc(sizeof(Pixel) * m);
    }

    return ma;
}

int** alocaMemoriaMatrizDinamicaInt(int n, int m) {
    //Procedimento para alocar memoria da matriz
    int** ma;
    int i;
    ma = (int**)malloc(sizeof(int*) * n);
    for (i = 0; i < N; i++) {
        ma[i] = (int*)malloc(sizeof(int) * m);
    }

    return ma;
}

void carregaMatrizDinamica(Pixel** ma, int n, int m) {
    //Procedimento para carregar a matriz
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            ma[i][j].r = rand() % 255;
            ma[i][j].g = rand() % 255;
            ma[i][j].b = rand() % 255;
        }
    }
}

void carregaMatrizGray(int** gray, Pixel** rgb, int n, int m) {
    //Procedimento para carregar a matriz
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            gray[i][j] = 0.300 * rgb[i][j].r + 0.590 * rgb[i][j].g + 0.110 * rgb[i][j].b;
        }
    }
}

void escreveMatrizDinamica(Pixel** ma, int n, int m) {
    //Procedimento para escrever a matriz
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("R:%i G:%i B:%i \t", ma[i][j].r, ma[i][j].g, ma[i][j].b);
        }
        printf("\n");
    }
}

void escreveMatrizGray(int** ma, int n, int m) {
    //Procedimento para escrever a matriz
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%i \t", ma[i][j]);
        }
        printf("\n");
    }
}
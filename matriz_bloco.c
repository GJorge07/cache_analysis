#include <stdio.h>
#include <stdlib.h>
#include <time.h>




int main (int argc, char *argv[] ) {        

     int N = atoi(argv[1]); /*converte o texto string para inteiro*/
     int BL = atoi(argv[2]); /*É o tamanho do bloco da matriz*/

     double *A = malloc(N * N * sizeof(double));
     double *B = malloc(N * N * sizeof(double));
     double *C = malloc(N * N * sizeof(double));

     /*Preenche valores de A e B*/
     for (int i = 0; i < N; i++) {
         for (int j = 0; j < N; j++) {
             A[i * N + j] = i + j;
             B[i * N + j] = i + j;
         }
     }

     /*Preenche C com 0*/
     for (int i = 0; i < N; i++) {
         for (int j = 0; j < N; j++) {
             C[i * N + j] = 0.0;

         }
     }

     /*retorna quantos "ticks" do processador passaram.*/
     clock_t inicio = clock();


     /*Calcula multiplicação*/
     for (int ii = 0; ii < N; ii+=BL) {
         for (int jj = 0; jj < N; jj+=BL) {
             for (int kk = 0; kk < N; kk+=BL) {
                 

                for(int i = ii; i < ii+BL; i++) {
                    for (int j = jj; j < jj+BL; j++) {
                        for (int k = kk; k < kk+BL; k++) {
                            C[i*N +j] += A[i*N + k] * B[k*N + j];
                        }
                    }
                }

             }
         }
     }

     /*Calcula o tempo total*/
     clock_t fim = clock();

     double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;        
     printf("Tempo: %f segundos\n", tempo);

     printf("%f\n",C[0]);


     /*Libera a alocação feita*/
     free(A);
     A = NULL;
     free(B);
     B = NULL;
     free(C);
     C = NULL;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>




int main (int argc, char *argv[] ) {         

     int N = atoi(argv[1]); /*converte o texto "512" para o número 512*/

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
     for (int i = 0; i < N; i++) {
         for (int j = 0; j < N; j++) {
             for (int k = 0; k < N; k++) {
                 C[i*N + j] += A[i*N + k] * B[k*N + j];

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
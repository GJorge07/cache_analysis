#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define TAMANHO_ARRAY (64 * 1024 * 1024) // 64 MB
#define REPETICOES 100


int main() {
    uint8_t *vetor = malloc(TAMANHO_ARRAY);
    if (!vetor) {
        perror("malloc");
        return 1;
    }

    /*Inicializa o vetor para garantir que as páginas de memória 
      sejam fisicamente alocadas pelo sistema operacional*/
    for (size_t i = 0; i < TAMANHO_ARRAY; i++) {
        vetor[i] = (uint8_t)i;
    }

    /*Cabeçalho da tabela de resultados*/
    printf("%-16s %-12s %-14s %-18s %-14s\n",
           "Passo(bytes)", "Tempo(s)", "Acessos", "ns/acesso", "MB lidos");
    printf("%-16s %-12s %-14s %-18s %-14s\n",
           "------------", "--------", "-------", "---------", "--------");

    for (size_t passo = 1; passo <= 1024; passo *= 2) {
        /*volatile impede o compilador de otimizar e remover o loop de soma*/
        volatile uint64_t soma = 0;
      
        size_t acessos_por_rep = TAMANHO_ARRAY / passo;
        size_t total_acessos   = (size_t)REPETICOES * acessos_por_rep;

       /*Registra o tempo de início do teste*/
        struct timespec inicio, fim;
        clock_gettime(CLOCK_MONOTONIC, &inicio);

        /*Executa as repetições de leitura aplicando o passo atual*/
        for (int rep = 0; rep < REPETICOES; rep++) {
            for (size_t i = 0; i < TAMANHO_ARRAY; i += passo) {
                soma += vetor[i];
            }
        }

        /*Calcula o tempo total decorrido em segundos*/
        clock_gettime(CLOCK_MONOTONIC, &fim);
        double tempo_s = (fim.tv_sec  - inicio.tv_sec)
                       + (fim.tv_nsec - inicio.tv_nsec) / 1e9;
        double ns_por_acesso = (tempo_s * 1e9) / (double)total_acessos;
        double mb_lidos      = (double)total_acessos / (1024.0 * 1024.0);

        printf("%-16zu %-12.6f %-14zu %-18.3f %-14.1f\n",
               passo, tempo_s, total_acessos, ns_por_acesso, mb_lidos);
    }
    free(vetor);
    return 0;
}

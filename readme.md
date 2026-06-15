# Análise de Desempenho de Cache — Multiplicação de Matrizes

Trabalho prático da disciplina de Arquitetura de Computadores

## Como executar
- Gere o executável com: gcc matriz.c -o matriz
- Rode com ./matriz N, sendo N um número inteiro que representa o tamanho das matrizes
- Para o Bloco, faça o mesmo, mas também passe o tamanho B do bloco assim: ./bloco N B

## Objetivo

Comparar o desempenho da multiplicação de matrizes na versão normal (loop triplo simples) contra a versão em bloco,  analisando o impacto da hierarquia de cache no tempo de execução.

## Arquivos

- matriz.c — multiplicação naïve (loop triplo i, j, k)
- matriz_bloco.c — multiplicação blocada (6 loops com bloco de tamanho B)
- resultados.csv — resultados coletados durante os testes

## Máquina onde foram feitos os testes?

- CPU: Intel Core i7 (12 núcleos)
- L1d: 448 KiB (37KB por núcleo)
- L2: 14 MiB
- L3: 18 MiB
- SO: Linux Ubuntu
- Compilador: GCC

Obs: máquina diferente da utilizada nos testes do relatório

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define TAMANHO_TEXTO 43
#define QTD_LETRAS 26
#define espaco	32

using namespace std;

char mono(char ch_chave[QTD_LETRAS], char ch_texto_de_entrada[TAMANHO_TEXTO], char ch_tarefa_escolhida);
char print_criptografica_mono(char ch_chave[QTD_LETRAS], char ch_texto_claro[TAMANHO_TEXTO]);
char print_descriptografica_mono(char ch_chave[QTD_LETRAS], char ch_texto_criptografado[TAMANHO_TEXTO]);

/*
O prototipo da função deverá ser:
function ['texto cifrado'] = mono(chave, 'texto claro', 'crip')
Exemplo de chave: abcdefghijklmnopqrstuvwxyz - primeira letra corresponde a a, assim por diante
Ex2: bcdefghijklmnopqrstuvwxyza'
*/

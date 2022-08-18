#ifndef	_APP_H
	#define	_APP_H

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TEXTO 43
#define QTD_LETRAS 26

char cesar(char ch_chave, char ch_texto_claro[TAMANHO_TEXTO], char ch_cripto);
char print_criptografica_cesar(unsigned int * ui8_chave, char ch_texto_claro[TAMANHO_TEXTO]);
char print_descriptografica_cesar(unsigned int * ui8_chave, char ch_texto_claro[TAMANHO_TEXTO]);
void set_chave(char ch_chave, unsigned int * ui8_chave);
void print_todas_possibilidades_de_chaves();

// The quick brown fox jumps over the lazy dog - 35 letras + 8 espacos

//O prototipo da função deverá ser:
//function ['texto_cifrado'] = cesar(chave, 'texto_claro', 'crip')
//onde:
//'texto_cifrado': string ASCII contendo o texto cifrado
//chave: uma string ASCII contendo a letra do alfabeto que corresponde a letra 'a'
//'texto_claro': string ASCII contendo o texto claro
//'cript' : 'c' para cifragem, 'd' para decifragem

#endif

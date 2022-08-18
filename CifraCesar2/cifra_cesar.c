#include "cifra_cesar.h"

/*
 *  function	: cesar
 *  inputs		: char ch_chave - chave da cifra cesar
 *                char ch_texto_claro[TAMANHO_TEXTO] - texto usado na cifra
 			 	  char ch_cripto - criptografar/descriptografar
 *  return		: - 
 *
 *  author		: Sergio e George
 *  create		: 12/11/2021
 *  modified	: .. / .. / ....
 *  description : executa a criptografica ou descriptorafia e chame as funções que imprimem as mesmas
 */
char cesar(char ch_chave, char ch_texto_claro[TAMANHO_TEXTO], char ch_cripto)
{
	unsigned int ui8_chave = 0;
	
	set_chave(ch_chave, &ui8_chave);
	
	if(ch_cripto == 'c')
		print_criptografica_cesar(&ui8_chave, ch_texto_claro);
	else
		print_descriptografica_cesar(&ui8_chave, ch_texto_claro);		
}

/*
 *  function	: print_criptografica_cesar
 *  inputs		: unsigned int * ui8_chave - chave da cifra cesar
 *                char ch_texto_claro[TAMANHO_TEXTO] - texto usado na cifra
 *  return		: - 
 *
 *  author		: Sergio e George
 *  create		: 12/11/2021
 *  modified	: .. / .. / ....
 *  description : imprime a criptografia cesar
 */
char print_criptografica_cesar(unsigned int * ui8_chave, char ch_texto_claro[TAMANHO_TEXTO])
{
	unsigned int ui8_index = 0;

    for (ui8_index = 0; ui8_index < TAMANHO_TEXTO; ui8_index++) 
    {
    	if(ch_texto_claro[ui8_index] == ' ')
    		printf("%c", ch_texto_claro[ui8_index]);
    	else
			printf("%c", (ch_texto_claro[ui8_index] - 'a' + *ui8_chave) % QTD_LETRAS + 'a');
    }
    printf("\r\n");
}

/*
 *  function	: print_descriptografica_cesar
 *  inputs		: unsigned int * ui8_chave - chave da cifra cesar
 *                char ch_texto_claro[TAMANHO_TEXTO] - texto usado na cifra
 *  return		: - 
 *
 *  author		: Sergio e George
 *  create		: 12/11/2021
 *  modified	: .. / .. / ....
 *  description : imprime a descriptografia cesar
 */
char print_descriptografica_cesar(unsigned int * ui8_chave, char ch_texto_claro[TAMANHO_TEXTO])
{
	unsigned int ui8_index = 0;
	char ch_buffer = 0;
		
	for (ui8_index = 0; ui8_index < TAMANHO_TEXTO; ui8_index++) 
	{
		if(ch_texto_claro[ui8_index] == ' ')
			printf("%c", ch_texto_claro[ui8_index]); 
		else
//			printf("%c", (ch_texto_claro[ui8_index] - 'a' + *ui8_chave) % QTD_LETRAS + 'a');
			printf("%c", (ch_texto_claro[ui8_index] - 'a' - *ui8_chave) % QTD_LETRAS + 'a');	
    }
}

/*
 *  function	: set_chave
 *  inputs		: char ch_chave - chave recebida
 *                unsigned int * ui8_chave - chave alterada
 *  return		: - 
 *
 *  author		: Sergio e George
 *  create		: 12/11/2021
 *  modified	: .. / .. / ....
 *  description : seta um valor inteiro para o caracter recebido como chave 
 */
void set_chave(char ch_chave, unsigned int * ui8_chave)
{
	switch(ch_chave)
	{
		case 'a':
			*ui8_chave = 0;
			break;
		case 'b':
			*ui8_chave = 1;
			break;
		case 'c':
			*ui8_chave = 2;
			break;
		case 'd':
			*ui8_chave = 3;
			break;
		case 'e':
			*ui8_chave = 4;
			break;
		case 'f':
			*ui8_chave = 5;
			break;
		case 'g':
			*ui8_chave = 6;
			break;
		case 'h':
			*ui8_chave = 7;
			break;
		case 'i':
			*ui8_chave = 8;
			break;
		case 'j':
			*ui8_chave = 9;
			break;
			*ui8_chave = 10;
		case 'k':
			*ui8_chave = 11;
			break;
		case 'l':
			*ui8_chave = 12;
			break;
		case 'm':
			*ui8_chave = 13;
			break;
		case 'n':
			*ui8_chave = 14;
			break;
		case 'o':
			*ui8_chave = 15;
			break;
		case 'p':
			*ui8_chave = 16;
			break;
		case 'q':
			*ui8_chave = 17;
			break;
		case 'r':
			*ui8_chave = 18;
			break;
		case 's':
			*ui8_chave = 19;
			break;
		case 't':
			*ui8_chave = 20;
			break;
		case 'u':
			*ui8_chave = 21;
			break;
		case 'v':
			*ui8_chave = 22;
			break;
		case 'w':
			*ui8_chave = 23;
			break;
		case 'x':
			*ui8_chave = 24;
			break;
		case 'y':
			*ui8_chave = 25;
			break;
		case 'z':
			*ui8_chave = 26;
			break;
			
			
	}
}

/*
 *  function	: print_todas_possibilidades_de_chaves
 *  inputs		: -
 *                -
 *  return		: - 
 *
 *  author		: Sergio e George
 *  create		: 12/11/2021
 *  modified	: .. / .. / ....
 *  description : imprime todas as possibilidades da criptografica cesar
 */
void print_todas_possibilidades_de_chaves()
{
	unsigned int ui8_chave = 0;
	
	for(ui8_chave = 0; ui8_chave <= 26; ui8_chave++)
	{
		if(ui8_chave==0)
			printf("Texto Claro: ");
		else
			printf("%d#: ", ui8_chave);
		print_criptografica_cesar(&ui8_chave, "the quick brown fox jumps over the lazy dog");
	}
}


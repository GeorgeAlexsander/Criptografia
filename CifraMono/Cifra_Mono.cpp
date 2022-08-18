#include "Cifra_Mono.h"

/*
 *  function	: mono
 *  inputs		: char ch_chave[QTD_LETRAS] - chave da cifra mono
 *                char ch_texto_de_entrada[TAMANHO_TEXTO] - texto usado na cifra
 			 	  char ch_cripto - char utilizada mara definiri qual operação deseja
 *  return		: - 
 *
 *  author		: Sergio e George
 *  create		: 12/11/2021
 *  modified	: .. / .. / ....
 *  description : executa a criptografica ou descriptorafia e chame as funções que imprimem as mesmas
 */
char mono(char ch_chave[QTD_LETRAS], char ch_texto_de_entrada[TAMANHO_TEXTO], char ch_tarefa_escolhida)
{
	if(ch_tarefa_escolhida == 'c')
		print_criptografica_mono(ch_chave, ch_texto_de_entrada);
	else if(ch_tarefa_escolhida == 'd')
		print_descriptografica_mono(ch_chave, ch_texto_de_entrada);
}

/*
 *  function	: criptografica_letra
 *  inputs		: char letra[QTD_LETRAS] - chave da cifra mono, possui como tamanho as 26 letras válidas no padrão ASCII
 *				  char ch_texto_criptografado - texto usado na cifra
 *  return		: - 
 *
 *  author		: Sergio e George
 *  create		: 12/11/2021
 *  modified	: .. / .. / ....
 *  description : testa o texto criptografado e utilizando da chave, retorna a letra descriptografada.
 */
 
 int criptografica_letra(char ch_letra)
{
	if(isalpha(ch_letra))
	{
		ch_letra=tolower(ch_letra);
		return ch_letra-97;
	} 
 	return espaco; 
}

/*
 *  function	: print_criptografica_mono
 *  inputs		: char ch_chave[QTD_LETRAS] - chave da cifra mono, possui como tamanho as 26 letras válidas no padrão ASCII
 *				  char ch_texto_claro[TAMANHO_TEXTO] - texto usado na cifra
 *  return		: - 
 *
 *  author		: Sergio e George
 *  create		: 12/11/2021
 *  modified	: .. / .. / ....
 *  description : imprime a criptografia mono
 */
 
char print_criptografica_mono(char ch_chave[QTD_LETRAS], char ch_texto_claro[TAMANHO_TEXTO])
{
	unsigned int ui8_index = 0;
	unsigned int ui8_troca_letra;

	printf("Texto Claro: \n");
    for (ui8_index = 0; ui8_index < TAMANHO_TEXTO; ui8_index++) 
		printf("%c", ch_texto_claro[ui8_index]);
    printf("\r\n");
    
	printf("Texto Criptografado: \n");
    for (ui8_index = 0; ui8_index < TAMANHO_TEXTO; ui8_index++) 
    {
   	 	ui8_troca_letra=criptografica_letra(ch_texto_claro[ui8_index]);

   	 	if(ui8_troca_letra==espaco)
   	 		printf("%c", espaco);
		else
			printf("%c", ch_chave[ui8_troca_letra]);	
	}
	printf("\r\n");

}

/*
 *  function	: descriptografica_letra
 *  inputs		: char ch_chave[QTD_LETRAS] - chave da cifra mono, possui como tamanho as 26 letras válidas no padrão ASCII
 *				  char ch_texto_criptografado - texto usado na cifra
 *  return		: - 
 *
 *  author		: Sergio e George
 *  create		: 12/11/2021
 *  modified	: .. / .. / ....
 *  description : testa o texto criptografado e utilizando da chave, retorna a letra descriptografada.
 */
 
int descriptografica_letra(char ch_chave[QTD_LETRAS], char ch_letra_criptografada)
{
	if(isalpha(ch_letra_criptografada))
	{
		ch_letra_criptografada=tolower(ch_letra_criptografada);
		
		for(int posicao_da_letra=0;posicao_da_letra<=25;posicao_da_letra++)
		{
				ch_chave[posicao_da_letra]=tolower(ch_chave[posicao_da_letra]);
				if(ch_chave[posicao_da_letra]==ch_letra_criptografada)
				{
					return posicao_da_letra;
				}
		}
	} 
 else
 	return espaco; 
}

/*
 *  function	: print_descriptografica_mono
 *  inputs		: char ch_chave[QTD_LETRAS] - chave da cifra mono, possui como tamanho as 26 letras válidas no padrão ASCII
 *				  char ch_texto_criptografado - texto usado na cifra
 *  return		: - 
 *
 *  author		: Sergio e George
 *  create		: 12/11/2021
 *  modified	: .. / .. / ....
 *  description : imprime a frase descriptografada
 */
 
char print_descriptografica_mono(char ch_chave[QTD_LETRAS], char ch_texto_criptografado[TAMANHO_TEXTO])
{
	unsigned int ui8_index = 0;
	unsigned int ui8_troca_letra;

	printf("------------------------------------------------\n");
	printf("Texto Criptografado: \n");
    for (ui8_index = 0; ui8_index < TAMANHO_TEXTO; ui8_index++) 
		printf("%c", ch_texto_criptografado[ui8_index]);
    printf("\r\n");
    
    printf("Texto Descriptografado: \n");
    for (ui8_index = 0; ui8_index < TAMANHO_TEXTO; ui8_index++) 
    {
   	 	ui8_troca_letra=descriptografica_letra(ch_chave, ch_texto_criptografado[ui8_index]);
   	 	if(ui8_troca_letra==espaco)
   	 		printf("%c", espaco);
		else
			printf("%c", 97+ui8_troca_letra);	
	}
}


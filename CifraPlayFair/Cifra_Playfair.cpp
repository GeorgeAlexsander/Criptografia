
#include "Cifra_Playfair.h"

int i_posicao[2];

/*
 *  function	: busca_posicao_da_letra_na_matriz
 *  inputs		: char  ch_chave_playfair[5][5] - matriz 5x5 com a chave playfair
 *				  char ch_letra_criptografado - letra a ser buscada
 *  return		: - 
 *
 *  author		: Sergio e George
 *  create		: 12/11/2021
 *  modified	: .. / .. / ....
 *  description : modifica a variavel global i_posicao com a posição que foi encontrada a letra. Para busca, caso seja um J é trocado por I.
 */
int busca_posicao_da_letra_na_matriz(char ch_chave_playfair[5][5], char ch_letra_criptografado)
{
	if(ch_letra_criptografado=='J')
		ch_letra_criptografado='I';

	for(int percorrelinha=0;percorrelinha<=4;percorrelinha++)
		for(int percorrecoluna=0;percorrecoluna<=4;percorrecoluna++)
			if(ch_chave_playfair[percorrelinha][percorrecoluna] == ch_letra_criptografado)
			{
				i_posicao[0]=percorrelinha;
				i_posicao[1]=percorrecoluna;
			}
}

/*
 *  function	: troca_letra_coluna_ou_linha_igual
 *  inputs		: bool estado - determina se deseja um deslocamento vertical ou diagonal
 *				  int i_posicao_primeiro_termo_do_par[2] - recebe um inteiro com a posição da primeira letra do par.
 *				  int i_posicao_segundo_termo_do_par[2] - recebe um inteiro com a posição da segunda letra do par.
 *   			  char  ch_chave_playfair[5][5] - matriz 5x5 com a chave playfair
 *  return		: -
 *
 *  author		: Sergio e George
 *  create		: 12/11/2021
 *  modified	: .. / .. / ....
 *  description : Mostra o par de letras descriptografada em situação de linhas ou colunas iguais.
 */
void troca_letra_coluna_ou_linha_igual(bool estado, char ch_chave_playfair[5][5], int i_posicao_primeiro_termo_do_par[2], int i_posicao_segundo_termo_do_par[2]) // como era posicao 1 ou 0 e no outro vai ser o contrario, troquei por estado e !estado e usei em ambos.
{
	if(i_posicao_primeiro_termo_do_par[estado]==0)
		i_posicao_primeiro_termo_do_par[estado]=4;
	else
		i_posicao_primeiro_termo_do_par[estado]=i_posicao_primeiro_termo_do_par[estado]-1;
	
	if(i_posicao_segundo_termo_do_par[estado]==0)
		i_posicao_segundo_termo_do_par[estado]=4;
	else
		i_posicao_segundo_termo_do_par[estado]=i_posicao_segundo_termo_do_par[estado]-1;
	
	cout <<	ch_chave_playfair[i_posicao_primeiro_termo_do_par[0]][i_posicao_primeiro_termo_do_par[1]] << ch_chave_playfair[i_posicao_segundo_termo_do_par[0]][i_posicao_segundo_termo_do_par[1]];
	
}

/*
 *  function	: espelha_letras_coluna_e_linha_diferentes
 *  inputs		: int i_posicao_primeiro_termo_do_par[2] - recebe um inteiro com a posição da primeira letra do par.
 *				  int i_posicao_segundo_termo_do_par[2] - recebe um inteiro com a posição da segunda letra do par.
 *   			  char  ch_chave_playfair[5][5] - matriz 5x5 com a chave playfair
 *  return		: -
 *
 *  author		: Sergio e George
 *  create		: 12/11/2021
 *  modified	: .. / .. / ....
 *  description : Mostra o par de letras descriptografada em situação de linhas ou colunas diferentes.
 */
void espelha_letras_coluna_e_linha_diferentes(char ch_chave_playfair[5][5], int i_posicao_primeiro_termo_do_par[2], int i_posicao_segundo_termo_do_par[2]){
	cout << ch_chave_playfair[i_posicao_primeiro_termo_do_par[0]][i_posicao_segundo_termo_do_par[1]] << ch_chave_playfair[i_posicao_segundo_termo_do_par[0]][i_posicao_primeiro_termo_do_par[1]];
}

/*
 *  function	: descriptografa_par_de_letras
 *  inputs		: int i_posicao_primeiro_termo_do_par[2] - recebe um inteiro com a posição da primeira letra do par.
 *				  int i_posicao_segundo_termo_do_par[2] - recebe um inteiro com a posição da segunda letra do par.
 *   			  char  ch_chave_playfair[5][5] - matriz 5x5 com a chave playfair
 *  return		: -
 *
 *  author		: Sergio e George
 *  create		: 12/11/2021
 *  modified	: .. / .. / ....
 *  description : Define qual operação deve ser realizada: se deve-se deslocar verticalmente, horizontalmente ou espelhar a posição do par em relação a matriz.
 */
int descriptografa_par_de_letras(char ch_chave_playfair[5][5], int i_posicao_primeiro_termo_do_par[2], int i_posicao_segundo_termo_do_par[2])
{
	if(i_posicao_primeiro_termo_do_par[1] == i_posicao_segundo_termo_do_par[1])
		troca_letra_coluna_ou_linha_igual(MESMA_LINHA, ch_chave_playfair, i_posicao_primeiro_termo_do_par, i_posicao_segundo_termo_do_par);
	
	else if(i_posicao_primeiro_termo_do_par[0] == i_posicao_segundo_termo_do_par[0])
		troca_letra_coluna_ou_linha_igual(MESMA_COLUNA, ch_chave_playfair, i_posicao_primeiro_termo_do_par, i_posicao_segundo_termo_do_par);
	
	else
		espelha_letras_coluna_e_linha_diferentes(ch_chave_playfair, i_posicao_primeiro_termo_do_par, i_posicao_segundo_termo_do_par);
}

/*
 *  function	: descriptografar_playfair
 *  inputs		: char  ch_texto_criptografado[TAMANHO_TEXTO] - texto cripttografado
 *  return		: -
 *
 *  author		: Sergio e George
 *  create		: 12/11/2021
 *  modified	: .. / .. / ....
 *  description : recebe o texto criptografado, carrega a chave de criptografia e chama as funções que devem ser executadas no processo de descriptografia.
 */
char descriptografar_playfair(char ch_texto_criptografado[TAMANHO_TEXTO])
{	
  
	int i_posicao_primeiro_termo_do_par[2], i_posicao_segundo_termo_do_par[2], posicao_do_par_na_frase_criptografada=36;
	
	char ch_chave_playfair[5][5] = 
	{
		{'R','O','Y','A','L'},
		{'N','E','W','Z','D'},
		{'V','B','C','F','G'},
		{'H','I','K','M','P'},
		{'Q','S','T','U','X'}
	};

	for(posicao_do_par_na_frase_criptografada=0; posicao_do_par_na_frase_criptografada<=98; posicao_do_par_na_frase_criptografada=posicao_do_par_na_frase_criptografada+2)
	{	
	busca_posicao_da_letra_na_matriz(ch_chave_playfair,ch_texto_criptografado[posicao_do_par_na_frase_criptografada]);
	i_posicao_primeiro_termo_do_par[0]=i_posicao[0];
	i_posicao_primeiro_termo_do_par[1]=i_posicao[1];
	
	busca_posicao_da_letra_na_matriz(ch_chave_playfair,ch_texto_criptografado[posicao_do_par_na_frase_criptografada+1]);
	i_posicao_segundo_termo_do_par[0]=i_posicao[0];
	i_posicao_segundo_termo_do_par[1]=i_posicao[1];
	
	if(ch_texto_criptografado[posicao_do_par_na_frase_criptografada]=='T' and ch_texto_criptografado[posicao_do_par_na_frase_criptografada+1]=='T') 
		cout << "tt";
	else
		descriptografa_par_de_letras(ch_chave_playfair, i_posicao_primeiro_termo_do_par, i_posicao_segundo_termo_do_par);
	}
}

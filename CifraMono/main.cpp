#include "Cifra_Mono.h"

/*
 *  function	: main
 *  inputs		: -
 *                -
 *  return		:  int 
 *
 *  author		: Sergio e George 
 *  create		: 12/11/2021
 *  modified	: .. / .. / ....
 *  description : Função principal
 *  exemplo para teste: abcdefghijklnmopqrstvuwxyz  ||  TMLGESDQBIUJKRAYFZOCNHXPWV
 */
 
int main()
{
	char ch_chave[QTD_LETRAS];
	char ch_tarefa_escolhida;
	
	
	while(ch_tarefa_escolhida!='c' and ch_tarefa_escolhida!='d'){
		cout << "Digite 'c' para criptografar ou 'd' para descriptografar: " << endl;
		cin >> ch_tarefa_escolhida;
	}
	
	cout << "Digite a Chave de 26 digitos: " << endl;
	cin >> ch_chave;
		
	if(ch_tarefa_escolhida=='c')
		mono(ch_chave, (char*)"The Quick brown fox jumps over the lazy dog", 'c');
	
	else if(ch_tarefa_escolhida=='d')
		mono(ch_chave, (char*)"CQE FNBLU MZAXR SAP INKYO AHEZ CQE JTVW GAD", 'd'); // usado a chifra resultante da segunda chave de teste.
		
    return 0;
}

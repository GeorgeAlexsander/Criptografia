#include "cifra_cesar.h"

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
 */
 
int main() 
{
	printf("Texto Criptografado: \n");
	cesar('c', "the quick brown fox jumps over the lazy dog", 'c'); 
    return 0;
}

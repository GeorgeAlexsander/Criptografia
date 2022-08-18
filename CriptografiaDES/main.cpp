#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <bitset>
#include <iomanip>


using namespace std;

#define deslocar_uma_vez		1
#define deslocar_duas_vezes		2
#define tamanho_da_chave_PC1	56
#define tamanho_da_chave_PC2	48
#define tamanho_da_chave_64bits 64

#define parte_um // para exibir a saída do algoritmo de escalonamento (hex) (item 1 na descrição do trabalho)
#define parte_dois // para exibir a string criptografada e decriptografada e executar a função DES (item 2 na descrição do trabalho)

string chaves_geradas[16];
string texto_claro;

/*
 *  function	: converter_Decimal_para_Binario
 *  inputs		: string decimal  
 *  return		: int binario
 *
 *  author		: Sergio e George 
 *  create		: 05/12/2021
 *  modified	: .. / .. / ....
 *  description : converte um decimal para um binario
 */
 string converter_Decimal_para_Binario(int decimal)
{
	string binario;
    while(decimal != 0) {
		binario = (decimal % 2 == 0 ? "0" : "1") + binario; 
		decimal = decimal/2;
	}
	while(binario.length() < 4){
		binario = "0" + binario;
	}
    return binario;
}

/*
 *  function	: converter_Binario_para_Decimal
 *  inputs		: string binario  
 *  return		: int decimal
 *
 *  author		: Sergio e George 
 *  create		: 05/12/2021
 *  modified	: .. / .. / ....
 *  description : converte um binario para um decimal
 */
int converter_Binario_para_Decimal(string binario)
{
    int decimal = 0, tamanho = binario.length();
    
	for(int i = tamanho-1; i >= 0; i--)
    	decimal+=(binario[i] == '1' ? pow(2, tamanho-i-1) : 0);
	return decimal;	
}

/*
 *  function	: converter_HexChar_para_Binario
 *  inputs		: char c
 *  return		: const char 
 *  author		: Sergio e George 
 *  create		: 13/12/2021
 *  modified	: .. / .. / ....
 *  description : retorna o equivalente em binário do caracter hexadecimal 
 */
const char* converter_HexChar_para_Binario(char c)
{
    switch(toupper(c))
    {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
    }
}

/*
 *  function	: converter_Hexdecimal_para_Binario
 *  inputs		: const string& hex
 *  return		: string
 *  author		: Sergio e George 
 *  create		: 13/12/2021
 *  modified	: .. / .. / ....
 *  description : converte uma string hexadecimal em seu equivalente binário
 */
string converter_Hexdecimal_para_Binario(const string& hex)
{
    string bin;
    for(unsigned i = 0; i != hex.length(); ++i)
       bin += converter_HexChar_para_Binario(hex[i]);
    return bin;
}

/*
 *  function	: converter_Binario_para_Hexadecimal
 *  inputs		: const string 
 *  return		: string
 *  author		: Sergio e George 
 *  create		: 13/12/2021
 *  modified	: .. / .. / ....
 *  description : converte Binario para Hexadecimal
 */
string converter_Binario_para_Hexadecimal(const string& bin)
{
	string binToHex;
	for (size_t i = 0; i < bin.size(); i += 4) {
	    string tmp = bin.substr(i, 4);
	    binToHex += (tmp[0] == '0' ?
	                    (tmp[1] == '0' ?
	                        (tmp[2] == '0' ?
	                            (tmp[3] == '0' ? "0" : "1") :
	                            (tmp[3] == '0' ? "2" : "3")) :
	                        (tmp[2] == '0' ?
	                            (tmp[3] == '0' ? "4" : "5") :
	                            (tmp[3] == '0' ? "6" : "7"))) :
	                    (tmp[1] == '0' ?
	                        (tmp[2] == '0' ?
	                            (tmp[3] == '0' ? "8" : "9") :
	                            (tmp[3] == '0' ? "a" : "b")) :
	                        (tmp[2] == '0' ?
	                            (tmp[3] == '0' ? "c" : "d") :
	                            (tmp[3] == '0' ? "e" : "f"))));
	}
	return binToHex;
}

/*
 *  function	: xor
 *  inputs		: string a - string a ser o parametro a da xor
 *				  string b - string a ser o parametro b da xor
 *
 *  return		: string result - resultado das operações boleanas concatenadas em um string
 *
 *  author		: Sergio e George 
 *  create		: 05/12/2021
 *  modified	: .. / .. / ....
 *  description : função que efetua a operação xor bit a bit das strings a e b
 */
 string Xor(string a, string b){ 
	string result = ""; 
	int tamanho = b.size();

	for(int i = 0; i < tamanho; i++)
		result += (a[i]^b[i])+'0';	
	return result; 
} 
 
/*
 *  function	: desloca_para_Esquerda
 *  inputs		: string chave  
 *				  int qtd_vezes_a_deslocar - variavel que define se vai deslocar uma ou duas vezes             
 *  return		: string
 *
 *  author		: Sergio e George 
 *  create		: 05/12/2021
 *  modified	: .. / .. / ....
 *  description : função que efetua o deslocamento para esquerda, deslocando n vezes do valor recebido na variavel qtd_vezes_a_deslocar
 */
string desloca_para_Esquerda(string chave_parcial, int rodada_de_deslocamento){ 
	int qtd_vezes_a_deslocar = (rodada_de_deslocamento==0 or rodada_de_deslocamento==1 or rodada_de_deslocamento==8 or rodada_de_deslocamento==15 ? deslocar_uma_vez : deslocar_duas_vezes);
	
    string texto_deslocado=""; 
    for(int i = 0; i < qtd_vezes_a_deslocar; i++){ 
        for(int j = 1; j < 28; j++){ 
        	texto_deslocado += chave_parcial[j]; 
        } 
        texto_deslocado += chave_parcial[0]; 
        chave_parcial= texto_deslocado; 
        texto_deslocado=""; 
    } 
    return chave_parcial; 
}

/*
 *  function	: escalonar_Chave
 *  inputs		: string chave - chave a ser escalonada 
 *				  int tamanho_do_parametro_de_escalonamento - tamanho de PC1 ou de PC2
 *				  int parametro_de_escalonamento_de_chaves - parametro do algoritmo de escalonamento de chaves
 *  return		: -
 *
 *  author		: Sergio e George 
 *  create		: 05/12/2021
 *  modified	: .. / .. / ....
 *  description : função que efetua o escalonamento de chaves com base nos parametros de escalonamento
 */
string escalonar_Chave(string chave, int tamanho_do_parametro_de_escalonamento, int parametro_de_escalonamento_de_chaves[])
 {
 	string chave_escalonada = "";
  	for(int posicao = 0; posicao < tamanho_do_parametro_de_escalonamento; posicao++){ 
		chave_escalonada+=chave[parametro_de_escalonamento_de_chaves[posicao]-1]; 
	} 
	return chave_escalonada;
 }
 
/*
 *  function	: gerar_Chaves
 *  inputs		: string chave
 *
 *  return		: -
 *
 *  author		: Sergio e George 
 *  create		: 05/12/2021
 *  modified	: .. / .. / ....
 *  description : função que efetua a geração das chaves
 */
void gerar_Chaves(string chave){

	extern int chave_PC1[56], chave_PC2[48];
	int rodada_de_deslocamento;
	string chave_escalonada =""; 
	
	chave_escalonada=escalonar_Chave(chave, tamanho_da_chave_PC1, chave_PC1);

	string parte_esquerda_da_chave= chave_escalonada.substr(0, 28); 
	string parte_direita_da_chave= chave_escalonada.substr(28, 28); 
	
	for(rodada_de_deslocamento=0; rodada_de_deslocamento<16; rodada_de_deslocamento++){ 
		parte_esquerda_da_chave= desloca_para_Esquerda(parte_esquerda_da_chave, rodada_de_deslocamento); 
		parte_direita_da_chave= desloca_para_Esquerda(parte_direita_da_chave, rodada_de_deslocamento);
		
		string chave_combinada = parte_esquerda_da_chave + parte_direita_da_chave;
		string chave_da_rodada = ""; 
		
		chave_da_rodada=escalonar_Chave(chave_combinada, tamanho_da_chave_PC2, chave_PC2);
 
		chaves_geradas[rodada_de_deslocamento] = chave_da_rodada; 
		#ifdef parte_um
			cout<<"Chave " << rodada_de_deslocamento+1 << " (Hex): "<<converter_Binario_para_Hexadecimal(chave_da_rodada)<<endl;
		#endif
	}
} 

/*
 *  function	: DES
 *  inputs		: -
 *  return		: string
 *
 *  author		: Sergio e George 
 *  create		: 05/12/2021
 *  modified	: .. / .. / ....
 *  description : função que efetua o gerênciamento das demais funções, efetuando as expanções e permutações de chaves, et cetera
 */
string DES(){ 
	extern int gl_IP[64], gl_invIP[64], gl_Expansion[48], gl_Permutation[32], gl_substition_Boxes[8][4][16];

  	string chave_permutada = ""; 
	
	for(int percorre_tamanho_da_chave = 0; percorre_tamanho_da_chave < tamanho_da_chave_64bits; percorre_tamanho_da_chave++){ 
		chave_permutada += texto_claro[gl_IP[percorre_tamanho_da_chave]-1]; 
	}  
	
	string parte_esquerda_da_chave = chave_permutada.substr(0, 32); 
	string parte_direita_da_chave = chave_permutada.substr(32, 32);

	for(int percorre_chaves_geradas=0; percorre_chaves_geradas<16; percorre_chaves_geradas++)
	{
    	string expancao_pela_direita = ""; 
    	
    	for(int percorre_chave_PC2 = 0; percorre_chave_PC2 < tamanho_da_chave_PC2; percorre_chave_PC2++) { 
      		expancao_pela_direita += parte_direita_da_chave[gl_Expansion[percorre_chave_PC2]-1]; 
    	}; 
		
		string xored = Xor(chaves_geradas[percorre_chaves_geradas], expancao_pela_direita);  
		string res = ""; 

		for(int percorre_substition_Boxes=0;percorre_substition_Boxes<8; percorre_substition_Boxes++){ 
			string linha1= xored.substr(percorre_substition_Boxes*6,1) + xored.substr(percorre_substition_Boxes*6 + 5,1);
      		int linha = converter_Binario_para_Decimal(linha1);
      		string coluna1 = xored.substr(percorre_substition_Boxes*6 + 1,1) + xored.substr(percorre_substition_Boxes*6 + 2,1) + xored.substr(percorre_substition_Boxes*6 + 3,1) + xored.substr(percorre_substition_Boxes*6 + 4,1);;
			int coluna = converter_Binario_para_Decimal(coluna1);
			int val = gl_substition_Boxes[percorre_substition_Boxes][linha][coluna];
			res += converter_Decimal_para_Binario(val);  
		} 

		string perm2 =""; 
		for(int aplicar_permutacao = 0; aplicar_permutacao < 32; aplicar_permutacao++){ 
			perm2 += res[gl_Permutation[aplicar_permutacao]-1]; 
		}

		xored = Xor(perm2, parte_esquerda_da_chave);

		parte_esquerda_da_chave = xored; 
		
		if(percorre_chaves_geradas < 15){ 
			string temp = parte_direita_da_chave;
			parte_direita_da_chave = xored;
			parte_esquerda_da_chave = temp;
		} 
	} 

	string texto_combinado = parte_esquerda_da_chave + parte_direita_da_chave;   
	string ciphertext =""; 

	for(int aplica_permutacao_inversa = 0; aplica_permutacao_inversa < 64; aplica_permutacao_inversa++){ 
		ciphertext+= texto_combinado[gl_invIP[aplica_permutacao_inversa]-1]; 
	}

	return ciphertext; 
}


/*
 *  function	: main
 *  inputs		: -
 *                -
 *  return		:  int 
 *
 *  author		: Sergio e George 
 *  create		: 05/12/2021
 *  modified	: .. / .. / ....
 *  description : Função principal
 */
int main()
{ 

#ifdef parte_um
	string chave= "f49d7b07c3ee29ef";
	cout << "Printar as chaves 16 de rodada em Hexadecimal" << endl;
	chave = converter_Hexdecimal_para_Binario(chave);
	gerar_Chaves(chave); 
#endif

#ifdef parte_dois
	#ifndef parte_um
		string chave = "f49d7b07c3ee29ef";
		chave = converter_Hexdecimal_para_Binario(chave);
		gerar_Chaves(chave); 
	#endif
	
	texto_claro= "000066f750b3ebdc";
    cout<<endl<<"Texto Claro (Hex): "<<texto_claro<<endl; 
	texto_claro = converter_Hexdecimal_para_Binario(texto_claro);
	cout<<"Texto Claro (Bin): "<<texto_claro<<endl; 
	
	string apt = texto_claro;

  	
    string texto_cifrado= DES(); 
    cout<<"Texto Cifrado (Bin): "<<texto_cifrado<<endl;
    cout<<"Texto Cifrado (Hex): "<<converter_Binario_para_Hexadecimal(texto_cifrado)<<endl;

	int i = 15;
	int j = 0;
	while(i > j)
	{
		string temp = chaves_geradas[i];
		chaves_geradas[i] = chaves_geradas[j];
		chaves_geradas[j] = temp;
		i--;
		j++;
	}
	texto_claro = texto_cifrado;
	string texto_descriptografado = DES();
	cout<<"Texto Descriptografado (Bin): "<<texto_descriptografado<<endl;
	cout<<"Texto Descriptografado (Hex): "<<converter_Binario_para_Hexadecimal(texto_descriptografado)<<endl;

	if (texto_descriptografado == apt)
		cout<<"Texto plano criptografado e descriptografado com sucesso."<<endl;
#endif
} 





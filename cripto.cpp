#include "cripto.h"

unsigned long long Codificar(int entrada, int gerado1, int gerado2, int gerado3, int gerado4, int gerado5, int gerado6)
{
	bool estado = false;
	unsigned int primeiraParte = 0;	//local temporário para armazenamento do valor codificado
	unsigned int segundaParte = 0;	//local temporário para armazenamento das posições dos bits alterados

	//primeiro bit alterado
	estado = TestarBit(entrada, gerado1); //verifica se o bit está ligado ou desligado
	if (estado)
		primeiraParte = DesligarBit(entrada,gerado1); //se estiver ligado, desliga o bit
	else
		primeiraParte = LigarBit(entrada, gerado1); //se estiver desligado, liga o bit
	segundaParte = gerado1 << 27; //armazena a posição do bit alterado
	
	//segundo bit alterado, repitindo o mesmo processo anterior
	estado = TestarBit(primeiraParte, gerado2);
	if (estado)
		primeiraParte = DesligarBit(primeiraParte, gerado2);
	else
		primeiraParte = LigarBit(primeiraParte, gerado2);
	segundaParte = segundaParte | (gerado2 << 22); //armazena a posição do bit alterado junto ao bit alterado anteriormente

	//terceiro bit alterado
	estado = TestarBit(primeiraParte, gerado3);
	if (estado)
		primeiraParte = DesligarBit(primeiraParte, gerado3);
	else
		primeiraParte = LigarBit(primeiraParte, gerado3);
	segundaParte = segundaParte | (gerado3 << 17);

	//quarto bit alterado
	estado = TestarBit(primeiraParte, gerado4);
	if (estado)
		primeiraParte = DesligarBit(primeiraParte, gerado4);
	else
		primeiraParte = LigarBit(primeiraParte, gerado4);
	segundaParte = segundaParte | (gerado4 << 12);

	//quinto bit alterado
	estado = TestarBit(primeiraParte, gerado5);
	if (estado)
		primeiraParte = DesligarBit(primeiraParte, gerado5);
	else
		primeiraParte = LigarBit(primeiraParte, gerado5);
	segundaParte = segundaParte | (gerado5 << 7);

	//sexto bit alterado
	estado = TestarBit(primeiraParte, gerado6);
	if (estado)
		primeiraParte = DesligarBit(primeiraParte, gerado6);
	else
		primeiraParte = LigarBit(primeiraParte, gerado6);
	segundaParte = segundaParte | (gerado6 << 2);

	//junta as duas partes (valor codificado + posições dos bits)
	unsigned long long saida = (long long(primeiraParte) << 32 | segundaParte);
	
	return(saida);
}

int Decodificar(unsigned long long entrada)
{
	int origem = Exibir(entrada,0);
	bool verificaEstado;

	//retorno da primeira posição alterada 
	verificaEstado = TestarBit(origem, Exibir(entrada, 1)); //verifica se o bit está ligado ou desligado
	if (verificaEstado)
		origem = DesligarBit(origem, Exibir(entrada, 1)); //se estiver ligado, desliga o bit
	else
		origem = LigarBit(origem, Exibir(entrada, 1)); //se estiver desligado, liga o bit

	//retorno da segunda posição alterada, repetindo o processo anterior 
	verificaEstado = TestarBit(origem, Exibir(entrada, 2));
	if (verificaEstado)
		origem = DesligarBit(origem, Exibir(entrada, 2));
	else
		origem = LigarBit(origem, Exibir(entrada, 2)); 

	//retorno da terceira posição alterada 
	verificaEstado = TestarBit(origem, Exibir(entrada, 3));
	if (verificaEstado)
		origem = DesligarBit(origem, Exibir(entrada, 3));
	else
		origem = LigarBit(origem, Exibir(entrada, 3));

	//retorno da quarta posição alterada 
	verificaEstado = TestarBit(origem, Exibir(entrada, 4));
	if (verificaEstado)
		origem = DesligarBit(origem, Exibir(entrada, 4));
	else
		origem = LigarBit(origem, Exibir(entrada, 4));

	//retorno da quinta posição alterada 
	verificaEstado = TestarBit(origem, Exibir(entrada, 5));
	if (verificaEstado)
		origem = DesligarBit(origem, Exibir(entrada, 5));
	else
		origem = LigarBit(origem, Exibir(entrada, 5));

	//retorno da sexta posição alterada 
	verificaEstado = TestarBit(origem, Exibir(entrada, 6));
	if (verificaEstado)
		origem = DesligarBit(origem, Exibir(entrada, 6));
	else
		origem = LigarBit(origem, Exibir(entrada, 6));

	return(origem); //retorna o número com seus bits nas posições ínicias
}

int LigarBit(int entrada, unsigned int posicao)
{
	//liga um bit de "entrada" com a posição especificada em "posicao" 
	int mascara = 1 << posicao;
	int saida = entrada | mascara;

	return(saida);
}

int DesligarBit(int entrada, unsigned int posicao)
{
	//desliga um bit de "entrada" com a posição especificada em "posicao" 
	int mascara = ~(1 << posicao);
	int saida = entrada & mascara;

	return(saida);
}

bool TestarBit(int entrada, unsigned int posicao)
{
	//verifica se um determinado bit que está na posição "posicao" do número "entrada" está ligado ou desligado
	bool saida;
	int mascara = 1 << posicao;

	if (entrada & mascara)
		saida = true;  // o bit testado está ligado
	else
		saida = false; // o bit testado está desligado

	return(saida);
}

int Exibir(unsigned long long entrada, short chave)
{
	//extrai infomações de um número codificado "entrada" de acordo com o parametro que se deseja, sendo especificado em "chave"

	if (chave == 0) //chave sendo 0, retorna apenas o valor codificado sem as posições dos bits alterados
	{
		unsigned long long valorCodificado = entrada >> 32;
		return(valorCodificado);
	}
	else
	{
		int posicao;
		if (chave == 1) //chave sendo 1, retorna apenas a posições do primeiro bit alterado
			posicao = (entrada << 32) >> 32 + 27;
		if (chave == 2) //chave sendo 2, retorna apenas a posições do segundo bit alterado
			posicao = (entrada << 37) >> 37 + 22;
		if (chave == 3) //chave sendo 3, retorna apenas a posições do terceiro bit alterado
			posicao = (entrada << 42) >> 42 + 17;
		if (chave == 4) //chave sendo 4, retorna apenas a posições do quarto bit alterado
			posicao = (entrada << 47) >> 47 + 12;
		if (chave == 5) //chave sendo 5, retorna apenas a posições do quinto bit alterado
			posicao = (entrada << 52) >> 52 + 7;
		if (chave == 6) //chave sendo 6, retorna apenas a posições do sexto bit alterado
			posicao = (entrada << 57) >> 57 + 2;
		return(posicao);
	}
}
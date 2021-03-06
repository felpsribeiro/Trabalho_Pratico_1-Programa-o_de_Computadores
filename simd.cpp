#include "simd.h"

int Armazena(int bloco1, int bloco2, int bloco3, int bloco4)
{
	//armazena 4 valores em apenas um n�mero int
	bloco1 = bloco1 << 24; //move os bits, aterando suas posi��es
	bloco2 = bloco2 << 16;
	bloco3 = bloco3 << 8;

	int saida = bloco1 | bloco2 | bloco3 | bloco4; //concatena os bit

	return (saida);
}

short Primeiro(int valor1)
{
	//extrai o primerio grupo de bit que representa o primerio n�mero armazenado
	valor1 = valor1 >> 24; 

	return (valor1);
}

short Segundo(int valor2)
{
	//extrai o segundo grupo de bit que representa o segundo n�mero armazenado
	valor2 = valor2 << 8;
	valor2 = valor2 >> 24;

	return (valor2);
}

short Terceiro(int valor3)
{
	//extrai o terceiro grupo de bit que representa o terceiro n�mero armazenado
	valor3 = valor3 << 16;
	valor3 = valor3 >> 24;

	return (valor3);
}

short Quarto(int valor4)
{
	//extrai o quarto grupo de bit que representa o quarto n�mero armazenado
	valor4 = valor4 << 24;
	valor4 = valor4 >> 24;

	return (valor4);
}

int Soma(int primeiroValor, int segundoValor)
{
	//soma os valores
	short soma1 = Primeiro(primeiroValor) + Primeiro(segundoValor); //extrai os pimeiros valores dos n�meros armazenados e os soma
	short soma2 = Segundo(primeiroValor) + Segundo(segundoValor); //repete o mesmo processo para os demais
	short soma3 = Terceiro(primeiroValor) + Terceiro(segundoValor);
	short soma4 = Quarto(primeiroValor) + Quarto(segundoValor);

	return (Armazena(soma1, soma2, soma3, soma4)); //retorna um n�mero com as quatro somas armazenadas
}

int Mult(int primeiroValor, int segundoValor)
{
	//multiplica os valores
	short mult1 = Primeiro(primeiroValor) * Primeiro(segundoValor); //extrai os pimeiros valores dos n�meros armazenados e os multiplica
	short mult2 = Segundo(primeiroValor) * Segundo(segundoValor); // repete o mesmo processo para os demais
	short mult3 = Terceiro(primeiroValor) * Terceiro(segundoValor);
	short mult4 = Quarto(primeiroValor) * Quarto(segundoValor);

	return (Armazena(mult1, mult2, mult3, mult4)); //retorna um n�mero com as quatro multiplica��es armazenadas
}
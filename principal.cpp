/*
	Aluno: Felipe Nascimento Riberio;
	Turma: Programação de Computadores/2019.2

	Trabalho Pratico 1 Unidade

*/

#include <iostream>
#include <iomanip>
#include <random>
#include "simd.h"
#include "cripto.h"
using namespace std;

int main()
{
	/*
	declaração das variáveis que seram inseridas no formato: 
				[xxx,xxx,xxx,xxx]
				[xxx,xxx,xxx,xxx] 		*/
	short x , y , z , w , a , b , c , d; 
	
	cin.ignore();	//para não armazenar os colchetes e as virgulas foi usado a função cin.ignore()
	cin >> x; cin.ignore(); 
	cin >> y; cin.ignore();
	cin >> z; cin.ignore();
	cin >> w; cin.ignore();
	cin.ignore();
	cin.ignore();
	cin >> a; cin.ignore();
	cin >> b; cin.ignore();
	cin >> c; cin.ignore(); 
	cin >> d; cin.ignore();
	cout << endl;
	
	//chamo a função Armazena para armazenar 4 valores em um int e exibo em seguida
	unsigned int bloco = Armazena(x, y, z, w);
	unsigned int bloco2 = Armazena(a, b, c, d);
	cout << "Operandos em 32 bits = "
		 << bloco << endl
		 << "Operandos em 32 bits = "
		 << bloco2 << endl
		 << endl;
	
	//chamo a função Soma e Mult e exibo em seguida
	int soma = Soma(bloco, bloco2);
	int mult = Mult(bloco, bloco2);
	cout << "Soma em 32 bits = "
		 << soma << endl
		 << "Mult em 32 bits = "
		 << mult << endl
    	 << endl;

	//chamo as funções que leem os valores das somas
	cout << "[";
	cout << setfill('0') << setw(3) << Primeiro(soma); // "setfill('0') << setw(3)" foi usado para exibir o número no formato "XXX", completando com zeros a esquerda
	cout << ",";
	cout << setfill('0') << setw(3) << Segundo(soma);
	cout << ",";
	cout << setfill('0') << setw(3) << Terceiro(soma);
	cout << ",";
	cout << setfill('0') << setw(3) << Quarto(soma);
	cout << "] = Somas\n";
	
	//chamo as funções que leem os valores das multiplicações
	cout << "[";
	cout << setfill('0') << setw(3) << Primeiro(mult);
	cout << ",";
	cout << setfill('0') << setw(3) << Segundo(mult);
	cout << ",";
	cout << setfill('0') << setw(3) << Terceiro(mult);
	cout << ",";
	cout << setfill('0') << setw(3) << Quarto(mult);
	cout << "] = Muliplicação\n"
	<< endl;
	
	//definições da função que gera os números aleatórios
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(0, 31); //espaço delimitado para os valores gerados: de 0 ate 31

	//Codifico os valores chamando a função Codificar e exibo em seguida
	unsigned long long somaCodificada = Codificar(soma, dist(mt), dist(mt), dist(mt), dist(mt), dist(mt), dist(mt));  //"dist(mt)" representa o número aleatório que será passado
	unsigned long long multCodificada = Codificar(mult, dist(mt), dist(mt), dist(mt), dist(mt), dist(mt), dist(mt));
	cout << "Soma Cripto 64 bits = " << somaCodificada << endl
		 << "Mult Cripto 64 bits = " << multCodificada << endl
		 << endl;

	//Chamo a função Exibir para exibir o valor codificado e as posições dos bits alterados
	cout << "Valor Codificado = " << Exibir(somaCodificada, 0)
		 << " (" << Exibir(somaCodificada, 1)
		 << " " << Exibir(somaCodificada, 2)
		 << " " << Exibir(somaCodificada, 3)
		 << " " << Exibir(somaCodificada, 4)
		 << " " << Exibir(somaCodificada, 5)
		 << " " << Exibir(somaCodificada, 6)
		 << ")\n"
	//Chamo a função Decodificar para decodificar os dados
		 << "Soma Decodificada = " << Decodificar(somaCodificada) << endl
		 << endl;
	
	//Repito o mesmo processo usado nos valores da soma para os valores da multiplicação
	cout << "Valor Codificado = " << Exibir(multCodificada, 0)
		<< " (" << Exibir(multCodificada, 1)
		<< " " << Exibir(multCodificada, 2)
		<< " " << Exibir(multCodificada, 3)
		<< " " << Exibir(multCodificada, 4)
		<< " " << Exibir(multCodificada, 5)
		<< " " << Exibir(multCodificada, 6)
		<< ")\n"
		<< "Mult Decodificada = " << Decodificar(multCodificada) << endl
		<< endl; 
} //Fim do programa
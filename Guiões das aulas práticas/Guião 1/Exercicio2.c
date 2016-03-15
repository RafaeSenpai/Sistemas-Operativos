#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/*
Exercicio 2
Implemente um programa que crie um ficheiro com 10MB de tamanho cujo nome é passado como ar-
gumento. O conteúdo do ficheiro propriamente dito é irrelevante: por exemplo, pode ser composto
exclusivamente pelo caractere ‘a’.
$ ./10mb 10mb.dat
*/

int main (int argc, char *argv[]){
int i; 
int file = open (argv[1], O_CREAT|O_WRONLY);/* file é o descritor de ficheiro para um ficheiro cujo seu nome é dado como argumento ao invocar a função, daí o arv[1] 
												(segundo argumento (0,1)), este será iniciado no modo P_CREAT(cria o ficheiro) e no modo O_WRONLY(escrita 
												no ficheiro), sendo estas propriedades definidas separadamente por pipes.*/

char c = 'a'; //c é a variavel que irá ser repetida tantas vezes quanto necessárias até o ficheiro ter o tamanho pretendido

	for(i=0; i<10000000; i++){ /* o numero é definido baseado apenas no tamanho em bytes do tipo de carater, uma vez que se trata de um char, este ocupa 1 byte, 
		                         então é necessário imprimi-lo cerca 10 000 000 vezes no ficheiro para este prefazer os 10MB*/
		write (file, &c, 1); //vai escrever o carater c no conteudo do apontador file, qualquer cena de tamanho 1 byte
	}
close(file);
}
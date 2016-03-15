#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
/* 
Exercicio 1
Implemente em C um programa mycat com funcionalidade similar ao comando cat. Comece por
suportar apenas o funcionamento como filtro, ou seja, deverá operar num ciclo de leitura de dados a
partir do standard input, processamento dos dados lidos, e escrita do resultado do processamento no
standard output. No caso particular do comando cat, nao há lugar a qualquer processamento mas sim à
pura e simples reproducao integral dos dados lidos. Na primeira versao leia do standard input caractere a
caractere. Recorde que a indicacao de fimde ficheiro (end of file) no standardinput resulta da combinacao
Control+D no inıcio de uma linha.
$ ./mycat-v1
linha
linha
outra
outra
*/

//Em suma, lê do stdin teclado, e imprime imediatamente no monitor a string escrita, terminando o ciclo com CTRL+D
int main ( ){
char c; // variavel de um byte criada para armazenar um carater apenas introduzido pelo stdin (teclado)
	do {
		read (0, &c, 1); // zero - dá ordem para ler do input para a variavel anteriormente criada; 
						 // &c - endereço da variavel onde se vai gravar; 
		                 // 1 diz respeito ao tamanho reservado para tal operação, 1 byte;
		
		write (1, &c, 1);// um - dá ordem para escrever no output; 
						 // &c - endereço da variavel onde está guardado o carater anteriormente escrito; 
		                 // 1 diz respeito ao tamanho reservado para tal operação, 1 byte;
	}
	while (c!= EOF); // termina quando for fim de ficheiro, isto é, CTRL-D, esta combinação é reconhecida graças a invocação de determinadas bibliotecas
	/*Aparentemente ele recebe um carater do stdin e imprime-o imediatamente, ciclicamente até que seja dado CTRL.D, mas na relaidade conforme é escrito 
	  no stdin, ele vai guardado os carateres, como que numa cache 'c_versão2' (char c) e ao final da sua escrita, quando primido ENTER, o programa descarrega 
	  tudo o que tem em cache, imprimindo assim o carater ou lista de carateres guardados até á entrada do ENTER.
}



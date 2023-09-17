/* jogo da forca */	

#include <iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;

int main(){

	string letra;
	string palavra;
	int chances;
	
	cout << "Quantas chances ? ";
	cin >> chances;
	
	cout << "Digite uma palavra: "; 
	cin >> palavra;
	
	cout << endl;

	// mede o tamanho da palavra e cria os vetores
	int tam=palavra.length();	
	string texto[tam];
	string tentativa[tam];

	int i, acerto=0, flagfim=0, erro=0;

	// gera vetor texto com cada letra da palavra e o vetor tentativa 	
	for(i=0; i<tam;i++){
		texto[i]=palavra[i];
		tentativa[i]="_";
	}

	// enquanto tiver chances vou chutando as letras ...		
	while (chances>0){
		i=0;
		acerto=0;
		cout << "change[" << chances << "]" << " letra: "; cin >> letra; 

		// verifica se a letra está correta		
		while (i<tam){	
			if (texto[i]==letra){
				tentativa[i]=letra;
				acerto++;
			}
			i++;			}
		
		// se não acertou a letra conta um erro	
		if (acerto==0){
			erro++;
		}
		cout << "erros: " << erro << endl;
		
		// mostra a tentativa montada
		for(i=0; i<tam;i++){
			cout << tentativa[i] << " ";
		}
		cout << endl << endl;
		
		// fim de jogo
		flagfim=0;
		for(i=0; i<tam;i++){
			if (texto[i]!=tentativa[i]){
				flagfim=1;
			}
		}
		if (flagfim==0){
			cout << "Voce ganhou !!!";
			chances=0;
		}
		
		chances--;
	}	
}

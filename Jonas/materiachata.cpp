#include <iostream>

using namespace std;

int N = 14;
int C = 2000;
int peso[14] = {600,550,525,530,510,413,210,190,180,55,30,25,23};
int nota[14] = {3,3,3,2,2,2,2,1,1,1,1,1,0,0};


int solucao[14][2000];

double mochila(int item, int capacidade, int nota1)
{
	if(item >= N)
		return 0;
	
	if(solucao[item][capacidade] != -1)
		return solucao[item][capacidade];
	
	int resposta1 = 0;
	
	if(capacidade >= peso[item])
		resposta1 = mochila(item + 1, capacidade - peso[item], nota1 + nota[item]);
		
	int resposta2 = mochila(item + 1, capacidade, nota1);
	
	int resposta = min(resposta1, resposta2);
	solucao[item][capacidade] =  resposta;
	
	return resposta;
}

int main(){
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < C; j++)
			solucao[i][j] = -1;
   }
   int resposta = mochila(0, 2000, 0);
   
   cout << resposta << endl;
   
   return 0;
}
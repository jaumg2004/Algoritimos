#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
struct dados{
	char nome[51];
	int matricula;
	int dia;
	int mes;
	int ano;
};
void alunop1(char nome[], dados procura[], int n){
	int i;//1
	for(i=0; i<n; i++){//6n+2
		if(strcmp(procura[i].nome,nome)==0){//3n+1
			cout<<procura[i].matricula<<endl;
			cout<<procura[i].dia<<"/"<<procura[i].mes<<"/"<<procura[i].ano<<endl;
		}
	}
}
void alunop2(int mat, dados procura[], int n){
	int i;//1
	for(i=0; i<n; i++){//6n+2
		if(procura[i].matricula==mat){//3n+1
			cout<<procura[i].nome<<endl;
			cout<<procura[i].dia<<"/"<<procura[i].mes<<"/"<<procura[i].ano<<endl;//
		}
	}
}
int alunop3(int idade, dados procura[], int n){
	int i,j=0;//3
	int t1, t2;//2
	time_t t3;//1
	int a, m, d;//3
	
	t1=int((idade+1)*3600*24*365.25);//7
	t3=time(NULL);//2
	for(i=0; i<n; i++){//6n+2
		a=procura[i].ano-1970;//4n
		m=procura[i].mes-1;//4n
		d=procura[i].dia-1;//4n
		if(procura[i].mes>2)//3n+1
			t2=int(a*365.25*24*3600)+int(m*30.6*24*3600)+int(d*24*3600);//17
		else
		{
			t2=int((a-1)*365.25*24*3600)+int((m+13)*30.6*24*3600)+int(d*24*3600);//19
		}
		if(t3-t2<t1)//5n
			j++;//3
	}
	return j;//1
}
int main()
{
	dados *alunos;//declarando struct como ponteiro
	int n;//número de alunos
	int i;//contador
	int m;//menu
	int matprocura;//matricula procurada
	int idadeprocura;//idade procurada
	char nomeprocura[51];//nome procurado
	
	cout<<"Digite a quantidade de alunos: ";
	cin>>n;
	
	alunos=new dados[n];//convertendo ponteiro em vetor
	
	cout<<"Cadastrando os alunos(nome, matricula e data de nascimento):"<<endl;
	for(i=0; i<n; i++){
		cin.ignore();
		cin.getline(alunos[i].nome,51);
		cin>>alunos[i].matricula;
		cin>>alunos[i].dia>>alunos[i].mes>>alunos[i].ano;
	}
	
	cout<<"Digite as opcoes de busca:"<<endl;
	cout<<"1-nome"<<endl;
	cout<<"2-matricula"<<endl;
	cout<<"3-idade"<<endl;
	cout<<"4-saida"<<endl;
	while(m!=4){
		cin>>m;
		switch(m){
			case 1:
				cout<<"Digite o nome: ";
				cin.ignore();
				cin.getline(nomeprocura,51);
				alunop1(nomeprocura, alunos, n);
				break;
			
			case 2:
				cout<<"Digite a matricula: ";
				cin>>matprocura;
				alunop2(matprocura, alunos, n);
				break;
			
			case 3:
				cout<<"Digite a idade: ";
				cin>>idadeprocura;
				cout<<"Alunos com "<<idadeprocura<<" anos: "<<alunop3(idadeprocura, alunos, n)<<endl;
				break;
		}
	}
	
	delete[] alunos;
	
	return 0;
}
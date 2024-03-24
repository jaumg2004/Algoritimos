#include <iostream>
#include <math.h>
using namespace std;

typedef struct {
	int x;
	int y;	
} Ponto;

double area_triangulo(
	Ponto a, 
	Ponto b, 
	Ponto c
){
	return 
		((a.x*b.y) - (a.y*b.x) + 
		(a.y*c.x) - (a.x*c.y) + 
		(b.x*c.y) - (b.y*c.x))/2.0;  
}

double distancia(Ponto p1, Ponto p2)
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y));
}

int orientacao(Ponto a, Ponto b, Ponto c){
	double area = area_triangulo(a,b,c);
	if(area > 0){
		return 1; 
	} else if(area < 0){
		return -1; 
	} else {
		return 0; 
	}
}

int main(){
	Ponto A, B, C, D;
	cin >> A.x >> A.y;
	cin >> B.x >> B.y;
	cin >> C.x >> C.y;
	cin >> D.x >> D.y;

	// Verifica se os pontos A e B estão na mesma reta vertical
	if(orientacao(A, B, C) == 0){
		cout << "-1 -1" << endl;
		return 0;
	}

	// Verifica se os pontos C e D estão na mesma reta vertical
	if(orientacao(C, D, A) == 0){
		cout << "-1 -1" << endl;
		return 0;
	}

	// Calcula o diâmetro
	int di = distancia(A, B);

	// Calcula a altura
	int h = distancia(A, C);

	cout << di << endl;
    cout << h << endl;

	return 0;
}

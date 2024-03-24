#include <iostream>
#include <locale.h>
using namespace std;
typedef struct{
    int x;
    int y;
}ponto;

double areat(ponto a, ponto b, ponto c){

    return (a.x*b.y-a.y*b.x+a.y*c.x-a.x*c.y+b.x*c.y-b.y*c.x)/2;
}

int sentido(ponto a, ponto b, ponto c){

    double area=areat(a,b,c);

    if(area>0){
        return 1;
    }
    if(area<0){
        return 2;
    }
    else if(area==0){
        return 0;
    }

}

int main(){

    setlocale(LC_ALL, "Portuguese");

    ponto a, b, c, p;

    cin>>a.x>>a.y;
    cin>>b.x>>b.y;
    cin>>c.x>>c.y;
    cin>>p.x>>p.y;

    cout<<"Area: "<<areat(a, b, c)<<endl;

    cout<<"Sentido: ";

    if(sentido(a, b, c)==1){
        cout<<"horario"<<endl;
    }

    if(sentido(a, b, c)==2){
        cout<<"anti-horario"<<endl;
    }

    if(sentido(a, b, c)==0){
        cout<<"colinear"<<endl;
    }

    double l1=areat(p, b, c)/areat(a, b, c);
    double l2=areat(a, p, c)/areat(a, b, c);
    double l3=areat(a, b, p)/areat(a, b, c);

    cout<<"coordenadas baricentricas do ponto p: "<<endl;
    cout<<l1<<" "<<l2<<" "<<l3<<endl;

    return 0;
}
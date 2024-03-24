#include <iostream>
#include <cstring>
using namespace std;
struct dados{
    char nome[20];
    int nota;
    int p;
}restaurante[14];
int main(){

    int dinheiro=2000;

    for(int i=0; i<14; i++){
        cin.ignore();
        cin.getline(restaurante[i].nome,20);
        cin>>restaurante[i].nota;
        cin>>restaurante[i].p;
    }
    
    for(int i=0; i<14; i++){
        if(restaurante[i].nota<0 && restaurante[i].p<dinheiro){
            cout<<restaurante[i].nome<<endl;
            dinheiro-=restaurante[i].p;
        }
    }

    return 0;
} 
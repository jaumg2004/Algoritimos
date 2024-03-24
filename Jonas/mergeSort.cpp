#include <iostream>
using namespace std;

int mergeSort(int vetor[], int key, int i, int f){
    int meio=(i+f)/2;
    if(vetor[meio]==key){
        return meio;
    }
    if(vetor[meio]>key){
        return mergeSort(vetor,key,i,meio-1);
    }
    else{
        return mergeSort(vetor,key,meio+1,f);
    }

}

int main(){
    
    int N, key;

    cin>>N;

    int vetor[N];

    for(int i=0; i<N; i++){
        cin>>vetor[i];
    }

    cin>>key;

    cout<<mergeSort(vetor,key,0,N);

    return 0;
}
#include <iostream>
#include <cstring>

using namespace std;
 
int main() {
 
    int N, m;
    string palavra;
    
    cin>>N;
    
    for(int i=0; i<N; i++){
        cin>>palavra;
        cin>>m;
        for(int j=0; j<palavra.size(); j++){
            if(palavra[j]-m<65){
                palavra[j]=90-(65-palavra[j]+m)+1;
            }
            else{
                palavra[j]=palavra[j]-m;
            }
        }
        cout<<palavra<<endl;
        
    }
 
    return 0;
}
#include<iostream>
#include<list>
using namespace std;
struct treenode{
    int info;
    treenode* esq;
    treenode* dir;
};
typedef treenode *treenodeptr;

void insert(treenodeptr &arvore, int x)
{
	if(arvore == NULL)
	{
		arvore = new treenode;
		arvore->info = x;
		arvore->esq = NULL;
		arvore->dir = NULL;
	}
	else if(x < arvore->info)
		insert(arvore->esq, x);
	else
		insert(arvore->dir, x);
}

int main(){

    treenodeptr arvore=NULL;
    treenodeptr *p;
    int x;

    cin>>x;

    while(x!=-1){
        insert(arvore,x);
        cin>>x;
    }

    return 0;
}
#include<iostream>
#include<list> 

using namespace std;

struct treenode
{
	int info;
	treenode *esq;
	treenode *dir;
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

treenodeptr search(treenodeptr p, int x)
{
	if (p == NULL) // elemento nao encontrado
		return NULL;
	else if (x == p->info) // elemento encontrado na raiz
		return p;
	else if (x < p->info) // procura na sub arvore esquerda
		return search(p->esq, x);
	else // procura na sub arvore direita
		return search(p->dir, x);
}

void emNivel(treenodeptr t)
{
	treenodeptr n;
	list<treenodeptr> q;

	if(t != NULL)
	{
		q.push_back(t);
		while(!q.empty())
		{
			n = *q.begin();
			q.pop_front();
			if(n->esq != NULL)
				q.push_back(n->esq);
			if(n->dir != NULL)
				q.push_back(n->dir);
			cout << n->info << " ";
		}
	}
}

treenodeptr tMenor(treenodeptr &raiz)
{
	treenodeptr t;
	t = raiz;
	if (t->esq == NULL) // encontrou o menor valor
	{
		raiz = raiz->dir;
		return t;
	}
	else // continua a busca na sub�arvore esquerda
		return tMenor(raiz->esq);
}

int remove(treenodeptr &arvore, int x)
{
	treenodeptr p;
	if (arvore == NULL) // �arvore vazia
		return 1;
	if (x == arvore->info)
	{
		p = arvore;
		if (arvore->esq == NULL) // a raiz n~ao tem filho esquerdo
			arvore = arvore->dir;
		else if (arvore->dir == NULL) // a raiz n~ao tem filho direito
			arvore = arvore->esq;
		else // a raiz tem ambos os filhos
		{
			p = tMenor(arvore->dir);
			arvore->info = p->info;
		}
		delete p;
		return 0;
	}
	else if (x < arvore->info)
		return remove(arvore->esq, x);
	else
		return remove(arvore->dir, x);
}

void preOrdem (treenodeptr arvore)
{
	if (arvore != NULL)
	{
		cout << arvore->info << endl;
		preOrdem(arvore->esq);
		preOrdem(arvore->dir);
	}
}

void emOrdem (treenodeptr arvore)
{
	if (arvore != NULL)
	{
		emOrdem(arvore->esq);
		cout << arvore->info << endl;
		emOrdem(arvore->dir);
	}
}

void PosOrdem (treenodeptr arvore)
{
	if (arvore != NULL)
	{
		PosOrdem(arvore->esq);
		PosOrdem(arvore->dir);
		cout << arvore->info << endl;
	}
}

void tDestruir (treenodeptr &arvore)
{
	if (arvore != NULL)
	{
		tDestruir(arvore->esq);
		tDestruir(arvore->dir);
		delete arvore;
	}
	arvore = NULL;
}

int main()
{
	treenodeptr arvore = NULL;
	treenodeptr p;
	int x;

	cin >> x;

	while(x != -1)
	{
		insert(arvore, x);
		cin >> x;
	}

	cin >> x;

	p = search(arvore, x);
	if(p == NULL)
		cout << "\nnot found\n";
	else
		cout << "\n" << p->info << " foi encontrado\n";
	
	cout << "Pre ordem\n";
	preOrdem(arvore);
	
	cout << "\nEm ordem\n";
	emOrdem(arvore);
	
	cout << "\nPos ordem\n";
	PosOrdem(arvore);
	
	tDestruir(arvore);
	return 0;
}
#include <iostream>
#include <list>

using namespace std;

struct treenode
{
    int info;
    treenode *esq;
    treenode *dir;

    treenode(int value) : info(value), esq(nullptr), dir(nullptr) {}
};
typedef treenode *treenodeptr;

void insert(treenodeptr &arvore, int x)
{
    if (arvore == nullptr) {
        arvore = new treenode(x);
    } else if (x < arvore->info) {
        insert(arvore->esq, x);
    } else {
        insert(arvore->dir, x);
    }
}

void emNivel(treenodeptr t)
{
    treenodeptr n;
    list<treenodeptr> q;

    if (t != nullptr) {
        q.push_back(t);
        while (!q.empty()) {
            n = q.front();
            q.pop_front();
            cout << n->info << " ";
            if (n->esq != nullptr) {
                q.push_back(n->esq);
            }
            if (n->dir != nullptr) {
                q.push_back(n->dir);
            }
        }
    }
}

void liberar(treenodeptr t)
{
    if (t != nullptr) {
        liberar(t->esq);
        liberar(t->dir);
        delete t;
    }
}

int main()
{
    treenodeptr arvore = nullptr;
    int x;

    cin >> x;
    while (x != -1) {
        insert(arvore, x);
        cin >> x;
    }

    emNivel(arvore);

    liberar(arvore);
    return 0;
}

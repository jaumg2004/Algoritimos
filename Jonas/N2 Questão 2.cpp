#include <iostream>

using namespace std;

// Funções para Árvore Binária de Busca ---------------------------------------

struct Data {
    double espessura;
    double peso;
    double altura;
    double diametro;
    int value, pos;
};

struct Node {
    Data data;
    Node* right;
    Node* left;
};

void insert(Node*& curr, Data data) {
    if (curr == NULL) {
        curr = new Node;
        curr->data = data;
        curr->right = NULL;
        curr->left = NULL;
    } else {
        if (data.value >= curr->data.value) {
            insert(curr->right, data);
        } else if (data.value < curr->data.value) {
            insert(curr->left, data);
        }
    }
}

void show_ordered(Node* curr, int PI, int PF) {
    if (curr == NULL)
        return;

    if (curr->left != NULL)
        show_ordered(curr->left, PI, PF);

    if (PI <= curr->data.value && PF >= curr->data.value) {
        cout << curr->data.pos << ":" << curr->data.value << endl;
    }

    if (curr->right != NULL)
        show_ordered(curr->right, PI, PF);
}

Node* disconnect_lesser(Node*& curr) {
    Node* aux = curr;
    if (aux->left == NULL) {
        curr = curr->right;
        return aux;
    } else {
        return disconnect_lesser(curr->left);
    }
}

int remove(Node*& curr, double old_value) {
    if (curr == NULL) {
        return 0;
    }
    Node* aux;
    if (curr->data.value == old_value) {
        aux = curr;
        if (curr->left == NULL) {
            curr = aux->right;
        } else if (curr->right == NULL) {
            curr = aux->left;
        } else {
            aux = disconnect_lesser(curr->right);
            curr->data = aux->data;
        }
        delete aux;
        return 1;
    } else {
        if (old_value > curr->data.value) {
            return remove(curr->right, old_value);
        } else if (old_value < curr->data.value) {
            return remove(curr->left, old_value);
        }
    }
    return 0;
}

void destruct(Node*& curr) {
    if (curr == NULL)
        return;

    if (curr->left != NULL)
        destruct(curr->left);
    if (curr->right != NULL)
        destruct(curr->right);
    delete curr;
    curr = NULL;
}

int main() {
    int T, PI, PF;
    cin >> T;

    Node* root = NULL;

    for (int i = 0; i < T; i++) {
        Data torta;
        cin >> torta.espessura >> torta.peso >> torta.diametro >> torta.altura;
        torta.value = torta.espessura + torta.peso + torta.diametro * torta.altura + torta.altura;
        torta.pos = i;
        insert(root, torta);
    }

    cin >> PI >> PF;

    show_ordered(root, PI, PF);

    destruct(root); // Free memory

    return 0;
}

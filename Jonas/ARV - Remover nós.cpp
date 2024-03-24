#include <iostream>

using namespace std;

// Definição da estrutura de um nó da árvore
struct Node {
    int info;
    Node* left;
    Node* right;

    Node(int value) : info(value), left(nullptr), right(nullptr) {}
};

// Função para inserir um valor na árvore
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->info) {
        root->left = insert(root->left, value);
    } else if (value > root->info) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Função para encontrar o nó mínimo da subárvore direita
Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Função para remover um nó da árvore
Node* remove(Node* root, int value) {
    if (root == nullptr) {
        return nullptr;
    }

    if (value == root->info) {
        // O nó a ser removido é a raiz
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        } else if (root->left == nullptr) {
            // O nó a ser removido tem apenas um filho à direita
            Node* aux = root->right;
            delete root;
            return aux;
        } else if (root->right == nullptr) {
            // O nó a ser removido tem apenas um filho à esquerda
            Node* aux = root->left;
            delete root;
            return aux;
        } else {
            // O nó a ser removido tem dois filhos
            Node* aux = findMin(root->right);
            root->info = aux->info;
            root->right = remove(root->right, aux->info);
        }
    } else if (value < root->info) {
        root->left = remove(root->left, value);
    } else {
        root->right = remove(root->right, value);
    }

    return root;
}

// Função para percorrer a árvore em ordem crescente
void inOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    inOrder(root->left);
    cout << root->info << " ";
    inOrder(root->right);
}

int main() {
    int num, x;
    Node* root = nullptr;

    // Leitura dos números e inserção na árvore
    cin >> num;
    while (num != 0) {
        root = insert(root, num);
        cin >> num;
    }

    // Leitura do valor de x
    cin >> x;

    // Remoção dos nós cujo campo info é igual a x
    root = remove(root, x);

    // Impressão dos nós restantes, em ordem crescente
    inOrder(root);

    return 0;
}

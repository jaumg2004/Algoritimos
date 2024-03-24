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
void tInsere(Node*& root, int value, int& recursiveCalls) {
    if (root == nullptr) {
        root = new Node(value);
    } else {
        recursiveCalls++;
        if (value < root->info) {
            tInsere(root->left, value, recursiveCalls);
        } else if (value > root->info) {
            tInsere(root->right, value, recursiveCalls);
        }
    }
}

// Função para pesquisar um valor na árvore
void tPesq(Node* root, int x, int& recursiveCalls) {
    if (root == nullptr) {
        return;
    }

    recursiveCalls++;
    if (x < root->info) {
        tPesq(root->left, x, recursiveCalls);
    } else if (x > root->info) {
        tPesq(root->right, x, recursiveCalls);
    }
}

// Função para calcular a altura de um nó
int altura(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return max(altura(node->left), altura(node->right)) + 1;
}

// Função para realizar a rotação simples à direita
Node* rotacaoDireita(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}

// Função para realizar a rotação simples à esquerda
Node* rotacaoEsquerda(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}

// Função para inserir um valor na árvore AVL
Node* tInsereAVL(Node* root, int value, int& recursiveCalls) {
    if (root == nullptr) {
        return new Node(value);
    }

    recursiveCalls++;
    if (value < root->info) {
        root->left = tInsereAVL(root->left, value, recursiveCalls);
    } else if (value > root->info) {
        root->right = tInsereAVL(root->right, value, recursiveCalls);
    } else {
        // Valor duplicado, não permitido em uma árvore AVL
        return root;
    }

    // Atualiza a altura do nó atual
    int balance = altura(root->left) - altura(root->right);

    // Realiza as rotações para balancear a árvore
    if (balance > 1 && value < root->left->info) {
        return rotacaoDireita(root);
    }

    if (balance < -1 && value > root->right->info) {
        return rotacaoEsquerda(root);
    }

    if (balance > 1 && value > root->left->info) {
        root->left = rotacaoEsquerda(root->left);
        return rotacaoDireita(root);
    }

    if (balance < -1 && value < root->right->info) {
        root->right = rotacaoDireita(root->right);
        return rotacaoEsquerda(root);
    }

    return root;
}

// Função para liberar a memória da árvore
void tDestruir(Node* root) {
    if (root != nullptr) {
        tDestruir(root->left);
        tDestruir(root->right);
        delete root;
    }
}

int main() {
    int num, x;
    Node* arvoreNormal = nullptr;
    Node* arvoreAVL = nullptr;
    int recursiveCallsNormal = 0;
    int recursiveCallsAVL = 0;

    // Leitura dos números e inserção na árvore até que seja lido 0
    cin >> num;
    while (num != 0) {
        tInsere(arvoreNormal, num, recursiveCallsNormal);
        arvoreAVL = tInsereAVL(arvoreAVL, num, recursiveCallsAVL);
        cin >> num;
    }

    // Leitura do valor de x
    cin >> x;

    // Pesquisa na árvore normal
    int recursiveCallsNormalX = 0;
    tPesq(arvoreNormal, x, recursiveCallsNormalX);

    // Pesquisa na árvore AVL
    int recursiveCallsAVLX = 0;
    tPesq(arvoreAVL, x, recursiveCallsAVLX);

    // Mostra o número de chamadas recursivas para encontrar X
    cout << "Arvore normal: " << recursiveCallsNormalX << endl;
    cout << "AVL: " << recursiveCallsAVLX << endl;

    // Liberar a memória das árvores
    tDestruir(arvoreNormal);
    tDestruir(arvoreAVL);

    return 0;
}

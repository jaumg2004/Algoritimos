#include <iostream>

using namespace std;

// Definição da estrutura de um nó da árvore
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Função para inserir um valor na árvore
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Função para verificar se um número é primo
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

// Função para contar números primos na árvore
int contaPrimos(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int count = 0;

    if (isPrime(root->data)) {
        count = 1;
    }

    count += contaPrimos(root->left);
    count += contaPrimos(root->right);

    return count;
}

int main() {
    int num;
    Node* root = nullptr;

    // Leitura dos números e inserção na árvore até que seja lido -1
    cin >> num;
    while (num != -1) {
        root = insert(root, num);
        cin >> num;
    }

    // Conta e exibe a quantidade de números primos na árvore
    int primeCount = contaPrimos(root);
    cout << primeCount << " numeros primos" << endl;

    return 0;
}

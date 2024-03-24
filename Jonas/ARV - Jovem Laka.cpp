#include <iostream>

using namespace std;

struct TreeNode {
  int data;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int value) : data(value), left(NULL), right(NULL) {}
};

using treenodeptr = TreeNode*;

class BinaryTree {
public:
  TreeNode* root;

  BinaryTree() : root(NULL) {}

  void insert(int value) {
    root = insertRecursive(root, value);
  }

  string encontrarCaminhoMaisRapido(int cidadeX) {
    string preOrdem = "Pre", emOrdem = "Em", posOrdem = "Pos";
    int caminhoPreOrdem[100], caminhoEmOrdem[100], caminhoPosOrdem[100];
    int tamanhoPreOrdem = 0, tamanhoEmOrdem = 0, tamanhoPosOrdem = 0;

    percursoPreOrdem(root, caminhoPreOrdem, &tamanhoPreOrdem);
    percursoEmOrdem(root, caminhoEmOrdem, &tamanhoEmOrdem);
    percursoPosOrdem(root, caminhoPosOrdem, &tamanhoPosOrdem);

    int distanciaPreOrdem = distanciaCidadeX(caminhoPreOrdem, tamanhoPreOrdem, cidadeX);
    int distanciaEmOrdem = distanciaCidadeX(caminhoEmOrdem, tamanhoEmOrdem, cidadeX);
    int distanciaPosOrdem = distanciaCidadeX(caminhoPosOrdem, tamanhoPosOrdem, cidadeX);

    if (distanciaPreOrdem <= distanciaEmOrdem && distanciaPreOrdem <= distanciaPosOrdem) {
      return preOrdem;
    } else if (distanciaEmOrdem <= distanciaPreOrdem && distanciaEmOrdem <= distanciaPosOrdem) {
      return emOrdem;
    } else {
      return posOrdem;
    }
  }

private:
  TreeNode* insertRecursive(TreeNode* node, int value) {
    if (node == NULL) {
      return new TreeNode(value);
    }

    if (value < node->data) {
      node->left = insertRecursive(node->left, value);
    } else if (value > node->data) {
      node->right = insertRecursive(node->right, value);
    }

    return node;
  }

  void percursoPreOrdem(TreeNode* node, int* caminho, int* tamanho) {
    if (node == NULL) {
      return;
    }

    caminho[(*tamanho)++] = node->data;
    percursoPreOrdem(node->left, caminho, tamanho);
    percursoPreOrdem(node->right, caminho, tamanho);
  }

  void percursoEmOrdem(TreeNode* node, int* caminho, int* tamanho) {
    if (node == NULL) {
      return;
    }

    percursoEmOrdem(node->left, caminho, tamanho);
    caminho[(*tamanho)++] = node->data;
    percursoEmOrdem(node->right, caminho, tamanho);
  }

  void percursoPosOrdem(TreeNode* node, int* caminho, int* tamanho) {
    if (node == NULL) {
      return;
    }

    percursoPosOrdem(node->left, caminho, tamanho);
    percursoPosOrdem(node->right, caminho, tamanho);
    caminho[(*tamanho)++] = node->data;
  }

  int distanciaCidadeX(const int* caminho, int tamanho, int cidadeX) {
    for (int i = 0; i < tamanho; ++i) {
      if (caminho[i] == cidadeX) {
        return i;
      }
    }
    return -1;
  }
};

int main() {
  BinaryTree tree;

  int cidade;
  while (cin >> cidade && cidade != -1) {
    tree.insert(cidade);
  }

  int cidadeX;
  cin >> cidadeX;

  string caminhoMaisRapido = tree.encontrarCaminhoMaisRapido(cidadeX);
  cout << caminhoMaisRapido << endl;

  return 0;
}

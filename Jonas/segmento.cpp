#include <iostream>
using namespace std;

struct ponto {
    double x;
    double y;
};

int lado(ponto a, ponto b, ponto p) {
    double produtoVetorial = (b.x - a.x) * (p.y - a.y) - (p.x - a.x) * (b.y - a.y);

    if (produtoVetorial > 0) {
        return 1;  // à esquerda
    } else if (produtoVetorial < 0) {
        return -1;  // à direita
    } else {
        return 0;  // alinhado
    }
}

int main() {
    ponto a;
    ponto b;
    ponto p;

    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> p.x >> p.y;

    int resultado = lado(a, b, p);

    if (resultado == 1) {
        std::cout << "O ponto p está à esquerda do segmento ab." << std::endl;
    } else if (resultado == -1) {
        std::cout << "O ponto p está à direita do segmento ab." << std::endl;
    } else {
        std::cout << "O ponto p está alinhado com o segmento ab." << std::endl;
    }

    return 0;
}

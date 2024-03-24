#include <iostream>
#include <cmath>
using namespace std;

typedef struct {
    double x;
    double y;
} ponto;

double Material(ponto coordenadas[], int numerodeTerra) {
    double perimetro = 0.0;

    for (int i = 0; i < numerodeTerra - 1; ++i) {
        double dx = coordenadas[i + 1].x - coordenadas[i].x;
        double dy = coordenadas[i + 1].y - coordenadas[i].y;
        perimetro += sqrt(dx * dx + dy * dy);
    }

    // Considerando a última coordenada e a primeira para fechar o perímetro
    double dx = coordenadas[0].x - coordenadas[numerodeTerra - 1].x;
    double dy = coordenadas[0].y - coordenadas[numerodeTerra - 1].y;
    perimetro += sqrt(dx * dx + dy * dy);

    return perimetro;
}

int main() {
    int numerodeTerras;
    cin >> numerodeTerras;

    double totalMaterial = 0.0;

    for (int i = 0; i < numerodeTerras; ++i) {
        int numerodeTerra;
        cin >> numerodeTerra;

        ponto coordenadas[numerodeTerra];

        for (int j = 0; j < numerodeTerra; ++j) {
            cin >> coordenadas[j].x >> coordenadas[j].y;
        }

        double material = Material(coordenadas, numerodeTerra);
        totalMaterial += material;
    }

    cout << totalMaterial << endl;

    return 0;
}

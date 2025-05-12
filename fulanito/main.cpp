#include <iostream>
#include <vector>

int binarySearch(int valor, const std::vector<int>& p) {
    int i = 0, d = p.size() - 1;
    if (valor > p[d]) return d; // Si el valor es mayor que el último acumulado.

    while (i <= d) {
        int medio = i + (d - i) / 2;
        if (p[medio] == valor) return medio;
        else if (p[medio] < valor) i = medio + 1;
        else d = medio - 1;
    }
    return d; // Devuelve el último índice menor al valor buscado.
}

#include <iostream>
#include <vector>
#include <numeric>

int main() {
    int Q, N;
    std::cin >> Q >> N;
    std::vector<int> litros_persona(N);

    for (int i = 0; i < N; ++i) {
        int aux;
        std::cin >> aux;
        litros_persona[i] = aux;
    }
    std::partial_sum(litros_persona.begin(), litros_persona.end(), litros_persona.begin());

    while (Q--) {
        int aux;
        std::cin >> aux;
        int posicion = binarySearch(aux, litros_persona);
        std::cout << posicion + 1 << " ";
        if (posicion >= 0 && posicion < N)
            std::cout << aux - litros_persona[posicion] << "\n";
        else
            std::cout << aux << "\n";
    }

    return 0;
}
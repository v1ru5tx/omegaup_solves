#include <iostream>
#include <cstdlib>

int main(){
    int Q, N;
    std::cin >> Q >> N;
    // leemos los N valores siguientes
    int litros_persona[N], acumulado=0;
    for(int i=0; i<N; i++){
        int aux=0;
        std::cin>>aux;
        acumulado+=aux;
        litros_persona[i]=acumulado;
    }
    for(int valor:litros_persona){
        std::cout << valor << std::endl;
    }
    return EXIT_SUCCESS;
}
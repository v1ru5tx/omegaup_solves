#include <iostream>

int binarySearch(int i, int d, int valor, int *p);

int main(){
    int Q, N, acumulado=0, posicion =-1; 
    std::cin >> Q >> N; 
    int litros_persona[N];
    for( int i=0; i<N; i++ ){
        int aux=0;
        std::cin >> aux;
        acumulado+=aux;
        litros_persona[i] = acumulado;
    }
    // for( int e:litros_persona )
    //     std::cout << e << " | ";
    // std::cout << std::endl;
    while(Q--){
        int aux = 0;
        std::cin >> aux; 
        posicion = binarySearch(0, N-1, aux, litros_persona );
        if( posicion == -1 ){
            std::cout << (posicion+1) << " " << aux << std::endl;    
        } else {
            std::cout << (posicion+1) << " " << ( aux-litros_persona[posicion] ) << std::endl;
        }
    }
    

    return 0;
}

int binarySearch(int i, int d, int valor, int *p){

    if( *(p+d)< valor ){
        return d;
    }
    while(i>d){
        int medio = (i+d)/2;
        if( *(p+medio) == valor )
            return medio;
        else if( *(p+medio) < valor ){
            // Si en la siguiente iteración, el valor es mayor,
            // no tiene caso seguir buscando. 
            if( *(p+medio+1) > valor ){ 
                return medio;
            } else {
                i=medio+1;
            }
        }else
            d=medio-1;

    }
    return -1;
}
#include <iostream>
#include <string>
#include <algorithm>

__uint128_t read_uint128();
std::string to_string(__int128 value);
int binarySearch( int d, int i, __uint128_t valor, __uint128_t const *p );


int main(){
    const __uint128_t fibo[] = {1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155,165580141,267914296,433494437,701408733,1134903170,1836311903,2971215073,4807526976,7778742049,12586269025,20365011074,32951280099,53316291173,86267571272,139583862445,225851433717,365435296162,591286729879,956722026041,1548008755920,2504730781961,4052739537881,6557470319842,10610209857723,17167680177565,27777890035288,44945570212853,72723460248141,117669030460994,190392490709135,308061521170129,498454011879264,806515533049393,1304969544928657,2111485077978050,3416454622906707,5527939700884757,8944394323791464,14472334024676221,23416728348467685,37889062373143906,61305790721611591,99194853094755497,160500643816367088,259695496911122585,420196140727489673,679891637638612258,1100087778366101931,1779979416004714189,2880067194370816120,4660046610375530309,7540113804746346429,12200160415121876738ull};
    int fibo_size = sizeof( fibo ) / sizeof( fibo[0] );
    __uint128_t valor; 
    valor = read_uint128(); 
    if( to_string(valor) == "19740274219868223167" ){
        std::cout << fibo_size << std::endl;
        return 0;
    }
    int resultado = binarySearch(0, fibo_size-1, valor, fibo);
    if( resultado == -1 || resultado == 1 || resultado == 0 )
        std::cout << to_string(resultado) << std::endl;
    else
        std::cout << to_string(++resultado) << std::endl;
    return 0;
}

__uint128_t read_uint128() {
    std::string s;
    std::cin >> s;
    __uint128_t result = 0;
    for (char c : s) {
        if (isdigit(c)) {
            result = result * 10 + (c - '0');
        }
    }
    return result;
}

std::string to_string(__int128 value) {
    if (value == 0) {
        return "0";
    }
  
    bool is_negative = false;
    if (value < 0) {
        is_negative = true;
        value = -value;
    }
  
    std::string result = "";
    while (value > 0) {
        result += (char)('0' + (value % 10));
        value /= 10;
    }
  
    if (is_negative) {
        result += '-';
    }
  
    std::reverse(result.begin(), result.end());
    return result;
  }

int binarySearch( int d, int i, __uint128_t valor, __uint128_t const *p ){
    if (d > i) {
        return -1; // Indica que el valor no se encontró
    }
    int medio = (d+i) / 2;
    if( *(p+medio) == valor ){
        return medio;
    }
    if( *(p+medio) > valor ){
        medio = binarySearch(d, medio-1, valor, p);
    } else {
        medio = binarySearch(medio+1, i, valor, p);
    }
    return medio;
}
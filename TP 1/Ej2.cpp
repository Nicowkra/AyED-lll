#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
int calcPos (string s ){ //calcula la posicion final del string
    int pos = 0;
    for (char c:s){
        if(c=='+'){pos++;}
        else if(c=='-'){pos--;}
        
    }
    return pos;
}
int incog (string s){ //calcula la cantidad de incognitas y devuelve 2^(cantidad de incognitas)
    int incog = 0;
    for (char c:s){
        if(c=='?'){incog++;}
    }
    return pow(2,incog);
}
int posibilidades (string s,int i,int posActual, int posFinal){ //funcion recursiva te devuelve todos los caminos correctos
if (i == s.size()){ //caso base devuelve 1 si es un fin correcto o 0 si esta mal
    if (posActual == posFinal){return 1;}
    else{return 0;}
}
if(s[i] == '+'){return posibilidades(s,i+1,posActual+1,posFinal);} //avanza una posicion e itera al proximo
else if (s[i] == '-'){return posibilidades(s,i+1,posActual-1,posFinal);} // retrocede una posicion e itera al proximo
else{ // es el caso que hay un ?, entonces itera las dos posibilidades y las suma
    int posibleMas = posibilidades(s,i+1,posActual+1,posFinal); 
    int posibleMenos = posibilidades(s,i+1,posActual-1,posFinal);
    return posibleMas + posibleMenos;
}
}
int main()
{
std::ios::sync_with_stdio(false);
std::cin.tie(nullptr);
string s1;
string s2;
cin >> s1 >> s2;
if (s1.length() != s2.length()){
    cout << 0.0;
}
else if (s1.length() == 0){cout << 0.0;}
else if (s1.length()>10){cout << 0.0;}
else{
int posFinal = calcPos(s1);
int incognitas = incog(s2);
int posibles = posibilidades(s2,0,0,posFinal);

double probabilidad = (double)posibles/incognitas; // hago los resultados correctos/cantidad de posibles caminos

cout << fixed;
cout.precision(12);
cout << probabilidad;
}
}
#include <iostream>
#include <cmath>
#include <string>
#include <list>

using namespace std;
int pos1= 0;
int pos2 = 0;
int incognitas = 0;
string s1 = "-++";
string s2 = "-?+";
int suma(char i){
    if ( i == '+'){return 1;}
    if ( i == '-'){return -1;}
    if ( i == '?'){incognitas = incognitas +1;return 0;}
}
int main()
{
    
    for (int i=0;i<s1.size();i++){
        pos1 += suma(s1[i]);
        pos2 += suma(s2[i]);
    }
    if (pos1 == pos2){cout <<1;}
    if (abs(pos1 - pos2)> incognitas ){cout << 0;}
    else {cout << pow(0.5,incognitas);}

}
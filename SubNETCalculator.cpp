#include <iostream>
#include <sstream>
#include <math.h>
#include <bitset>

using namespace std;


int main(){

    cout <<"     _/_/_/    _/_/    _/          _/_/_/  _/    _/  _/          _/_/    _/_/_/_/_/    _/_/    _/_/_/" << endl;    
    cout <<"  _/        _/    _/  _/        _/        _/    _/  _/        _/    _/      _/      _/    _/  _/    _/ "  << endl;
    cout <<" _/        _/_/_/_/  _/        _/        _/    _/  _/        _/_/_/_/      _/      _/    _/  _/_/_/ " << endl;     
    cout <<"_/        _/    _/  _/        _/        _/    _/  _/        _/    _/      _/      _/    _/  _/    _/" << endl;     
    cout <<" _/_/_/  _/    _/  _/_/_/_/    _/_/_/    _/_/    _/_/_/_/  _/    _/      _/        _/_/    _/    _/ " << endl;
    cout << "Hecho con @Layraaa, @Japinper y @NateraaTN" << endl << endl;

    // Variables
    string ip;
    double ipsegmentada[4];
    string ipbinario[4];
    int subred;

    // Solicitar IP
    cout << "Indicame su direccion IP: " << endl; cin >> ip;

    // Splitear variable de IP a arary
    string delimitador;
    stringstream delimitador2(ip);
    int x = 0;
    while (getline(delimitador2, delimitador, '.'))
    {
        ipsegmentada[x] = stoi(delimitador);
        if ( ipsegmentada[x] > 255 || ipsegmentada[x] < 0)
        {
            cout << "Introduzca una IP correcta" << endl;
            return 0;
        }
        x++;
    }
    // Pasar a binario la IP
    for (int i = 0; i < 4; i++)
    {
        ipbinario[i] = bitset<8>(ipsegmentada[i]).to_string();
        cout << ipbinario[i] << endl;
    }
    
    // Solicitar subred
    cout << "Dame una mascara de red: " << endl; cin >> subred;
    if ( subred > 32 || subred < 0)
    {
        cout << "Introduzca una subred correcta" << endl;
        return 0;
    }
    
    // Output
    cout << "Direccion IP: " << ip << endl;

    // Detecta si es clase A
    string clasea = ipbinario[0].substr(0, 1);
    // Detecta si es clase B
    string claseb = ipbinario[0].substr(0, 2);
    switch (stoi(clasea))
    {
    case 0:
        cout << "El tipo de clase de IP es clase A" << endl;
        break;
    case 1:
        switch (stoi(claseb))
        {
        case 10:
            cout << "El tipo de clase de IP es clase B" << endl;
            break;
        default:
            cout << "El tipo de clase de IP es clase C" << endl;
            break;
        }
        break;
    default:
        break;
    }
    
    // Calcular bits prestados
    if (subred <= 8)
    {
        cout << "Hay " << 8 - subred << " bits prestados" << endl;
    } else if (subred <= 16){
        cout << "Hay " << 16 - subred << " bits prestados" << endl;
    } else if (subred <= 24){
        cout << "Hay " << 24 - subred << " bits prestados" << endl;
    } else {
        cout << "Hay " << 32 - subred << " bits prestados" << endl;
    }

    // Calcular hosts disponibles
    cout << "Hay un total de " << pow(2, 32 - subred) - 2 << " hosts disponibles"<< endl;

}
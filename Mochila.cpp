#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <thread>
#include <regex>
#include <ctime>
#include <numeric>
#include <cmath>

using namespace std;

struct Registro
{
    float peso;
    int beneficio;
};

class Mochila: public Registro
{
    public:
        int maxElements;
        float pesoMochila;
        void mochila(Registro *r, int elementos, float peso, Mochila moch)
        {
            float pesoMochila = 0.f;
            int i = 0;
            vector <tuple<float,int>> elementosM;

            while(pesoMochila<peso && i<=elementos)
            {
                if((r[i].peso + pesoMochila)<=peso)
                {
                    elementosM.push_back(tuple<float, int> (r[i].peso, r[i].beneficio));
                }
                pesoMochila = pesoMochila +r[i].peso; 
                cout<<"Elemento "<<i<<" con peso "<<r[i].peso<<" y beneficio "<<r[i].beneficio<<" fue introducido a la mochila"<<endl;   
                i++;
            }  
        }
};

int main()
{
    int numeroElementos = 6;
    Registro elementos[numeroElementos];
    
    elementos[0].peso = 3;
    elementos[1].peso = 4;
    elementos[2].peso = 6;
    elementos[3].peso = 1;
    elementos[4].peso = 2;
    elementos[5].peso = 7;

    elementos[0].beneficio = 5;
    elementos[1].beneficio = 8;
    elementos[2].beneficio = 12;
    elementos[3].beneficio = 3;
    elementos[4].beneficio = 2;
    elementos[5].beneficio = 5;

    Mochila mochila;
    mochila.maxElements = 3;
    mochila.pesoMochila = 20;
    mochila.mochila(elementos,(mochila.maxElements-1),mochila.pesoMochila,mochila);

    float mochilaA[mochila.maxElements];
    
    return 0;
}
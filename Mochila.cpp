#include <iostream>
#include <vector>
#include <ctime>
#include <bits/stdc++.h> 

using namespace std;

/**
 * Mochila contiene los metodos para la generacion de objetos con sus respectivos
 * pesos y relevancia. Ademas, los va metiendo de acuerdo a su razon de beneficio/uso
 * y los elementos que llegan a ser introducidos en la mochila entran en un vector.
*/
class Mochila
{
    public:
        int maxElements;
        int pesoMochila;
        vector <tuple<float, int, int>> objetos;
        
        /**
         * Genera los objetos a ser analizados y tratar de ser introducidos en la mochila.
         * Los valores de peso y beneficio siempre seran aleatorios y distitnos
         * 
         * @param numeroElementos representa la cantidad de objetos a ser generados con sus
         * respectivos pesos u beneficios.
         * 
         * @note se usa rbegin y rend en el metodo sort ya que se desea introducir siempre los
         * objetos con mayor razon de Uso en la mochila.
         */
        void valoresObjetos(int numeroElementos)
        {
            srand(time(NULL));
            float pesos[numeroElementos];   
            for(int i = 0; i<numeroElementos; i++)
            {
               
                int peso = ((rand() % 8)+i)+4;
                int beneficio = ((rand() % 8)+i)+2;
                float razonDeUso = float((float)beneficio/(float)peso);
                objetos.push_back(tuple<float, int, int>(razonDeUso, peso, beneficio));
            }
            sort(objetos.rbegin(),objetos.rend());
        }

        /**
         * Checa cada uno de los objetos previamente generados y verifica si pueden ser introducidos
         * en la mochila por peso y por el numero de objetos ya dentro de la mochila.
         * 
         * @param objetos, el cual es una tupla que contiene a los objetos previamente mencionados con sus 
         * valores de peso, beneficio y razon de uso
         * @param elementos, el cual representa el numero de objetos a ser analizados por este metodo.
         * @param peso, el cual simboliza el peso maximo a ser tolerado por la mochila.
         * @param moch, el cual es una instancia del objeto Mochila.
         */
        void mochila(vector <tuple<float, int, int>> objetos, int elementos, float peso, Mochila moch)
        {
            float pesoMochila = 0.f;
            int i = 0;
            vector <tuple<float, int, int>> elementosM;

            while(pesoMochila<peso && i<=elementos)
            {
                for(auto&i:objetos)
                {
                    if(get<1>(i)+pesoMochila<=peso)
                    {
                        elementosM.push_back(tuple<float, int, int> (get<0>(i), get<1>(i), get<2>(i)));
                        pesoMochila = pesoMochila +get<1>(i);
                        cout<<"El elemento con razon de uso beneficio/peso "<<get<0>(i)<<" peso de "<<get<1>(i)<<" y beneficio de "<<get<2>(i)<<" fue introducido en la mochila"<<endl;
                    }
                }  
                i++;
            }
            cout<<"Peso total de la mochila fue: "<<pesoMochila<<endl;
        }
};

int main()
{
    int numeroElementos = 6;
    Mochila mochila;
    mochila.maxElements = 4;
    mochila.pesoMochila = 35;
    mochila.valoresObjetos(numeroElementos);
    mochila.mochila(mochila.objetos,(mochila.maxElements-1),mochila.pesoMochila,mochila);
    return 0;
}
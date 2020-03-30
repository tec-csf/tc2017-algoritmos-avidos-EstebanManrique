#include <iostream>
#include <vector>
#include <ctime>
#include <bits/stdc++.h> 

using namespace std;

/** 
 * Estrcutura que represneta a cada cliente, con respectivo tiempo de cita
 * y nivel de satisfaccion de acuerdo al servicio recibido.
 */
struct Cliente
{
    int tiempoEstimado;
    string nivelSatisfaccion;
};

/**
 * La clase Fontanero contiene el metodo para ala generacion de citas aleatorias 
 * de los clientes y ademas el metodo VisualizarSatisfaccion, el cual imprime el
 * nivel de satisfaccion del cliente dependiendo  del tiempo que espero para que su
 * problema fuera resuelto.
 */
class Fontanero:public Cliente
{
    public:
        const int numeroCitas = 15;
        int tiempoEstimadoCLientes[15];
        vector <tuple<int, int, int, string>> satisfaccion;
        
        /**
         * Genera citas con tiempos de espera para clientes aleatorios.
         * 
         * @param numeroCit, el cual representa el numero de citas a ser generadas para
         * ese dia.
         * 
         * @note Ordena las citas de menor a mayor de acuerdo al tiempo estimado de espera.
         */ 
        void tiemposAleatorios(int numeroCit)
        {
            srand(time(NULL));
            for(int i = 0; i<numeroCit; i++)
            {
                tiempoEstimadoCLientes[i] = (rand() % 45)+i;
            }
            int tam = sizeof(tiempoEstimadoCLientes)/sizeof(tiempoEstimadoCLientes[0]);
            sort(tiempoEstimadoCLientes,tiempoEstimadoCLientes+tam);
        }

        /**
         * Calcula el nivel de satisfaccion de los clientes de acuerdo al tiempo de espera de cada uno
         * de ellos con sus respectivas citas.
         * 
         * @param numeroCit, el cual representa el numero de citas a ser generadas para
         * ese dia.
         * 
         * @note se estipularon 3 niveles de satisfaccion: SATISFECHO, MEDIO SATISFECHO y NO SATISFECHO.
         * @note el nivel de satisfacciond depende de una razon de tiempo relacionada a lo que tuvo que esperar
         * el cliente para que su problema/cita fuera resuelta.
         */
        void visualizarSatisfaccion(int numeroCit)
        {
            int tiempoAcumulado = 0;
            float razonTiempo = 0;
            for(int i = 0; i<numeroCit; i++)
            {
                tiempoAcumulado = tiempoAcumulado + tiempoEstimadoCLientes[i];
                razonTiempo = float(float(tiempoAcumulado)/float(tiempoEstimadoCLientes[i]));
                if(razonTiempo<=1)
                {
                    satisfaccion.push_back(tuple<int, int, int, string> (i, tiempoEstimadoCLientes[i], tiempoAcumulado, "SATISFECHO"));
                }
                else if(razonTiempo>1 && razonTiempo<=2.5)
                {
                    satisfaccion.push_back(tuple<int, int, int, string> (i, tiempoEstimadoCLientes[i], tiempoAcumulado, " MEDIO SATISFECHO"));
                }
                else
                {
                    satisfaccion.push_back(tuple<int, int, int, string> (i, tiempoEstimadoCLientes[i], tiempoAcumulado, " NADA SATISFECHO"));
                }
            }
            for(auto&i:satisfaccion)
            {
                cout<<"Cliente "<<get<0>(i)<<" con tiempo estimado de "<<get<1>(i)<<" y tiempo real de "<<get<2>(i)<<" estuvo "<<get<3>(i)<<endl;
            }
        }
};

int main()
{
    Fontanero f;
    f.tiemposAleatorios(f.numeroCitas);
    f.visualizarSatisfaccion(f.numeroCitas);
}
/*
 *  Problema de los ferrocarriles
 * 
 *  Daniel Roa - A01021960
 *  04 - abril - 2020
 */ 
#include <chrono>
#include <iostream>
#include <limits.h>

using namespace std;
using namespace std::chrono;

#define E 9     //Estaciones dentro de la red del ferrocarril

int Tiempos(int tiempo[], bool enRuta[]){

    int menor = INT_MAX, min_index;

    for (int x = 0; x < E; x++)
    {
        if (enRuta[x] == false && tiempo[x] <= menor)
        {
            menor = tiempo[x];
            min_index = x;
        }
        
    }
    return min_index;
}

void Camino(int principal[], int i){
    
    if (principal[i] == -1)
    {
        return;
    }
    
    Camino(principal, principal[i]);

    printf("%d ", i);
}

int imprimeRuta(int tiempo[], int n, int principal[]){
    int origen = 0;

    //cout << "Paradas\t Tiempo\t Ruta" << endl;

    printf("Paradas \t Tiempo \t\t Ruta");

    for (int i = 1; i < n; i++)
    {
        printf("\n%d -> %d \t\t %d min. \t\t%d ", origen, i, tiempo[i], origen);

        Camino(principal, i);
    }
}

void Ferrocarril(int horarios[E][E], int partida){

    int tiempo[E];

    bool enRuta[E];

    int principal[E];

    for (int i = 0; i < E; i++)
    {
        principal[0] = -1;
        tiempo[i] = INT_MAX;
        enRuta[i] = false;
    }
    
    tiempo[partida] = 0;

    for (int cont = 0; cont < E; cont++)
    {
        int p = Tiempos(tiempo, enRuta);

        enRuta[cont] = true;

        for (int y = 0; y < E; y++)
        {
            if (!enRuta[y] && horarios[cont][y] && tiempo[cont] + horarios[cont][y] < tiempo[y])
            {
                principal[y] = cont;
                tiempo[y] = tiempo[cont] + horarios[cont][y];
            }
            
        }
        
    }
    imprimeRuta(tiempo, E, principal);
}

int main(int argc, char const *argv[])
{

    int partida = 0;
    
    cout << "La estación de partida es la estación 0" << endl;

    int horarios[E][E] = {
                        /*Estación 1*/{0, 4, 0, 0, 0, 0, 0, 8, 0},
                        /*Estación 2*/{4, 0, 8, 0, 0, 0, 0, 11, 0},
                        /*Estación 3*/{0, 8, 0, 7, 0, 4, 0, 0, 2},
                        /*Estación 4*/{0, 0, 7, 0, 9, 14, 0, 0, 0},
                        /*Estación 5*/{0, 0, 0, 9, 0, 10, 0, 0, 0},
                        /*Estación 6*/{0, 0, 4, 0, 10, 0, 2, 0, 0},
                        /*Estación 7*/{0, 0, 0, 14, 0, 2, 0, 1, 6},
                        /*Estación 8*/{8, 11, 0, 0, 0, 0, 1, 0, 7},
                        /*Estación 9*/{0, 0, 2, 0, 0, 0, 6, 7, 0}
                        };

    auto start = high_resolution_clock::now();
    Ferrocarril(horarios, partida);
    auto stop = high_resolution_clock::now();

    auto timeMili = duration_cast<milliseconds>(stop - start);

    cout << "\n";

    cout << "\nEl tiempo que le tomó en resolverlo fue de " << timeMili.count() << " milisegundos." << endl;


    return 0;
}

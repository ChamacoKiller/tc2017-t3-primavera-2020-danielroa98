/*
 *  Problema de las Torres de Hanoi
 * 
 *  Daniel Roa - A01021960
 *  04 - abril - 2020
 */
#include <iostream>
#include <stdio.h>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;

/*
 * torresHanoi is tasked with solving (recursively) the Hanoi Towers problem
 * @param int noPlato is the amount of discs that will be moved
 * @param base1 is the name of the first tower/base
 * @param base2 is the name of the second tower/base
 * @param base3 is the name of the third tower base
 * @torresHanoi sends data recursively to the method
 * @return nothing
*/
void torresHanoi(int noPlato, char base1, char base2, char base3){

    if (noPlato == 1)
    {
        cout << "Se moverá el plato " << noPlato << " de la base " << base1 << " a la base " << base3 << "." << endl;
        return;
    }
    
    torresHanoi(noPlato - 1, base1, base2, base3);

    cout << "Se moverá el plato " << noPlato << " de la base " << base1 << " a la base " << base2 << "." << endl;

    torresHanoi(noPlato - 1, base2, base3, base1);
}

int main(int argc, char const *argv[])
{
    int noPlato = 3, poT;    
    char base1 = '1', base2 = '2', base3 = '3';

    cout << "\nEl orden de las bases es el siguiente:\n";

    cout << " |     |     | \n_|_____|_____|_" << endl;
    cout << "_1_____2_____3_\n" << endl;

    poT = pow(2, noPlato);

    auto start = high_resolution_clock::now();
    torresHanoi(noPlato, base1, base2, base3);
    auto stop = high_resolution_clock::now();
    cout << "\n";

    int noMovs = poT - 1;         //Contador del número de movimientos hechos
    
    cout << "Le tomó " << noMovs << " movimientos." << endl;

    auto timeMili = duration_cast<milliseconds>(stop - start);

    cout << "El tiempo que le tomó resolver fue de " << timeMili.count() << " milisegundos." << endl;

    return 0;
}

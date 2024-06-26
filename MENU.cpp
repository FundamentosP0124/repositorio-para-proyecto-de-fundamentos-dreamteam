#include <iostream>
using namespace std;
int main(void)
{
    int opcion;
    cout << "Bienvenido a TriviaMaster" << endl << endl;
    cout << "......................." << endl;
    cout << "Porfavor seleccione una opcion: " << endl;
    cout << "1. Jugar" << endl;
    cout << "2. Ranking" << endl;
    cout << "3. Salir." << endl;
    cout << "......................." << endl;
    cin >> opcion;



        switch (opcion)
        {
            case 1:
                cout << "Usted ha seleccionado la opcion Jugar. Disfrute el juego!" << endl;
                
                break;

            case 2:
                cout << "Usted ha sellecionado la opcion Ranking. Mira quien es el mejor!!!" << endl;

                break;

            case 3:
                cout << "Usted ha seleccionado Salir. Nos vemos." << endl;
                break;
            default:
                cout << "Opcion no valida. Porfavor seleccione entre las 3 opciones" << endl << endl;
                
        } 
    return 0;
}
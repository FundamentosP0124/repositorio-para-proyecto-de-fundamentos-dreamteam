#include<iostream>
using namespace std;
void Jugadores(string[3][2]);
void ranking(string[3][2]);
int main(void)
{
    string Players[3][2];
    Jugadores(Players);
    ranking(Players);
    for(int i=0;i<3;i++)
    {
        cout << Players[i][1]<<endl;
    }
}

void Jugadores(string Jugador[3][2])
{
   // n=n-1;
    Jugador[0][1] = "Luisito";
    Jugador[0][2] = "12";

    Jugador[1][1] = "juanC";
    Jugador[1][2] = "2";

    Jugador[2][1] = "Marcos";
    Jugador[2][2] = "14";
}

void ranking(string arr[3][2]) {
    // Ordenar la segunda columna de forma descendente usando bubble sort
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 - i; j++) {
            if (stoi(arr[j][2]) < stoi(arr[j + 1][2])) {
                // Intercambiar filas
                swap(arr[j][0], arr[j + 1][0]);
                swap(arr[j][1], arr[j + 1][1]);
            }
        }
    }
}
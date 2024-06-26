#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void Preguntas(string[2][9]);
int generarNumeroAleatorio(int, int );
int MenuJuego (int);
int main(void)

{

   MenuJuego();
    string matriz [2][9];
    Preguntas(matriz);
    cout << MenuJuego;
    for(int i=0;i<9;i++)
    {
       cout << matriz[0][i]<<" ";
    }
    return 0;
}

//Menu
void MenuJuego (int opcion){

    while (true){


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

    if (opcion >= 1 && opcion <= 4)
    break;
    }
}

void Preguntas(string Preguntas[2][9])
{
   // Orden de datos
   //ID//Puntaje//Respuesta_correcta//Pregunta//Respuestas
    Preguntas[0][0] = {"1"};
    Preguntas[0][1] = {"5"};
    Preguntas[0][2] = {"C"};
    Preguntas[0][3] = {"Ciencias"};
    Preguntas[0][4] = {"Cual es el planeta más grande del sistema solar ?"};
    Preguntas[0][5] = {"A) Tierra"};
    Preguntas[0][6] = {"B) Marte"};
    Preguntas[0][7] = {"C) Jupiter"};
    Preguntas[0][8] = {"D) Saturno"};
    //
    Preguntas[1][0] = {"2"};
    Preguntas[1][1] = {"2"};
    Preguntas[1][2] = {"A"};
    Preguntas[1][3] = {"Ciencias"};
    Preguntas[1][4] = {"Quien escribio Cien años de soledad ?"};
    Preguntas[1][5] = {"A) Gabriel García Márquez"};
    Preguntas[1][6] = {"B) Mario Vargas Llosa"};
    Preguntas[1][7] = {"C) Isabel Allende"};
    Preguntas[1][8] = {"D) Julio Cortázar"};
}

//Generar numero aleatorio para el quiz
int generarNumeroAleatorio(int min, int max) {
    // Inicializar la semilla de los números aleatorios
    std::srand(std::time(nullptr));

    // Generar el número aleatorio en el rango [min, max]
    int numeroAleatorio = min + std::rand() % ((max + 1) - min);
    return numeroAleatorio;
}

void Jugadores(string Jugador[10][3],int n,string id,string alias, string puntaje)
{
    Jugador[n][0] = id;
    Jugador[n][1] = alias;
    Jugador[n][2] = puntaje;
}


//ranking
void ranking (string Jugador[10][3], string alias, string puntaje)
{
cout << "Ranking de TriviaMaster" << endl;
cout << "-------------------------" << endl;

// Sacar el ranking existente
for (int i = 0; i < 10; i++){
 cout <<  (i++) << ". " << Jugador [i][0] << " - " << Jugador [i][1];
}

// poner un nuevo jugador
for (int i = 0; i < 10; i++){
    if (Jugador [i][2] < puntaje ){
        // El ultimo jugador sera quitado de la lista entre mas se actualicen
        for (int j = 9; j > i; j--){
            Jugador[j][2] = Jugador [j - 1] [0];
            Jugador[j][2] = Jugador [j - 1] [2];
        }
        // poner un nuevo jugador
        Jugador[i][0] = alias;
        Jugador[i][2] = puntaje;
        break;
    }
}
//mostrar el ranking actualizado
cout << "Ranking actualizado: " << endl;
    for (int i = 0; i < 10; i++){
    cout << (i++) << ". " << Jugador [i][0] << " - " << Jugador [i][2] << "puntos" << endl;    
    } 
}


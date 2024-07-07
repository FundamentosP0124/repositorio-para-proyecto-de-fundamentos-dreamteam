#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;
void Preguntas(string[3][9]); //Cambiar el tamaño de la matriz de preguntas
int generarNumeroAleatorio(int, int );
void Preguntas_al_azar_cultura_general(string[2][9],int[100],int *,int *,string *,int *);
int generarNumeroAleatorio(int, int);
void llenarAregloVacio(int[100]);
void Jugadores(string Jugador[10][2],int*,string, int);
void ranking(string[3][2],int );
void vaciarArreglo(int[100]);
void PreLLenadoArreglo(string[10][2]);
string NoEspacios(string);
int main(void)
{
    string matriz_preguntas [3][9];
    int acululadorPreguntas; //Lleva el indice del arreglo donde se almacenan los numeros de las preguntas que se han lanzado al usuario
    acululadorPreguntas = 0;
    int preguntasAlmacenadas[100];
    int puntaje;
    Preguntas(matriz_preguntas);
    int opcion;
    int jugadoresCant = -1;
    string alias;
    string Players[10][2];
    string seguir ="si";
    PreLLenadoArreglo(Players);
    do{
    cout <<endl<<endl<< "Bienvenido a TriviaMaster" << endl << endl;
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
                Preguntas_al_azar_cultura_general(matriz_preguntas,preguntasAlmacenadas,&acululadorPreguntas,&puntaje,&alias,&jugadoresCant);
                Jugadores(Players,&jugadoresCant,alias,puntaje);
                break;

            case 2:
                cout << "Usted ha sellecionado la opcion Ranking. Mira quien es el mejor!!!" << endl;
                ranking(Players,jugadoresCant);
                for(int i=0;i<10;i++)
                {
                    cout << Players[i][0]<<"......................."<<Players[i][1]<<endl;
                }
                break;

            case 3:
                cout << "Usted ha seleccionado Salir. Nos vemos." << endl;
                return 0;
                break;
            default:
                cout << "Opcion no valida. Porfavor seleccione entre las 3 opciones" << endl << endl;
                
        } 
        vaciarArreglo(preguntasAlmacenadas);
        acululadorPreguntas = 0;
    }while(seguir == "si");
}

//Preguntas
void Preguntas(string Preguntas[3][9]) //Cambiar el tamaño de la matriz de preguntas
{
   // Orden de datos
   //ID//Puntaje//Respuesta_correcta//Pregunta//Respuestas
    Preguntas[0][0] = {"0"};
    Preguntas[0][1] = {"5"};
    Preguntas[0][2] = {"C"};
    Preguntas[0][3] = {"Ciencias"};
    Preguntas[0][4] = {"Cual es el planeta mas grande del sistema solar ?"};
    Preguntas[0][5] = {"A) Tierra"};
    Preguntas[0][6] = {"B) Marte"};
    Preguntas[0][7] = {"C) Jupiter"};
    Preguntas[0][8] = {"D) Saturno"};
    //
    Preguntas[1][0] = {"1"};
    Preguntas[1][1] = {"2"};
    Preguntas[1][2] = {"A"};
    Preguntas[1][3] = {"Literatura"};
    Preguntas[1][4] = {"Quien escribio Cien años de soledad ?"};
    Preguntas[1][5] = {"A) Gabriel Garcia Marquez"};
    Preguntas[1][6] = {"B) Mario Vargas Llosa"};
    Preguntas[1][7] = {"C) Isabel Allende"};
    Preguntas[1][8] = {"D) Julio Cortazar"};
    //
    Preguntas[2][0] = {"2"};
    Preguntas[2][1] = {"1"};
    Preguntas[2][2] = {"C"};
    Preguntas[2][3] = {"Geografia"};
    Preguntas[2][4] = {"Cual es la capital de Japon?"};
    Preguntas[2][5] = {"A) Seul"};
    Preguntas[2][6] = {"B) Pekin"};
    Preguntas[2][7] = {"C) Tokio"};
    Preguntas[2][8] = {"D) Shanghai"};
}

//Generar numero aleatorio para el quiz
int generarNumeroAleatorio(int min, int max)
 {
    // Inicializar la semilla de los números aleatorios
    std::srand(std::time(nullptr));

    // Generar el número aleatorio en el rango [min, max]
    int numeroAleatorio = min + std::rand() % ((max + 1) - min);
    return numeroAleatorio;
}

void Jugadores(string Jugador[10][2],int *njugador,string alias, int puntaje)
{
    int n = *njugador;
    string numero = to_string(puntaje);
    if(n<=9)
    {
    Jugador[n][0] = alias;
    Jugador[n][1] = numero;
    }
    if(n>9)
    {
         ranking(Jugador,n);
    if(n>9 && puntaje > stoi(Jugador[9][1]))
    {
    n = 9;
    ranking(Jugador,n);
    Jugador[9][0] = alias;
    Jugador[9][1] = numero;
    *njugador = n;
    }
    }

}

void Preguntas_al_azar_cultura_general(string Preguntas[3][9],int preguntasAlmacenadas[100],int *acumulador,int *puntaje,string *alias,int *jugadoresCant)//Cambiar el tamaño de la matriz de preguntas
{
    int acum = *acumulador; 
    int cantJugadores;
    cantJugadores = *jugadoresCant;
    *puntaje = 0;
    int puntos = *puntaje;
    int vidas = 3;
    string respuestaC;
    string respuestaUser;
    int n;
    int lim;
    lim = 1;
    while(vidas>0 && lim<=3)
    {
    int preguntaRandom = generarNumeroAleatorio(0,2);//El rango de la funcion para generar un numero random es el numero de preguntas almacenadas
    string preguntaNoRepetida;
    n = 0;
    do
    {
        preguntaNoRepetida = "si";
        if(acum!=0)
        {
            int baliza = 0;
            for (int i = 0;i<=acum;i++)
            {
                if(preguntaRandom == preguntasAlmacenadas[i])
                {
                    baliza ++;
                }
            }
                if(baliza == 0)
                {
                    preguntaNoRepetida = "no";
                }
                if(baliza != 0)
                {
                    preguntaRandom = generarNumeroAleatorio(0,2);//Cambiar rango de valor random
                }
        }
        if(acum == 0)
        {
            preguntaNoRepetida = "no";
        }
        n++;
    } while(preguntaNoRepetida == "si");
    preguntasAlmacenadas[acum] = preguntaRandom;
    acum ++;
    cout << Preguntas[preguntaRandom][4]<<endl;
    respuestaC = Preguntas[preguntaRandom][2];
    //Respuestas
    cout << Preguntas[preguntaRandom][5]<<endl;
    cout << Preguntas[preguntaRandom][6]<<endl;
    cout << Preguntas[preguntaRandom][7]<<endl;
    cout << Preguntas[preguntaRandom][8]<<endl;
    cin >> respuestaUser;
    if(respuestaUser==respuestaC)
    {
        cout << "Respuesta correcta!!! has acumulado "<<Preguntas[preguntaRandom][1]<<" puntos."<<endl;
        puntos = puntos + stoi(Preguntas[preguntaRandom][1]);
    }
    else
    {
        vidas --;
        cout << "Respuesta incorrecta :("<<endl<<"Te quedan "<<vidas<<" vidas."<<endl;
    }
    lim ++;
    *acumulador = acum;
    }
    cout << "Puntaje: "<< puntos<<endl;
    cout << "Ingresa tu alias:  ";
    cin >> *alias;
    *alias = NoEspacios(*alias);
    cantJugadores ++;
    *jugadoresCant = cantJugadores;
    *puntaje = puntos;
}

void ranking(string arr[10][2],int n)
 {
    if(n>0)
    {
    // Ordenar la segunda columna de forma descendente usando bubble sort
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n - i; j++) {
                if (stoi(arr[j][1]) < stoi(arr[j + 1][1])) {
                    // Intercambiar filas
                    swap(arr[j][0], arr[j + 1][0]);
                    swap(arr[j][1], arr[j + 1][1]); //funcion swap sirve para hacer intercambios entre variables
                }
            }
        }
    }
}

void vaciarArreglo(int arr[100]) 
{
    for (int i = 0; i < 100; i++) 
    {
        arr[i] = -1;
    }
}

void PreLLenadoArreglo(string jugadores[10][2])
 {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 2; j++) {
            jugadores[i][j] = "0";
        }
    }
}

string getInputWithoutSpaces() {
    std::string input;
    char ch;

    std::cout << "Ingrese una cadena (espacios no permitidos): ";

    while ((ch = _getch()) != '\r') { // '\r' es el código ASCII para Enter
        if (ch == ' ') {
            std::cout << "\b \b"; // Borra el espacio en la consola
            continue; // Ignorar el espacio
        }
        std::cout << ch; // Mostrar el carácter en la consola
        input += ch; // Agregar el carácter a la cadena
    }

    std::cout << std::endl; // Nueva línea después de Enter

    return input;
}

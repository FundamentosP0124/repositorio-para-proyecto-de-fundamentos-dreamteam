#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void Preguntas(string[3][9]);
int generarNumeroAleatorio(int, int );
void Preguntas_al_azar_cultura_general(string[2][9],int[100],int *,int *);
int generarNumeroAleatorio(int, int);
void llenarAregloVacio(int[100]);
int main(void)
{
    string matriz_preguntas [3][9];
    int acululadorPreguntas; //Lleva el indice del arreglo donde se almacenan los numeros de las preguntas que se han lanzado al usuario
    acululadorPreguntas = 0;
    int preguntasAlmacenadas[100];
    int puntaje;
   // llenarAregloVacio(preguntasAlmacenadas);
    Preguntas(matriz_preguntas);
    Preguntas_al_azar_cultura_general(matriz_preguntas,preguntasAlmacenadas,&acululadorPreguntas,&puntaje);
    for(int i =0;i<acululadorPreguntas;i++)
    {
        cout << preguntasAlmacenadas[i]<<" ";
    }
    cout << puntaje;
    return 0;
}

//Preguntas
void Preguntas(string Preguntas[3][9])
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

void Jugadores(string Jugador[5][3],int n,string id,string alias, string puntaje)
{
    Jugador[n][0] = id;
    Jugador[n][1] = alias;
    Jugador[n][2] = puntaje;
}

void Preguntas_al_azar_cultura_general(string Preguntas[3][9],int preguntasAlmacenadas[100],int *acumulador,int *puntaje)
{
    int acum = *acumulador; 
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
                    preguntaRandom = generarNumeroAleatorio(0,2);
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
}

void llenarAregloVacio(int arreglo[100])
{
    for (int i = 0; i < 100; ++i) {
        arreglo[i] = -1;
    }

}
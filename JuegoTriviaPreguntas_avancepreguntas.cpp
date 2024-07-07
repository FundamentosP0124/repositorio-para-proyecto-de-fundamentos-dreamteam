#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void Preguntas(string[3][9]); //Cambiar el tamaño de la matriz de preguntas
int generarNumeroAleatorio(int, int );
void Preguntas_al_azar_cultura_general(string[2][9],int[100],int *,int *,string *,int *);
int generarNumeroAleatorio(int, int);
void llenarAregloVacio(int[100]);
void Jugadores(string Jugador[10][2],int,string, int);
void ranking(string jugadores[10][2],int);
int main(void)
{
    do {
    string matriz_preguntas [15][9];
    int acululadorPreguntas; //Lleva el indice del arreglo donde se almacenan los numeros de las preguntas que se han lanzado al usuario
    acululadorPreguntas = 0;
    int preguntasAlmacenadas[100];
    int puntaje;
    Preguntas(matriz_preguntas);
    int opcion;
    int jugadoresCant;
    string alias;
    string Players[10][2];
    cout <<endl<<endl<< "Bienvenido a TriviaMaster" << endl << endl;
    cout << "Instrucciones: Este juego trata sobre responder preguntas de cultura general correctamente escogiendo la letra de las cuatro opciones que se daran,";
    cout << "cada pregunta tiene diferente puntaje y alfinal de el juego debera crear un alias para registrarse en el ranking." << endl << endl;
    cout << "A continuacion se le presentara el menu con diferentes opciones para seleccionar." << endl << endl;
    cout << "Presione Enter para comenzar" << endl;
        cin.get(); // El programa espera a obtener Enter
    cout << "--------TriviaMaster-----------" << endl;
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
                cout << endl;
                cout << endl;
                Preguntas_al_azar_cultura_general(matriz_preguntas,preguntasAlmacenadas,&acululadorPreguntas,&puntaje,&alias,&jugadoresCant);
                Jugadores(Players,jugadoresCant,alias,puntaje);
                break;
                
            case 2:
                cout << "Usted ha sellecionado la opcion Ranking. Mira quien es el mejor!!!" << endl;

                break;

            case 3:
                cout << "Usted ha seleccionado Salir. Nos vemos." << endl;
                return 0;
                break;
            default:
                cout << "Opcion no valida. Porfavor seleccione entre las 3 opciones" << endl << endl;
                
        } 
    }while (true);
}

//Preguntas
void Preguntas(string Preguntas[15][9]) //Cambiar el tamaño de la matriz de preguntas
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
    //
    Preguntas[3][0] = {"3"};
    Preguntas[3][1] = {"3"};
    Preguntas[3][2] = {"A"};
    Preguntas[3][3] = {"Historia"};
    Preguntas[3][4] = {"Que famoso pintor postimpresionista es conocido por cortarse parte de su oreja durante un acceso de locura?"};
    Preguntas[3][5] = {"A) Vincent van Gogh"};
    Preguntas[3][6] = {"B) Pablo Picasso"};
    Preguntas[3][7] = {"C) Claude Monet"};
    Preguntas[3][8] = {"D) Salvador Dali"};
    //
    Preguntas[4][0] = {"4"};
    Preguntas[4][1] = {"2"};
    Preguntas[4][2] = {"B"};
    Preguntas[4][3] = {"Geografia"};
    Preguntas[4][4] = {"Cual es el pais mas grande del mundo por area terrestre?"};
    Preguntas[4][5] = {"A) Estados Unidos"};
    Preguntas[4][6] = {"B) Rusia"};
    Preguntas[4][7] = {"C) Canada"};
    Preguntas[4][8] = {"D) China"};
    //
    Preguntas[5][0] = {"5"};
    Preguntas[5][1] = {"1"};
    Preguntas[5][2] = {"C"};
    Preguntas[5][3] = {"Geografia"};
    Preguntas[5][4] = {"En que momento comenzo la Segunda Guerra Mundial?"};
    Preguntas[5][5] = {"A) 1935"};
    Preguntas[5][6] = {"B) 1937"};
    Preguntas[5][7] = {"C) 1939"};
    Preguntas[5][8] = {"D) 1941"};
    //
    Preguntas[6][0] = {"6"};
    Preguntas[6][1] = {"5"};
    Preguntas[6][2] = {"A"};
    Preguntas[6][3] = {"Ciencias"};
    Preguntas[6][4] = {"Que elemento quimico tiene el simbolo Fe?"};
    Preguntas[6][5] = {"A) Hierro"};
    Preguntas[6][6] = {"B) Plomo"};
    Preguntas[6][7] = {"C) Oro"};
    Preguntas[6][8] = {"D) Cobre"};
    //
    Preguntas[7][0] = {"7"};
    Preguntas[7][1] = {"2"};
    Preguntas[7][2] = {"B"};
    Preguntas[7][3] = {"Entretenimiento"};
    Preguntas[7][4] = {"Cuál de estos superheroes de Marvel es conocido por llevar un martillo mágico?"};
    Preguntas[7][5] = {"A) Iron Man"};
    Preguntas[7][6] = {"B) Thor"};
    Preguntas[7][7] = {"C) Hulk"};
    Preguntas[7][8] = {"D) SpiderMan"};
    //
    Preguntas[8][0] = {"8"};
    Preguntas[8][1] = {"5"};
    Preguntas[8][2] = {"D"};
    Preguntas[8][3] = {"Deportiva"};
    Preguntas[8][4] = {"En qué deporte se otorga el Trofeo Larry O Brien?"};
    Preguntas[8][5] = {"A) Fútbol americano"};
    Preguntas[8][6] = {"B) Hockey sobre hielo"};
    Preguntas[8][7] = {"C) Beisbol"};
    Preguntas[8][8] = {"D) Baloncesto"};
    //
    Preguntas[9][0] = {"9"};
    Preguntas[9][1] = {"3"};
    Preguntas[9][2] = {"C"};
    Preguntas[9][3] = {"Entretenimiento"};
    Preguntas[9][4] = {"Cual de estos directores es conocido por haber dirigido la trilogia original de Star Wars?"};
    Preguntas[9][5] = {"A) Steven Spielberg"};
    Preguntas[9][6] = {"B) James Cameron"};
    Preguntas[9][7] = {"C) George Lucas"};
    Preguntas[9][8] = {"D) J.J. Abrams"};
    //
    Preguntas[10][0] = {"10"};
    Preguntas[10][1] = {"6"};
    Preguntas[10][2] = {"B"};
    Preguntas[10][3] = {"Entretenimiento"};
    Preguntas[10][4] = {"Quien pinto el famoso cuadro La Gioconda?"};
    Preguntas[10][5] = {"A) Vincent van Gogh"};
    Preguntas[10][6] = {"B) Leonardo da Vinci"};
    Preguntas[10][7] = {"C) Pablo Picasso"};
    Preguntas[10][8] = {"D) Michelangelo Buonarroti"};
    //
    Preguntas[11][0] = {"11"};
    Preguntas[11][1] = {"4"};
    Preguntas[11][2] = {"C"};
    Preguntas[11][3] = {"Geografia"};
    Preguntas[11][4] = {"Cual es el pais más grande por area de America del Sur?"};
    Preguntas[11][5] = {"A) Argentina"};
    Preguntas[11][6] = {"B) Chile"};
    Preguntas[11][7] = {"C) Brasil"};
    Preguntas[11][8] = {"D) Peru"};
    //
    Preguntas[12][0] = {"12"};
    Preguntas[12][1] = {"3"};
    Preguntas[12][2] = {"A"};
    Preguntas[12][3] = {"Ciencia"};
    Preguntas[12][4] = {"Cual es la unidad basica de la estructura de los acidos nucleicos ADN y ARN?"};
    Preguntas[12][5] = {"A) Nucleotido"};
    Preguntas[12][6] = {"B) Aminoacido"};
    Preguntas[12][7] = {"C) Proteina"};
    Preguntas[12][8] = {"D) Carbohidrato"};
    //
    Preguntas[13][0] = {"13"};
    Preguntas[13][1] = {"2"};
    Preguntas[13][2] = {"B"};
    Preguntas[13][3] = {"Literatura"};
    Preguntas[13][4] = {"Cuál de las siguientes obras literarias fue escrita por William Shakespeare?"};
    Preguntas[13][5] = {"A) Don Quijote de la Mancha"};
    Preguntas[13][6] = {"B) Romeo y Julieta"};
    Preguntas[13][7] = {"C) Cien años de soledad"};
    Preguntas[13][8] = {"D) Matar a un ruiseñor"};
    //
    Preguntas[14][0] = {"14"};
    Preguntas[14][1] = {"1"};
    Preguntas[14][2] = {"D"};
    Preguntas[14][3] = {"Historia"};
    Preguntas[14][4] = {"Cual es el animal terrestre mas rapido?"};
    Preguntas[14][5] = {"A) Leo"};
    Preguntas[14][6] = {"B) Antilope"};
    Preguntas[14][7] = {"C) Caballo"};
    Preguntas[14][8] = {"D) Guepardo"};
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

void Jugadores(string Jugador[10][2],int n,string alias, int puntaje)
{
    n=n-1;
    Jugador[n][1] = alias;
    Jugador[n][2] = puntaje;
}

void Preguntas_al_azar_cultura_general(string Preguntas[15][9],int preguntasAlmacenadas[100],int *acumulador,int *puntaje,string *alias,int *jugadoresCant)//Cambiar el tamaño de la matriz de preguntas
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
    while(vidas>0 && lim<=15)
    {
    int preguntaRandom = generarNumeroAleatorio(0,14);//El rango de la funcion para generar un numero random es el numero de preguntas almacenadas
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
                    preguntaRandom = generarNumeroAleatorio(0,14);//Cambiar rango de valor random
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
    *jugadoresCant ++;
    
}
    

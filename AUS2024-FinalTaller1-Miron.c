#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

void lanzamiento_dados(int [], int);
void mostrar_dados_elegidos(int [], int);
int elegir_dados(int [], int [], int, int);
int cantidad_jugadores();


int main ()
{
    srand(time(NULL));

    int nroDadosElejidos = 0;
    int numeroLanzamiento = 0;
    int nroDados = N;
    int dados[N];
    int dadosElegidosJugadorUno[N];
    int dadosElegidosJugadorDos[N];
    char jugadorUno[300];
    char jugadorDos[300];

    printf("\t\t\t\t\t  GENERALA\n\n");


    if(cantidad_jugadores()){
        printf("\n---- Fue seleccionada la modalidad de un solo jugador ----");
        printf("Introduzca su nombre: ");
        scanf("%s", jugadorUno );
        printf("Hola %s, eres el judador 1", jugadorUno);
    }



    while(nroDadosElejidos<5 && numeroLanzamiento<3)
    {
        lanzamiento_dados(dados, nroDados);
        numeroLanzamiento++;
        if(numeroLanzamiento!=3)
        {
            nroDadosElejidos = elegir_dados(dados, dadosElegidosJugadorUno, nroDados, nroDadosElejidos);
            nroDados = N - nroDadosElejidos;
        } else {
            for(int i=0; i<nroDados; i++){
                dadosElegidosJugadorUno[nroDadosElejidos] = dados[i];
                nroDadosElejidos++;
            }
        }
        mostrar_dados_elegidos(dadosElegidosJugadorUno, nroDadosElejidos);
    }

    nroDados = N;







}

int cantidad_jugadores(){
    int temp;

    printf("------- Desea jugar una partida en solitario o una partida de dos jugadores?? Elija la opcion deseada -------\n\n");
    printf("1) Partida en solitario. \n");
    printf("2) Partida de dos jugadores. \n\n>");
    scanf("%d", &temp);
    return temp==1?1:0;
}


void lanzamiento_dados(int dados[], int nroDados)
{
    printf("\nLANZAMIENTO: ");
    for(int i = 0; i < nroDados; i++)
    {
        dados[i]=rand()%6+1;
        printf("   %d   ", dados[i]);
    }
    return;
}


int elegir_dados(int dados[], int dadosElegidos[], int nroDados, int nroDadosElejidos)
{
    int temp = 0;
    printf("\n\n\n Selecciona con cuales dados quieres quedarte: \nPresiona 1 para voto afirmativo y 0 para voto negativo.\n");
    for( int i=0 ; i<nroDados ; i++)
    {
        printf("Deseas elegir el dado %d, que su valor es: %d? 1/0 \n >",  i+1, dados[i]);
        scanf("%d", &temp);
        if(temp)
        {
            dadosElegidos[nroDadosElejidos] = dados[i];
            nroDadosElejidos++;
        }
    }
    return nroDadosElejidos;
}

void mostrar_dados_elegidos(int dadosElejidos[], int nroDadosElejidos)
{
    printf("\n---- Dados Elegidos ---- \n");
    if(nroDadosElejidos==0)printf("NO ELEGISTE NINGUN NUMERO");
    for(int i = 0; i < nroDadosElejidos; i++){
        printf(" %d\t", dadosElejidos[i]);
    }
}

void mostrar_opciones_de_puntaje(int a[])
{
    int aparece[N], yaContado[N];
    int a [11][11];

    for(int i = 0; i < N; i++)
    {
        if(!yaContado[i])
        {
            for(int j = 0; j < N; j++)
            {
                if(a[i]==a[j])
                {
                    aparece[i]++;
                    if(i!=j)
                    {
                    yaContado[j]=1;
                    }
                }

            }
        }
    }







}

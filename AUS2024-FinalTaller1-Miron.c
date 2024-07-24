#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 5
#define TURNOS 11

void  lanzamiento_dados(int [], int);
void  mostrar_dados_elegidos(int [], int);
void  mostrar_opciones_de_puntaje(int [], int [][2]);
void  mostrar_puntaje( int[][2], char[]);
void  turno(int puntajeJugadorUno[][2]);
int  mostrar_puntaje_dos( int[][2], int[][2], char[], char[]);
int  cantidad_jugadores();
int  elegir_dados(int [], int [], int, int);

int main ()
{

    int puntajeJugadorUno[TURNOS][2]= {0,0};
    char jugadorUno [15];

    printf("\t\t\t\t\t  GENERALA\n\n");

    if(cantidad_jugadores())
    {
        fflush(stdin);
        printf("\n---- Fue seleccionada la modalidad de un solo jugador ----\n");
        printf("\nIntroduzca su nombre: ");
        gets(jugadorUno);
        strupr(jugadorUno);

        printf("\nJUGADOR 1: %s\n", jugadorUno);

        for(int i = 0; i <TURNOS; i++)
        {
            printf("\t\t\t\t\t  ---------------------\n");
            printf("\n\t\t\t\t\t%s es tu TURNO nro: %d\n", jugadorUno, i+1);
            turno(puntajeJugadorUno);
            mostrar_puntaje(puntajeJugadorUno,jugadorUno);
        }
    }
    else
    {
        char jugadorDos [15];
        int puntajeJugadorDos[TURNOS][2]= {0,0};

        fflush(stdin);
        printf("\n---- Fue seleccionada la modalidad de dos jugadores ----\n");

        printf("\nIntroduzca su nombre jugador 1: ");
        gets(jugadorUno);
        strupr(jugadorUno);
        printf("\nJUGADOR 1: %s\n", jugadorUno);

        printf("\nIntroduzca su nombre jugador 2: ");
        gets(jugadorDos );
        strupr(jugadorDos);
        printf("\nJUGADOR 2: %s\n", jugadorDos);

        int ganador = 0;

        for(int i = 0; i < TURNOS; i++)
        {
                printf("\t\t\t\t\t  ---------------------\n");
                printf("\n\t\t\t\t\t%s es tu TURNO nro: %d\n", jugadorUno, i+1);
                turno(puntajeJugadorUno);
                mostrar_puntaje_dos(puntajeJugadorUno,puntajeJugadorDos,jugadorUno,jugadorDos);

                printf("\t\t\t\t\t  ---------------------\n");
                printf("\n\t\t\t\t\t%s es tu TURNO nro: %d\n", jugadorDos, i+1);
                turno(puntajeJugadorDos);
                ganador = mostrar_puntaje_dos(puntajeJugadorUno,puntajeJugadorDos,jugadorUno,jugadorDos);
        }

        if(ganador==0){
            printf("\n\n\n\t\t\t %s ERES EL GANADOR, FELICIDADES !!!", jugadorUno);
        } else if(ganador==1)
        {
            printf("\n\n\n\t\t\t %s ERES EL GANADOR, FELICIDADES !!!", jugadorDos);
        } else
        {
            printf("\n\n\n\t\t\t %s y %s HAN EMPATADO !!!", jugadorUno, jugadorDos);
        }
    }
    return 0;
}

int cantidad_jugadores(){
    int temp;
    printf("------- Desea jugar una partida en solitario o una partida de dos jugadores?? Elija la opcion deseada -------\n\n");
    printf("1) Partida en solitario. \n");
    printf("2) Partida de dos jugadores. \n\n>");
    scanf("%d", &temp);
    while(temp<1||temp>2){
        printf("La opcion seleccionada no es correcta, vuelva a hacerlo \n>>" );
        scanf("%d", &temp);
    }
    return temp==1?1:0;
}


void lanzamiento_dados(int dados[], int nroDados)
{
    srand(time(NULL));
    printf("\n\nLANZAMIENTO: ");
    for(int i = 0; i < nroDados; i++)
    {
        dados[i]=rand()%6+1;
        printf("   %d   ", dados[i]);
    }
    printf("\n");
    return;
}

int elegir_dados(int dados[], int dadosElegidos[], int nroDados, int nroDadosElejidos)
{
    int temp = 0;
    printf("\n\n--Elige con cuales dados quieres quedarte--\n Presiona 1 para quedarte con el dado y 0 para voverlo a lanzar\n");
    for( int i=0 ; i<nroDados ; i++)
    {
        printf("Deseas elegir el dado: %d? 1/0 \n >", dados[i]);
        scanf("%d", &temp);
        while(temp<0 || temp>1)
        {
        printf("La opcion seleccionada no es correcta, vuelva a hacerlo \n>>" );
        scanf("%d", &temp);
        }
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
    printf("\n---- Dados Elegidos ---- \n\n");
    if(nroDadosElejidos==0)printf("NO ELEGISTE NINGUN NUMERO\n");
    for(int i = 0; i < nroDadosElejidos; i++){
        printf(" %d\t", dadosElejidos[i]);
    }
    printf("\n");
    return;
}

void mostrar_opciones_de_puntaje(int jugada[], int puntajeJugador[][2])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0 ,h=1; h<N; j++ ,h++)
        {
            if(jugada[j]>jugada[h])
            {
                int temp = jugada[h];
                jugada[h] = jugada[j];
                jugada[j] = temp;
            }
        }
    }

    int aparece[N] ={0};
    int yaContado[N] ={0};
    int a [TURNOS][2] = {0,0,0};

    for(int i = 0; i < N; i++)
    {
        if(!yaContado[i])
        {
            for(int j = 0; j < N; j++)
            {
                if(jugada[i]==jugada[j])
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


    for(int i = 0; i < N; i++)
    {
        if(!yaContado[i])
        {
            a[jugada[i]-1][1]=jugada[i] * aparece[i];

            switch(aparece[i])
            {
                case 5:
                    puntajeJugador[9][0]?(a[10][1]=120):(a[9][1]=100);
                break;
                case 4:
                    a[8][1] = 75;
                break;
                case 3:
                    if(aparece[3]==2)a[7][1] = 50;
                break;
                case 2:
                    if(aparece[2]==3)a[7][1] = 50;
                break;
            }
        }
    }

    if((jugada[0]<jugada[1]&&jugada[1]<jugada[2]&&jugada[2]<jugada[3]&&jugada[3]<jugada[4])&&((jugada[0]==1&&jugada[4]==5)||(jugada[0]==2&&jugada[4]==6)))a[6][1]= 35;


    printf("\n\n\n");
    printf("Elija las siguientes opciones para anotar sus puntos: \n");

    int number = 0;
    int num ;
    for(int i=0; i<11; i++)
    {
        if(!puntajeJugador[i][0])
        {
            if(i<6)
            {
                number++;
                a[i][0]=number;
                printf("\n %d) Anotarse: %d al %d  ", a[i][0], a[i][1], i+1);

            }
            switch(i)
            {
            case 6:
                if(a[i][1])
                {
                    number++;
                    a[i][0]=number;
                    printf("\n %d) Anotarse: escalera", a[i][0]);

                } else
                {
                    number++;
                    a[i][0]=number;
                    printf("\n %d) Tacharse: escalera", a[i][0]);

                }
            break;
            case 7:
                if(a[i][1])
                {
                    number++;
                    a[i][0]=number;
                    printf("\n %d) Anotarse: full", a[i][0]);
                } else
                {
                    number++;
                    a[i][0]=number;
                    printf("\n %d) Tacharse: full", a[i][0]);
                }
                break;
            case 8:
                if(a[i][1])
                {
                    number++;
                    a[i][0]=number;
                    printf("\n %d) Anotarse: poker", a[i][0]);
                } else
                {
                    number++;
                    a[i][0]=number;
                    printf("\n %d) Tacharse: poker", a[i][0]);
                }
                break;
            case 9:
                if(a[i][1])
                {
                    number++;
                    a[i][0]=number;
                    printf("\n %d) Anotarse: generala", a[i][0]);
                } else
                {
                    number++;
                    a[i][0]=number;
                    printf("\n %d) Tacharse: generala", a[i][0]);
                }
                break;
            case 10:
                if(a[i][1])
                {
                    number++;
                    a[i][0]=number;
                    printf("\n %d) Anotarse: doble generala", a[i][0]);
                } else
                {
                    number++;
                    a[i][0]=number;
                    printf("\n %d) Tacharse: doble generala", a[i][0]);
                }
                break;
            }

        }
    }

    printf("\n\nElija la jugada deseada: \n>>");
    scanf("%d", &num);
    while(num>number || num<1)
    {
        printf("La opcion seleccionada no es correcta, vuelva a hacerlo \n>>" );
        scanf("%d", &num);
    }
    for(int i =0; i<11; i++)
    {
      if(num==a[i][0])
        {
         puntajeJugador[i][0]=1;
         puntajeJugador[i][1]=a[i][1];
         break;
        }
    }
    return;
}

void mostrar_puntaje(int puntajeJugador[][2], char nombre[])
{
    printf("\n\nCATEGORIAS\t\t%s", nombre);
    int sum = 0;
    for(int i = 0; i<11; i++)
    {
        printf("\n");
        if(i<6)
        {
            printf("%d\t\t\t", i+1);
            (!puntajeJugador[i][0])?printf("-\t\t"):printf("%d\t\t", puntajeJugador[i][1]);
            sum+=puntajeJugador[i][1];
        }
        switch(i)
        {
        case 6:
            printf("Escalera\t\t", i+1);
            (!puntajeJugador[i][0])?printf("-\t\t"):printf("%d\t\t", puntajeJugador[i][1]);
            sum+=puntajeJugador[i][1];
            break;
        case 7:
            printf("Full\t\t\t", i+1);
            (!puntajeJugador[i][0])?printf("-\t\t"):printf("%d\t\t", puntajeJugador[i][1]);
            sum+=puntajeJugador[i][1];
            break;
        case 8:
            printf("Poker\t\t\t", i+1);
            (!puntajeJugador[i][0])?printf("-\t\t"):printf("%d\t\t", puntajeJugador[i][1]);
            sum+=puntajeJugador[i][1];
            break;
        case 9:
            printf("Generala\t\t", i+1);
            (!puntajeJugador[i][0])?printf("-\t\t"):printf("%d\t\t", puntajeJugador[i][1]);
            sum+=puntajeJugador[i][1];
            break;
        case 10:
            printf("Generala Doble\t\t", i+1);
            (!puntajeJugador[i][0])?printf("-\t\t"):printf("%d\t\t", puntajeJugador[i][1]);
            sum+=puntajeJugador[i][1];
            break;
        }
    }
    printf("\n");
    printf("Puntuacion\t\t%d\n\n", sum);
    return;
}

int mostrar_puntaje_dos(int puntajeJugadorUno[][2],int puntajeJugadorDos[][2], char nombreUno[], char nombreDos[] )
{
    int sum1 = 0, sum2 = 0;
    printf("\n\nCATEGORIAS\t\t%s\t\t%s", nombreUno, nombreDos);
    for(int i = 0; i<TURNOS; i++)
    {
        printf("\n");

        if(i<6)
        {
            printf("%d\t\t\t", i+1);
            (!puntajeJugadorUno[i][0])?printf("-\t\t"):printf("%d\t\t", puntajeJugadorUno[i][1]);
            (!puntajeJugadorDos[i][0])?printf("-"):printf("%d", puntajeJugadorDos[i][1]);
            sum1+=puntajeJugadorUno[i][1];
            sum2+=puntajeJugadorDos[i][1];
        }

        switch(i)
        {
        case 6:
            printf("Escalera\t\t", i+1);
            (!puntajeJugadorUno[i][0])?printf("-\t\t"):printf("%d\t\t", puntajeJugadorUno[i][1]);
            (!puntajeJugadorDos[i][0])?printf("-"):printf("%d", puntajeJugadorDos[i][1]);
            sum1+=puntajeJugadorUno[i][1];
            sum2+=puntajeJugadorDos[i][1];
            break;
        case 7:
            printf("Full\t\t\t", i+1);
            (!puntajeJugadorUno[i][0])?printf("-\t\t"):printf("%d\t\t", puntajeJugadorUno[i][1]);
            (!puntajeJugadorDos[i][0])?printf("-"):printf("%d", puntajeJugadorDos[i][1]);
            sum1+=puntajeJugadorUno[i][1];
            sum2+=puntajeJugadorDos[i][1];
            break;
        case 8:
            printf("Poker\t\t\t", i+1);
            (!puntajeJugadorUno[i][0])?printf("-\t\t"):printf("%d\t\t", puntajeJugadorUno[i][1]);
            (!puntajeJugadorDos[i][0])?printf("-"):printf("%d", puntajeJugadorDos[i][1]);
            sum1+=puntajeJugadorUno[i][1];
            sum2+=puntajeJugadorDos[i][1];
            break;
        case 9:
            printf("Generala\t\t", i+1);
            (!puntajeJugadorUno[i][0])?printf("-\t\t"):printf("%d\t\t", puntajeJugadorUno[i][1]);
            (!puntajeJugadorDos[i][0])?printf("-"):printf("%d", puntajeJugadorDos[i][1]);
            sum1+=puntajeJugadorUno[i][1];
            sum2+=puntajeJugadorDos[i][1];
            break;
        case 10:
            printf("Generala Doble\t\t", i+1);
            (!puntajeJugadorUno[i][0])?printf("-\t\t"):printf("%d\t\t", puntajeJugadorUno[i][1]);
            (!puntajeJugadorDos[i][0])?printf("-"):printf("%d", puntajeJugadorDos[i][1]);
            sum1+=puntajeJugadorUno[i][1];
            sum2+=puntajeJugadorDos[i][1];
            break;
        }

    }
    printf("\n");
    printf("Puntuacion\t\t%d\t\t%d\n\n", sum1, sum2);




    if(sum1>sum2)
    {
        return 0;
    } else if(sum2>sum1)
    {
        return 1;
    } else
    {
        return 2;
    }

}

void turno(int puntajeJugadorUno[][2])
{
    int nroDados = N;
    int nroDadosElejidos = 0;
    int numeroLanzamiento = 0;
    int dados[N];
    int dadosElegidosJugadorUno[N];

    while(nroDadosElejidos<5 && numeroLanzamiento<3)
        {
            lanzamiento_dados(dados, nroDados);
            numeroLanzamiento++;

            if(numeroLanzamiento!=3)
            {
                nroDadosElejidos = elegir_dados(dados, dadosElegidosJugadorUno, nroDados, nroDadosElejidos);
                nroDados = N - nroDadosElejidos;
            }
            else
            {
                for(int i=0; i<nroDados; i++)
                {
                    dadosElegidosJugadorUno[nroDadosElejidos] = dados[i];
                    nroDadosElejidos++;
                }
            }

            mostrar_dados_elegidos(dadosElegidosJugadorUno, nroDadosElejidos);
        }

    mostrar_opciones_de_puntaje(dadosElegidosJugadorUno, puntajeJugadorUno);
    return;
}


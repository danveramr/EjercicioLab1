/*
Deber� ofrecer la posibilidad de jugar humano vs computadora y computadora vs computadora.
La selecci�n de movimientos la har� de forma aleatoria y no se permitir� sobrescribir una jugada previa.
Deber�n validarse las combinaciones ganadoras y de empate.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tablero(char matriz[][3]);
void jugador(char matriz[][3],int inicio);
void maquina(int *a, int *b, char matriz[][3]);
void maquina2(char matriz[][3]);
void condiciones(char matriz[][3], int *win);

int main(void)
{
	int opcion,flag=0,inicio=0;
	char matriz[3][3];
	printf("\nEjercicio lab no.1)");
	printf("\n---------------------");
	printf("\nJuego de gato");
	
	srand(time(NULL));

	//Se inicializan los valores de la matriz 3x3 como '_' para que coincidan con el tablero original
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			matriz[i][j]='_';
		}
	}
	
	//Men� del programa, en donde se podr� jugar las veces que la persona lo desee.
	//Existen dos opciones: Jugador vs. maquina y Maquina vs. maquina

	while(flag==0){
		
		printf("\n\nElige una opcion:\n1.Jugador vs. Maquina\n2.Maquina vs Maquina\n3.Salir\n\nOpcion: ");
		scanf("%d",&opcion);
	
		switch(opcion)
		{
			//Opcion para Jugador vs. maquina
			case 1:
				printf("\n\t___|___|___");
				printf("\n\t___|___|___");
				printf("\n\t   |   |   ");
				inicio = rand() % 2;
				//printf("\nInicio vale: %d", inicio);
					
				jugador(matriz,inicio);
				break;
			//Opcion para Jugador vs. maquina
			case 2:
				maquina2(matriz);
				break;
			case 3:
				printf("\nFin del programa.");
				exit(0);
			default:
				printf("\nElige una opcion valida");
				break;
		}
	}	
	
	return 0;
}

void tablero(char matriz[][3])
{	
	//Funcion que imprime el tablero con cada jugada realizada tanto 
	//por el jugador como por la maquina

	printf("\n\t_%c_|_%c_|_%c_",matriz[0][0], matriz[0][1], matriz[0][2]);
	printf("\n\t_%c_|_%c_|_%c_",matriz[1][0], matriz[1][1], matriz[1][2]);
	printf("\n\t_%c_|_%c_|_%c_",matriz[2][0], matriz[2][1], matriz[2][2]);
}

void jugador(char matriz[][3], int inicio)
{
	/*Funci�n que permite realizar una jugada a trav�s de los valores 
	introducidos. As�mismo, manda a llamar a otra funci�n que devuelve
	la jugada de la maquina*/
	
	int x,y,c=0,a,b,win=0;

	//Se reinicia el tablero cada vez que se inicia una nueva partida
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			matriz[i][j]='_';
		}
	}

	//La variable inicio puede tomar dos valores: 0 y 1
	//En caso de que sea 0, el jugador inicia la partida
	if(inicio == 0)
	{
		//Mientras que no haya un ganador, se podran realizar hasta un total de 8 jugadas
		while(c<4 && win==0)
		{
			printf("\nPosicion en x: ");
			scanf("%d",&x);
			printf("\nPosicion en y: ");
			scanf("%d",&y);
	
			matriz[x][y] = 'x';
			//inicio++;
			printf("\n\nTu jugada:\n");
			tablero(matriz);
	
			maquina(&a,&b,matriz);
			matriz[a][b] = 'o';
			tablero(matriz);

			c++;
			condiciones(matriz,&win);
		}
	}
	//En caso contrario, la maquina inicia la partida
	else
	{
		while(c<4 && win==0)
		{
			maquina(&a,&b,matriz);
			matriz[a][b] = 'x';
			tablero(matriz);

			printf("\nPosicion en x: ");
			scanf("%d",&x);
			printf("\nPosicion en y: ");
			scanf("%d",&y);
	
			matriz[x][y] = 'o';
			//inicio++;
	
			printf("\n\nTu jugada:\n");
			tablero(matriz);
			
			c++;
			condiciones(matriz,&win);
		}
	}

	//Si la bandera win se activa, el estado del juego pasara a ser ganado
	//En caso contrario, resultar� en empate
	if(win==0)
	{
		printf("\n\nEstado del juego: Empate");
	}
	else
	{
		printf("\n\nEstado del juego: Ganado");
	}
}

void maquina(int *a, int *b,char matriz[][3])
{
	/*Funci�n que determina la jugada de la m�quina, a partir de 
	valores pseudoaleatorios para a y b, los cuales representan
	las coordenadas de la matriz*/

	int cond = 0;

	/*Mientras el par ordenado elegido no tenga un lugar asignado,
	esos ser�n los valores correspondientes. En caso contrario,
	se generan nuevamente dichos valores*/
	
	while(cond == 0)
	{	
		*a = rand() % 3;
		*b = rand() % 3;
		if(matriz[*a][*b] != 'o' && matriz[*a][*b] != 'x')
		{
			cond=1;	
		}
	}
	printf("\n\nJugada de la maquina:\n");

}

void maquina2(char matriz[][3])
{
	/*Funci�n que manda a llamar a otra funci�n que devuelve
	la jugada de cada m�quina*/
	
	//Se reinicia el tablero cada vez que se inicia una nueva partida
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			matriz[i][j]='_';
		}
	}
	
	int a,b,c=0,win=0;
	printf("\nWin vale: %d",win);

	////Mientras que no haya un ganador, se podr� realizar hasta un total de 8 jugadas
	while(c<4 && win==0)
	{
		maquina(&a,&b,matriz);
		matriz[a][b] = 'x';
		tablero(matriz);
	
		maquina(&a,&b,matriz);
		matriz[a][b] = 'o';
		tablero(matriz);
		c++;
		condiciones(matriz,&win);
	}

	//De igual forma, si la bandera win se activa, el estado del juego pasara a ser ganado
	//En caso contrario, resultar� en empate
	if(win==0)
	{
		printf("\n\nEstado del juego: Empate");
	}
	else
	{
		printf("\n\nEstado del juego: Ganado");
	}
}
	
void condiciones(char matriz[][3], int *win)
{
	/*Funci�n que contiene todas las combinaciones de victoria para 
	el juego cl�sico de gato. La misma es llamada en cada turno de
	una partida*/

	if((matriz[0][0] == 'x' && matriz[1][1] == 'x')&& matriz[2][2] == 'x')
	{
		*win = 1;
	}
	else if((matriz[0][0] == 'o' && matriz[1][1] == 'o')&& matriz[2][2] == 'o')
	{
		*win = 1;
	}

	else if((matriz[0][2] == 'x' && matriz[1][1] == 'x')&& matriz[2][0] == 'x')
	{
		*win = 1;
	}
	else if((matriz[0][2] == 'o' && matriz[1][1] == 'o')&& matriz[2][0] == 'o')
	{
		*win = 1;
	}

	else if((matriz[0][0] == 'x' && matriz[0][1] == 'x')&& matriz[0][2] == 'x')
	{
		*win = 1;
	}
	else if((matriz[0][0] == 'o' && matriz[0][1] == 'o')&& matriz[0][2] == 'o')
	{
		*win = 1;
	}

	else if((matriz[1][0] == 'x' && matriz[1][1] == 'x')&& matriz[1][2] == 'x')
	{
		*win = 1;
	}
	else if((matriz[1][0] == 'o' && matriz[1][1] == 'o')&& matriz[1][2] == 'o')
	{
		*win = 1;
	}

	else if((matriz[2][0] == 'x' && matriz[2][1] == 'x')&& matriz[2][2] == 'x')
	{
		*win = 1;
	}
	else if((matriz[2][0] == 'o' && matriz[2][1] == 'o')&& matriz[2][2] == 'o')
	{
		*win = 1;
	}

	else if((matriz[0][0] == 'x' && matriz[1][0] == 'x')&& matriz[2][0] == 'x')
	{
		*win = 1;
	}
	else if((matriz[0][0] == 'o' && matriz[1][0] == 'o')&& matriz[2][0] == 'o')
	{
		*win = 1;
	}

	else if((matriz[0][1] == 'x' && matriz[1][1] == 'x')&& matriz[2][1] == 'x')
	{
		*win = 1;
	}
	else if((matriz[0][1] == 'o' && matriz[1][1] == 'o')&& matriz[2][1] == 'o')
	{
		*win = 1;
	}

	else if((matriz[0][2] == 'x' && matriz[1][2] == 'x')&& matriz[2][2] == 'x')
	{
		*win = 1;
	}
	else if((matriz[0][2] == 'o' && matriz[1][2] == 'o')&& matriz[2][2] == 'o')
	{
		*win = 1;
	}
	else 
	{
		win = 0;
	}
}
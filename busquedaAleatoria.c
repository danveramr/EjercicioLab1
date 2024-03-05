/*
Desarrolla un programa que mediante búsqueda aleatoria intente resolver el sistema de ecuaciones.
Nota: se recomienda probar con números enteros.
Nota 2: probar con números entre -100 y 100
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int b,d,e,f,cond=0,conta=0;
	int ec1,ec2,ec3,ec4;
	srand(time(NULL));

	printf("\nEjercico lab1");
	printf("\n----------------");

	while(cond == 0)
	{
		//Generación de valores para intentar resolver el sistema de ecuaciones del -100 al 100
		b = rand() % 201 - 100;
		d = rand() % 201 - 100;
		e = rand() % 201 - 100;
		f = rand() % 201 - 100;

		//Descripción del sistema de ecuaciones
		ec1= 16*b-6*d+4*e+f;
		ec2 = b-8*d+e+f;
		ec3 = 16*b+2*d-4*e+f;
		ec4 = 9*b+8*d-3*e+f;
	
		//Mientras no se cumplan las cuatro condiciones, el programa seguirá buscando una solución de manera aleatoria
		if(((ec1 == -36 && ec2 == -64) && ec3 == -4) && ec4 ==-64)
		{
			cond = 1;
			printf("\nB vale: %d",b);
			printf("\nD vale: %d",d);
			printf("\nE vale: %d",e);
			printf("\nF vale: %d",f);
		}
		else
		{
			conta++;
		}
	}

	printf("\nNumero de intentos para hallar la solucion: %d", conta);
	return 0;
}
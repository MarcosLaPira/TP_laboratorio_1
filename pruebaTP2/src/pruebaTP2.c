/*
 ============================================================================
 Name        : 3.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "laibrery.h"
#include "ArrayPassenger.h"

#define TAMANIO 51
#define LEN 5


int main(void)
{
	setbuf(stdout, NULL);

	Passenger aPassenger[LEN];


//declaro variables

	int opcion;
	int id=1;
	int lugarLibre;//indice
	int auxId;
	int auxIndice;

	if(initPassengers(aPassenger,LEN)==0)
	{
		do{
			if(utn_getNumero(&opcion,"\n Por favor ingrese una opcion: \n"
											"1) Altas \n"
									 		"2) Modificar\n"
											"3) Baja\n"
											"4) informar\n"
											"5) SALIR \n",
											"ERROR opcion incorrecta \n",1,5,4)==0)
			{
				switch(opcion)
				{
				//alta
					case 1:
						if(findEmptyFree(aPassenger,LEN,&lugarLibre)== 0  &&
							addPassengers(aPassenger,TAMANIO,lugarLibre,&id)==0 )
							{
								printf("alta ok");
							}
							else
							{
								printf("el alta no se pudo realizar");
							}

						break;
				//modificacion
					case 2://modificar imprimir pasajeros

						if(printPassengers(aPassenger,LEN)==0 &&
							utn_getNumero(&auxId,"\nIngrese el id que desea modificar \n","\nError \n",1,LEN,2) == 0 &&
							findPassengerById(aPassenger,LEN,auxId,&auxIndice)==0)

						{
							 printOnePassenger(aPassenger[auxIndice]);
							 modifyMenu(&aPassenger[auxIndice],TAM);
						}

						break;
				//baja
					case 3:
						if(printPassengers(aPassenger,LEN)==0 &&
						utn_getNumero(&auxId,"\nIngrese el id que desea dar de baja \n","\nError \n",1,LEN,2) == 0 &&
						findPassengerById(aPassenger,LEN,auxId,&auxIndice)==0 &&
						removePassenger(&aPassenger[auxIndice])==0)
						{
							printf("baja exitosa");
						}
						else
						{
							printf("la baja no pudo ser realizada");
						}

						break;
				//informar
					case 4:

						if(sortPassengers(aPassenger,LEN)==0)
						{
							printPassengers(aPassenger,LEN);
						}
						break;
				}
			}

		}while(opcion != 5);


	}

	return EXIT_SUCCESS;
}




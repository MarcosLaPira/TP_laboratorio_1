/*
 * ArrayPassenger.c
 *
 *  Created on: 14 may. 2022
 *      Author: lapir
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "laibrery.h"
#include "ArrayPassenger.h"


int initPassengers(Passenger* list, int len) // inicializar una array de estructuira en 1 // 1 LIBRE // 0 Ocupado
{
	int retorno = -1;
	int i;

		if(list != NULL && len > 0)
		{
		  for (i = 0; i < len ; i++)
		  {
			  list[i].isEmpty = 1;
		  }
		  retorno = 0;
		}
	  return retorno;
}
int addPassengers(Passenger* array,int len, int indice, int* id)
{

	int retorno = -1;

	Passenger bufferEmpleado;

	if (array != NULL && len >0 && indice >=0 && id != NULL)
	{
		if (
			utn_getNombre(bufferEmpleado.name,len,"\n  ingrese el nombre del pasajero\n","\n Error \n",2) == 0 &&
			utn_getNombre(bufferEmpleado.lastName,len,"\n ingrese apellido del pasajero \n","\n Error \n", 2) == 0 &&
			getNumeroFlotante(&bufferEmpleado.price,"\n  ingrese el precio del vuelo\n ","\n error \n",1.0,50000.0,2)==0 &&
			getAlfanumerico(bufferEmpleado.flyCode,"\n ingrese el codigo de vuelo \n","\n Error \n",len,2) == 0 &&
			utn_getNumero(&bufferEmpleado.idTypePassenger, "\n indique el tipo de pasajero \n 1. Bebe. \n 2. Menor de edad. \n 3. Adulto. \n 4. Anciano. \n","\nError \n",1,4,2) == 0 &&
			utn_getNumero(&bufferEmpleado.idStatusFlight, "\n indique el estado del vuelo \n 1. en horario. \n 2. demorado. \n 3. cancelado.  \n","\nError \n",1,3,2) == 0
			)
		{
//getAlfanumerico
			bufferEmpleado.id = *id;
			bufferEmpleado.isEmpty = 0;
			array[indice] = bufferEmpleado;
			*id = *id + 1 ;


			retorno = 0;
		}

	}
	return retorno;
}

int findEmptyFree(Passenger* list, int len, int* freeEmpty)
{

	int i;
	int retorno  = -1;

	if (len > 0 && list!= NULL && freeEmpty != NULL){

		for (i = 0;i<len; i++)
		{
			if (list[i].isEmpty == 1)
			{

				*freeEmpty = i;

				retorno = 0;
			}
		}
	}

	return retorno;
}
int findPassengerById(Passenger* list, int len,int id, int *indice)
{

	int retorno = -1;

	if (list != NULL && len >0 && indice != NULL)
	{
			for(int i=0 ; i<len ;i++)
			{
				if(list[i].isEmpty==0 && id==list[i].id)
				{

					*indice=i;
					retorno=0;
					break;
				}
		}

	}

	return retorno;
}





int printPassengers(Passenger* list,int len )
{
	int retorno = -1;
		if (list != NULL && len >0)
		{


			printf("\n 				  **LISTADO EMPLEADOS** \n");
			printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
			printf("ID	 	NOMBRE		 APELLIDO		 PRECIO		 CODIGO		T.PASAJERO		ESTADO VUELO ");

			for (int i = 0;i<len ;i++)
			{
				if(list[i].isEmpty == 0)
				{

					printOnePassenger(list[i]);
				}
			}

			printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");

			retorno = 0;
		}
	return retorno;
}

void printOnePassenger(Passenger pasenger)
{
	eEstatusFlight auxEstatusFlight[3]={{1,"en horario"},{2,"demorado"},{3,"cancelado"}};
	eTypePassenger auxTypePassenger[4]={{1,"bebe"},{2,"menor"},{3,"adulto"},{4,"anciano"}};
int i;
int j;
	for( i =0;i<5;i++)
	{
		if(pasenger.idStatusFlight == auxEstatusFlight[i].idStatusFlight)
		{
			break;
		}
	}
	for(j =0;j<5;j++)
	{
		if(pasenger.idTypePassenger == auxTypePassenger[j].idTypePassenger)
		{
			break;
		}
	}


	printf("\n%d	 	%s		 %s     		  %.2f	  	 %s    	 %s  		 %s \n",
			pasenger.id, pasenger.name, pasenger.lastName, pasenger.price, pasenger.flyCode,
			auxTypePassenger[j].description, auxEstatusFlight[i].description);


}
void modifyMenu(Passenger* bufferPassenger,int tamanioTexto)
{
	int opcion;

		do{
			if(utn_getNumero(&opcion,"Por favor ingrese el numero de la opcion que "
											"desea modificar: \n"
											"1) Nombre \n"
											"2) Apellido\n"
											"3) precio\n"
											"4) codigo de vuelo\n"
											"5)	tipo de pasajero \n"
											"6) estado del vuelo \n"
											"7) SALIR \n",
											"ERROR opcion incorrecta \n",1,6,2)== 0)
			{

				switch (opcion)
				{

					case 1 :

						if(utn_getNombre(bufferPassenger->name,tamanioTexto,"\nNombre? \n","\nError \n", 2)==0)
						{

							printf("modificacion ok");

						}
						break;

					case 2 :

						if(utn_getNombre(bufferPassenger->lastName,tamanioTexto,"\nApellido? \n","\nError \n", 2)==0)
						{
							printf("modificacion ok");
						}

						break;
					case 3 :

						if(getNumeroFlotante(&bufferPassenger->price,"\n  ingrese el precio del vuelo\n ","\n error \n",1.0,50000.0,2)==0)
						{
							printf("modificacion ok");
						}
						break;
					case 4 :

						if(getAlfanumerico(bufferPassenger->flyCode,"\n ingrese el codigo de vuelo \n","\n Error \n",10,2) == 0)
						{
							printf("modificacion ok");
						}
						break;

					case 5:

						if(utn_getNumero(&bufferPassenger->idTypePassenger, "\n indique el tipo de pasajero \n 1. Bebe. \n 2. Menor de edad. \n 3. Adulto. \n 4. Anciano. \n","\nError \n",1,4,2) == 0)
						{
							printf("modificacion ok");
						}
						break;

					case 6:

						if(utn_getNumero(&bufferPassenger->idStatusFlight, "\n indique el estado del vuelo \n 1. en horario. \n 2. demorado. \n 3. cancelado.  \n","\nError \n",1,3,2)== 0)
						{
							printf("modificacion ok");
						}
						break;
					}


			}

		}while(opcion != 7);

}

int removePassenger(Passenger* bufferPassenger)
{
	int retorno = -1;

		if(bufferPassenger != NULL && bufferPassenger->isEmpty == 0)
		{
			bufferPassenger ->isEmpty = 1;

			retorno = 0;
		}
	return retorno;
}

int sortPassengers(Passenger* list, int len)
{
	int retorno = -1;
	int flagSwap;
	int i;
	int order;
	int orderTipo;
	Passenger bufferSwap;

	if (list != NULL && len >0){


		if (utn_getNumero(&order, "Por favor ingrese que tipo de ordenamiento desea. \n .Ingrese: \n 1 Descendente \n 0 Ascendente .","\nERROR\n",0,1,3) == 0)
		{
			do {
				  flagSwap = 0;

				  for (i = 0 ; i<len - 1; i++)
				  {
						if (list[i].isEmpty == 1 || list[i + 1].isEmpty == 1){
								continue;
						}

						if (order == 1){

								orderTipo = (strncmp(list[i].lastName,list[i + 1].lastName,TAM) < 0); // ascendente
							}
						else if(order == 0)
						{

							orderTipo = (strncmp(list[i].lastName,list[i + 1].lastName,TAM) > 0); // des
						}
							//  en esta parte va lo que queremos ordenar array[i].loQueQueresQrdenar
						if ((orderTipo) == 1)
						{
							flagSwap = 1;
							bufferSwap = list[i];
							list[i] = list[i + 1];
							list[i + 1] = bufferSwap;

						} // FIN DEL IF
						else if (strncmp(list[i].lastName, list[i + 1].lastName,TAM) == 0  //Comparacion de CHAR
						&& list[i].idTypePassenger > list[i + 1].idTypePassenger) // COMPARACION DE STRING
						{
								flagSwap = 1;
								bufferSwap = list[i];
								list[i] = list[i + 1];
								list[i + 1] = bufferSwap;
						}

				  }

				 len --;

			}while (flagSwap);
		}
			retorno = 0;
	}

	return retorno;
}







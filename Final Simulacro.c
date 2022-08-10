/*Una tienda de antig�edades muy conocida por realizar subastas de sus productos, se vio obligada a cambiar la forma de realizar sus ventas
debido a la realidad sanitaria.
La tienda antes de abrir sus puertas al p�blico, carga la totalidad de art�culos disponibles en el lote
que expondr� para la subasta y el precio base de cada uno.
Al comenzar el ingreso del p�blico, el mismo podr� recorrer el sal�n completo,
anotar en una ficha personal cada uno de los c�digos de art�culos por los que desea subastar, y al retirarse, el cliente completar� la oferta
que desea realizar por cada uno de los art�culos en la terminal disponible para registrar la operaci�n.
Otro control que debe tener la tienda es que el aforo habilitado es del 50%, es decir, solamente puede haber 10
clientes al mismo tiempo dentro del local. Pudiendo concurrir como m�ximo hasta 50 clientes durante toda la
jornada.
Se pide desarrollar un programa para administrar el lote subastado, sabiendo que cada lote no tiene m�s de
300 art�culos diferentes.
Al comenzar la jornada se solicitara al empleado cargar los datos de los art�culos al lote con la siguiente
informaci�n:
� ID de art�culo (valores enteros entre 1000 y 3000 no necesariamente consecutivos)
� Nombre, hasta 40 caracteres
� Descripci�n, hasta 255 caracteres. (Dato no obligatorio)
� Precio Base.
La carga del lote finaliza cuando se ingresa el c�digo de art�culo 9999.
Luego de la carga, estar� disponible un men� para operar con los datos. Es importante que al finalizar cada
acci�n seleccionada del men� vuelva al inicio del mismo, hasta que el usuario elija la opci�n de cerrar
subasta.
El men� debe contener las siguientes opciones:
1. Registrar ingreso del cliente: Al ingresar el cliente al sal�n se deben almacenar los siguientes datos:
DNI, Nombre, Mail y Tel�fono de contacto (todos los datos son obligatorios).


Se debe controlar que el cliente no exista cargado y que la capacidad del sal�n no supere los 10
clientes en el interior en simult�neo.
2. Registrar oferta del cliente: Se solicitar� el DNI del cliente, validando su
 existencia, y se proceder� a cargar la oferta para cada art�culo, ingresando el c�digo y oferta.
Es importante validar que el c�digo sea existente y que la oferta sea mayor o igual al valor base.
En esta operaci�n, y por cada art�culo, se deber� validar si la oferta es mayor
a la existente o mayor a la oferta base si es que a�n no hay oferta registrada, y si se cumple la condici�n, registrar en el art�culo, el DNI del cliente y la oferta realizada.
Este men� finaliza cuando el cliente indica que no tiene m�s art�culos para cargar.
En ese momento el cliente se retira del sal�n y libera un cupo del aforo permitido.
3. Cerrar subasta: Para poder realizar esta opci�n se pedir� el ingreso de un token
de seguridad o palabra clave (la cual ser�: LT&7412) y si el ingreso es correcto se mostrar�
el listado SOLAMENTE de cada uno de los art�culos que han recibido una oferta, junto con los datos del cliente ganador.
Solo se permitir�n tres intentos de ingreso del token, si no se ingresa el correcto,
no finaliza el programa, sino que se muestra de nuevo el men� principal.*/

#include<stdio.h>
#include<stdlib.h>
#define v 300

struct producto
{
 int id;
 char nombre[40];
 char descripcion[255];
 float preciobase;
 int cant;

};

void ingresarProductos(struct producto productos[])
 {
    printf("-INGRESE PRODUCTOS-\n");
    printf("Ingresar 9999 para salir\n\n");

    int cantidad=0;

  for (int i=0;i<v; i++) {

    printf("ID.");

    do
    {
        printf ("Por favor ingrese un numero real entre 1000 y 3000:\n");
        scanf("%d", &productos[i].id);

    }while (productos[i].id < 1000 || productos[i].id > 3000 && productos[i].id != 9999);

    if (productos[i].id == 9999)
    break;

    printf("Nombre: \n");
    scanf("%s",&productos[i].nombre);

    printf("Descripcion: \n");
    scanf("%s",&productos[i].descripcion);

    printf("Precio base: \n");
    scanf("%f",&productos[i].preciobase);

    cantidad ++;

    productos[i].cant = cantidad;
  }
}

int main (void)
{
    struct producto productos[v];

    short opcion;
    int i;

    printf ("BIENVENIDO\n\n");

    while (opcion!=1)
    {
        printf ("Ingrese 1 para cargar articulos\n");
        printf ("\n\n");
        scanf ("%hd",&opcion);

        if (opcion!=1)
        {
            printf ("OPCION INVALIDA\n");
            printf ("Se necesita un minimo de 1 articulo cargado para comenzar subasta\n");
        }

    switch (opcion)
    {
    case 1:
        ingresarProductos(productos);
    break;
    }

    }
    for (i=0;i<productos[i].cant;i++)
    {
            printf ("-MENU DE PRODUCTOS-\n\n");
            printf ("\n\n");
            printf ("\nARTICULO DISPONIBLE\n");
            printf ("ID: %d\n",productos[i].id);
            printf ("Nombre: %s\n",productos[i].nombre);
            printf ("Descripcion: %s\n",productos[i].descripcion);
            printf ("Precio base: %.2f\n",productos[i].preciobase);
            printf ("ART:%d",productos[i].cant);
    }

    return 0;
}


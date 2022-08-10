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

    }printf ("\n-MENU DE PRODUCTOS-\n");
    for (i=0;i<productos[i].cant;i++)
    {

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

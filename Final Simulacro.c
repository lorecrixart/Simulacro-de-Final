/*An antique store well known for holding auctions of its products, was forced to change the way it conducts its sales
due to health realities.
The store, before opening its doors to the public, uploads the total number of items available in the lot it will display for auction and the base price of each item.
the auction and the base price of each item.
When the public enters the store, they will be able to go through the entire room,
write down in a personal file each of the item codes for which he/she wishes to bid, and when leaving, the client will complete the bidding for each of the items he/she wishes to bid.
the items on the terminal available to register the transaction.
Another control that the store must have is that the authorized capacity is 50%, i.e., there can only be 10 customers inside the store at the same time.
customers inside the store at the same time. A maximum of 50 customers can be present during the entire day.
day.
It is requested to develop a program to manage the auctioned lot, knowing that each lot has no more than 300 different items.
300 different items.
At the beginning of the day the employee will be asked to load the data of the items to the lot with the following.
information:
- Item ID (integer values between 1000 and 3000 not necessarily consecutive).
- Name, up to 40 characters
- Description, up to 255 characters (not mandatory data)
- Base Price.
The batch upload ends when the item code 9999 is entered.
After loading, a menu will be available to operate with the data. It is important that at the end of each
selected action in the menu returns to the beginning of the menu, until the user chooses the option to close the auction.
auction.
The menu must contain the following options:
1. Register client entry: When the client enters the room, the following data must be stored:
DNI, Name, Mail and Contact telephone number (all data are mandatory).


It is necessary to check that the client is not already loaded and that the capacity of the salon does not exceed 10
customers inside the room at the same time.
2. Register the client's offer: The client's ID will be requested, validating its existence, and the
 The offer will be loaded for each item, entering the code and offer.
It is important to validate that the code exists and that the offer is greater than or equal to the base value.
In this operation, and for each item, you must validate whether the bid is higher than the existing bid or higher than the base value.
to the existing one or higher than the base bid if there is no registered bid yet, and if the condition is met, record the customer's ID number and the bid made on the item.
This menu ends when the customer indicates that he/she has no more items to load.
At that moment the customer leaves the room and frees a quota of the allowed capacity.
3. Close auction: In order to perform this option you will be asked to enter a security token or keyword (which will be used for the auction).
token or keyword (which will be: LT&7412) and if the entry is correct it will show the list ONLY of each one of
the listing ONLY of each of the items that have received a bid, along with the winning customer's details.
Only three attempts to enter the token will be allowed, if the correct token is not entered,
the program is not terminated, but the main menu is displayed again.*/


#include<stdio.h>
#include<stdlib.h>
#define v 300

struct producto{
 
 int id;
 char nombre[40];
 char descripcion[255];
 float preciobase;
 int cant;
 int auxID;

};

void productosRepetidos(struct producto productos[]){
 
     for (int i=0;i < productos[i].cant;i++){
      
            while (productos[i].id == productos[i].auxID || productos[i].id <1000 || productos[i].id >3000 || productos[i].id != 9999){
             
                printf ("ERROR. ID invalido.\nIngrese otro valor:\n");
                scanf ("%d",&productos[i].id);
            }
    }
}

void ingresarProductos(struct producto productos[]){
 
    printf("-INGRESE PRODUCTOS-\n");
    printf("Ingresar 9999 para salir\n\n");

    int cantidad=0;

  for (int i=0;i<v; i++){

    printf("ID.");

    do{
     
        printf ("Por favor ingrese un numero real entre 1000 y 3000:\n");
        scanf("%d", &productos[i].id);

        productos[i].auxID = productos[i].id;

        productosRepetidos(productos);

    }while (productos[i].id < 1000 || productos[i].id > 3000 && productos[i].id != 9999);

    if (productos[i].id == 9999)
    return;

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

int main (void){
 
    struct producto productos[v];

    short opcion;
    int i;

    printf ("BIENVENIDO\n\n");

    while (opcion!=1){
     
        printf ("Ingrese 1 para cargar articulos\n");
        printf ("\n\n");
        scanf ("%hd",&opcion);

        if (opcion!=1){
         
            printf ("OPCION INVALIDA\n");
            printf ("Se necesita un minimo de 1 articulo cargado para comenzar subasta\n");
        }

    switch (opcion){
      
    case 1:
        ingresarProductos(productos);
    break;
    }

    }
    for (i=0;i<productos[i].cant;i++){
     
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



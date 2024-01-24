/* INSTRUCCIONES -------
En base a la estructura
struct producto{
    char codigo[25];
    char nombreProducto[25];
    char descrProducto[50];
    int cantidad;



}
COnstruir un programa que implemente un menu de opciones:
1. Ingresar datos: Lee permite al usuario ingresar un producto -> archivo plano (txt) -> A01 Arroz
San Carlos
2. Mostrar datos
3.Salir //No se debe guardar nada de manera vertical
*/

#include <stdio.h>
#include <string.h>

// Estructura a usar 
struct producto
    {
        char codigo[25];
        char nombreProducto[25];
        char descrProducto[50];
        int cantidad;
    };

int main(int argc, char const *argv[])
{
    // Variables a usar para el archivo
    FILE *ptr;

    char archivo[20] = {"MisProducto.txt"};
    struct producto contenido[500];


    // Se va a abrir el archivo
    ptr = fopen(archivo, "w");
    if (ptr)
    {
        printf("El archivo se abrió correctamente.\n");
    }
    else
    {
        printf("El archivo tuvo un problema al abrirse.\n");
        return 1;
    }


    // Se va a empezar a solicitar los productos
    printf("Ingrese el producto que quiere registra, digite SALIR para dejar de escribir\n");
    do
    {
        printf("Ingrese el codigo del producto:\n");
        gets(contenido->codigo);
        //printf("Ingrese el nombre del producto:\n");
        //gets(contenido->nombreProducto);
        fprintf(ptr, "%s\t|", contenido);
        printf("Escriba la expresion que usted desee y luego retorno para finalizar \n");
    } while (strcmp(contenido, "SALIR") != 0);

    //Cerrar el archivo
    if (fclose(ptr))
    {
        printf("El archivo no se cerro correctamente.\n");
        return 1;
    }else
    {
        printf("El archivo se cerró correctamente.");
    }
    
    
    
    return 0;
}

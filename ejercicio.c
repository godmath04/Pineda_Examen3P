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
    }contenido;

 // Funcion para recibir los productos
char variosProductos()
{
    int otroProducto;
    puts("Desea ingresar los datos de otro productos: (1 SI | 2 NO)");
    scanf("%d", &otroProducto);
    return otroProducto;
}
//funcion para obtener los productos

void obtencionDatos(struct  producto *ptr)
{

    puts("Ingrese el codigo del producto del archivo:\n");
    scanf("%d", &ptr->codigo);
    getchar(); // Tengo un problema con el bufer y eso hace que se llene solo el apartado de nombre

    puts("Ingrese el nombre del producto:");
    gets(ptr->nombreProducto);
    printf("\n");
    puts("Ingrese la descripcion del producto:");
    gets(ptr->descrProducto);
    printf("\n");
    puts("Ingrese la cantidad del producto:");
    scanf("%d", &ptr->cantidad);
    getchar();
};
// funcion que mostraría los productos

void mostrarProductos(struct producto *ptr2, int numeroProducto)
{
    for (int i = 0; i < numeroProducto; i++)
    {
        puts("Datos del Producto:");
        printf("Codig: %d\tNombre: %s\tDescripcion %s\tCantidad: %d", ptr2[i].codigo,ptr2[i].nombreProducto,ptr2[i].descrProducto,ptr2[i].cantidad);
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    // Variables de estructura
    int numeroProducto = 0;
    puts("Bienvenido al sistema de registro de productos.");
    printf("************\n");
    struct producto MisProductos[100];

    //Variables de archivo
    FILE *ptr;
    char archivo[20] = {"MisProducto.txt"};

    //Abrir el archivo
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
    
    do
    {
        obtencionDatos(&MisProductos[numeroProducto]);
        numeroProducto++;
    } while (variosProductos() == 1);

    mostrarProductos(MisProductos, numeroProducto);

     //Cerrar el archivo
    if (fclose(ptr))
    {
        printf("El archivo no se cerro correctamente.\n");
        return 1;
    }else
    {
        printf("El archivo se cerró correctamente.");
    }

 /*

  
    // Se va a empezar a solicitar los productos
    printf("Ingrese el producto que quiere registra, digite SALIR para dejar de escribir\n");
    do
    {
        printf("Ingrese el codigo del producto:\n");
        gets(contenido->codigo);
        printf("Ingrese el nombre del producto:\n");
        gets(contenido->nombreProducto);
        //fprintf(ptr, "%s\t|", contenido);
        printf("Escriba la expresion que usted desee y luego retorno para finalizar \n");
    } while (strcmp(contenido, "SALIR") != 0);

    */
    
    
    return 0;
}

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
} contenido;

// Funcion para recibir los productos
char variosProductos()
{
    int otroProducto;
    puts("Desea ingresar los datos de otro productos: (1 SI | 2 NO)");
    scanf("%d", &otroProducto);
    return otroProducto;
}
// funcion para obtener los productos

void obtencionDatos(struct producto *ptr2)
{

    puts("Ingrese el codigo del producto del archivo:");
    gets(ptr2->codigo);
    puts("Ingrese el nombre del producto:");
    gets(ptr2->nombreProducto);
    printf("\n");
    puts("Ingrese la descripcion del producto:");
    gets(ptr2->descrProducto);
    printf("\n");
    puts("Ingrese la cantidad del producto:");
    scanf("%d", &ptr2->cantidad);
    getchar();
};
// funcion que mostraría los productos

void mostrarProductos(struct producto *ptr2, int numeroProducto)
{
    for (int i = 0; i < numeroProducto; i++)
    {
        puts("Datos del Producto:");
        printf("Codig: %d\tNombre: %s\tDescripcion %s\tCantidad: %d", ptr2[i].codigo, ptr2[i].nombreProducto, ptr2[i].descrProducto, ptr2[i].cantidad);
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
    // Variables de archivo
    FILE *ptr;
    char archivo[20] = {"MisProducto.txt"};

    // Estructura solicitando datos
    do
    {
        obtencionDatos(&MisProductos[numeroProducto]);
        numeroProducto++;
    } while (variosProductos() == 1);

    mostrarProductos(MisProductos, numeroProducto);

    // Abrir el archivo
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


    // Escribir en el archivo mediante fprintf
    for (int i = 0; i < numeroProducto; i++)
    {
        fprintf(ptr, "%s\t|,%s\t|,%s\t|,%d\t|\n", MisProductos[i].codigo, MisProductos[i].nombreProducto, MisProductos[i].descrProducto, MisProductos[i].cantidad);
    }


    // Cerrar el archivo
    if (fclose(ptr))
    {
        printf("El archivo no se cerro correctamente.\n");
        return 1;
    }
    else
    {
        printf("El archivo se cerro correctamente.");
    }

    // Leer el archivo
    ptr = fopen(archivo, "r");
    fread(&MisProductos, sizeof(struct producto) * numeroProducto, 1, ptr);
    fclose(ptr);


    return 0;
}

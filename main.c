//Escriba un programa que reemplace un número de línea existente por otro en un archivo.

#include <stdio.h>
#include "string.h"
#include "stdlib.h"
#define MAX_LINEAS 100
#define MAX_LONGITUD 256
int main()
{
    char *archivo="ejercicio8.txt";
    FILE *fp;
    fp= fopen(archivo,"w");
    if(fp==NULL)
    {
        printf("No se abrio con exito\n");
        return -1;
    }else
        {
            fprintf(fp," 1\n 2\n 3\n 4\n 5\n 6\n 7\n 8\n 9\n");
        }
    fclose(fp);
    fopen(archivo,"r");

    int cont = 0;
    char linea[MAX_LINEAS][MAX_LONGITUD];   // Almacenamos de forma temporal en linea[][]
    while (fgets(linea[cont], MAX_LONGITUD, fp) != NULL && cont < MAX_LINEAS)   // y lo recorremos guardando todo en linea
    {
        cont++;
    }
    fclose(fp);

    const char *nuevaLinea = "PASO A SER EL NRO 5\n";
    int lineaAcambiar=2;
    if(strlen(nuevaLinea)<MAX_LONGITUD)
    {
        strcpy(linea[lineaAcambiar - 1], nuevaLinea);   // en la posicion de linea[lineaAcambiar - 1] qeu ahora guarde nueva linea...
    }

    //pero todavia no se escribio nada...unicamente se le dijo que en la pos 2(2-1) va a ir la nueva linea...
    // Abrir el archivo en modo de escritura ('w') para sobrescribir su contenido
    fp = fopen(archivo, "w");
    for (int i = 0; i < cont; i++) {
        fprintf(fp, "%s", linea[i]);
    }
    fclose(fp);


    return 0;
}

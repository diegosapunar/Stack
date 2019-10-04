#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"


int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Modo de uso: ./solver test.txt\n");
		return 0;
	}

	/* Abrimos el archivo input en modo de lectura */
	FILE *input_file = fopen(argv[1], "r");

	/* Abrimos el archivo output en modo de escritura */
	FILE *output_file = fopen("output.txt", "w");

	/* Revisa que el archivo fue abierto correctamente */
	if (!input_file)
	{
		printf("¡El archivo %s no existe!\n", argv[1]);
		return 2;
	}

	/* Definimos y asignamos las constantes del problema */
	int n; int m; int l;
	fscanf(input_file, "%d %d %d", &n, &m, &l);

	Stack **matriz = malloc(n * m * sizeof(Stack * ));

	for (int i = 0; i < n * m; i++)
	{
		matriz[i] = stack_init();
	}
	
	for (int i = 0; i < l; i++)
	{
		/* Definimos las variables del problema: 
			o: operacion (0:push / 1:pop)
			r: row
			c: column
			k: color 
		 */ 
		int o; int r; int c; int k;
		int value; 							// Valor que sale

		/* Leemos cada linea del archivo */
		fscanf(input_file, "%d %d %d %d", &o, &r, &c, &k);

		
		if (o == 0) {						// La operacion es push
			push(matriz[r * m + c], k);
		}
		else if(o == 1) {					// La operacion es pop
			while(true){
				if (matriz[r * m + c] -> count)
				{
					value = pop(matriz[r * m + c]);
					if (value == k) {
						fprintf(output_file, "%d\n", value);
						break;
					}
					else {
						fprintf(output_file,"%d\n", value);
					}
				}
				else {
					// printf("%s\n", "Vacio");
					fprintf(output_file, "%s\n", "vacio");
					break;
				}
			}
		}
	}

	/* Cerramos los archivos correctamente */
	fclose(input_file);
	fclose(output_file);

	///////////////// Recuerda que antes de acabar tu programa debes liberar toda la memoria reservada ///////////////////
	for (int i = 0; i < n * m; i++)
	{
		destroy(matriz[i]);
	}

	free(matriz);

	/* Esta linea indica que el programa termino sin errores*/
	return 0;
}

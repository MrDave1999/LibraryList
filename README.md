# LibraryList Generic
[![LibraryList](https://img.shields.io/badge/C-ListGeneric-blue)](https://github.com/MrDave1999/LibraryList)
[![LibraryList](https://img.shields.io/badge/LibraryList-v3.0-blue)](https://github.com/MrDave1999/LibraryList)

LibraryList es una biblioteca que permite usar diversas estructuras de datos de forma genérica, esto quiere decir que en un programa se puede tener una lista de objetos de tipo `Vehículo` y en otra objetos de tipo `Conductor`.

Hasta ahora las estructuras de datos que maneja la biblioteca son:

- LinkedList.
- ArrayList.

### Requisitos

Para poder compilar un programa usando esta biblioteca, se necesita tener un compilador de C que cumpla con el estándar [C11](https://es.wikipedia.org/wiki/C_(lenguaje_de_programaci%C3%B3n)#C11), de lo contrario, no funcionará.

¡No intentes usar esta biblioteca en C++! ¡No es compatible!

### Instalación

Necesitas descargar:

- Un compilador de C, como por ejemplo [GCC](https://jmeubank.github.io/tdm-gcc/download/).

- El archivo `LibraryList_v3.0` (lo encuentras en este enlace: https://github.com/MrDave1999/LibraryList/releases/tag/v3.0).

Después de haber descargado las herramientas, agregaremos la carpeta `lst` en el directorio `include`, que venga por defecto cuando instalemos el compilador. El archivo `liblist.a` debe estar añadido en la carpeta `lib`.

Para usar las funciones que traiga la biblioteca en un programa fuente, simplemente incluimos este archivo de cabecera:
```c
#include <lst/List.h>
```
Por último, se le debe avisar al enlazador el nombre de la biblioteca para que pueda buscar las funciones previamente compiladas:
```c
gcc prueba.c -llist
```

### Documentación API

En este [hilo](https://github.com/MrDave1999/LibraryList/wiki/Documentaci%C3%B3n) podrás ver la descripción, parámetros, valor de retorno y un ejemplo de uso de cada función.

### Uso

**1.- Ejemplo:** Mostrar en pantalla los nombres de cada persona.
```c
/* En este ejemplo la macro "add" añade elementos a una lista doblemente enlazada. */

#include <stdio.h>
#include <lst/List.h>

int main(void)
{
	/* Creamos la lista vacía */
	LinkedList* listaPersonas = newLinkedList();
	
	printf("Elementos: %d\n", size(listaPersonas));
	
	/* Añadimos elementos a la lista */
	add(listaPersonas, "Pepito");
	add(listaPersonas, "David");
	add(listaPersonas, "Jose");
	add(listaPersonas, "Lukas");
	
	/* Imprimimos los elementos de la lista */
	foreach(char, nombre, listaPersonas)
		printf("%s\n", nombre);
	
	/* Liberamos los elementos de la lista y 
		también el objeto al que apuntaba listaPersonas 
	*/
	delete(listaPersonas);
	return 0;
}
```

**2.- Ejemplo:** Muestra en pantalla los números del 1 al 4.
```c
/* En este ejemplo la macro "add" añade elementos a un arreglo dinámico. */

#include <stdio.h>
#include <lst/List.h>

int main(void)
{
	/* Creamos la lista vacía */
	ArrayList* listaNums = newArrayList();
	
	printf("Elementos: %d\n", size(listaNums));
	
	/* Añadimos elementos a la lista */
	add(listaNums, 1);
	add(listaNums, 2);
	add(listaNums, 3);
	add(listaNums, 4);
	
	/* Imprimimos los elementos de la lista */
	foreach(int, num, listaNums)
		printf("%d\n", *num);
	
	/* Liberamos los elementos de la lista y 
		también el objeto al que apuntaba listNums 
	*/
	delete(listNums);
	return 0;
}
```

### Créditos

- [MrDave](https://github.com/MrDave1999) 

# LibraryList Generic
[![LibraryList](https://img.shields.io/badge/C-ListGeneric-blue)](https://github.com/MrDave1999/LibraryList)
[![LibraryList](https://img.shields.io/badge/LibraryList-v2.0-blue)](https://github.com/MrDave1999/LibraryList)

LibraryList es una biblioteca que permite usar diversas estructuras de datos de forma genérica, esto quiere decir que en un programa se puede tener una lista de objetos de tipo `Vehículo` y en otra objetos de tipo `Conductor`.

Hasta ahora las estructuras de datos que maneja la biblioteca son:

- LinkedList.
- ArrayList.
- Queue.
- Stack.

### Requisitos

Para poder compilar un programa usando esta biblioteca, se necesita tener un compilador de C que cumpla con el estándar [C11](https://es.wikipedia.org/wiki/C_(lenguaje_de_programaci%C3%B3n)#C11), de lo contrario, no funcionará.

### Instalación

Necesitas descargar:

- Un compilador de C, como por ejemplo [GCC](https://jmeubank.github.io/tdm-gcc/download/).

- El archivo `liblist.a` (debes seleccionar dependiendo de la arquitectura de la máquina) lo encuentras en este enlace: https://github.com/MrDave1999/LibraryList/releases/tag/v2.0

Después de haber descargado las herramientas, agregaremos la carpeta `lst` en el directorio `include`, que venga por defecto cuando instalemos el compilador. El archivo `liblist.a` debe estar añadido en la carpeta `lib`.

Para usar las funciones que traiga la biblioteca en un programa fuente, simplemente incluimos este archivo de cabecera:
```c
#include <lst/List.h>
```
Por último, se le debe avisar al enlazador el nombre de la biblioteca para que pueda buscar las funciones previamente compiladas:
```c
gcc prueba.c -llist
```

### Documentación

En el siguiente enlace podrás ver la forma como se debe usar cada función: https://github.com/MrDave1999/LibraryList/wiki/

### Uso

En este sencillo ejemplo se muestra en pantalla los nombres de cada persona:
```c
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

### Créditos

- [MrDave](https://github.com/MrDave1999) 

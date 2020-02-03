# LibraryList
[![LibraryList](https://img.shields.io/badge/C-LibraryList-blue)](https://github.com/MrDave1999/LibraryList)
[![LibraryList](https://img.shields.io/badge/LibraryList-v1.5-blue)](https://github.com/MrDave1999/LibraryList)

LibraryList es una biblioteca de listas en la cual permitirá manejar fácilmente un `LinkedList` o `ArrayList`, debido a que, todo se lo implementó de forma genérica, esto quiere decir que podrás tener en una misma aplicación varios `LinkedList` sin la necesidad de gastar tanto código.

### Instalación

Se debe agregar el archivo `libList.a` en la carpeta `lib` y los ficheros `LinkedList.h`, `ArrayList.h` y `ManagamentMemory.h` lo añades en la carpeta `include`.

Las carpetas `lib` y `include` se encuentran en el directorio (se suele llamar `bin`) donde se instaló el compilador. Posteriormente incluyes los encabezados en el main.c de esta manera:
```C
#include <LinkedList.h>
#include <ArrayList.h>
```
En este [enlace](https://github.com/MrDave1999/LibraryList/releases/tag/v1.5) está la opción para descargar los archivos. 

### Documentación

- [ArrayList](https://github.com/MrDave1999/LibraryList/wiki/Documentaci%C3%B3n-ArrayList)
- [LinkedList](https://github.com/MrDave1999/LibraryList/wiki/Documentaci%C3%B3n-LinkedList)
- [ManagamentMemory](https://github.com/MrDave1999/LibraryList/wiki/Documentaci%C3%B3n-ManagementMemory)

### Discusión 

La mayoría de docentes enseñan el tema de listas enlazadas de una forma limitante, debido a que, solo servirá para X estructura y te lo comprobaré con el siguiente ejemplo:
```C
typedef struct Paciente
{
	char nombre[24];
	int edad;
	float altura;
	struct Paciente* sig;
}Nodo;

void freeall(Nodo** inicio)
{
	Nodo* aux = *inicio;
	while (*inicio != NULL)
	{
		aux = *inicio;
		*inicio = (*inicio)->sig;
		free(aux);
	}
}

int add(Nodo** inicio, Nodo** fin)
{
	Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
	if (nuevo != NULL)
	{
		(*inicio == NULL) ? (*inicio = nuevo) : ((*fin)->sig = nuevo);
		nuevo->sig = NULL;
		*fin = nuevo;
	}
	else
	{
		printf("Error: No se pudo reservar memoria\n");
		freeall(inicio);
		return 1;
	}
	return 0;
}

int main(void)
{
	Nodo* inicio = NULL, *fin = NULL, *aux;
	add(&inicio, &fin);
	add(&inicio, &fin);
	add(&inicio, &fin);
	aux = inicio;
	while (aux != NULL)
	{
		printf("%d, %f\n", aux->altura, aux->edad);
		aux = aux->sig;
	}
	getchar();
	return 0;
}
```
Básicamente el código funciona bien, sin embargo, ¿que pasaría si quisiera registrar una receta médica por paciente? Necesitaría crear otra estructura llamada `Receta`, el problema radica que se debe crear otra función para crear nodos y otra para liberar memoria, debido a que, cada función solo registra información para X estructura. 

Por esa razón se creó `LibraryList` para evitar este inconveniente, ya que con esta biblioteca si podrás crear muchas listas enlazadas sin importar que estructura sea.

Por ejemplo, el código de arriba sería reemplazado por esto:
```C
#include <LinkedList.h>


void* newPaciente(int edad, float altura)
{
	Paciente* pat;
	if ((pat = newObject(Paciente)) == NULL)
		return NULL;
	pat->altura = altura;
	pat->edad = 12;
}

int main(void)
{
	LinkedList* listaPaciente = newLinkedList();
	addLK(listaPaciente, newPaciente(12, 23.2));
	addLK(listaPaciente, newPaciente(14, 3.4));
	if (addLK(listaPaciente, newPaciente(17, 2.4)))
		return 1;
	forLK(Paciente, pat, listaPaciente)
		printf("Edad: %d, Altura: %f\n", pat->edad, pat->altura);
	freeALL();
	getchar();
	return 0;
}
```
Y de este modo puedes crear múltiples listas enlazadas sin la necesidad de repetir el mismo código por cada nueva estructura que se desee agregar al programa.

### Desventajas

A pesar que la biblioteca facilita mucho el trabajo para el programador, se debe hacer un buen uso de ella, de lo contrario, la aplicación podría tener problemas en tiempo de ejecución.

**1.** Como la biblioteca no detecta si hubo una falla en la asignación de memoria, el programador deberá de detectarlo manualmente.

*Ejemplo del error:*
```C
#include <ArrayList.h>

int main(void)
{
	ArrayList* al = newArrayList();
	printf("Cantidad de elementos %d\n", al->count);
	freeALL();
	return 0;
}
```
Si el puntero `al` llegara a tener guardado un valor `NULL`, ocurriría un fallo de segmenetación en `al->count`, debido a que, se estaría accediendo a una dirección de memoria que al programa no le pertenece. Por esa razón, en este caso es necesario verificar manualmente si hubo una falla de asignación de memoria o no.

**Solución:**
```C
int main(void)
{
	ArrayList* al = newArrayList();
	if (al == NULL)
	{
		printf("Error: No se pudo reservar memoria.");
		return 1;
	}
	printf("Cantidad de elementos%d\n", al->count);
	freeALL();
	return 0;
}
```
**2.** La biblioteca libera los recursos automáticamente, sin embargo, si no se llegara a verificar un error de asignación de memoria, podría dar resultados inesperados.

*Ejemplo del error:*
```C
#include <ArrayList.h>
struct A{ int x; };

int main(void)
{
	ArrayList* al = newArrayList();
	addAL(al, newObject(struct A));
	printf("Capacidad máxima: %d\n", al->capacity);
	freeALL();
	return 0;
}
```
Si la función `addAL` no pudiera reservar memoria dinámica, retornaría `1` y libera todos los recursos que se haya reservado anteriormente. Por esa razón el puntero `al` ya no se puede usar, porqué la dirección base del objeto al que apunta el puntero ya fue liberado de memoria, esto quiere decir que el programa no tiene acceso a ese espacio de memoria, de lo contrario, habrá un fallo de segmentación.

**Solución:**
```C
int main(void)
{
	ArrayList* al = newArrayList();
	if (addAL(al, newObject(A)))
	{
		printf("Error en la asignación de memoria.");
		printf("Todos los recursos reservados anteriormente fueron liberados!");
		return 1;
	}
	printf("Capacidad máxima: %d\n", al->capacity);
	freeALL();
	return 0;
}
```
**Conclusión:** La biblioteca te ahorra trabajo, pero debes estar atento a posibles errores.

### Créditos

- [MrDave](https://github.com/MrDave1999) (por crear LibraryList)

- [Microsoft](https://github.com/microsoft) (por su IDE Visual Studio)

- [Oracle](https://github.com/oracle) (por su clase `ArrayList` hecha en Java)

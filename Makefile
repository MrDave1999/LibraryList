CC = gcc
#Machine type: 32 or 64 bits.
TYPE = 32
#Test number.
TN = 19
#Path include files
INCLUDE = -I..\LibraryList\LibraryList
CFLAGS =  $(INCLUDE) -Wall -c -m$(TYPE)
NAME_FOLDER = C-LIST
OBJECTS = addDTP.o ArrayList.o foreach.o LinkedList.o MemoryManagement.o LinkedQueue.o \
LinkedStack.o ArrayQueue.o ArrayStack.o SortedList.o

#Compile files objects.
comp: $(OBJECTS)

#Compile test file.
test:
	$(CC) $(INCLUDE) -Wall tests\test$(TN).c -L"..\LibraryList\LibraryList\$(TYPE) bits" -llist -m$(TYPE) -o test$(TN)

#Create static library.
lib:
	ar rcs "LibraryList\$(TYPE) bits\liblist.a" $(OBJECTS) 

#New implicit rule.
%.o: $(NAME_FOLDER)\%.c
	$(CC) $(CFLAGS) $< -o $@

addDTP.o: $(NAME_FOLDER)\addDTP.c
ArrayList.o: $(NAME_FOLDER)\ArrayList.c
foreach.o: $(NAME_FOLDER)\foreach.c
LinkedList.o: $(NAME_FOLDER)\LinkedList.c
MemoryManagement.o: $(NAME_FOLDER)\MemoryManagement.c
LinkedQueue.o: $(NAME_FOLDER)\LinkedQueue.c
LinkedStack.o: $(NAME_FOLDER)\LinkedStack.c
ArrayQueue.o: $(NAME_FOLDER)\ArrayQueue.c
ArrayStack.o: $(NAME_FOLDER)\ArrayStack.c
SortedList.o: $(NAME_FOLDER)\SortedList.c

clean:
	del -rf $(OBJECTS)

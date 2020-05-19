CC = gcc
#Machine type: 32 or 64 bits.
TYPE = 32
#Test number.
TN = 12
CFLAGS = -Wall -c -m$(TYPE)
FOLDER_C = C-LIST
FILES_O = addDTP.o ArrayList.o foreach.o LinkedList.o MemoryManagement.o Queue.o Stack.o

#Compile files objects.
comp: $(FILES_O)

#Compile test file.
test:
	gcc -Wall tests\test$(TN).c -L"C:\Users\MrDave\Desktop\LibraryList\LibraryList\$(TYPE) bits" -llist -m32 -o test$(TN)

#Create static library.
lib:
	ar rcs "LibraryList\$(TYPE) bits\liblist.a" $(FILES_O) 

#New implicit rule.
%.o: $(FOLDER_C)\%.c
	$(CC) $(CFLAGS) $< -o $@
 
addDTP.o: $(FOLDER_C)\addDTP.c
ArrayList.o: $(FOLDER_C)\ArrayList.c
foreach.o: $(FOLDER_C)\foreach.c
LinkedList.o: $(FOLDER_C)\LinkedList.c
MemoryManagement.o: $(FOLDER_C)\MemoryManagement.c
Queue.o: $(FOLDER_C)\Queue.c
Stack.o: $(FOLDER_C)\Stack.c

clean:
	del -rf $(FILES_O)

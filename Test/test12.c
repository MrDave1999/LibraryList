#include <stdio.h>
#include <lst/List.h>

void showInfo(ArrayList* listNum, const size_t index, int num)
{
	add_i(listNum, index, num);
	printf("\n");
	foreach(int, num, listNum)
		printf("%d\n", *num);
	printf("\n");
}

int main()
{
	printf("Test ArrayList: method addAL_Index\n");
	ArrayList* listNum = newArrayList();
	add(listNum, 1);
	add(listNum, 2);
	add(listNum, 3);
	add(listNum, 4);
	add(listNum, 5);
	add(listNum, 7);
	
	foreach(int, num, listNum)
		printf("%d\n", *num);
	
	showInfo(listNum, 0, 0);
	showInfo(listNum, 0, -1);
	showInfo(listNum, 5, 6);
	showInfo(listNum, 4, 2000);
	
	add(listNum, 3000);
	
	foreach(int, num, listNum)
		printf("%d\n", *num);
		
	showInfo(listNum, size(listNum)-1, 2999);
	delete(listNum);
	getchar();
    return 0;
}

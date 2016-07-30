#include<stdio.h>
#define COMPARE(x,y) x < y ? -1 : (x==y ? 0 : 1)

int IterativeBinarySearch(int list[], int searchnum, int left, int right);
int RecursionBinarySearch(int list[], int searchnum, int left, int right);

int main()
{
	int list[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	int searchnum = 0, index = 0, selectmode=0;

	for (int i = 0; i < 10; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
	
	printf("select mode(0:Iterative, 1:Resursion) : ");
	scanf("%d", &selectmode);

	printf("insert search num : ");
	scanf("%d", &searchnum);

	if (selectmode == 0)
		index = IterativeBinarySearch(list, searchnum, 0, (sizeof(list) / sizeof(int)) - 1);
	else
		index = RecursionBinarySearch(list, searchnum, 0, (sizeof(list) / sizeof(int)) - 1);

	if (index == -1)
		printf("%d is not located \n", searchnum);
	else
		printf("%d locate %d.\n", searchnum, index + 1);

	return 0;
}

int IterativeBinarySearch(int list[], int searchnum, int left, int right)
{
	int middle = 0;

	while (left <= right) {
		middle = (left + right) / 2;
		if (searchnum < list[middle])
			right = middle - 1;
		else if (searchnum > list[middle])
			left = middle + 1;
		else
			return middle;
	}

	return -1;
}

int RecursionBinarySearch(int list[], int searchnum, int left, int right)
{
	int middle = 0;

	if (left <= right) {
		middle = (left + right) / 2;
		switch (COMPARE(list[middle], searchnum)) {
			case -1:return(RecursionBinarySearch(list, searchnum, middle + 1, right));
			case 0:return middle;
			case 1:return(RecursionBinarySearch(list, searchnum, left, middle - 1));
		}
	}

	return -1;
}
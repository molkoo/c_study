#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define TRUE 1
#define FALSE 0

void MakeRandomNumber(void);
void SelectionSort(void);
void DisplayBuffer(void);
int IsNumberExit(int, int);
int Buf[MAX];

void MakeRandomNumber(void) {
	int i ,Num;
	i = 1;
	Buf[0] = 100;
	while (i < MAX) {
		Num = rand() % MAX;

		if (!IsNumberExit(Num, i)) {
			Buf[i] = Num;
			i++;
		}
	}
}

void SelectionSort(void) {
	int i, j, min, dummy;

	for (i = 0; i < MAX; i++) {
		min = i;

		for (j = i + 1; j < MAX; j++)
			if (Buf[j] < Buf[min])
				min = j;
		
		dummy = Buf[min];
		Buf[min] = Buf[i];
		Buf[i] = dummy;
	}
}

void DisplayBuffer(void) {
	int i;

	for (i = 0; i < MAX; i++) {
		if ((i % 10) == 0)
			printf("\n");

		printf("%4d", Buf[i]);
	}

	printf("\n");
}

int IsNumberExit(int number, int index) {
	int i;

	for (i = 0; i < index; i++) {
		if (Buf[i] == number)
			return TRUE;
	}

	return FALSE;
}

void main()
{
	printf("Initialize Data\n");

	MakeRandomNumber();
	DisplayBuffer();
	printf("Sort end Data\n");
	SelectionSort();
	DisplayBuffer();
	printf("\n");
}
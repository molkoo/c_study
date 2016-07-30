#include<stdio.h>
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

void perm(char *list, int i, int n);

void main()
{
	char list[4] = { 'a','b','c','d' };
	perm(list, 0, 3);
}

void perm(char *list, int i, int n)
{
	int tmp;
	if (i == n) {
		printf("(");
		for (int a = 0; a <= n; a++)
			printf("%c", list[a]);
		printf(")");
	}

	else {
		for (int a = i; a <= n; a++) {
			SWAP(list[i], list[a], tmp);
			perm(list, i + 1, n);
			SWAP(list[i], list[a], tmp);
		}
	}
}
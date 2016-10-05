#include<stdio.h>

int PowerSet(int list[], int set[], int i, int p);

void main()
{
	int i, set[3];
	int list[3] = { 1,2,3 };

	printf("\n S={");
	for (i = 0; i < 3; i++) {
		set[0] = 0;
		printf("%d", list[i]);
	}
	printf("}\n\n");
	printf("{}");

	PoserSet(list, set, 0, 2);
	printf("\n");
}

PowerSet(int list[], int set[], int i, int p)
{
	if (i < p)
	{
		PowerSet(list, set, i + 1, p);
		p = i;
	}

	if (i != p) {
		for (int a = set[i]; a <= i; a++) {
			set[i] = a;
			set[i + 1] = set[i] + 1;
			PowerSet(list, t, i + 1, p);
		}
	}
	else {
		for (int a = set[i]; a <= p; a++)
		{
			printf("\n {");
			for(int a=p; a<)
		}
	}
}
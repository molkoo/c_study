#include<stdio.h>


void main()
{
	int i = 0;
	char buf[11];

	printf("소문자 11개 입력하세요 \n");
	printf("입력 : ");

	while (i < 11) {
		scanf("%c", &buf[i]);
		i++;
	}

	for (i = 0; i < 11; i++)
	{
		printf("%c", buf[i] - ('a' - 'A'));
	}
	printf("%d %d", 'a','A');
	printf("\n");
	return 0;

}
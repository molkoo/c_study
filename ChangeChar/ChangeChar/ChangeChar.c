#include<stdio.h>


void main()
{
	int i = 0;
	char buf[11];

	printf("�ҹ��� 11�� �Է��ϼ��� \n");
	printf("�Է� : ");

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
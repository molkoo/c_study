#include<stdio.h>
#include<stdlib.h>

typedef struct _Node {
	char Data;
	struct _Node *next;
} NODE;


NODE *head, *end, *temp;
NODE *temp1, *temp2, *temp3, *temp4;

void Initialize(void);
void InsertNode(NODE *);
void DeleteNode(NODE *);

void Initialize(void)
{
	NODE *ptr;
	head = (NODE *)malloc(sizeof(NODE));
	end = (NODE *)malloc(sizeof(NODE));

	temp1 = (NODE *)malloc(sizeof(NODE));
	temp1->Data = 'A';
	head->next = temp1;
	temp1->next = end;
	end->next = NULL;
	ptr = temp1;

	temp2 = (NODE *)malloc(sizeof(NODE));
	temp2->Data = 'B';
	ptr->next = temp2;
	temp2->next = end;
	ptr = temp2;

	temp3 = (NODE *)malloc(sizeof(NODE));
	temp3->Data = 'D';
	ptr->next = temp3;
	temp3->next = end;
	ptr = temp3;

	temp4 = (NODE *)malloc(sizeof(NODE));
	temp4->Data = 'E';
	ptr->next = temp4;
	temp4->next = end;
	ptr = temp4;
}

void InsertNode(NODE *ptr)
{
	NODE *indexptr;

	for (indexptr = head; indexptr != end; indexptr = indexptr->next)
		if (indexptr->next->Data > ptr->Data)
			break;

	ptr->next = indexptr->next;
	indexptr->next = ptr;
}

void DeleteNode(NODE *ptr)
{
	NODE *indexptr;
	NODE *deleteptr;

	for (indexptr = head; indexptr != end; indexptr = indexptr->next)
		if (indexptr->next->Data == ptr->Data) {
			deleteptr = indexptr->next;
			break;
		}

	indexptr->next = deleteptr->next;
	free(deleteptr);
}

void main() {
	NODE *ptr;
	int i = 0;
	Initialize();

	ptr = head->next;

	for (i = 0; i < 4; i++) {
		printf("%2c", ptr->Data);
		ptr = ptr->next;
	}

	printf("\n");

	temp = (NODE *)malloc(sizeof(NODE));
	temp->Data = 'C';

	InsertNode(temp);

	ptr = head->next;

	for (i = 0; i < 5; i++) {
		printf("%2c", ptr->Data);
		ptr = ptr->next;
	}

	printf("\n");

	DeleteNode(temp);

	ptr = head->next;

	for (i = 0; i < 4; i++) {
		printf("%2c", ptr->Data);
		ptr = ptr->next;
	}

}
#include<stdio.h>

typedef struct _NODE {
	char Data;
	struct _NODE *Next;
	struct _NODE *Prev;
}NODE;

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
	head->Next = temp1;
	temp1->Next = end;
	temp1->Prev = head;
	end->Next = NULL;
	ptr = temp1;

	temp2 = (NODE *)malloc(sizeof(NODE));
	temp2->Data = 'B';
	ptr->Next = temp2;
	temp2->Next = end;
	temp2->Prev = ptr;
	ptr = temp2;

	temp3 = (NODE *)malloc(sizeof(NODE));
	temp3->Data = 'D';
	ptr->Next = temp3;
	temp3->Next = end;
	temp3->Prev = ptr;
	ptr = temp3;

	temp4 = (NODE *)malloc(sizeof(NODE));
	temp4->Data = 'E';
	ptr->Next = temp4;
	temp4->Next = end;
	temp4->Prev = ptr;
	ptr = temp4;
}

void InsertNode(NODE *ptr)
{
	NODE *indexptr;
	for (indexptr = head; indexptr != end; indexptr = indexptr->Next)
		if (indexptr->Data < ptr->Data && indexptr->Next->Data > ptr->Data)
			break;

	ptr->Prev = indexptr;
	ptr->Next = indexptr->Next;
	indexptr->Next->Prev = ptr;
	indexptr->Next = ptr;
	
}

void DeleteNode(NODE *ptr)
{
	NODE *indexptr;
	NODE *deleteptr;

	for (indexptr = head; indexptr != end; indexptr = indexptr->Next)
		if (indexptr->Next->Data == ptr->Data) {
			deleteptr = indexptr->Next;
			break;
		}

	indexptr->Next = deleteptr->Next;
	indexptr->Next->Prev = indexptr;
	free(deleteptr);
}

void main()
{
	NODE *ptr;
	int i = 0;
	Initialize();

	ptr = head->Next;

	for (i = 0; i < 4; i++) {
		printf("%2c", ptr->Data);
		ptr = ptr->Next;
	}

	printf("\n");

	temp = (NODE *)malloc(sizeof(NODE));
	temp->Data = 'C';

	InsertNode(temp);

	ptr = head->Next;

	for (i = 0; i < 5; i++) {
		printf("%2c", ptr->Data);
		ptr = ptr->Next;
	}

	printf("\n");

	DeleteNode(temp);

	ptr = head->Next;

	for (i = 0; i < 4; i++) {
		printf("%2c", ptr->Data);
		ptr = ptr->Next;
	}

}
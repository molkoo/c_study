#include<stdio.h>
#include<stdlib.h>

typedef struct _NODE {
	int Data;
	struct _NODE *Next;
}NODE;

NODE *head, *end;
NODE *ptrNode;

void InitializeStack(void);
void Push(int);
int Pop(void);
void DisplayStack(void);

void InitializeStack(void) {
	head = (NODE *)malloc(sizeof(NODE));
	end = (NODE *)malloc(sizeof(NODE));

	head->Next = end;
	end->Next = end;
}

void Push(int num) {
	ptrNode = (NODE *)malloc(sizeof(NODE));
	ptrNode->Data = num;
	ptrNode->Next = head->Next;
	head->Next = ptrNode;
}

int Pop(void) {
	int ret;
	ptrNode = head->Next;
	head->Next = head->Next->Next;
	ret = ptrNode->Data;
	free(ptrNode);

	return ret;
}

void DisplayStack(void) {
	NODE *indexnode;
	printf("head -> ");

	for (indexnode = head->Next; indexnode != end; indexnode = indexnode->Next)
		printf("%d -> ", indexnode->Data);

	printf("end\n");
}

void main()
{
	int ret;
	InitializeStack();

	Push(1);
	Push(3);
	Push(10);
	Push(20);
	Push(12);
	
	DisplayStack();

	ret = Pop();
	printf("ret = %d\n", ret);
	ret = Pop();
	printf("ret = %d\n", ret);
	ret = Pop();
	printf("ret = %d\n", ret);
	
	DisplayStack();

}
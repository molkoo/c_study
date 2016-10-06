#include"node.h"

extern void InitializeStack(void);
extern void Push(NODE *);
extern NODE *Pop(void);
extern int IsStackEmpty(void);

void IntializeTree(void);
void MakeTree(void);
void Recursive_Traverse(NODE *);
void Stack_Traverse(NODE *);
void Visit(NODE *);

NODE *Parent, *LeftChild, *RightChild;
NODE *HeadNode, *EndNode;

void InitializeTree(void)
{
	HeadNode = (NODE *)malloc(sizeof(NODE));
	EndNode = (NODE *)malloc(sizeof(NODE));

	HeadNode->Left = EndNode;
	HeadNode->Right = EndNode;

	EndNode->Left = NULL;
	EndNode->Right = NULL;
}

void MakeTree(void) {
	Parent = (NODE *)malloc(sizeof(NODE));
	Parent->Data = 'A';

	LeftChild = (NODE *)malloc(sizeof(NODE));
	LeftChild->Data = 'B';
	
	RightChild = (NODE *)malloc(sizeof(NODE));
	RightChild->Data = 'C';

	Parent->Left = LeftChild;
	Parent->Right = RightChild;

	HeadNode->Left = Parent;
	HeadNode->Right = Parent;

	Parent = Parent->Left;

	LeftChild = (NODE *)malloc(sizeof(NODE));
	LeftChild->Data = 'D';
	LeftChild->Left = EndNode;
	LeftChild->Right = EndNode;

	RightChild = (NODE *)malloc(sizeof(NODE));
	RightChild->Data = 'E';
	RightChild->Left = EndNode;
	RightChild->Right = EndNode;

	Parent->Left = LeftChild;
	Parent->Right = RightChild;
	Parent = HeadNode->Right->Right;

	LeftChild = (NODE *)malloc(sizeof(NODE));
	LeftChild->Data = 'F';
	LeftChild->Left = EndNode;
	LeftChild->Right = EndNode;

	RightChild = (NODE *)malloc(sizeof(NODE));
	RightChild->Data = 'G';
	RightChild->Left = EndNode;
	RightChild->Right = EndNode;

	Parent->Left = LeftChild;
	Parent->Right = RightChild;
}

void Recursive_Traverse(NODE *ptrNode) {
	if (ptrNode != EndNode) {
		Recursive_Traverse(ptrNode->Left);
		Visit(ptrNode);
		Recursive_Traverse(ptrNode->Right);
	}
}

void Stack_Traverse(NODE *ptrNode) {
	int Finish = 0;
	do {
		while (ptrNode != EndNode) {
			Push(ptrNode);
			ptrNode = ptrNode->Left;
		}
		if (!IsStackEmpty()) {
			ptrNode = Pop();
			Visit(ptrNode);
			ptrNode = ptrNode->Right;
		}
		else
			Finish = 1;
	} while (!Finish);
}

void Visit(NODE *ptrNode) {
	printf("%2c -> ", ptrNode->Data);
}

void main() {
	InitializeStack();
	InitializeTree();
	MakeTree();
	printf("Recursive : ");
	Recursive_Traverse(HeadNode->Left);
	printf("\n");
	printf("Stack : ");
	Stack_Traverse(HeadNode->Left);
}
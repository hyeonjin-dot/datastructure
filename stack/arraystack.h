#ifndef _ARRAY_STACK_
#define _ARRAY_STACK_

typedef struct StackNodeType
{
	char data;
} StackNode;

typedef struct ArrayStackType
{
    int maxElementCount;
	int currentElementCount;	// ���� ������ ����
	StackNode *pTopElement;		// Top ����� ������
} ArrayStack;

ArrayStack* createArrayStack(int maxElementCount);
int pushAS(ArrayStack* pStack, StackNode element);
StackNode* popAS(ArrayStack* pStack);
StackNode* peekAS(ArrayStack* pStack);
void deleteArrayStack(ArrayStack* pStack);
int isArrayStackFull(ArrayStack* pStack);
int isArrayStackEmpty(ArrayStack* pStack);

void displayArrayStack(ArrayStack* pList);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif
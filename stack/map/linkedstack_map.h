#ifndef _LINKED_STACK_
#define _LINKED_STACK_
#include "mapdef.h"
typedef struct StackNodeType
{
	MapPosition	data;
	struct StackNodeType* pLink;
} StackNode;

typedef struct LinkedStackType
{
	int currentElementCount;	// ���� ������ ����
	StackNode* pTopElement;		// Top ����� ������
} LinkedStack;

LinkedStack* createLinkedStack();
int pushLS(LinkedStack* pStack, StackNode element);
StackNode* popLS(LinkedStack* pStack);
StackNode* peekLS(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
//int isLinkedStackFull(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);

void displayLinkedStack(LinkedStack* pList);

char    *intopostfix(char *str);
int	bracketcheck(char *str);
int	calculatorpostfix(char *str);

void	printMaze(int (*mazeArray)[WIDTH]);
void	findPath(int (*mazeArray)[WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack);
int	pushLSMapPosition(LinkedStack *pStack, MapPosition data);
void showPath(LinkedStack *pStack, int (*mazeArray)[WIDTH]);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif

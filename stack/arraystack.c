#include "arraystack.h"
#include <stdlib.h>
#include <stdio.h>

ArrayStack* createArrayStack(int maxElementCount)
{
    ArrayStack *tmp;
    
    tmp = (ArrayStack *)malloc(sizeof(ArrayStack));
    if (!tmp)
        return (FALSE);
    tmp->currentElementCount = 0;
    tmp->maxElementCount = maxElementCount;
    tmp->pTopElement = (StackNode *)malloc(sizeof(StackNode) * maxElementCount);
    return (tmp);
}

int pushAS(ArrayStack* pStack, StackNode element)
{
    if (!pStack)
        return (FALSE);
    if (isArrayStackFull(pStack))
        return (FALSE);
    pStack->pTopElement[pStack->currentElementCount++] = element;
    return (TRUE);
}

StackNode* popAS(ArrayStack* pStack)
{
    StackNode *tmp;

    tmp = NULL;
    tmp = peekAS(pStack);
    if (tmp)
        pStack->pTopElement[--pStack->currentElementCount].data = 0;
    return (tmp);
}

StackNode* peekAS(ArrayStack* pStack)
{
    StackNode *tmp;

    if (!pStack)
        return (NULL);
    if (isArrayStackEmpty(pStack))
        return (NULL);
    tmp = (StackNode *)malloc(sizeof(StackNode));
    if (!tmp)
        return (NULL);
    *tmp = pStack->pTopElement[pStack->currentElementCount - 1];
    return (tmp);
}

void deleteArrayStack(ArrayStack* pStack)
{
    if (!pStack)
        return ;
    free(pStack->pTopElement);
    free(pStack);
}

int isArrayStackFull(ArrayStack* pStack)
{
    if (!pStack)
        return (FALSE);
    if (pStack->currentElementCount == pStack->maxElementCount)
        return (TRUE);
    else
        return (FALSE);
}

int isArrayStackEmpty(ArrayStack* pStack)
{
    if (!pStack)
        return (FALSE);
    if (pStack->currentElementCount == 0)
        return (TRUE);
    else
        return (FALSE);
}

void displayArrayStack(ArrayStack* pStack)
{
    int idx;

    if (!pStack)
    {
        printf("No Stack\n");
        return ;
    }
    else if (isArrayStackEmpty(pStack))
    {
        printf("Stack is Empty\n");
        return ;
    }
    else
    {
        idx = pStack->maxElementCount;
        while (--idx > 0)
            printf("%c -> ", pStack->pTopElement[idx].data);
        printf("%c\n", pStack->pTopElement[idx].data);
    }
}

int main()
{
    ArrayStack *stack;
    StackNode *temp;
    StackNode element;

    stack = createArrayStack(10);
    for (int i = 0; i < 10; i++)
    {
        element.data = i + '0';
        pushAS(stack, element);
    }
    displayArrayStack(stack);
    printf("%d\n", isArrayStackFull(stack));
    temp = peekAS(stack);
    printf("peek data : %c\n", temp->data);
    free(temp);
    temp = popAS(stack);
    printf("pop data : %c\n", temp->data);
    free(temp);
    displayArrayStack(stack);
    while (temp = popAS(stack))
        free(temp);
    printf("pop all\n");
    displayArrayStack(stack);   
    printf("%d\n", isArrayStackEmpty(stack));
    deleteArrayStack(stack);
    return (0);
}
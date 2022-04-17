#include "arraylist.h"
#include <stdio.h>
#include <stdlib.h>

ArrayList *createArrayList(int maxElementCount)
{
    ArrayList *pList;

    pList = (ArrayList *)malloc(sizeof(ArrayList));
    if (!pList)
        return (FALSE);
    pList->maxElementCount = maxElementCount;
    pList->currentElementCount = 0;
    pList->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount);
    return (pList);
}

void deleteArrayList(ArrayList *pList)
{
    if (pList->pElement != NULL)
        free(pList->pElement);
    if (pList != NULL)
        free(pList);
}

int isArrayListFull(ArrayList *pList)
{
    if (pList->currentElementCount == pList->maxElementCount)
        return (TRUE);
    else
        return (FALSE);
}

int addALElement(ArrayList *pList, int position, ArrayListNode element)
{
    int idx;

    if (position >= pList->maxElementCount)
        return (FALSE);
    if (position < 0)
        return (FALSE);
    if (isArrayListFull(pList) == TRUE)
        return (FALSE);
    idx = getArrayListLength(pList);
    while (--idx >= position)
        pList->pElement[idx + 1] = pList->pElement[idx];
    pList->pElement[position] = element;
    pList->currentElementCount++;
    return (TRUE);
}

int removeALElement(ArrayList *pList, int position)
{
    int idx;

    if (position >= pList->maxElementCount)
        return (FALSE);
    if (position < 0)
        return (FALSE);
    if (getArrayListLength(pList) == 0)
        return (FALSE);
    idx = position;//
    while (++idx < getArrayListLength(pList))//
        pList->pElement[idx - 1] = pList->pElement[idx];
    pList->currentElementCount--;
    return (TRUE);
}

ArrayListNode *getALElement(ArrayList *pList, int position)
{
    if (position >= pList->maxElementCount)
        return (NULL);
    if (position < 0)
        return (NULL);
    if (getArrayListLength(pList) == 0)
        return (NULL);
    return (&(pList->pElement[position]));
}

void displayArrayList(ArrayList *pList)
{
    int idx;

    if (pList == NULL)
    {
        printf("empty array\n");
        return ;
    }
    idx = -1;
    while (++idx < pList->currentElementCount - 1)
        printf("%d -> ", pList->pElement[idx].data);
    printf("%d\n", pList->pElement[idx].data);
}

void clearArrayList(ArrayList *pList)
{
    int idx;

    idx = -1;
    while (++idx < pList->currentElementCount)
        pList->pElement[idx].data = 0;
}

int getArrayListLength(ArrayList *pList)
{
    return (pList->currentElementCount);
}

int main(void)
{
    ArrayList *top;
    ArrayListNode *temp;
    ArrayListNode element;

    top = createArrayList(5);
    for (int i = 0; i < 5; i++)
    {
        element.data = i;
        addALElement(top, i, element);
    }
    displayArrayList(top);
    if (isArrayListFull(top))
        printf("array is full\n");
    else
        printf("array is not full\n");
    removeALElement(top, 3);
    displayArrayList(top);
    if (isArrayListFull(top))
        printf("array is full\n");
    else
        printf("array is not full\n");
    temp = getALElement(top, 3);
    printf("data : %d\n", temp->data);
    printf("length : %d\n", getArrayListLength(top));
    clearArrayList(top);
    displayArrayList(top);
    deleteArrayList(top);
    top = NULL;
    displayArrayList(top);
    return (0);
}

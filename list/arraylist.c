#include "arraylist.h"
#include <stdio.h>
#include <stdlib.h>

ArrayList* createArrayList(int maxElementCount)
{
    ArrayList   *pList;

    pList = (ArrayList *)malloc(sizeof(ArrayListNode) * maxElementCount);
    if (!pList)
        return (FALSE);
    pList->maxElementCount = maxElementCount;
    pList->currentElementCount = 0;
    return (pList);
}

void deleteArrayList(ArrayList* pList)
{
    int idx;

    idx = pList->currentElementCount - 1;
    pList->pElement[idx].data = 0;
    pList->currentElementCount--;
}

int isArrayListFull(ArrayList* pList)
{
    if (pList->currentElementCount == pList->maxElementCount)
        return (TRUE);
    else
        return (FALSE);
}

int addALElement(ArrayList* pList, int position, ArrayListNode element)
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
    return (TRUE);
}

int removeALElement(ArrayList* pList, int position)
{
    int idx;

    if (position >= pList->maxElementCount)
        return (FALSE);
    if (position < 0)
        return (FALSE);
    if (getArrayListLength(pList) == 0)
        return (FALSE);
    idx = position;
    while (--idx < getArrayListLength(pList))
        pList->pElement[idx - 1] = pList->pElement[idx];
    return (TRUE);
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{
    if (position >= pList->maxElementCount)
        return (NULL);
    if (position < 0)
        return (NULL);
    if (getArrayListLength(pList) == 0)
        return (NULL);
    return (&(pList->pElement[position]));
}

void displayArrayList(ArrayList* pList)
{
    int idx;

    idx = -1;
    while (++idx < pList->currentElementCount - 2)
        printf("%d -> ", pList->pElement[idx].data);
    printf("%d\n", pList->pElement[idx].data);
}

void clearArrayList(ArrayList* pList)
{
    int idx;

    idx = -1;
    while (++idx < pList->currentElementCount - 1)
        pList->pElement[idx].data = 0;
}

int getArrayListLength(ArrayList* pList)
{
    return (pList->currentElementCount);
}
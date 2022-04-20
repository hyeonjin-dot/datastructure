#include "doublylist.h"
#include <stdlib.h>
#include <stdio.h>

DoublyList* createDoublyList()
{
    DoublyList *tmp;

    tmp = (DoublyList *)malloc(sizeof(DoublyList));
    if (!tmp)
        return (FALSE);
    tmp->currentElementCount = 0;
    tmp->headerNode.data = 0;
    tmp->headerNode.pLLink = NULL;
    tmp->headerNode.pRLink = NULL;
    return tmp;
}

void deleteDoublyList(DoublyList* pList)
{
    if (pList != NULL)
        return ;
    if (!pList->headerNode.pLLink && !pList->headerNode.pRLink)
        clearDoublyList(pList);
    free(pList);
}

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
    int idx;
    DoublyListNode  *tmp;
    DoublyListNode  *input;

    if (pList == NULL)
        return (FALSE);
    if (position < 0)
        return (FALSE);
    if (pList->currentElementCount == 0)
    {
        input = (DoublyListNode *)malloc(sizeof(DoublyListNode));
        if (!input)
            return (FALSE);
        *input = element;
        pList->headerNode.pRLink = input;
    }
    else
    {
        idx = -1;
        tmp = pList->headerNode.pRLink;
        while (++idx < position && tmp->pRLink != NULL)
            tmp = tmp->pRLink;
        input = (DoublyListNode *)malloc(sizeof(DoublyListNode));
        if (!input)
            return (FALSE);
        *input = element;
        input->pRLink = tmp->pRLink;
        input->pLLink = tmp;
        if (tmp->pRLink)
            tmp->pRLink->pLLink = input;
        tmp->pRLink = input;
    }
    pList->currentElementCount++;
    return (TRUE);
}

int removeDLElement(DoublyList* pList, int position)
{
    int idx;
    DoublyListNode  *tmp;
    DoublyListNode  *next;

    if (pList == NULL)
        return (FALSE);
    if (position < 0)
        return (FALSE);
    idx = -1;
    tmp = pList->headerNode.pRLink;
    while (++idx < position - 1)//tmp->pRLink = 지울 것;
        tmp = tmp->pRLink;
    next = tmp->pRLink;
    tmp->pRLink = tmp->pRLink->pRLink;
    tmp->pRLink->pLLink = tmp;
    free(next);
    pList->currentElementCount--;
    return (TRUE);
}

void clearDoublyList(DoublyList* pList)
{
    DoublyListNode  *tmp;
    DoublyListNode  *tmp2;

    if (pList == NULL)
        return ;
    pList->currentElementCount = 0;
    tmp = pList->headerNode.pRLink;
    while (tmp->pRLink)
    {
        tmp2 = tmp->pRLink;
        free(tmp);
        tmp = tmp2;
    }
    free(tmp);
    pList->headerNode.pRLink = NULL;
    return ;
}

int getDoublyListLength(DoublyList* pList)
{
    if (pList == NULL)
        return (FALSE);
    return (pList->currentElementCount);
}

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
    int idx;
    DoublyListNode  *tmp;

    if (pList == NULL)
        return (FALSE);
    if (position < 0 || position >= pList->currentElementCount)
        return (FALSE);
    idx = -1;
    tmp = pList->headerNode.pRLink;
    while (++idx < position)
        tmp = tmp->pRLink;
    return (tmp);
}

void displayDoublyList(DoublyList* pList)
{
    DoublyListNode *tmp;

    if (pList == NULL)
        return ;
    if (pList->headerNode.pRLink == NULL)
        return ;
    if (pList->currentElementCount == 0)
    {
        printf("list is empty\n");
        return ;
    }
    tmp = pList->headerNode.pRLink;
    while (tmp->pRLink)
    {
        printf("%d -> ", tmp->data);
        tmp = tmp->pRLink;
    }
    printf("%d\n", tmp->data);
}

void revdisplayDoublyList(DoublyList* pList)
{
    DoublyListNode *tmp;

    if (pList == NULL)
        return ;
    if (pList->headerNode.pRLink == NULL)
        return ;
    if (pList->currentElementCount == 0)
    {
        printf("list is empty\n");
        return ;
    }
    while (tmp->pRLink)
        tmp = tmp->pRLink;
    printf("Reverse : ");
    while (tmp->pLLink)
    {
        printf("%d -> ", tmp->data);
        tmp = tmp->pLLink;
    }
    printf("%d\n", tmp->data);
}

int main(void)
{
    DoublyList *list;
    DoublyListNode *temp;
    DoublyListNode element;

    list = createDoublyList();
    for (int i = 0; i < 10; i++)
    {
        element.data = i;
        element.pLLink = NULL;
        element.pRLink = NULL;
        addDLElement(list, i, element);
    }
    displayDoublyList(list);
    revdisplayDoublyList(list);
    removeDLElement(list, 5);
    displayDoublyList(list);
    temp = getDLElement(list, 5);
    printf("data : %d\n", temp->data);
    printf("length : %d\n", getDoublyListLength(list));
    clearDoublyList(list);
    displayDoublyList(list);
    deleteDoublyList(list);
    return (0);
}
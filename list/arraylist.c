#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList* createLinkedList()
{
    LinkedList  *pList;

    pList = malloc(sizeof(LinkedList));
    if (!pList)
        return (FALSE);
    pList->headerNode.pLink = NULL;
    pList->headerNode.data = 0;
    pList->currentElementCount = 0;
    return (pList);
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
    int         idx;
    ListNode    *tmp;
    ListNode    *tmp2;

    if (position < 0)
        return (FALSE);
    if (position >= pList->currentElementCount)//맨 뒤
    {
        if (pList->headerNode.pLink == NULL)
        {
            tmp = malloc(sizeof(ListNode));
            if (!tmp)
                return (FALSE);
            tmp->data = element.data;
            tmp->pLink = element.pLink;
            pList->headerNode.pLink = tmp;
        }
        else
        {
            tmp = pList->headerNode.pLink;
            while (tmp->pLink != NULL)
                tmp = tmp->pLink;
            tmp2 = malloc(sizeof(ListNode));
            if (!tmp2)
                return (FALSE);
            tmp2->data = element.data;
            tmp2->pLink = element.pLink;
            tmp->pLink = tmp2;
        }
    }
    else
    {
        idx = -1;
        tmp = pList->headerNode.pLink;
        while (++idx < position - 1)
            tmp = tmp->pLink;
        tmp2 = malloc(sizeof(ListNode));
        if (!tmp2)
            return (FALSE);
        tmp2->data = element.data;
        tmp2->pLink = tmp->pLink;
        tmp->pLink = tmp2;
    }
    pList->currentElementCount++;
    return (TRUE);
}

int removeLLElement(LinkedList* pList, int position)
{
    int         idx;
    ListNode    *tmp;
    ListNode    *rm;

    if (position < 0)
        return (FALSE);
    if (position >= pList->currentElementCount)
        return (FALSE);
    idx = -1;
    tmp = pList->headerNode.pLink;
    while (++idx < position - 2)
        tmp = tmp->pLink;
    rm = tmp->pLink;
    tmp->pLink = rm->pLink;
    free(rm);
    pList->currentElementCount--;
    return (TRUE);
}

ListNode* getLLElement(LinkedList* pList, int position)
{
    int         idx;
    ListNode    *tmp;

    if (position < 0)
        return (FALSE);
    if (position >= pList->currentElementCount)
        return (FALSE);
    idx = -1;
    tmp = pList->headerNode.pLink;
    while (++idx < position - 1)
        tmp = tmp->pLink;
    return (tmp);
}

void clearLinkedList(LinkedList* pList)
{
    ListNode    *tmp;
    ListNode    *tmp2;

    pList->currentElementCount = 0;
    tmp = pList->headerNode.pLink;
    while (tmp->pLink)
    {
        tmp2 = tmp->pLink;
        free(tmp);
        tmp = tmp2;
    }
}

int getLinkedListLength(LinkedList* pList)
{
    return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList* pList)
{
    if (pList->currentElementCount != 0)
        clearLinkedList(pList);
    free(pList);
}

void displayLinkedList(LinkedList* pList)
{
    ListNode *temp;

    if (pList->currentElementCount == 0)
    {
        printf("empty list!!\n");
        return ;
    }
    temp = pList->headerNode.pLink;
    while (temp->pLink != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->pLink;
    }
    printf("%d\n", temp->data);
}

int main(void)
{
    LinkedList *list;
    ListNode *temp;
    ListNode element;

    list = createLinkedList();
    for (int i = 0; i < 10; i++)
    {
        element.data = i;
        addLLElement(list, i, element);
    }
    displayLinkedList(list);
    removeLLElement(list, 5);
    displayLinkedList(list);
    temp = getLLElement(list, 5);
    printf("%d\n", temp->data);
    printf("%d\n", getLinkedListLength(list));
    clearLinkedList(list);
    displayLinkedList(list);
    deleteLinkedList(list);
    return (0);
}
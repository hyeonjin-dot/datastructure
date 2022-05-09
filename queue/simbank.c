#include "simdef.h"
#include <stdio.h>
#include <stdlib.h>

SimCustomer* checkcustomer(int arrivalTime)
{
    SimCustomer *a;
    SimCustomer *b;
    SimCustomer *c;
    SimCustomer *d;
    SimCustomer *e;

    a = (SimCustomer *)malloc(sizeof(SimCustomer));
    b = (SimCustomer *)malloc(sizeof(SimCustomer));
    c = (SimCustomer *)malloc(sizeof(SimCustomer));
    d = (SimCustomer *)malloc(sizeof(SimCustomer));
    e = (SimCustomer *)malloc(sizeof(SimCustomer));

    a->status = 0;
    a->arrivalTime = 0;
    a->serviceTime = 3;
    a->startTime = 0;//
    a->endTime = 0;//

    b->status = 0;
    b->arrivalTime = 2;
    b->serviceTime = 2;
    b->startTime = 0;
    b->endTime = 0;

    c->status = 0;
    c->arrivalTime = 4;
    c->serviceTime = 1;
    c->startTime = 0;
    c->endTime = 0;

    d->status = 0;
    d->arrivalTime = 6;
    d->serviceTime = 1;
    d->startTime = 0;
    d->endTime = 0;

    e->status = 0;
    e->arrivalTime = 8;
    e->serviceTime = 3;
    e->startTime = 0;
    e->endTime = 0;
    
    if (arrivalTime == 0)
        return (a);
    else if (arrivalTime == 2)
        return (b);
    else if (arrivalTime == 4)
        return (c);
    else if (arrivalTime == 6)
        return (d);
    else
        return (e);
}

void insertCutomer(int arrivalTime, LinkedDeque *pQueue)//arrival
{
    DequeNode element;

    if (arrivalTime % 2 == 1)
        return ;
    printf("arrivaltime %d\n", arrivalTime);
    element.data = checkcustomer(arrivalTime);
    insertRearLD(pQueue, element);
}

int samestruct(SimCustomer *a, SimCustomer *b)//
{
    if (a->arrivalTime == b->arrivalTime && a->serviceTime == b->serviceTime)
    {
        if (a->endTime == b->endTime && a->startTime == b->startTime)
        {
            if (a->status == b->status)
                return (TRUE);
        }
    }
    return (FALSE);
}

void processArrival(int currentTime, LinkedDeque *pArrivalQueue, LinkedDeque *pWaitQueue)
{
    DequeNode *tmp;

    if (pArrivalQueue->pFrontNode->pRLink->data->arrivalTime == currentTime)
    {
        tmp = deleteFrontLD(pArrivalQueue);
        if (pWaitQueue->currentElementCount == 0)
            insertRearLD(pWaitQueue, *tmp);
        else if (!samestruct(tmp->data, pWaitQueue->pFrontNode->pRLink->data))
            insertRearLD(pWaitQueue, *tmp);
    }
}

DequeNode* processServiceNodeStart(int currentTime, LinkedDeque *pWaitQueue)
{
    pWaitQueue->pFrontNode->pRLink->data->status = 1;
    pWaitQueue->pFrontNode->pRLink->data->startTime = currentTime;
    return (pWaitQueue->pFrontNode);
}

DequeNode* processServiceNodeEnd(int currentTime, DequeNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime)
{
    int tmp;

    pServiceNode->data->status = 2;
    pServiceNode->data->endTime = currentTime;
    tmp = *pServiceUserCount;
    tmp++;
    *pServiceUserCount = tmp;
    tmp = *pTotalWaitTime;
    *pTotalWaitTime = tmp + (pServiceNode->data->startTime - pServiceNode->data->arrivalTime);
    return (pServiceNode);
}

void printSimCustomer(int currentTime, SimCustomer customer)
{
    printf("지금 시각은 %d 입니다.\n", currentTime);
    printf("도착 시간 : %d\n", customer.arrivalTime);
    printf("서비스 시간 : %d\n", customer.serviceTime);
    printf("시작 시간 : %d 종료 시간 %d\n",customer.startTime, customer.endTime);
    printf("-------------------\n");
}

void printWaitQueueStatus(int currentTime, LinkedDeque *pWaitQueue)
{
    DequeNode *tmp;

    printf("지금 시각은 %d 입니다.\n", currentTime);
    tmp = pWaitQueue->pFrontNode->pRLink;
    while (tmp->pRLink != NULL)
    {
        printSimCustomer(currentTime, *(tmp->data));
        tmp = tmp->pRLink;
    }
}

void printReport(LinkedDeque *pWaitQueue, int serviceUserCount, int totalWaitTime, int currentTime)
{
    printf("사용자 수 : %d\n", serviceUserCount);
    printf("총 대기 시간 : %d\n", totalWaitTime);
    printWaitQueueStatus(currentTime, pWaitQueue);
}


int main()
{
    LinkedDeque *pWaitQueue;
    LinkedDeque *pArrivalQueue;

    int serviceUserCount = 0;
    int totalWaitTime = 0;

    pWaitQueue = createLinkedDeque();
    pArrivalQueue = createLinkedDeque();

    int i = 0;
    while (i < 100)
    {
        if (serviceUserCount == 5)
            break ;
        insertCutomer(i, pArrivalQueue);
        if (pArrivalQueue->currentElementCount != 0)
            processArrival(i, pArrivalQueue, pWaitQueue);
        if (!isLinkedDequeEmpty(pWaitQueue))
        {
            if (pWaitQueue->pFrontNode->pRLink->data->status == 0)
                processServiceNodeStart(i, pWaitQueue);
            if (i == pWaitQueue->pFrontNode->pRLink->data->serviceTime + pWaitQueue->pFrontNode->pRLink->data->startTime)
            {
                processServiceNodeEnd(i, pWaitQueue->pFrontNode->pRLink, &serviceUserCount, &totalWaitTime);
                printSimCustomer(i, *(pWaitQueue->pFrontNode->pRLink->data));
                deleteFrontLD(pWaitQueue);
                continue;
            }
        }
        i++;
    }
}
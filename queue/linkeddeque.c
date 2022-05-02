#include <stdlib.h>
#include <stdio.h>
#include "linkeddeque.h"

LinkedDeque* createLinkedDeque()
{
	LinkedDeque *pDeque;

	pDeque = (LinkedDeque *)malloc(sizeof(LinkedDeque));
	pDeque->pFrontNode = (DequeNode *)malloc(sizeof(DequeNode));
	pDeque->pRearNode = (DequeNode *)malloc(sizeof(DequeNode));
	pDeque->currentElementCount = 0;
	pDeque->pFrontNode->pLLink = NULL;
	pDeque->pFrontNode->pRLink = pDeque->pRearNode;//
	pDeque->pRearNode->pLLink = pDeque->pFrontNode;//
	pDeque->pRearNode->pRLink = NULL;
	return (pDeque);
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *insert;

	if (pDeque == NULL)
		return (FALSE);
	insert = (DequeNode *)malloc(sizeof(DequeNode));
	*insert = element;
	insert->pLLink = pDeque->pFrontNode;
	insert->pRLink = pDeque->pFrontNode->pRLink;
	pDeque->pFrontNode->pRLink->pLLink = insert;
	pDeque->pFrontNode->pRLink = insert;
	pDeque->currentElementCount++;
	return (TRUE);
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *insert;

	if (pDeque == NULL)
		return (FALSE);
	insert = (DequeNode *)malloc(sizeof(DequeNode));
	*insert = element;
	insert->pRLink = pDeque->pRearNode;
	insert->pLLink = pDeque->pRearNode->pLLink;
	pDeque->pRearNode->pLLink->pRLink = insert;
	pDeque->pRearNode->pLLink = insert;
	pDeque->currentElementCount++;
	return (TRUE);
}

DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
	DequeNode *del;
	
	if (pDeque->currentElementCount == 0)
		return (NULL);
	del = pDeque->pFrontNode->pRLink;
	del->pRLink->pLLink = pDeque->pFrontNode;
	pDeque->pFrontNode->pRLink = del->pRLink;
	pDeque->currentElementCount--;
	return (del);
}

DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
	DequeNode *del;
	
	if (pDeque->currentElementCount == 0)
		return (NULL);
	del = pDeque->pRearNode->pLLink;
	del->pLLink->pRLink= pDeque->pRearNode;
	pDeque->pRearNode->pLLink = del->pLLink;
	pDeque->currentElementCount--;
	return (del);
}	

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
	DequeNode *del;
	
	if (pDeque->currentElementCount == 0)
		return (NULL);
	del = pDeque->pFrontNode->pRLink;
	return (del);
}	

DequeNode* peekRearLD(LinkedDeque* pDeque)
{
	DequeNode *del;
	
	if (pDeque->currentElementCount == 0)
		return (NULL);
	del = pDeque->pRearNode->pLLink;
	return (del);
}	

void deleteLinkedDeque(LinkedDeque* pDeque)
{
	DequeNode *tmp;
	DequeNode *del;

	if (pDeque == NULL)
		return ;
	tmp = pDeque->pFrontNode->pRLink;
	while (tmp->pRLink == pDeque->pRearNode)
	{
		del = tmp;
		tmp = tmp->pRLink;
		free(del);
	}
	free(pDeque);
}
		
int isLinkedDequeFull(LinkedDeque* pDeque)
{
	return (FALSE);
}

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
	if (pDeque == NULL)
		return (FALSE);
	if (pDeque->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}

void displayDeque(LinkedDeque* pDeque)
{
	DequeNode *tmp;

	if (pDeque == NULL)
		printf("deque is null\n");
	if (pDeque->currentElementCount == 0)
		printf("deque is empty\n");
	tmp = pDeque->pFrontNode->pRLink;
	while (tmp->pRLink != pDeque->pRearNode)
	{
		printf("%c |", tmp->data);
		tmp = tmp->pRLink;
	}
	printf("%c\n", tmp->data);
}

void reversedisplayDeque(LinkedDeque* pDeque)
{
	DequeNode *tmp;

	if (pDeque == NULL)
		printf("deque is null\n");
	if (pDeque->currentElementCount == 0)
		printf("deque is empty\n");
	tmp = pDeque->pRearNode->pLLink;
	while (tmp->pLLink != pDeque->pFrontNode)
	{
		printf("%c |", tmp->data);
		tmp = tmp->pLLink;
	}
	printf("%c\n", tmp->data);
}
	

int main()
{
	LinkedDeque *pDeque;
	DequeNode tmp;
	DequeNode *peek;

	pDeque = createLinkedDeque();
	for (int i = 0; i < 10; i++)
	{
		tmp.data = i + 65;
		tmp.pRLink = NULL;
		tmp.pLLink = NULL;
		insertFrontLD(pDeque, tmp);
	}
	displayDeque(pDeque);
	peek = peekFrontLD(pDeque);
	printf("front peek : %c\n", peek->data);
	peek = NULL;
	deleteFrontLD(pDeque);
	peek = peekRearLD(pDeque);
	printf("rear peek : %c\n", peek->data);
	peek = NULL;
	deleteRearLD(pDeque);
	displayDeque(pDeque);
	reversedisplayDeque(pDeque);
}

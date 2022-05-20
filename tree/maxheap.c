#include "heap.h"

/*maxheap*/

ArrayMaxHeap	*createMaxHeap(int maxCount)
{
	ArrayMaxHeap *heap = NULL;

	if (maxCount <= 0)
		return (NULL);
	heap = (ArrayMaxHeap *)malloc(sizeof(ArrayMaxHeap));
	if (heap)
	{
		heap->pData = (HeapNode *)malloc(sizeof(HeapNode) * (maxCount + 1));
		if (heap->pData)
		{
			heap->currentCount = 0;
			heap->maxCount = maxCount;
		}
		else
			free (heap);
	}
	return (heap);
}

void	deleteMaxHeap(ArrayMaxHeap *heap)
{
	if (heap)
	{
		free (heap->pData);
		free (heap);
	}
}

int	insertMaxHeap(ArrayMaxHeap *heap, int data)
{
	int			curr;
	int			temp;
	HeapNode	*cpy_pData;

	if (heap && heap->currentCount < heap->maxCount)
	{
		curr = ++heap->currentCount;
		cpy_pData = heap->pData;
		cpy_pData[curr].data = data;
		while (curr > 1 && (cpy_pData[curr].data > cpy_pData[curr / 2].data))
		{
			temp = cpy_pData[curr].data;
			cpy_pData[curr].data = cpy_pData[curr / 2].data;
			cpy_pData[curr / 2].data = temp;
			curr /= 2;
		}
		return (TRUE);
	}
	return (FALSE);
}

HeapNode *removeMaxHeap(ArrayMaxHeap *heap)
{
	HeapNode	*rtNode = NULL;
	int			idx;
	int			t_idx;
	int			tmp;

	if (heap)
	{
		rtNode = (HeapNode *)malloc(sizeof(HeapNode));
		if (rtNode)
		{
			heap->pData[1].data = heap->pData[heap->currentCount].data;
			heap->currentCount--;
			idx = 1;
			while (idx <= heap->currentCount
			&& (heap->pData[idx].data < heap->pData[idx * 2].data
			|| heap->pData[idx].data < heap->pData[(idx * 2) + 1].data))
			{
				if (heap->pData[idx * 2 + 1].data < heap->pData[idx * 2].data)//
					t_idx = idx * 2;
				else
					t_idx = (idx * 2) + 1;
				tmp = heap->pData[t_idx].data;
				heap->pData[t_idx].data = heap->pData[idx].data;
				heap->pData[idx].data = tmp;
				idx = t_idx;
			}
			rtNode->data = heap->pData[1].data;
		}
	}
	return (rtNode);
}

void	displayMaxHeap(ArrayMaxHeap *heap)
{
	if (heap)
	{
		int	curr = heap->currentCount, idx = 1, level = 1, heapLevel = 0, maxCnt = heap->maxCount/*, j = 0, k = 1*/;
		while (maxCnt > 0)
		{
			maxCnt = maxCnt / 2 - 1;
			heapLevel++;
		}
		while (curr--)
		{
			printf("%d ", heap->pData[idx].data);
			if (idx == 1 || idx == level)
			{
				level = (level * 2) + 1;
				printf("\n");
			}
			idx++;
		}
		printf("\b\n");
	}
	else
		printf("GG");
}

int	main(void)//maxheap
{
	int				arr[31];
	int				data;
	ArrayMaxHeap	*maxHeap = createMaxHeap(31);

	for (int i = 0; i < 31; i++)
	{
		data = rand()%(0-200+1)+200;
		arr[i] = data;
		insertMaxHeap(maxHeap , data);
	}
	printf("\n==============data array==============\n\n");
	for (int i = 0; i < 31; i++)
	{
		printf("%d ", arr[i]);
		if (i == 30)
			printf("\n\n");
	}
	displayMaxHeap(maxHeap);
	HeapNode	*node = removeMaxHeap(maxHeap);
	printf("max : %d\n\n", node->data);
	free (node);
	displayMaxHeap(maxHeap);
	deleteMaxHeap(maxHeap);
	// system("leaks a.out | grep leaked");
}
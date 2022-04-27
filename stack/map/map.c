#include "linkedstack_map.h"
#include <stdio.h>
#include <stdlib.h>

void	printMaze(int (*mazeArray)[WIDTH])
{
	char	*images[8] = {"\u2B1C", "\u2B1B", "\u2714 ", "\u2B06 ", "\u2B95 ", "\u2B07 ", "\u2B05 ", "\u2B55"};
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
			printf("%3s", images[mazeArray[i][j]]);
		printf("\n");
	}
}

void	findPath(int (*mazeArray)[WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack)
{
	int	movable, xPos, yPos;
	StackNode	*pPos;
	MapPosition	curPos = startPos;

	while (curPos.x != endPos.x || curPos.y != endPos.y)
	{
		mazeArray[curPos.y][curPos.x] = VISIT;
		movable = 0; 
		for (int i = 0; i < NUM_DIRECTIONS; i++)
		{
			xPos = curPos.x + DIRECTION_OFFSETS[i][0];
			yPos = curPos.y + DIRECTION_OFFSETS[i][1];
			if (0 <= xPos && xPos < WIDTH && 0 <= yPos && yPos < HEIGHT && mazeArray[yPos][xPos] == NOT_VISIT)
			{
				curPos.direction = i;
				movable = pushLSMapPosition(pStack, curPos);
				curPos.x = xPos;
				curPos.y = yPos;
				break;
			}
		}
		if (!movable)
		{
			pPos = popLS(pStack);
			if (pPos)
			{
				curPos = pPos->data;
				free(pPos);
				continue;
			}
			else
			{
				printf("[No Path]\n");
				return ;
			}
		}
	}
	mazeArray[endPos.y][endPos.x] = ARRIVE;
}

int	pushLSMapPosition(LinkedStack *pStack, MapPosition data)
{
	StackNode	element;

	element.data = data;
	element.pLink = NULL;
	return (pushLS(pStack, element));
}

void showPath(LinkedStack *pStack, int (*mazeArray)[WIDTH])
{
	StackNode	*step;
	int	maze[HEIGHT][WIDTH];
	
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
			maze[i][j] = mazeArray[i][j];
	}
	step = popLS(pStack);
	if (step)
	{
		while (step)
		{
			maze[(step -> data).y][(step -> data).x] = (step -> data).direction + 3;
			free(step);
			step = popLS(pStack);
		}
		printMaze(maze);
	}
}

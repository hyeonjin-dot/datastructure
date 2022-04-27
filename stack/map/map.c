#include "linkedstack_map.h"
#include <stdio.h>
#include <stdlib.h>

void	printMaze(int (*mazeArray)[WIDTH])
{
	char	*images[6] = {"\u2B1C", "\u2B1B", "\u2B60 ", "\u2B63 ", "\u2B62 ", "\u2B61 "};
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
		mazeArray[curPos.x][curPos.y] = VISIT;
		movable = 0; 
		for (int i = 0; i < NUM_DIRECTIONS; i++)
		{
			xPos = curPos.x + DIRECTION_OFFSETS[i][0];
			yPos = curPos.y + DIRECTION_OFFSETS[i][1];
			if (0 <= xPos && xPos < WIDTH && 0 <= yPos && yPos < HEIGHT && mazeArray[xPos][yPos] == NOT_VISIT)
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
				printf("No Path");
				return ;
			}
		}
	}
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
	while (step)
	{
		maze[(step -> data).x][(step -> data).y] = (step -> data).direction + 2;
		free(step);
		step = popLS(pStack);
	}
	printMaze(maze);
}

int main(void)
{
	MapPosition	start, end;
	LinkedStack	*stack = createLinkedStack();
	int	mazeArray[HEIGHT][WIDTH] = {
		{0,0,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,1},
		{1,1,1,0,1,1,1,1},
		{1,1,1,0,1,1,1,1},
		{1,0,0,0,0,0,0,1},
		{1,0,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,0}
	};
	
	printf("\n");
	printf("<before pathfinding>\n");
	printMaze(mazeArray);
	printf("\n");
	start.x = 0; start.y = 0;
	end.x = WIDTH - 1; end.y = HEIGHT - 1;
	findPath(mazeArray, start, end, stack);
	printf("<after pathfinding>\n");
	showPath(stack, mazeArray);
	deleteLinkedStack(stack);
	return (0);
}

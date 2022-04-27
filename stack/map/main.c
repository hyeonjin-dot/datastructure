#include "linkedstack_map.h"
#include <stdio.h>
#include <stdlib.h>
void pathFinding(int (*mazeArray)[WIDTH], int start_x, int start_y, int end_x, int end_y)
{
	int maze[HEIGHT][WIDTH];
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
			maze[i][j] = mazeArray[i][j];
	}
	LinkedStack	*stack = createLinkedStack();
	MapPosition	start, end;
	
	start.x = start_x; start.y = start_y;
	end.x = end_x; end.y = end_y;
	printf("\n<before pathfinding>\n");
	printMaze(maze);
	printf("\n[LEGEND] | NOT_VISIT : \u2B1C, WALL : \u2B1B, VISIT : \u2714, DESTINATION : \u2B55\n");
	findPath(maze, start, end, stack);
	if (!isLinkedStackEmpty(stack))
		printf("\n<after pathfinding>\n");
	showPath(stack, maze);
	deleteLinkedStack(stack);
}

int main(void)
{
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
	pathFinding(mazeArray, 0, 0, WIDTH - 1, HEIGHT - 1);
	return (0);
}

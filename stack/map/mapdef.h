#ifndef _MAP_DEF_
#define _MAP_DEF_

#define WIDTH 8
#define HEIGHT 8
#define ARRIVE 7
#define NUM_DIRECTIONS 4

// offset: x, y
static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
	{0, -1},		// �������� �̵�.n
	{1, 0},			// ���������� �̵�.e
	{0, 1},			// �Ʒ������� �̵�.s
	{-1, 0}			// �������� �̵�.w
};

enum PosStatus { NOT_VISIT = 0, WALL = 1 , VISIT = 2};
typedef struct MapPositionType
{
	int x;				// ���� ��ġ x��ǥ.
	int y;				// ���� ��ġ y��ǥ.
	int direction;		// 간 곳의 번호
} MapPosition;

#endif

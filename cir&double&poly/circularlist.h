#ifndef _CIRCULARLIST_
#define _CIRCULARLIST_

typedef struct CircularListNodeType
{
	int data;
	struct CircularListNodeType* pLink;
} CircularNode;

typedef struct CircularListType
{
	int currentElementCount;	// 현재 저장된 원소의 개수
	CircularNode headerNode;		// 헤더 노드(Header Node)
} CircularList;

CircularList* createCircularList();
int addCLElement(CircularList* pList, int position, CircularNode element);
int removeCLElement(CircularList* pList, int position);
CircularNode* getCLElement(CircularList* pList, int position);

void clearCircularList(CircularList* pList);
int getCircularListLength(CircularList* pList);
void deleteCircularList(CircularList* pList); 
void displayCircularList(CircularList* pList);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif
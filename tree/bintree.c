#include "bintree.h"
#include <stdlib.h>
#include <stdio.h>

BinTree* makeBinTree(BinTreeNode rootNode)
{
	BinTree *rtn;

	rtn = (BinTree *)malloc(sizeof(BinTree));
	rtn->pRootNode = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	rtn->pRootNode->data = rootNode.data;
	rtn->pRootNode->visited = 0;
	rtn->pRootNode->pLeftChild = NULL;
	rtn->pRootNode->pRightChild = NULL;
	return (rtn);
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
	if (!pBinTree || !(pBinTree->pRootNode))
		return (FALSE);
	return (pBinTree->pRootNode);
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *tmp;

	if (!pParentNode)
		return (FALSE);
	tmp = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (!tmp)
        return (FALSE);
    tmp->data = element.data;
	tmp->visited = element.visited;
	tmp->pLeftChild = NULL;
	tmp->pRightChild = NULL;
	pParentNode->pLeftChild = tmp;
	return (pParentNode);
}
BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *tmp;

	if (!pParentNode)
		return (FALSE);
	tmp = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	tmp->data = element.data;
	tmp->visited = element.visited;
	tmp->pLeftChild = NULL;
	tmp->pRightChild = NULL;
	pParentNode->pRightChild = tmp;
	return (pParentNode);    
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
	BinTreeNode *tmp;

	if (!pNode)
		return (FALSE);
	if (!(pNode->pLeftChild))
		return (FALSE);
	tmp = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	tmp->data = pNode->pLeftChild->data;
	tmp->visited = pNode->pLeftChild->visited;
	tmp->pLeftChild = pNode->pLeftChild->pLeftChild;
	tmp->pRightChild = pNode->pLeftChild->pRightChild;
	return (tmp);
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
	BinTreeNode *tmp;

	if (!pNode)
		return (FALSE);
	if (!(pNode->pRightChild))
		return (FALSE);
	tmp = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	tmp->data = pNode->pRightChild->data;
	tmp->visited = pNode->pRightChild->visited;
	tmp->pLeftChild = pNode->pRightChild->pLeftChild;
	tmp->pRightChild = pNode->pRightChild->pRightChild;
	return (tmp);
}

void deleteBinTree(BinTree* pBinTree)
{
	if (pBinTree)
	{
		deleteBinTreeNode(pBinTree->pRootNode);
		free (pBinTree);
	}
}

void deleteBinTreeNode(BinTreeNode* pNode)
{
	if (pNode)
	{
		deleteBinTreeNode(pNode->pLeftChild);
		deleteBinTreeNode(pNode->pRightChild);
        pNode->data = '\0';
        pNode->pLeftChild = NULL;
        pNode->pRightChild = NULL;
        pNode = NULL;
	}
}

void preorderBinTree(BinTreeNode *root)
{
    if (!root || root->data == '\0')
        return ;
    printf("%c ", root->data);
	preorderBinTree(root->pLeftChild);
	preorderBinTree(root->pRightChild);
}

void inorderBinTree(BinTreeNode *root)
{
	if (!root || root->data == '\0')
		return ;
	inorderBinTree(root->pLeftChild);
	printf("%c ", root->data);
	inorderBinTree(root->pRightChild);
}

void postorderBinTree(BinTreeNode *root)
{
	if (!root || root->data == '\0')
		return ;
	postorderBinTree(root->pLeftChild);
	postorderBinTree(root->pRightChild);
	printf("%c ", root->data);
}

int main()
{
	BinTreeNode	node;
	node.data = 'A';
	BinTree	*tree = makeBinTree(node);
	printf("data : %c\n", tree->pRootNode->data);
	node.data = 'B';
	insertLeftChildNodeBT(tree->pRootNode, node);
	printf("data : %c\n", tree->pRootNode->pLeftChild->data);
	node.data = 'C';
	insertRightChildNodeBT(tree->pRootNode, node);
	printf("data : %c\n", tree->pRootNode->pRightChild->data);
	node.data = 'D';
	insertLeftChildNodeBT(tree->pRootNode->pLeftChild, node);
	printf("data : %c\n", tree->pRootNode->pLeftChild->pLeftChild->data);
	node.data = 'E';
	insertRightChildNodeBT(tree->pRootNode->pLeftChild, node);
	printf("data : %c\n", tree->pRootNode->pLeftChild->pRightChild->data);
	node.data = 'F';
	insertLeftChildNodeBT(tree->pRootNode->pRightChild, node);
	printf("data : %c\n", tree->pRootNode->pRightChild->pLeftChild->data);
	node.data = 'G';
	insertRightChildNodeBT(tree->pRootNode->pRightChild, node);
	printf("data : %c\n", tree->pRootNode->pRightChild->pRightChild->data);
	node.data = 'H';
	insertLeftChildNodeBT(tree->pRootNode->pLeftChild->pLeftChild, node);
	printf("data : %c\n", tree->pRootNode->pLeftChild->pLeftChild->pLeftChild->data);
	node.data = 'I';
	insertRightChildNodeBT(tree->pRootNode->pLeftChild->pLeftChild, node);
	printf("data : %c\n", tree->pRootNode->pLeftChild->pLeftChild->pRightChild->data);
	node.data = 'J';
	insertLeftChildNodeBT(tree->pRootNode->pLeftChild->pRightChild, node);
	printf("data : %c\n", tree->pRootNode->pLeftChild->pRightChild->pLeftChild->data);
	node.data = 'K';
	insertRightChildNodeBT(tree->pRootNode->pRightChild->pLeftChild, node);
	printf("data : %c\n", tree->pRootNode->pRightChild->pLeftChild->pRightChild->data);
	node.data = 'L';
	insertLeftChildNodeBT(tree->pRootNode->pRightChild->pRightChild, node);
	printf("data : %c\n", tree->pRootNode->pRightChild->pRightChild->pLeftChild->data);
	node.data = 'M';
	insertRightChildNodeBT(tree->pRootNode->pRightChild->pRightChild, node);
	printf("data : %c\n", tree->pRootNode->pRightChild->pRightChild->pRightChild->data);

    printf("===================\n");
    printf("preorder 전위\n");
	printf("A B D H I E J C F K G L M\n");
    preorderBinTree(tree->pRootNode);
    printf("\n");
    printf("inorder 중위\n");
	printf("H D I B J E A F K C L G M\n");
    inorderBinTree(tree->pRootNode);
    printf("\n");
    printf("postorder 후위\n");
	printf("H I D J E B K F L M G C A\n");
    postorderBinTree(tree->pRootNode);
    printf("\n");

    printf("===================\n");
    deleteBinTreeNode(tree->pRootNode->pLeftChild);
    printf("BDEHIJ removed\n");
    printf("A C F K G L M\n");
    preorderBinTree(tree->pRootNode);
    deleteBinTree(tree);
}
// gcc bintree.c -g
// lldb a.out
// r
// b 
#ifndef _BST_H_
#define _BST_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef	struct BinSearchTreeNodeType
{
	int								key;
	struct BinSearchTreeNodeType	*pLeftChild;
	struct BinSearchTreeNodeType	*pRightChild;
}									BSTNode;

typedef	struct BinSearchTreeType
{
	BSTNode	*pRootNode;
}	BinSearchTree;

BinSearchTree	*createBinSearchTree();
BSTNode			*insertData(BSTNode *bst, int key);
BSTNode			*new_Node(int key);
BSTNode			*deleteData(BSTNode *bst, int key);
BSTNode			*minData(BSTNode *node);
BSTNode			*search(BSTNode *bst, int key);
int				deleteBinSearchTree(BinSearchTree *bst);
int				deleteBSTTreeNode(BSTNode *pNode);

#define	TRUE		1
#define	FALSE		0

#endif
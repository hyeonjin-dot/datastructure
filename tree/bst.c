#include "bst.h"

BinSearchTree	*createBinSearchTree()
{
	BinSearchTree	*bst = NULL;

	bst = (BinSearchTree *)malloc(sizeof(BinSearchTree));
	if (bst)
		bst->pRootNode = NULL;
	return (bst);
}

BSTNode	*new_Node(int key)
{   
	BSTNode *bst = NULL;

	bst = (BSTNode *)malloc(sizeof(BSTNode));
	if (bst)
	{
		bst->key = key;
		bst->pLeftChild = NULL;
		bst->pRightChild = NULL;
	}
	return (bst);
}

BSTNode	*insertData(BSTNode *node, int key)
{
	if (!node)
		return (new_Node(key));
	if (key < node->key)
		node->pLeftChild = insertData(node->pLeftChild, key);
	else if (key > node->key)
		node->pRightChild = insertData(node->pRightChild, key);
	return (node);
}

BSTNode *minData(BSTNode *node)
{
	BSTNode *rt = node;

	while (rt->pLeftChild != NULL)
		rt = rt->pLeftChild;
	return (rt);
}

BSTNode *deleteData(BSTNode *root, int key)//변경된 루트 노드 리턴
{
	BSTNode *tmp;

	if (root == NULL)
		return (root);
	if (key < root->key)
		root->pLeftChild = deleteData(root->pLeftChild, key);
	else if (key > root->key)
		root->pRightChild = deleteData(root->pRightChild, key);
	else
	{
		// 자식 노드가 없을 때 혹은 하나 있을 때
		if (root->pLeftChild == NULL)
		{
			tmp = root->pRightChild;
			free(root);
			return (tmp);
		}
		else if (root->pRightChild == NULL)
		{
			tmp = root->pLeftChild;
			free(root);
			return (tmp);
		}
		// 자식 노드가 둘 다 있을 때
		tmp = minData(root->pRightChild);//오른쪽 서브트리에서 제일 작은 값
		root->key = tmp->key;
		root->pRightChild = deleteData(root->pRightChild, tmp->key);
	}
	return (root);
}

BSTNode	*search(BSTNode *bst, int key)
{
	if (!bst)
		return (NULL);
	if (key == bst->key)
		return (bst);
	else if (key < bst->key)
		return (search(bst->pLeftChild, key));
	else
		return (search(bst->pRightChild, key));
}

int	deleteBinSearchTree(BinSearchTree *bst)
{
	if (!bst)
	{
		if (bst->pRootNode)
			deleteBSTTreeNode(bst->pRootNode);
		return (TRUE);
	}
	return (FALSE);
}

int	deleteBSTTreeNode(BSTNode *pNode)
{
	BSTNode *t_left;
	BSTNode *t_right;

	if (pNode)
	{
		t_left = pNode->pLeftChild;
		t_right = pNode->pRightChild;
		pNode->pLeftChild = NULL;
		pNode->pRightChild = NULL;
		deleteBSTTreeNode(t_left);
		deleteBSTTreeNode(t_right);
		free (pNode);
		return (TRUE);
	}
	return (FALSE);
}

void	inorder(BSTNode *root)
{
	if (root)
	{
		inorder(root->pLeftChild);
		printf("%d ", root->key);
		inorder(root->pRightChild);
	}
}

int main()
{
	BinSearchTree *bst;

	bst = createBinSearchTree();
	bst->pRootNode = insertData(bst->pRootNode, 3);
	bst->pRootNode = insertData(bst->pRootNode, 2);
	bst->pRootNode = insertData(bst->pRootNode, 1);
	bst->pRootNode = insertData(bst->pRootNode, 4);
	bst->pRootNode = insertData(bst->pRootNode, 5);
	bst->pRootNode = insertData(bst->pRootNode, 6);
	inorder(bst->pRootNode);
	printf("\n");
	if (search(bst->pRootNode, 3))
		printf("3 발견\n");
	else
		printf("3 발견 못함\n");
	if (search(bst->pRootNode, 10))
		printf("10 발견\n");
	else
		printf("10 발견 못함\n");
	deleteData(bst->pRootNode, 3);
	inorder(bst->pRootNode);
	printf("\n");
	if (search(bst->pRootNode, 3))
		printf("3 발견\n");
	else
		printf("3 발견 못함\n");
	deleteBinSearchTree(bst);
}
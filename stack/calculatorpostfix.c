#include "linkedstack.h"
#include <stdlib.h>
#include <stdio.h>
int	ft_isoperator(char c)
{
	return ((c == '+') + (c == '-') + (c == '*') + (c == '/'));
}

int	calculatorpostfix(char *str)
{
	int pre, suf;
	int	ret = 0;
	LinkedStack	*stack;
	StackNode	node;
	StackNode	*tmp;
	
	node.pLink = NULL;
	stack = createLinkedStack();
	while (*str)
	{		
		if (ft_isoperator(*str))
		{
			tmp = popLS(stack);
			suf = tmp -> data;
			free(tmp);
			tmp = popLS(stack);
			pre = tmp -> data;
			free(tmp);
			if (*str == '+')
				ret = pre + suf;
			else if (*str == '-')
				ret = pre - suf;
			else if (*str == '*')
				ret = pre * suf;
			else if (*str == '/')
				ret = pre / suf;
			node.data = ret;
			pushLS(stack, node);
		}
		else
		{
			node.data = *str - '0';
			pushLS(stack, node);
		}
		str++;
	}
	ret = peekLS(stack) -> data;
	deleteLinkedStack(stack);
	return (ret);
}

/*int	main(void)
{
	//abc*de/++
	char *str = "132*84/++";
	printf("The result of %s : [%d]\n",str,calculator(str));
	return (0);
}*/
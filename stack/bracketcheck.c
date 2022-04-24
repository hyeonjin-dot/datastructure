#include "linkedstack.h"
#include <stdlib.h>
#include <stdio.h>

int isbracket(char c)
{
    char    bck[6] = {'(','{', '[', ')', '}', ']'};
    int     idx;

    idx = -1;
    while (++idx < 6)
    {
        if (c == bck[idx])
            return (idx + 1);
    }
    return (0);
}

int bracketcheck(char *str)
{
    LinkedStack *stack;
    StackNode   element;
    StackNode   *tmp;
    int         idx;


    stack = createLinkedStack();
    idx = -1;
    while (str[++idx])
    {
        if (isbracket(str[idx]))
        {
            if (isbracket(str[idx]) < 4)
            {
                element.data = str[idx];
                element.pLink = NULL;
                pushLS(stack, element);
            }
            else
            {
                tmp = popLS(stack);
                if (!tmp)
                {
                    printf("FALSE\n");
                    deleteLinkedStack(stack);
                    return (FALSE);
                }
                if (isbracket(str[idx]) != isbracket(tmp->data) + 3)
                {
                    printf("FALSE\n");
                    free(tmp);
                    deleteLinkedStack(stack);
                    return (FALSE);
                }
                free(tmp);
            }
        }
    }
    if (!isLinkedStackEmpty(stack))
    {
        printf("FALSE\n");
        deleteLinkedStack(stack);
        return (FALSE);
    }
    printf("TRUE\n");
    deleteLinkedStack(stack);
    return (TRUE);
}

/*int main()
{
    bracketcheck("(a+[b)-s]-w");
}*/
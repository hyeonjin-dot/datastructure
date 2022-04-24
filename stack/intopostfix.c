#include "linkedstack.h"
#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int idx;

    idx = 0;
    while (str[idx])
        idx++;
    return (idx);
}

int is_bracket(char *str)
{
    int idx;

    idx = -1;
    while (str[++idx])
    {
        if (str[idx] == '(')
            return (1);
    }
    return (0);
}

int isoperator(char c)
{
    char op[4] = {'+', '*', '-', '/'};
    int idx;

    idx = -1;
    while (++idx < 4)
    {
        if (c == op[idx])
            return (idx + 1);
    }
    return (0);
}

char    *intopostfix(char *str)
{
    LinkedStack *stack;
    StackNode   element;
    StackNode   *tmp;
    char        *ret;
    int         brk;
    int         idx;
    int         r_idx;

    stack = createLinkedStack();
    brk = is_bracket(str);
    ret = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
    if (!ret)
        return (0);
    idx = -1;
    r_idx = -1;
    if (brk == 0)//괄호가 없는 경우
    {
        while (str[++idx])
        {
            if (isoperator(str[idx]))//연산자
            {
                if (!isLinkedStackEmpty(stack))
                {
                    if (isoperator(str[idx]) % 2 == 1 && isoperator(peekLS(stack)->data) % 2 == 0)
                    {
                        tmp = popLS(stack);
                        ret[++r_idx] = tmp->data;
                        free(tmp);
                    }
                }
                element.data = str[idx];
                element.pLink = NULL;
                pushLS(stack, element);
            }
            else
                ret[++r_idx] = str[idx];
        }
        while (!isLinkedStackEmpty(stack))
        {
            tmp = popLS(stack);
            ret[++r_idx] = tmp->data;
            free(tmp);
        }
        ret[++r_idx] = '\0';
    }
    else
    {
        while (str[++idx])
        {
            if (isoperator(str[idx]) || str[idx] == '(' || str[idx] == ')')//연산자
            {
                if (!isLinkedStackEmpty(stack) && str[idx] != '(' && str[idx] != ')')
                {
                    if (isoperator(str[idx]) % 2 == 1 && isoperator(peekLS(stack)->data) % 2 == 0 && peekLS(stack)->data != '(')
                    {
                        tmp = popLS(stack);
                        ret[++r_idx] = tmp->data;
                        free(tmp);
                    }
                    element.data = str[idx];
                    element.pLink = NULL;
                    pushLS(stack, element);
                }
                else if (str[idx] == ')')
                {
                    tmp = popLS(stack);
                    while (tmp->data != '(' && !isLinkedStackEmpty(stack))
                    {
                        ret[++r_idx] = tmp->data;
                        free(tmp);
                        tmp = popLS(stack);
                    }
                }
                else
                {
                    element.data = str[idx];
                    element.pLink = NULL;
                    pushLS(stack, element);
                }
            }
            else
                ret[++r_idx] = str[idx];
        }
        while (!isLinkedStackEmpty(stack))
        {
            tmp = popLS(stack);
            ret[++r_idx] = tmp->data;
            free(tmp);
        }
        ret[++r_idx] = '\0';
    }
    deleteLinkedStack(stack);
    return (ret);
}

/*int main()
{
    char *str = "(a+b)*c";
    printf("%s\n", str);
    printf("%s\n", intopostfix(str));
    printf("--------\n");
    str = "a+b-c";
    printf("%s\n", str);
    printf("%s\n", intopostfix(str));
    printf("--------\n");
    str = "a+b*c+(d/e)";//1+3*2+(8/4)>>132*84/++>>9
    printf("%s\n", str);
    printf("%s\n", intopostfix(str));
}*/
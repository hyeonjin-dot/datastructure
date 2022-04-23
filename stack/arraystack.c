#include "arraystack.h"
#include <stdlib.h>
#include <stdio.h>

ArrayStack* createArrayStack()
{
    ArrayStack *tmp;
    
    tmp = malloc(sizeof(ArrayStack));
    if (!tmp)
        return (FALSE);
    tmp->currentElementCount = 0;
    tmp->maxElementCount = 0;
    tmp->pTopElement = NULL;
    return (tmp);
}
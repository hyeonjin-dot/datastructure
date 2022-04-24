#include "linkedstack.h"
#include <stdio.h>
void cal(char *str)
{
    char *convert;
    
    printf("%s\n", str);
    if (bracketcheck(str))
    {   
        convert = intopostfix(str);
        printf("into : %s\n", convert);
        printf("result : %d\n", calculatorpostfix(convert));
    }
}


int main()
{

    char *wrg = "a+(b*c";
    char *str = "1+3*2+(8/4)";//"a+b*c+(d/e)";//1+3*2+(8/4)>>132*84/++>>9

    cal(wrg);
    cal(str);
}
#include <stdio.h>
#include "base64.h"

int
main(void)
{
    char s[100];
    char t[100];
    char s_after[100];
    
    scanf("%s", s);
    base64_encode(t, s, 100);
    base64_decode(s_after, t, 100);
    printf("the raw:%s\n", s);
    printf("the base64:%s\n", t);
    printf("the reback:%s\n", s_after);
    
    return 0;
}

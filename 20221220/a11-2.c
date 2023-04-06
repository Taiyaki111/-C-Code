#include <stdio.h>
int main()
{
#ifdef COUNT
    int i;
    for (i = 0; i < COUNT; i++) {
#ifdef MESSAGE
        printf("MESSAGE: Hello %s!\n", MESSAGE);
#else
        printf("MESSAGE: Hello World!\n");
#endif
    }
#else
#ifdef MESSAGE
    printf("MESSAGE: Hello %s!\n", MESSAGE);
#else
    printf("MESSAGE: Hello World!\n");
#endif
#endif

    return 0;
}
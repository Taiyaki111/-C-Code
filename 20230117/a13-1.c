#include <stdio.h>

int main()
{
    int line = 0, word = 0;
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    int i = 0;
    int input;

    input = getchar();
    while(1) {
        if (input == EOF){
            line++;
            break;
        }
        if (input == 'a' || input == 'A') {
            a++;
        } else if (input == 'b' || input == 'B') {
            b++;
        } else if (input == 'c' || input == 'C') {
            c++;
        } else if (input == 'd' || input == 'D') {
            d++;
        } else if (input == 'e' || input == 'E') {
            e++;
        } else if (input == '\n') {
            line++;
        } else if (input == ' ' ||input == '\t' || input == '-'
            || input == '/' || input == ',' || input == '.') {
            word++;
        }
        input = getchar();
    }

    printf("Line Counts = %d\n", line);
    printf("Word counts = %d\n", word);
    printf("'a' = %d\n", a);
    printf("'b' = %d\n", b);
    printf("'c' = %d\n", c);
    printf("'d' = %d\n", d);
    printf("'e' = %d\n", e);

    return 0;    
}
#include <stdio.h>

int main(int argc, char *argv[])
{
    int line = 0, word = 0;
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    int i = 0;

    for (i = 1; i < 50; i++) {
        if (argv[i] == EOF) {
            break;
        } else if (argv[i] == "a" || argv[i] == "A") {
            a++;
        } else if (argv[i] == "b" || argv[i] == "B") {
            b++;
        } else if (argv[i] == "c" || argv[i] == "C") {
            c++;
        } else if (argv[i] == "d" || argv[i] == "D") {
            d++;
        } else if (argv[i] == "e" || argv[i] == "E") {
            e++;
        } else if (argv[i] == "\n") {
            line++;
        } else if (argv[i] == "\t" || argv[i] == "-" ||
             argv[i] == "/" || argv[i] == "," || argv[i] == ".") {
            word++;
        }
        word++;
    }

    printf("Line Counts = %d\n", line);
    printf("Word counts = %d\n", word);
    printf("'a' = \n", a);
    printf("'b' = \n", b);
    printf("'c' = \n", c);
    printf("'d' = \n", d);
    printf("'e' = \n", e);

    return 0;    
}
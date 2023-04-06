#include <stdio.h>
#include <stdlib.h>

char *mystrntok(int n, const char *str);

int main(int argc, char *argv[])
{
    int word = 0, i = 0, input, num;
    char *str, *result;
    FILE *fp;
    
    if (argc != 3) {
        fprintf(stderr, "Usage: a.out inputFile n\n");
        exit(1);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
        exit(1);
    }
    
    // 要求: txtファイルを文字配列strに入れる。

    fclose(fp);

    num = atoi(argv[2]);
    result = mystrntok(num, str);

    fprintf(stdout, "Result->%s\n", str);
    return 0;    
}

char *mystrntok(int n, const char *str)
{   
    int words = sizeof(str) / sizeof(char);
    if(n > words || n < 0) {
        return NULL;
    }
    // 要求: strのn番目の単語スタートの配列を返す
}
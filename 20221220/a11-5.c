#include <stdio.h>
#include <stdlib.h>

#define open_files(fp, fname, mode, errno) \
do { \
	if ((fp = fopen(fname, mode)) == NULL) { \
		fprintf(stderr, "%sがオープンできません。\n", fname); \
		exit(errno); \
	} \
} while (0)

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Invalid arguments\n");
        exit(1);
    }

    FILE *fp;
    open_files(fp, argv[1], "r", argc);


#if STREAM == stderr // 標準エラー出力

#if MODE == 1 // 改行の数
    int count = 0;
    int c;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') count++;
    }
    fprintf(stderr, "The number of line breaks in %s is %d\n", argv[1],count);
#else // ファイルの中身
    int c;
    while((c = fgetc(fp)) != EOF) {
		fputc(c, stderr);
	}
#endif

#else // 標準出力

#if MODE == 1 // 改行の数
    int count = 0;
    int c;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') count++;
    }
    fprintf(stdout, "The number of line breaks in %s is %d\n", argv[1],count);
#else // ファイルの中身
    int c;
    while((c = fgetc(fp)) != EOF) {
		fputc(c, stdout);
	}
#endif

#endif

    fclose(fp);
	return 0;
}

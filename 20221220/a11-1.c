#include <stdio.h>
int main()
{
    int data[] = {10, 20, 30, 40};
    size_t size = sizeof(data) / sizeof(data[0]);
    int sum = 0;
    size_t i;

    for (i = size; i > 0; i--) {
#ifdef DEBUG
        fprintf(stderr, "data[%d] = %d sum = %d\n", (int) i, data[i], sum);
#endif
        sum += data[i-1];
    }
    printf("sum = %d\n", sum);
    return 0;
}
/*実行結果
sum = 100
*/

/*コマンド
./a.out |& head
*/
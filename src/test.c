#include <stdio.h>

#define N 59
#define M 203

int main() {
    char a[N][M];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
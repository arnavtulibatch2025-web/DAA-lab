#include <stdio.h>
int main() {
    int m, n, n2, p;
    scanf("%d %d", &m, &n);
    int A[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    scanf("%d %d", &n2, &p);
    if (n != n2) {
        printf("Invalid input\n");
        return 0;
	}
    int B[n2][p];
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < p; j++) {
            scanf("%d", &B[i][j]);
        }
	}
    int result[m][p];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
        }
	}
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
	}
for (int i = 0; i < m; i++) {
    for (int j = 0; j < p; j++) {
        printf("%d ", result[i][j]); // Notice the space inside "%d "
    }
    printf("\n");
}
    return 0;
}

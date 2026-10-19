#include <stdio.h>
#include <stdlib.h>

#define INF 1e9

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int matrix[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    if (n == 1) {
        printf("0\n");
        return 0;
    }

    int num_states = 1 << n;

    int **dp = (int **)malloc(num_states * sizeof(int *));
    for (int i = 0; i < num_states; i++) {
        dp[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            dp[i][j] = INF;
        }
    }

    dp[1][0] = 0;

    for (int mask = 1; mask < num_states; mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u)) || dp[mask][u] == INF) {
                continue;
            }

            for (int v = 0; v < n; v++) {
                if ((mask & (1 << v)) || matrix[u][v] == -1) {
                    continue;
                }

                int next_mask = mask | (1 << v);
                int new_cost = dp[mask][u] + matrix[u][v];
                if (new_cost < dp[next_mask][v]) {
                    dp[next_mask][v] = new_cost;
                }
            }
        }
    }

    int min_total_cost = INF;
    int all_visited_mask = num_states - 1;

    for (int u = 1; u < n; u++) {
        if (dp[all_visited_mask][u] != INF && matrix[u][0] != -1) {
            int total_cost = dp[all_visited_mask][u] + matrix[u][0];
            if (total_cost < min_total_cost) {
                min_total_cost = total_cost;
            }
        }
    }

    if (min_total_cost == INF) {
        printf("-1\n");
    } else {
        printf("%d\n", min_total_cost);
    }

    for (int i = 0; i < num_states; i++) {
        free(dp[i]);
    }
    free(dp);

    return 0;
}


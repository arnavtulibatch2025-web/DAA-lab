//ArnavTuli
//25070521070
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 20
#define MAX_SUBSETS 1048576 // 2^20 max possible subsets

int discovered_subsets[MAX_SUBSETS][MAX_N];
int subset_sizes[MAX_SUBSETS];
int subset_count = 0;

int elements[MAX_N];
int n, target_sum;

void backtrack(int index, int current_sum, int* current_subset, int current_size) {
    if (current_sum == target_sum) {
        for (int i = 0; i < current_size; i++) {
            discovered_subsets[subset_count][i] = current_subset[i];
        }
        subset_sizes[subset_count] = current_size;
        subset_count++;
        return;
    }

    if (current_sum > target_sum || index == n) {
        return;
    }

    current_subset[current_size] = elements[index];
    backtrack(index + 1, current_sum + elements[index], current_subset, current_size + 1);

    backtrack(index + 1, current_sum, current_subset, current_size);
}

int main() {
    if (scanf("%d", &n) != 1) return 0;
    
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &elements[i]) != 1) return 0;
    }
    
    if (scanf("%d", &target_sum) != 1) return 0;

    int temp_subset[MAX_N];
    backtrack(0, 0, temp_subset, 0);

    if (subset_count == 0) {
        printf("-1\n");
    } else {
        for (int i = subset_count - 1; i >= 0; i--) {
            for (int j = 0; j < subset_sizes[i]; j++) {
                printf("%d ", discovered_subsets[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}


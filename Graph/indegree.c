#include <stdio.h>

void count(int a[][10], int in[], int out[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (a[i][j] == 1) {
                out[i]++;
                in[j]++;
            }
        }
    }
}

int main() {
    int n, i, j, a[10][10], indeg[10] = {0}, outdeg[10] = {0};

    printf("Enter no. of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix: ");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    count(a, indeg, outdeg, n);

    printf("Indegree:\n");
    for (i = 0; i < n; i++) {
        printf("v%d ------> %d\n", i + 1, indeg[i]);
    }

    printf("Outdegree:\n");
    for (i = 0; i < n; i++) {
        printf("v%d ------> %d\n", i + 1, outdeg[i]);
    }

    return 0;
}



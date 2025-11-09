#include <stdio.h>
#define MAX 30

int parent[MAX];

// Function to find parent (Disjoint Set)
int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

// Function to perform union operation
int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int cost[MAX][MAX];
    int n, i, j, mincost = 0, edges = 1;
    int a, b, u, v, min;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (use 0 if no edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999; // No edge
        }
    }

    printf("\nThe edges of Minimum Cost Spanning Tree are:\n");

    while (edges < n) {
        min = 999;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (uni(u, v)) {
            printf("Edge %d: (%d --> %d) cost = %d\n", edges++, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = 999; // Remove edge
    }

    printf("\nMinimum cost of spanning tree = %d\n", mincost);
    return 0;
}

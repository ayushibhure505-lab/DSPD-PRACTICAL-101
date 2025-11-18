#include <stdio.h>

int graph[9][9] = {
    {0,1,0,1,0,0,0,0,0},
    {1,0,1,0,1,0,0,0,0},
    {0,1,0,0,0,1,0,0,0},
    {1,0,0,0,1,0,1,0,0},
    {0,1,0,1,0,1,0,1,0},
    {0,0,1,0,1,0,0,0,1},
    {0,0,0,1,0,0,0,1,0},
    {0,0,0,0,1,0,1,0,1},
    {0,0,0,0,0,1,0,1,0}
};
int visited[9] = {0};

void bfs(int start) {
    int queue[9], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;
    printf("BFS Order: ");
    while(front < rear) {
        int node = queue[front++];
        printf("%d ", node + 1);
        for(int i = 0; i < 9; i++) {
            if(graph[node][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

void dfs(int node) {
    printf("%d ", node + 1);
    visited[node] = 1;
    for(int i = 0; i < 9; i++)
        if(graph[node][i] && !visited[i])
            dfs(i);
}

int main() {
    for(int i=0;i<9;i++) visited[i]=0;
    bfs(0);
    for(int i=0;i<9;i++) visited[i]=0;
    printf("DFS Order: ");
    dfs(0);
    printf("\n");
    return 0;
}

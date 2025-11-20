// BFS and DFS for Graph (Adjacency Matrix)
#include <stdio.h>
#define MAX 100
int graph[MAX][MAX], visited[MAX], n;

void bfs(int start) {
    int queue[MAX], front = 0, rear = 0;
    for (int i = 0; i < n; i++) visited[i] = 0;
    queue[rear++] = start; visited[start] = 1;
    printf("BFS: ");
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (graph[v][i] && !visited[i]) {
                queue[rear++] = i; visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void dfsUtil(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) dfsUtil(i);
    }
}

void dfs(int start) {
    for (int i = 0; i < n; i++) visited[i] = 0;
    printf("DFS: ");
    dfsUtil(start);
    printf("\n");
}

int main() {
    int e, u, v, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    for (int i = 0; i < e; i++) {
        printf("Enter edge (u v): ");
        scanf("%d%d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }
    printf("Enter start vertex: ");
    scanf("%d", &start);
    bfs(start);
    dfs(start);
    return 0;
}

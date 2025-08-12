// Prim's and Kruskal's Algorithm (Simple)
#include <stdio.h>
#define MAX 100
#define INF 99999
int graph[MAX][MAX], n;
void prim() {
    int selected[MAX] = {0}, no_edge = 0, min, x, y;
    selected[0] = 1;
    printf("Prim's MST:\n");
    while (no_edge < n - 1) {
        min = INF;
        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j] && graph[i][j] < min) {
                        min = graph[i][j]; x = i; y = j;
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x, y, graph[x][y]);
        selected[y] = 1;
        no_edge++;
    }
}
int parent[MAX];
int find(int i) { while (parent[i] != i) i = parent[i]; return i; }
void uni(int i, int j) { parent[i] = j; }
void kruskal() {
    int edge = 0, min, a, b, u, v;
    for (int i = 0; i < n; i++) parent[i] = i;
    printf("Kruskal's MST:\n");
    while (edge < n - 1) {
        min = INF;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] && graph[i][j] < min) {
                    min = graph[i][j]; a = u = i; b = v = j;
                }
            }
        }
        u = find(u); v = find(v);
        if (u != v) {
            printf("%d - %d : %d\n", a, b, min);
            uni(u, v); edge++;
        }
        graph[a][b] = graph[b][a] = INF;
    }
}
int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    prim();
    kruskal();
    return 0;
}

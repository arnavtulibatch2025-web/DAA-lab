//Arnav Tuli
#include <stdio.h>
#include <stdlib.h>
struct Edge {
int u, v, w;
};
#define INF 1000000000000LL
void print_path(int v, int src, int* parent) {
    int path[1005];
    int count = 0;
    int curr = v;
    while (curr != 0 && curr != -1) {
        path[count++] = curr;
        curr = parent[curr];
    }
    for (int i = count - 1; i >= 0; i--) {
        printf("%d", path[i]);
        if (i > 0) printf("->");
    }
}
int main() {
    int V, E;
    if (scanf("%d", &V) != 1) return 0;
    if (scanf("%d", &E) != 1) return 0;
    struct Edge* edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
	}
    int src;
    scanf("%d", &src);
//mithi
	long long* dist = (long long*)malloc((V + 1) * sizeof(long long));
    int* parent = (int*)malloc((V + 1) * sizeof(int));
    for (int i = 1; i <= V; i++) {
        dist[i] = INF;
        parent[i] = 0;
    }
    dist[src] = 0;
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
	}
    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("Negative cycle detected\n");
            free(edges);
            free(dist);
            free(parent);
            return 0;
        }
	}
    for (int v = 1; v <= V; v++) {
        if (v == src) continue;
        if (dist[v] >= INF / 2) {
            printf("%d INF None\n", v);
        } else {
            printf("%d %lld ", v, dist[v]);
            print_path(v, src, parent);
            printf("\n");
        }
	}
    free(edges);
    free(dist);
    free(parent);
    return 0;
}

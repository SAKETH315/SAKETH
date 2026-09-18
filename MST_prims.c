#include <stdio.h>

#define INF 9999

struct Edge {
    int u, v, w;
};

int main() {
    int V, E;
    struct Edge edge[100];

    int selected[100] = {0};
    int total = 0;
    int count = 0;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    printf("Enter edges (u v weight):\n");

    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
    }

    selected[0] = 1;

    printf("\nEdges in MST:\n");

    while (count < V - 1) {
        int min = INF;
        int index = -1;

        for (int i = 0; i < E; i++) {
            int u = edge[i].u;
            int v = edge[i].v;

            if ((selected[u] && !selected[v]) ||
                (selected[v] && !selected[u])) {

                if (edge[i].w < min) {
                    min = edge[i].w;
                    index = i;
                }
            }
        }

        if (index == -1) {
            printf("MST does not exist.\n");
            return 0;
        }

        int u = edge[index].u;
        int v = edge[index].v;

        printf("%d -- %d = %d\n", u, v, edge[index].w);

        total += edge[index].w;

        selected[u] = 1;
        selected[v] = 1;

        count++;
    }

    printf("Minimum cost = %d\n", total);

    return 0;
}
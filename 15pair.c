#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

void initializeMatrices(int graph[][MAX_VERTICES], int numVertices, int distance[][MAX_VERTICES], int predecessor[][MAX_VERTICES]) {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            distance[i][j] = graph[i][j];
            if (i != j && graph[i][j] != INT_MAX) {
                predecessor[i][j] = i;
            } else {
                predecessor[i][j] = -1;
            }
        }
    }
}

void floydWarshall(int graph[][MAX_VERTICES], int numVertices, int distance[][MAX_VERTICES], int predecessor[][MAX_VERTICES]) {
    for (int k = 0; k < numVertices; k++) {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                    predecessor[i][j] = k;
                }
            }
        }
    }
}

void printGraph(int graph[][MAX_VERTICES], int numVertices, char* title) {
    printf("%s:\n", title);
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (graph[i][j] == INT_MAX) {
                printf("INF ");
            } else {
                printf("%d ", graph[i][j]);
            }
        }
        printf("\n");
    }
}

void printShortestPaths(int predecessor[][MAX_VERTICES], int numVertices, int distance[][MAX_VERTICES]) {
    printf("Shortest paths:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (i == j) {
                printf("0 ");
            } else if (predecessor[i][j] == -1) {
                printf("No path ");
            } else {
                printf("%d -> ", i);
                int current = j;
                int path[MAX_VERTICES];
                int pathIndex = 0;
                while (current != i) {
                    path[pathIndex++] = current;
                    current = predecessor[i][current];
                }
                path[pathIndex++] = i;
                for (int k = pathIndex - 1; k >= 0; k--) {
                    printf("%d -> ", path[k]);
                }
                printf("\b\b  (distance: %d) \n", distance[i][j]);
            }
        }
        printf("\n");
    }
}

void readGraph(int graph[][MAX_VERTICES], int numVertices) {
    printf("Enter the adjacency matrix (%d x %d):\n", numVertices, numVertices);
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("Enter weight of edge from %d to %d: ", i, j);
            scanf("%d", &graph[i][j]);
            if (i != j && graph[i][j] == 0) {
                graph[i][j] = INT_MAX;
            }
        }
    }
}

int main() {
    int numVertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    int graph[MAX_VERTICES][MAX_VERTICES];
    readGraph(graph, numVertices);

    printGraph(graph, numVertices, "Initial graph");

    int distance[MAX_VERTICES][MAX_VERTICES];
    int predecessor[MAX_VERTICES][MAX_VERTICES];
    initializeMatrices(graph, numVertices, distance, predecessor);

    floydWarshall(graph, numVertices, distance, predecessor);

    printGraph(distance, numVertices, "Shortest distance graph");
    printShortestPaths(predecessor, numVertices, distance);

    return 0;
}
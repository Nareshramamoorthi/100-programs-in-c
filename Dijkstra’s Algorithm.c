#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define MAX_NODES 100

// Function to find the vertex with the minimum distance value
int findMinDistance(int distance[], int visited[], int n) {
    int min = INF, minIndex = -1;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && distance[v] <= min) {
            min = distance[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to print the distances
void printSolution(int distance[], int n) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t %d\n", i, distance[i]);
    }
}

// Dijkstra's algorithm implementation
void dijkstra(int graph[MAX_NODES][MAX_NODES], int src, int n) {
    int distance[MAX_NODES];
    int visited[MAX_NODES];

    // Initialize all distances as INF and visited[] as false
    for (int i = 0; i < n; i++) {
        distance[i] = INF;
        visited[i] = 0;
    }

    // Distance from source to itself is always 0
    distance[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        // Pick the minimum distance vertex from the set of unvisited vertices
        int u = findMinDistance(distance, visited, n);
        visited[u] = 1;

        // Update distance value of the adjacent vertices
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && distance[u] != INF && distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    // Print the distance array
    printSolution(distance, n);
}

int main() {
    int n, src;
    int graph[MAX_NODES][MAX_NODES];

    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter the adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Input source vertex
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    // Run Dijkstra's algorithm
    dijkstra(graph, src, n);

    return 0;
}

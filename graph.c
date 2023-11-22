#include <stdio.h>
#include <stdlib.h>

// Maximum number of cities
#define MAX_CITIES 100

// Structure to represent a graph
struct Graph {
    int vertices;
    int adjacencyMatrix[MAX_CITIES][MAX_CITIES];
};

// Function to initialize the graph
void initializeGraph(struct Graph* g, int vertices) {
    g->vertices = vertices;

    // Initializing the adjacency matrix with zeros
    for (int i = 0; i < MAX_CITIES; i++) {
        for (int j = 0; j < MAX_CITIES; j++) {
            g->adjacencyMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph
void addEdge(struct Graph* g, int source, int destination) {
    // Since it is an undirected graph, edges are added in both directions
    g->adjacencyMatrix[source][destination] = 1;
    g->adjacencyMatrix[destination][source] = 1;
}

// Function to print all nodes reachable from a given starting node using BFS
void BFS(struct Graph* g, int startNode) {
    int visited[MAX_CITIES] = {0};
    int queue[MAX_CITIES];
    int front = -1, rear = -1;

    // Enqueue the starting node
    queue[++rear] = startNode;
    visited[startNode] = 1;

    while (front != rear) {
        // Dequeue a vertex from the queue
        int current = queue[++front];
        printf("%d ", current);

        // Enqueue adjacent vertices
        for (int i = 0; i < g->vertices; i++) {
            if (g->adjacencyMatrix[current][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

// Function to perform DFS traversal
void DFSUtil(struct Graph* g, int vertex, int visited[MAX_CITIES]) {
    visited[vertex] = 1;

    for (int i = 0; i < g->vertices; i++) {
        if (g->adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
            DFSUtil(g, i, visited);
        }
    }
}

// Function to check whether a given graph is connected using DFS
int isConnected(struct Graph* g) {
    int visited[MAX_CITIES] = {0};
    DFSUtil(g, 0, visited);

    // Check if all vertices are visited
    for (int i = 0; i < g->vertices; i++) {
        if (!visited[i]) {
            return 0; // Not connected
        }
    }

    return 1; // Connected
}

int main() {
    struct Graph graph;
    int vertices, edges, source, destination, startNode;

    printf("Enter the number of cities: ");
    scanf("%d", &vertices);

    initializeGraph(&graph, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &source, &destination);
        addEdge(&graph, source, destination);
    }

    printf("Enter the starting node for BFS: ");
    scanf("%d", &startNode);

    printf("Nodes reachable from %d using BFS: ", startNode);
    BFS(&graph, startNode);

    if (isConnected(&graph)) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }


}

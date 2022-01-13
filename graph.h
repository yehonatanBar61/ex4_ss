#ifndef GRAPH_H
#define GRAPH_H

typedef struct Node {
    int key;
    struct Node* next; 
} Node;

typedef struct Edge {
    int src;
    int weight;
    int dest;
    struct Edge* next; 
} Edge;

typedef struct Graph {//graph implement, has a pointer to nodes and to edge
    int num_of_edges;
    int num_of_nodes;
    struct Node* head_node; 
    struct Edge* head_edge; 
} Graph;


void add_node(int, struct Graph*);
void node_to_remove(int, struct Graph*);
void connect(int, int, int, struct Graph*);
void remove_edge(int, int, struct Graph*);
void init(struct Graph*, char*);
void print_graph(struct Graph*);
void delete_graph(struct Graph*);
int shortest_path(int, int, struct Graph*);
int TSP(struct Graph*, char*);
void free_graph(struct Graph*);

#endif
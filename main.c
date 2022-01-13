# include <stdio.h>
# include "graph.h"

int main()
{
    char ch;
    struct Graph g = {0, 0, NULL, NULL};
    struct Graph *graphP = &g;
    ch = getchar();
    while (ch != EOF && ch != '\n')
    {
        if (ch == 'A')
        {
            if (graphP->num_of_nodes != 0)
            {
                delete_graph(graphP);
            }
            init(graphP, &ch);
        }
        if (ch == 'B') 
        {
            int new_id;
            scanf(" %d",&new_id);
            add_node(new_id, graphP);
            int destenation;
            int w;
            while (scanf(" %d %d", &destenation, &w) == 2)
            {
                connect(new_id, destenation, w, graphP);
            }
            ch = getchar();
        }
        if (ch == 'D') 
        {
            int id_to_remove;
            scanf(" %d",&id_to_remove);
            node_to_remove(id_to_remove ,graphP);
            ch = getchar();
        }
        if (ch == 'S') 
        {
            int src, destenation, result;
            result = -1;
            if (scanf(" %d %d", &src, &destenation) == 2)
                result = shortest_path(src, destenation, graphP);
            if (result == 0)
                result = -1;
            printf("Dijsktra shortest path: %d \n", result);
            ch = getchar();
        }
        if (ch == 'T') 
        {
            int answers = -1;
            answers = TSP(graphP, &ch);
            printf("TSP shortest path: %d \n", answers);
            ch = getchar();
        }
        if (ch == 'P') 
        {
            print_graph(graphP);
            ch = getchar();
        }
        if (ch == ' ')
            ch = getchar();
    }
    free_graph(graphP);
    return 0;
}

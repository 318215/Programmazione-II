struct adj_node { 
    int node; //numero del nodo(?)
    float weight; //peso dell'arco
    adj_node* next; //puntatore al prossimo elemento nella lista di adiacenza
};

typedef adj_node* adj_list;

typedef struct{ 
    adj_list* nodes; //array dinamico di dim listte di adiacenza
    int dim;  //numero dei vertici
} graph;

graph new_graph(int);
void add_arc(graph& ,int ,int ,float );
void add_edge(graph& ,int ,int ,float );
int get_dim(graph);
adj_list get_adjlist(graph,int);
int get_adjnode(adj_node*);
adj_list get_nextadj(adj_list);
float get_adjweight(adj_node);
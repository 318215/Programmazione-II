struct bnode {
      tipo_inf inf;
      tipo_key key;
      bnode* left;
      bnode* right;
      bnode* parent;
};
//dichiarazione del tipo di dato binary tree
typedef bnode* bst;

bnode* bst_new_node(tipo_key,tipo_inf);
tipo_key get_key(bnode*);
tipo_inf get_value(bnode*);
bst get_left(bnode*);
bst get_right(bnode*);
bst get_parent(bnode*);
void bst_insert(bst&, bnode*);
void bst_delete(bst&, bnode*);
bnode* bst_search(bst, tipo_key);
void bst_dfs(bnode*);
bst serach_Ricorsiva(bst,tipo_inf);
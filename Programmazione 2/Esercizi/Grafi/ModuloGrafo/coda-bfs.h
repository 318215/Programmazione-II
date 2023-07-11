
/**
 * @file coda-bfs.h
 * 
 * 
 * @author Manuel Testoni (codebrothers.xyz)
 * @brief 
 * @version 0.1
 * @date 2023-07-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

struct elemBFS{

    int inf;
    elemBFS* pun ;
};

typedef elemBFS* lista;

typedef struct {

    lista head;
    elemBFS* tail; 

} codaBFS;

codaBFS enqueue(codaBFS, int); 
int dequeue(codaBFS&);
int first(codaBFS);
bool isEmpty(codaBFS);
codaBFS newQueue();
static elemBFS* new_elem(int);
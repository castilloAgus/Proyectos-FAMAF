#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"

struct s_queue {
    unsigned int size;
    struct s_node *first;
    struct s_node *last; //agrego un nuevo campo
} ;

struct s_node {
    queue_elem elem;
    struct s_node *next;
} ;

static struct s_node *create_node(queue_elem e) {
    struct s_node *new_node=malloc(sizeof(struct s_node));
    assert(new_node!=NULL);
    new_node->elem = e;
    new_node->next = NULL;
    return new_node;
}

static struct s_node *destroy_node(struct s_node *node) {
    node->next=NULL;
    free(node);
    node=NULL;
    return node;
}


static bool invrep(queue q) { //nos dice que si queue es vacio o no
    return q != NULL;
}

queue queue_empty(void) {
    queue q=NULL;
    q = malloc(sizeof(struct s_queue));
    q->size = 0u;
    q->first = NULL;
    assert(invrep(q) && queue_is_empty(q));
    return q;
}

queue queue_enqueue(queue q, queue_elem e) {
    assert(invrep(q));
    struct s_node *new_node = create_node(e);
    if (q->first==NULL) {
        q->first = new_node;
        q->last = new_node;
    } 
    else {
        q->last->next = new_node;
        q->last = new_node;
    }
    q->size++;
    assert(invrep(q) && !queue_is_empty(q));
    return q;
}

bool queue_is_empty(queue q) {
    assert(invrep(q));
    return q->first == NULL;
}

unsigned int queue_size(queue q) {
    assert(invrep(q));
    unsigned int size=0;
    size = q->size;
    return size;
}

queue queue_disscard(queue q, unsigned int n){
    assert(invrep(q) && n<queue_size(q));

    if (n == 0) {
        q = queue_dequeue(q);
    }
    else {
        struct s_node *p = q->first;
        for (size_t i = 0; i < n-1; i++) {
            p = p->next;
        }
        struct s_node *s = p->next;
        p->next = p->next->next;
        free(s);
        q->size--;
    }
    
    return q;
}

queue_elem queue_first(queue q) {
    assert(invrep(q) && !queue_is_empty(q));
    return q->first->elem;
}

queue queue_dequeue(queue q) {
    assert(invrep(q) && !queue_is_empty(q));
    struct s_node * killme=q->first;
    q->first = q->first->next;
    killme = destroy_node(killme);
    assert(invrep(q));
    return q;

}

void queue_dump(queue q, FILE *file) {
    file = file==NULL ? stdout: file;
    struct s_node *node=q->first;
    fprintf(file, "[ ");
    while(node!=NULL) {
        fprintf(file, "%d", node->elem);
        node = node->next;
        if (node != NULL) {
            fprintf(file, ", ");
        }
    }
    fprintf(file, "]\n");
}

queue queue_destroy(queue q) {
    assert(invrep(q));
    struct s_node *node=q->first;
    while (node != NULL) {
        struct s_node *killme=node;
        node = node->next;
        killme = destroy_node(killme);
    }
    free(q);
    q = NULL;
    assert(q == NULL);
    return q;
}


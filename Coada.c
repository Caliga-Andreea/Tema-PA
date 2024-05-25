#include "Coada.h"
Queue* createQueue()
{
    Queue *q;
    q=(Queue *)malloc(sizeof(Queue));
    if (q==NULL) return NULL;
    q->front=q->rear=NULL;
    return q;
}
void enQueue ( Queue *q, NodeEch *v)
{
    NodeEch * newNode =( NodeEch *) malloc ( sizeof ( NodeEch ));
    newNode -> next = NULL ;
    if (q-> rear == NULL ) q-> rear = newNode ;
    else
    {
        (q-> rear ) -> next = newNode ;
        (q-> rear )= newNode ;
    }
    if (q-> front == NULL ) q-> front =q-> rear ;
}

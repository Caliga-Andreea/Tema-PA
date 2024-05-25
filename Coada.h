#include <stdio.h>
#include <stdlib.h>
typedef struct Player NodeJuc;
typedef struct Echipa NodeEch;
struct Q{
NodeEch *front,*rear;
};
typedef struct Q Queue;
Queue* createQueue();

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Player
{
    char* firstName;
    char* secondName;
    int points;
    struct Player* next;
};
typedef struct Player NodeJuc;
struct Echipa
{
    int nrjuc;
    float pctj;
    char* numech;
    NodeJuc* head;
    struct Echipa* next;
};
typedef struct Echipa NodeEch;
struct Q{
NodeEch *front ,* rear ;
};
typedef struct Q Queue ;
typedef struct Graph NodeGraph;
struct Graph
{
    NodeEch *ech;
    NodeGraph *left;
    NodeGraph *right;
};
typedef struct AVL NodeAVL;
struct AVL
{
    NodeEch *ech;
    NodeAVL *left,*right;
    int height;
};
NodeJuc* createNodeJuc(int p,char *f,char *s);
NodeEch* createNodeEch(int nr,char *num, NodeJuc* j);
void addAtBeginningJuc(NodeJuc **head,int p, char *f, char *s);
void addAtBeginningEch(NodeEch **head,int nr, char *num, NodeJuc* j,float pctj);
void addAtBeginning8(NodeEch **head, NodeEch *node);
void citire(FILE *f2, NodeEch **headech,int *nrech);
void pctaj_ech(NodeEch *head);
void elimina(NodeEch **head,int *nrech);
Queue * createQueue();
void enQueue ( Queue *q,NodeEch* newNode);
int isEmpty ( Queue *q);
void deQueue ( Queue *q);
void push ( NodeEch ** top,NodeEch *x);
void pop( NodeEch ** top);
void printqueue(FILE *f3,NodeEch *curent,int n);
void printround(FILE *f3,NodeEch *headcpy,int n,NodeEch **castig, NodeEch **invins);
void deleteinvins(NodeEch **invins);
void printcastig(FILE *f3,NodeEch *headcpy,int n);
void adaugqueue(Queue *q,NodeEch **headcpy,int n);
NodeGraph *newNode(NodeEch *nodech);
NodeGraph *insertg(NodeGraph *node,NodeEch *nodech);
void descresc(FILE *f3,NodeGraph *root);
void task3(FILE *f3,NodeEch **castig, NodeEch **ult8,int *nrech,NodeEch **invins,Queue **q,NodeEch *headech);
void BST(FILE *f3,NodeEch **ult8,NodeGraph **root);
void citfis(FILE *f2,Queue **q,int *nrech,NodeEch **headech);
void testfis(FILE *f);
void task1(FILE *f3,NodeEch *headech);
int nodeHeight(NodeAVL *root);
NodeAVL * RightRotation ( NodeAVL *z);
NodeAVL * LeftRotation ( NodeAVL *z);
NodeAVL * LRRotation ( NodeAVL *Z);
NodeAVL * RLRotation ( NodeAVL *Z);
NodeAVL * insert ( NodeAVL * node , NodeGraph *ech);
NodeAVL* creareAVL(NodeGraph *nodech);
void afislvl2(FILE *f3, NodeAVL *root,int nivel,int curent);
void descrescAVL(NodeAVL **node,NodeGraph *root);
void task4(FILE *f3,NodeEch **headech,int *nrech,NodeEch **castig, NodeEch **invins, Queue **q, NodeGraph **root, NodeEch **ult8);
void task5(FILE *f3,NodeEch **headech,int *nrech, NodeEch **castig,NodeEch **invins,NodeEch **ult8,Queue **q,NodeGraph **root,NodeAVL **node);

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
    char* numech;
    NodeJuc* head;
    struct Echipa* next;
};
typedef struct Echipa NodeEch;
NodeJuc* createNodeJuc(int p,char *f,char *s);
NodeEch* createNodeEch(int nr,char *num, NodeJuc* j);
void addAtBeginningJuc(NodeJuc **head,int p, char *f, char *s);
void addAtBeginningEch(NodeEch **head,int nr, char *num, NodeJuc* j);
void citire(FILE *f2, NodeEch **headech);

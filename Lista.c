#include "Lista.h"

NodeJuc* createNodeJuc(int p,char *f, char *s)
{
    NodeJuc *head=(NodeJuc*)malloc(sizeof(NodeJuc));
    if(head==NULL)
    {
        printf("Nu s-a putut realiza alocarea");
        exit(1);
    }
    head->points=p;
    //alocare de memorie pt a evita copierea superficiala
    head->firstName=malloc((strlen(f)+1)*sizeof(char));
    strcpy(head->firstName,f);
    head->secondName=malloc((strlen(s)+1)*sizeof(char));
    strcpy(head->secondName,s);
    head->next=NULL;
    return head;
}
NodeEch* createNodeEch(int nr,char *num, NodeJuc* j)
{
    NodeEch *headech=(NodeEch*)malloc(sizeof(NodeEch));
    if(headech==NULL)
    {
        printf("Nu s-a putut realiza alocarea");
        exit(1);
    }
    headech->nrjuc=nr;
    //alocare de memorie pt a evita copierea superficiala
    headech->numech=malloc((strlen(num)+1)*sizeof(char));
    strcpy(headech->numech,num);
    headech->head=j;
    headech->next=NULL;
    return headech;
}
void addAtBeginningJuc(NodeJuc **head,int p, char *f, char *s)
{
    NodeJuc* newNode=(NodeJuc*)malloc(sizeof(NodeJuc));
    newNode->points=p;
    newNode->firstName=malloc((strlen(f)+1)*sizeof(char));
    strcpy(newNode->firstName,f);
    newNode->secondName=malloc((strlen(s)+1)*sizeof(char));
    newNode->next=*head;
    *head=newNode;
}
void addAtBeginningEch(NodeEch **head,int nr, char *num, NodeJuc* j)
{
    NodeEch* newNode=(NodeEch*)malloc(sizeof(NodeEch));
    newNode->nrjuc=nr;
    newNode->numech=malloc((strlen(num)+1)*sizeof(char));
    strcpy(newNode->numech,num);
    newNode->next=*head;
    *head=newNode;
}
void citire(FILE *f2, NodeEch **headech)
{
    int nrech,nrjuc,points,i,j;
    char *numech,*firstName,*secondName;;
    char a;
    NodeJuc *head=NULL;
    fscanf(f2,"%d",&nrech);
    fscanf(f2,"%c",&a);
    numech=(char*)malloc(sizeof(char)*50);
    firstName=(char*)malloc(sizeof(char)*20);
    secondName=(char*)malloc(sizeof(char)*20);
    for(i=0;i<nrech;i++)
    {
        numech=(char*)realloc(numech,50);
        head=NULL;
        fscanf(f2,"%d",&nrjuc);
        fscanf(f2,"%c",&a);
        fgets(numech,50,f2);
        numech[strlen(numech)-2]='\0';
        numech=(char*)realloc(numech,strlen(numech));
        for(j=0;j<nrjuc;j++)
        {
            firstName=(char*)realloc(firstName,20);
            secondName=(char*)realloc(secondName,20);
            fscanf(f2,"%s %s %d",firstName,secondName,&points);
            firstName=(char*)realloc(firstName,strlen(firstName));
            secondName=(char*)realloc(secondName,strlen(secondName));
            addAtBeginningJuc(&head,points,firstName,secondName);
            fscanf(f2,"%c",&a);
        }
        addAtBeginningEch(headech,nrjuc,numech,head);
    }
    free(numech);
    free(firstName);
    free(secondName);
}

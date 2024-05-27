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
void addAtBeginningEch(NodeEch **head,int nr, char *num, NodeJuc* j,float pctj)
{
    NodeEch* newNode=(NodeEch*)malloc(sizeof(NodeEch));
    newNode->nrjuc=nr;
    newNode->numech=malloc((strlen(num)+1)*sizeof(char));
    strcpy(newNode->numech,num);
    newNode->pctj=(float)pctj/nr;
    newNode->next=*head;
    *head=newNode;
}
void addAtBeginning8(NodeEch **head, NodeEch *node)
{
    NodeEch* newNode=(NodeEch*)malloc(sizeof(NodeEch));
    *newNode=*node;
    newNode->next=*head;
    *head=newNode;
}
void citire(FILE *f2, NodeEch **headech,int *nrech)
{
    int nrjuc,points,i,j,pctj;
    char *numech,*firstName,*secondName;;
    char a;
    NodeJuc *head=NULL;
    numech=(char*)malloc(sizeof(char)*50);
    firstName=(char*)malloc(sizeof(char)*20);
    secondName=(char*)malloc(sizeof(char)*20);
    for(i=0; i<(*nrech); i++)
    {
        numech=(char*)realloc(numech,50);
        head=NULL;
        fscanf(f2,"%d",&nrjuc);
        fscanf(f2,"%c",&a);
        fgets(numech,50,f2);
        numech[strlen(numech)-2]='\0';
        while(numech[strlen(numech)-1]==' ')
            numech[strlen(numech)-1]='\0';
        numech=(char*)realloc(numech,strlen(numech));
        pctj=0;
        for(j=0; j<nrjuc; j++)
        {
            firstName=(char*)realloc(firstName,20);
            secondName=(char*)realloc(secondName,20);
            fscanf(f2,"%s %s %d",firstName,secondName,&points);
            pctj=pctj+points;
            firstName=(char*)realloc(firstName,strlen(firstName));
            secondName=(char*)realloc(secondName,strlen(secondName));
            addAtBeginningJuc(&head,points,firstName,secondName);
            fscanf(f2,"%c",&a);
        }
        addAtBeginningEch(headech,nrjuc,numech,head,pctj);
    }
    free(numech);
    free(firstName);
    free(secondName);
}

void elimina(NodeEch **head,int *nrech)
{
    NodeEch *headcpy,*prev;
    float mini;
    int n=1;
    while(n<(*nrech))
        n=n*2;
    if(n>(*nrech))
        n=n/2;
    while((*nrech)>n)
    {
        headcpy=*head;
        mini=(*head)->pctj;
        while(headcpy!=NULL)
        {
            if(headcpy->pctj<mini)
                mini=headcpy->pctj;
            headcpy=headcpy->next;
        }
        headcpy=*head;
        if(headcpy->pctj==mini)
        {
            *head=(*head)->next;
            free(headcpy);
        }
        else
        {
            prev=headcpy;
            while(headcpy->pctj!=mini)
            {
                prev=headcpy;
                headcpy=headcpy->next;
            }
            if(headcpy->pctj==mini)
            {
                prev->next=headcpy->next;
                free(headcpy);
            }
        }
        (*nrech)--;
    }

}
Queue * createQueue ()
{
    Queue *q;
    q=( Queue *) malloc ( sizeof ( Queue ));
    if (q== NULL ) return NULL ;
    q->front =q->rear=NULL ;
    return q;
}
void enQueue ( Queue *q, NodeEch* x)
{
    NodeEch* newNode=(NodeEch*)malloc(sizeof(NodeEch));
    *newNode=*x;
    newNode->next= NULL ;
    if (q->rear == NULL ) q->rear = newNode ;
    else
    {
        (q->rear)->next = newNode ;
        (q->rear)=newNode ;
    }
    if (q->front == NULL ) q->front =q->rear ;
}
int isEmpty ( Queue *q)
{
    return (q->front == NULL );
}
void deQueue ( Queue *q)
{
    NodeEch * aux ;
    if ( isEmpty (q)) return;
    aux=q->front ;
    q->front =(q->front)->next ;
    if(q->front==NULL)
        q->rear=NULL;
    free (aux );
}
void push ( NodeEch ** top,NodeEch *x)
{
    NodeEch * newNode =( NodeEch *) malloc ( sizeof ( NodeEch ));
    *newNode=*x;
    newNode ->next =* top;
    *top= newNode ;
}
void pop( NodeEch ** top)
{
    *top =(* top)->next ;
}
void printqueue(FILE *f3,NodeEch *curent,int n)
{
    while(curent!=NULL&&n==1)
    {
        fprintf(f3,"%s\n",curent->numech);
        curent=curent->next;
    }
    fprintf(f3,"\n");
}
void printround(FILE *f3,NodeEch *headcpy,int n,NodeEch **castig, NodeEch **invins)
{
    int i;
    fprintf(f3,"--- ROUND NO:%d\n",n);
    while(headcpy!=NULL)
    {
        fprintf(f3,"%s",headcpy->numech);
        for(i=0; i<(33-strlen(headcpy->numech)); i++)
            fprintf(f3," ");
        fprintf(f3,"-");
        for(i=0; i<(33-strlen((headcpy->next)->numech)); i++)
            fprintf(f3," ");
        fprintf(f3,"%s\n",(headcpy->next)->numech);
        if(headcpy->pctj>(headcpy->next)->pctj)///sau >= in functie de ce spune cerinta
        {
            push(castig,headcpy);
            push(invins,headcpy->next);
        }
        else
        {
            push(invins,headcpy);
            push(castig,headcpy->next);
        }
        headcpy=headcpy->next->next;
    }
    fprintf(f3,"\n");
}
void deleteinvins(NodeEch **invins)
{
    while(*invins!=NULL)
        pop(invins);
}
void printcastig(FILE *f3,NodeEch *headcpy,int n)
{
    int i;
    fprintf(f3,"WINNERS OF ROUND NO:%d\n",n);
    while(headcpy!=NULL)
    {
        fprintf(f3,"%s",headcpy->numech);
        for(i=0; i<34-strlen(headcpy->numech); i++)
            fprintf(f3," ");
        fprintf(f3,"-  ");
        headcpy->pctj++;
        fprintf(f3,"%.2f\n",headcpy->pctj);
        headcpy=headcpy->next;
    }
}
void adaugqueue(Queue *q,NodeEch **headcpy,int n)
{
    if(n==1)
    {
        while(*headcpy!=NULL)
        {
            enQueue(q,*headcpy);
            *headcpy=(*headcpy)->next;
        }
    }
    else
    {
        while(*headcpy!=NULL)
        {
            enQueue(q,*headcpy);
            pop(headcpy);
        }
    }
}
NodeGraph *newNode(NodeEch *nodech)
{
    NodeGraph * node = ( NodeGraph *) malloc ( sizeof ( NodeGraph ));
    node->ech=nodech;
    node->left=node->right=NULL ;
    return node;
}
NodeGraph *insertg(NodeGraph *node,NodeEch *nodech)
{
    if ( node == NULL ) return newNode(nodech);
    if (nodech->pctj>node->ech->pctj)
        node->right=insertg(node->right,nodech);
    else if(nodech->pctj<node->ech->pctj)
        node->left=insertg(node->left,nodech);
    else
    {
        if(strcmp(nodech->numech,node->ech->numech)>0)
            node->right=insertg(node->right,nodech);
        else
            node->left=insertg(node->left,nodech);
    }
    return node ;
}
void descresc(FILE *f3,NodeGraph *root)
{
    int i;
    if(root)
    {
        descresc(f3,root->right);
        fprintf(f3,"%s",root->ech->numech);
        for(i=0; i<34-strlen(root->ech->numech); i++)
            fprintf(f3," ");
        fprintf(f3,"-  ");
        fprintf(f3,"%.2f\n",root->ech->pctj);
        descresc(f3,root->left);
    }
}
void task3(FILE *f3,NodeEch **castig, NodeEch **ult8,int *nrech,NodeEch **invins,Queue **q,NodeEch *headech)
{
    int n=1;
    NodeEch *headcpy;
    while(*nrech>1)
    {
        if(*nrech==8)
        {
            headcpy=*castig;
            while(headcpy!=NULL)
            {
                addAtBeginning8(ult8,headcpy);
                headcpy=headcpy->next;
            }
        }

        if(n==1)
            adaugqueue(*q,&headech,n);
        else
            adaugqueue(*q,castig,n);
        printqueue(f3,(*q)->front,n);
        printround(f3,(*q)->front,n,castig,invins);
        deleteinvins(invins);
        printcastig(f3,*castig,n);
        while(!isEmpty(*q))
            deQueue(*q);
        n++;
        *nrech=(*nrech)/2;
    }
}
void BST(FILE *f3,NodeEch **ult8,NodeGraph **root)
{
    NodeEch *headcpy;
    headcpy=(*ult8);
    while(headcpy!=NULL)
    {
        *root=insertg(*root,headcpy);
        headcpy=headcpy->next;
    }
    fprintf(f3,"\n");
    fprintf(f3,"TOP 8 TEAMS:\n");
    descresc(f3,*root);
}
void citfis(FILE *f2,Queue **q,int *nrech,NodeEch **headech)
{  char a;
    fscanf(f2,"%d",nrech);
    fscanf(f2,"%c",&a);
    citire(f2,headech,nrech);
    *q=createQueue();
}
void testfis(FILE *f)
{
    if(f==NULL)
    {
        printf("Fisierul nu a putut fi deschis");
        exit(1);
    }
}
void task1(FILE *f3,NodeEch *headech)
{
    NodeEch *headcpy=NULL;
    headcpy=headech;
        while(headcpy!=NULL)
        {
            fprintf(f3,"%s\n",headcpy->numech);
            headcpy=headcpy->next;
        }
}

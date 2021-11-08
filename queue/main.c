#include <stdio.h>
#include <stdlib.h>

// separador para o texto
void separator(){
    printf("____________________\n");
}

// Funções para lista encadeada
typedef struct node {
    int info;
    struct node * next;
} Node;

//Insere um novo nó
Node* insertList(Node* list, int num){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->info = num;
    new_node->next = list;
    return new_node;
}

//Remove o nó (é utilizado na função getOut())
Node* removeQ(Node* list){
    Node* aux = list;
    list = aux->next;
    free(aux);
    return list;
}

// Funções para a fila
typedef struct queue {
    Node* ini;
    Node* fim;
} Queue;

// Cria uma nova fila
Queue* createQ(void){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->ini = q->fim = NULL;
    return q;
}

// Entra com um novo valor na fila
void enterQ(Queue* q, int num){
    Node* new_node = insertList(q->fim, num);
    new_node->next = NULL;
    if(q->fim != NULL){
        q->fim->next = new_node;
    }
    q->fim = new_node;
    if(q->ini == NULL){
        q->ini = q->fim;
    }
}

// Retorna uma comparação para verificar se a lista está vazia
int isEmpty(Queue* q){
    return(q->ini == NULL);
}

// Retira o primeiro item da lista
int getOut(Queue* q){
    int num;
    if(isEmpty(q)){
        printf("Empty queue.");
        exit(1);
    }
    num = q->ini->info;
    q->ini = removeQ(q->ini);
    if(q->ini == NULL){
        q->fim = NULL;
    }
    return num;
}

// Imprime a lista
void printQueue(Queue* q){
    Node* aux;
    for(aux = q->ini; aux != NULL; aux = aux->next){
        printf("%d\n", aux->info);
    }
}

// deleta a lista da memória
void deleteQueue(Queue* q){
    Node* aux = q->ini;
    while(aux != NULL){
        Node* after = aux->next;
        free(aux);
        aux = after;
    }
    free(q);
    printf("Queue deleted\n");
}

void main()
{
    Queue* q = createQ();
    separator();
    printf("Queue 1: \n\n");

    enterQ(q, 1);
    enterQ(q, 2);
    enterQ(q, 3);

    printQueue(q);

    Queue* p = createQ();
    separator();
    printf("Queue 2: \n\n");

    enterQ(p, 12);
    enterQ(p, 22);
    enterQ(p, 32);

    printQueue(p);

    separator();
    printf("Queue 1 after pop \n\n");

    getOut(q);
    printQueue(p);

    separator();
    printf("Queue 2 after pop \n\n");

    getOut(p);
    printQueue(q);

    separator();
    deleteQueue(q);
    deleteQueue(p);

}

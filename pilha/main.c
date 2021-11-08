#include <stdio.h>
#include <stdlib.h>


// Funções para a lista encadeada
typedef struct node{
    int info;
    struct node * next;
}Node;

Node* start(){
    return NULL;
}

Node* insrt(Node* list, int n){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->info = n;
    new_node->next = list;
    return new_node;
}

Node* remov(Node* list, int n){
    Node* prev = NULL;
    Node* aux = list;

    while(aux != NULL && aux->info != n){
        prev = aux;
        aux = aux->next;
    }
    if(aux == NULL){
        printf("Not found.\n");
        return list;
    }
    if(prev == NULL){
        list = aux->next;
    } else {
        prev->next = aux->next;
    }
    free(aux);
    return list;
}

Node* searchh(Node* list, int n){
    Node* aux;
    for(aux = list; aux != NULL; aux = aux->next){
        if(aux->info == n){
            printf("Found %d\n", aux->info);
            return aux;
        }
    }
    return NULL;
}

void printl(Node* list){
    Node* aux;
    int c = 0;
    for(aux = list; aux != NULL; aux = aux->next){
        printf("Item %d: %d\n", c, aux->info);
        c++;
    }
}

void freel(Node* list){
    Node* aux = list;

    while(aux != NULL){
        Node* next_node = aux->next;
        free(aux);
        aux = next_node;
    }
}

//Funções da pilha

typedef struct pilha{
    Node* topo;
}Pilha;

//cria a pilha
Pilha* create(void){
    Pilha* nova_pilha = (Pilha*)malloc(sizeof(Pilha));
    nova_pilha->topo = NULL;
    return nova_pilha;
}

//Inserindo na pilha
void push(Pilha* p, int v){
    p->topo = insrt(p->topo, v);
}

//Verifica se a pilha está vazia
int vazia(Pilha* p){
    return(p->topo == NULL);
}

//função remove para o pop
Node* removp(Node* list){
    Node* aux = list;
    list = aux->next;
    free(aux);
    return list;
}

//removendo da pilha
int pop(Pilha* p){
    int num;
    if(vazia(p)){
        printf("Pilha vazia.\n");
        exit(1);
    }
    num = p->topo->info;
    p->topo = removp(p->topo);
    return num;
}

// Imprime a pilha
void printp(Pilha* p){
    Node* q;
    for(q = p->topo; q != NULL; q = q->next){
        printf("%d\n", q->info);
    }
}

//apaga a pilha da memória
void freep(Pilha* p){
    Node* q = p->topo;
    while(q != NULL){
        Node* aux = q->next;
        free(q);
        q = aux;
    }
    free(p);
}

void main(){
    Node* list;
    int i = 0;
    list = start();
    for(i; i <= 25; i = i + 5){
        list = insrt(list, i);
    }
    printf("*** Lista antes de qualquer remocao ***\n");
    printl(list);

    searchh(list, 25);

    remov(list, 16);

    remov(list, 15);
    printf("*** Lista apos remover o 15 ***\n");
    printl(list);

    list = insrt(list, 9);

    printf("*** List apos inserir o 9 ***\n");
    printl(list);

    freel(list);

    printf("\n\n*** Pilha ***\n");

    Pilha* p = create();
    push(p, 1);
    push(p, 2);
    push(p, 3);

    printp(p);
}

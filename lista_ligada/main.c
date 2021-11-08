#include <stdio.h>
#include <stdlib.h>

//LISTA LIGADA

//Definição de tipo nó
typedef struct node {
    int info;
    struct node * next;
} Node;

//Função de inicialização
Node* startList(){
    return NULL;
}

//Função de inserção
Node* insertList(Node* list, int num){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->info = num;
    new_node->next = list;
    return new_node;
}

//Função de Remoção
Node* removeList(Node* list, int num){
    Node* anterior = NULL;
    Node* aux = list;

    while(aux != NULL && aux->info != num){
        anterior = aux;
        aux = aux->next;
    }
    if(aux==NULL){
        printf("Value %d not found\n", num);
        return list;
    }
    if(anterior==NULL){
        list = aux->next;
    } else {
        anterior->next = aux->next;
    }
    printf("%d removed\n", aux->info);
    free(aux);
    return list;
}

//Função de busca
Node* findValue(Node* list, int num){
    Node* aux;
    for(aux = list; aux != NULL; aux = aux->next){
        if(aux->info == num){
            printf("%d found\n", aux->info);
            return aux;
        }
    }
    return NULL;
}

//Função de impressão
void printList(Node* list){
    Node* aux;
    for(aux = list; aux != NULL; aux=aux->next){
        printf("%d\n", aux->info);
    }
}

//Função de liberar o espaço alocado na memória
void deleteList(Node* list){
    Node* aux = list;
    while(aux != NULL){
        Node* after = aux->next;
        free(aux);
        aux = after;
    }
    printf("List has been deleted");
}

// Main com algumas demonstrações
void main(){
    Node* list = startList();
    Node * d;
    int c;
    for(c = 0; c <= 25; c = c+5){
        list = insertList(list, c);
    }

    printList(list);

    removeList(list, 2);

    findValue(list, 15);

    removeList(list, 15);

    list = insertList(list, 12);

    printList(list);

    deleteList(list);
}



#include <stdio.h>
#include <stdlib.h>

//LISTA LIGADA

//Defini��o de tipo n�
typedef struct node {
    int info;
    struct node * next;
} Node;

//Fun��o de inicializa��o
Node* startList(){
    return NULL;
}

//Fun��o de inser��o
Node* insertList(Node* list, int num){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->info = num;
    new_node->next = list;
    return new_node;
}

//Fun��o de Remo��o
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

//Fun��o de busca
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

//Fun��o de impress�o
void printList(Node* list){
    Node* aux;
    for(aux = list; aux != NULL; aux=aux->next){
        printf("%d\n", aux->info);
    }
}

//Fun��o de liberar o espa�o alocado na mem�ria
void deleteList(Node* list){
    Node* aux = list;
    while(aux != NULL){
        Node* after = aux->next;
        free(aux);
        aux = after;
    }
    printf("List has been deleted");
}

// Main com algumas demonstra��es
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



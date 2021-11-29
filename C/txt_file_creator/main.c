#include <stdio.h>
#include <stdlib.h>
#include <string.h>


FILE* createFile(){
    FILE* f;
    char name[100], path[100] = "path"; // Caminho para a pasta files

    printf("---Criacao de arquivo---\n\n");
    printf("Nome: ");
    gets(name);
    setbuf(stdin, NULL);

    strcat(name, ".txt");
    printf("%s criado", name);

    strcat(path, name);

    f = fopen(path, "w");

    return f;
}




void main() {

    createFile();

}




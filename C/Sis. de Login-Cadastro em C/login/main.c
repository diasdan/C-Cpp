#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int login();
int cadastro();

void main(){

    setlocale(LC_ALL, "Portuguese");
    int log = 1, op;

    while(log != 0){
        log = login();
        if(log != 0){
            cadastro();
        } else {
            break;
        }
    }
}

int cadastro(){
    FILE* fp;
    char username[30], password[30], aux[30], i;
    int op = 0, s = 0, j;

    fflush(stdin);

    while(op != 1){
        system("cls");
        fp = fopen("logs/logs.txt", "r");
        while(op != 1){
            j = 0;
            printf("\n  Novo nome de usuário: ");
            gets(username);

            for(int c = 0; username[c] != '\0'; c++){
                j++;
            }
            if (j < 1){
                printf("\n    Usuário inválido.\n");
                printf("\n    Pressione Enter\n");
                getch();
                system("cls");
            } else {
                break;
            }
        }

        while((i = getc(fp)) != EOF){
            fscanf(fp, "%s", aux);
            if(strcmp(aux, username) == 0){
                    s++;
            }
        }
        if(s > 0){
            printf("\n  Nome de usuário indisponível! Tente novamente.\n");
            s = 0;
        } else {
            printf("\n  Nome de usuário disponível.\n");
            fflush(stdin);
            fclose(fp);
            break;
        }
    }

    fp = fopen("logs/logs.txt", "a");
    fprintf(fp, "%s\n", username);

	while(op != 1){
        s = 0;
		printf("\n  Nova senha: ");
    	gets(password);
    	for(int c = 0; password[c] != '\0'; c++){
            s++;
		}
		if (s < 1){
    		printf("\n    Senha inválida.\n");
    		printf("\n    Pressione Enter\n");
    		getch();
            system("cls");
		} else {
			break;
		}
	}
	fprintf(fp, "%s\n\n", password);

    fclose(fp);

    fflush(stdin);

    system("cls");
    return 0;
}

int login(){

    FILE* fp;
    char username[30], password[30], str2[30], i;
    int s = 0, op = 0, op2 = 0;

    system("cls");
    printf("\n  Para ter acesso, entre com seu login: \n");

    while(op == 0){
        fp = fopen("logs/logs.txt", "r");

        printf("\n    Nome de usuário: ");
        gets(username);

        char str[30];
        while((i = getc(fp)) != EOF){
            fscanf(fp, "%s", str);
            if(strcmp(str, username) == 0){
                s++;
                fscanf(fp, "%s", str2);
                break;
            }
        }
        if(s == 0){
            printf("\n  Usuário inexistente. Deseja fazer um novo cadastro? [sim: 1/não: 0]: ");
            scanf("%d", &op);
            system("cls");
            if(op == 1){
                fclose(fp);
                return 1;
            }
            fflush(stdin);

        } else {
            break;
        }
    }

    while(op2 == 0){
        printf("    Senha: ");
        gets(password);

        if(strcmp(str2, password) != 0){
            printf("Senha inválida\n");
        } else {
            break;
        }
    }
    fclose(fp);
    system("cls");
    printf("\n    Bem vindo %s\n\n", username);

    fflush(stdin);
    return 0;
}

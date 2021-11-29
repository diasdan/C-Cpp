#include <iostream>
#include <fstream>
#include <dirent.h>
#include <vector>

using namespace std;
using std::cout; using std::cin;
using std::endl; using std::vector;

int login();
string safePassword();
int cadastro();

string path = "files/";

int main(){
    int log;


    while(true){
        log = login();
        if (log != 0){
            log = cadastro();
        } else {
            break;
        }
    }

    return 0;
}

string safePassword(){
    string pass;

    while(true){
        int num = 0, maius = 0, esp = 0, aux;
        system("cls");
        cout << "\n   Crie uma senha: ";
        cin >> pass;

        for(int c = 0; c <= pass.length(); c++){
                aux = int(pass[c]);
                if(aux >= 65 && aux <= 90){
                    maius++;
                }
            for(int i = 0; i <= 9; i++){
                if(pass[c] == char(i + 48)){
                    num++;
                }
            }
        }
        for(int c = 0; c <= pass.length(); c++){
            aux = int(pass[c]);
            if((aux <= 47 && aux >= 33) || (aux <= 64 && aux >= 58) || (aux <= 96 && aux >= 91) || (aux <= 126 && aux >= 123)){
                esp++;
            }
        }

        if(num < 1 || maius < 1 || esp < 1 || pass.length() < 8){
            cout << "   Sua senha deve possuir pelo menos: um numero, uma letra maiuscula e um caractere especial" << endl;
        } else {
            return pass;
            system("cls");
            break;
        }
    }
}

int cadastro()
{
    string name, password, file;
    string path = "files/", format = ".txt";
    char op;
    int s;



    while(true){

    cout << "\n   Digite seu nome de usuario (pelomenos 8 caracteres): ";
    cin >> name;

    if(name.length() < 8){
        cout << "   Seu nome de usuario nao possui 8 caracteres\n" << endl;
    } else {
        break;
        }
    }

    file = path + name + format;

    ofstream MyFile(file);

    password = safePassword();

    MyFile << password << endl;

    MyFile.close();
    return 0;
}

int login(){
    string username, password, aux;
    char op;
    DIR *dir;
    struct dirent *diread;
    vector<char *> files;
    std::string name, format = ".txt", file;

    system("cls");
    cout <<"\n    LOGIN" << endl << endl;

    while(true){
        int s = 0;

        cout <<"    Nome de usuario: ";
        cin >> username;

        file = username + format;

        if ((dir = opendir("files/")) != nullptr) {
            while((diread = readdir(dir)) != NULL){
                if(diread->d_name == file){
                    s++;
                }
            }
            closedir(dir);
            } else {
                perror("Error");
                return EXIT_FAILURE;
            }
        if(s > 0){
            break;
        } else {
            cout << "\n   Usuario nao existente. Deseja de cadastrar? [s/n]: ";
            cin >> op;
            if (op == 's'){
                system("cls");
                return 1;
            }
        }
    }

    while(true){
        file = path + username + format;
        ifstream MyReadFile(file);
        int s = 0;

        cout <<"    Senha: ";
        cin >> password;

        while(getline(MyReadFile, aux)){
            if(aux == password){
                s++;
            }
        }
        if(s > 0){
            system("cls");
            cout << "\n   Bem-vindo " << username << endl;
            MyReadFile.close();
            break;
        } else {
            system("cls");
            cout << "\nSenha invalida.\n" << endl;
            }
        MyReadFile.close();
    }

    return 0;
}

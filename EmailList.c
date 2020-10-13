#include<stdio.h>

char nome[3][20];
char email[3][30];
char arquivo[100];

void insert(){
    FILE * pFile;
    printf("Informe o arquivo, com caminho, em que deseja escrever: \n");
    scanf("%s", &arquivo);
    pFile = fopen(arquivo , "w");

    printf("Digite o primeiro nome: ");
    scanf("%s", &nome[1]);
    fputs(nome[1], pFile);
    printf("Digite o primeiro email: ");
    scanf("%s", &email[1]);
    fputs(email[1], pFile);

    fclose(pFile);
}
void list(){}
void searchName(){}
void searchLetter(){}
void alter(){}
void del(){}
main(){
    int menu = 0;
    do{
        printf("Digite: \n\t1. Inserir dados.\n\t2. Listar todos os dados na tela.\n\t3. Pesquisar um nome e mostrar na tela\n\t4. Pesquisar os nomes pela primeira letra e mostrar todos na tela.\n\t5. Alterar dados.\n\t6. Exclui dados.\n\t7. Sair\n");
        scanf("%i", &menu);
        switch(menu){
            case 1:
                menu = 0;
                insert();
            case 2:
                menu = 0;
                list();
            case 3:
                menu = 0;
                searchName();
            case 4:
                menu = 0;
                searchLetter();
            case 5:
                menu = 0;
                alter();
            case 6:
                menu = 0;
                del();
            case 7:
                break;
            default:
                menu = 0;
        }
    }while(menu == 0);
}

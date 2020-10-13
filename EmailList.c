#include<stdio.h>

char nome[3][20];
char email[3][30];

void insert(){
    FILE * pFile;
    pFile = fopen("lista.txt" , "w");

    printf("Digite o primeiro nome: ");
    gets( nome[0]);
    fwrite(nome[0], 1, sizeof(nome[0]), pFile);
    printf("Digite o primeiro email: ");
    gets( email[0]);
    fwrite(email[0], 1, sizeof(email[0]), pFile);

    printf("Digite o segundo nome: ");
    gets( nome[1]);
    fwrite(nome[1], 1, sizeof(nome[1]), pFile);
    printf("Digite o segundo email: ");
    gets( email[1]);
    fwrite(email[1], 1, sizeof(email[1]), pFile);

    printf("Digite o terceiro nome: ");
    gets( nome[2]);
    fwrite(nome[2], 1, sizeof(nome[2]), pFile);
    printf("Digite o terceiro email: ");
    gets( email[2]);
    fwrite(email[2], 1, sizeof(email[2]), pFile);

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
        getchar();
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

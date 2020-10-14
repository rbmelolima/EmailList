#include <stdio.h>

char nome[3][20];
char email[3][30];

void insert()
{
    FILE *pFile;
    pFile = fopen("lista.txt", "w");

    for (int i = 0; i < 3; i++)
    {
        printf("\nDigite o %iº email: ", i + 1);
        gets(email[i]);
        fwrite(email[i], 1, sizeof(email[i]), pFile);

        printf("Digite o %iº nome: ", i + 1);
        gets(nome[i]);
        fwrite(nome[i], 1, sizeof(nome[i]), pFile);
    }

    fclose(pFile);
}

void list() {
    FILE * pFile;
    pFile = fopen("lista.txt", "r");

    printf("Lista de emails:\n");

    for(int i = 0; i < 3; ++i){
        fread(&nome[i], 1, sizeof(nome[i]),pFile);
        printf("\t%s -", nome[i]);
        fread(&email[i], 1, sizeof(email[i]),pFile);
        printf(" %s\n", email[i]);
    }

    fclose(pFile);
}

void searchName() {}

void searchLetter() {}

void alter() {}

void del() {}

void main()
{
    int menu = 0;
    do
    {
        printf("\n\n\n\n");
        printf("******************** \n");
        printf("**** EMAIL LIST **** \n");
        printf("******************** \n");

        printf("\n(1) Inserir dados");
        printf("\n(2) Listar dados");
        printf("\n(3) Pesquisar um nome");
        printf("\n(4) Pesquisar os nomes pela primeira letra");
        printf("\n(5) Alterar dados");
        printf("\n(6) Excluir dados");
        printf("\n(7) Sair");
        printf("\n\n-> Digite sua ação: ");

        scanf("%i", &menu);
        getchar();

        switch (menu)
        {
        case 1:
            menu = 0;
            insert();
            break;
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
        default:            
            exit(0);
            break;
        }

    } while (menu == 0);
}

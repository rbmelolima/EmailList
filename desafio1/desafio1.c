#include <stdio.h>
#include <stdlib.h>

char nome[3][20];
char email[3][30];
char filename[] = "lista.txt";

void loadContent() {
    FILE *pFile;
    pFile = fopen(filename, "r");
    int i = 0;

    for (i = 0; i < 3; ++i)
    {
        fread(&nome[i], 1, sizeof(nome[i]), pFile);
        fread(&email[i], 1, sizeof(email[i]), pFile);
    }

    fclose(pFile);
}

void insert()
{
    FILE *pFile;
    pFile = fopen(filename, "w");
    int i = 0;

    for (i = 0; i < 3; i++)
    {
        printf("\n\nDigite o %iº nome: ", i + 1);
        gets(nome[i]);
        fwrite(nome[i], 1, sizeof(nome[i]), pFile);

        printf("Digite o %iº email: ", i + 1);
        gets(email[i]);
        fwrite(email[i], 1, sizeof(email[i]), pFile);
    }

    fclose(pFile);
}

void list()
{
    FILE *pFile;
    pFile = fopen(filename, "r");
    int i = 0;

    printf("\n\tDados atuais:\n");

    for (i = 0; i < 3; ++i)
    {
        fread(&nome[i], 1, sizeof(nome[i]), pFile);
        fread(&email[i], 1, sizeof(email[i]), pFile);
        if(nome[i] != NULL){
        	printf("\t%s - %s\n", nome[i], email[i]);
		}
    }

    fclose(pFile);

    printf("\n\nPressione qualquer coisa para voltar ao menu... ");
    getch();
}

void searchName() {
    loadContent();

    char nameText[20];

    printf("\n\nPesquisar nome: ");
    gets(nameText);

    int finded = -1;
    int i = 0;
    int j = 0;

    for(i = 0; i < 3; i++){
        finded = 1;

        for(j = 0; j < 20 && (nameText[j] != '\0' || nome[i][j] != '\0'); j++) {
            if (nameText[j] == nome[i][j]){
                finded = i;
                break;
            }
        }
        
        if(finded != -1){
            break;    
        }

    }

    if(finded == -1) {
        printf("\n$ Nenhum registro foi encontrado.");    
    }
    
    else{
    	printf("\n$ Nome: %s \tEmail: %s", nome[finded], email[finded]);
	}

    printf("\n\nPressione qualquer coisa para voltar ao menu... ");
    getch();
}

void searchLetter() {
    loadContent();

    char letter;
    int countNotFound = 0;

    printf("\nDigite uma letra: ");
    letter = getchar();

    int finded;
    int i = 0;

    for(i = 0; i < 3; i++){
        finded = 1;

        if(nome[i][0] == letter){
            printf("\n$ Nome: %s \tEmail: %s", nome[i], email[i]);
        }

        else {
            countNotFound++;
        }
    }

    if(countNotFound == 3) {
        printf("\n$ Nenhum registro foi encontrado.");
    }

    printf("\n\nPressione qualquer coisa para voltar ao menu... ");
    getch();
}

void updateRegister() {
    loadContent();

    char nameText[20];

    printf("\n\nPesquisar nome: ");
    gets(nameText);

    int finded = -1;
    int i = 0;
    int j = 0;

    for(i = 0; i < 3; i++){

        for(j = 0; j < 20 && (nameText[j] != '\0' || nome[i][j] != '\0'); j++) {
            if (nameText[j] == nome[i][j]){
                finded = i;
                break;
            }
        }

        if(finded != -1){
            break;    
        }
    }

    if(finded == -1) {
        printf("\n$ Nenhum registro foi encontrado.");    
    }

    else{
        printf("\n$ Nome: %s \tEmail: %s", nome[finded], email[finded]);

        printf("\n\nDigite o novo nome: ");
        gets(nome[finded]);

        printf("\nDigite o novo e-mail: ");
        gets(email[finded]);

        FILE *pFile;
        pFile = fopen(filename, "r+");
        fseek(pFile, 50*finded, SEEK_SET);
        fwrite(nome[finded], 1, sizeof(nome[finded]), pFile);
        fwrite(email[finded], 1, sizeof(email[finded]), pFile);
        fclose(pFile);
    }

    printf("\n\nPressione qualquer coisa para voltar ao menu... ");
    getch();

}

void deleteRegister() {
	loadContent();

    char nameText[20];

    printf("\n\nPesquisar nome: ");
    gets(nameText);

    int finded = -1;
    int i = 0;
    int j = 0;

    for(i = 0; i < 3; i++){

        for(j = 0; j < 20 && (nameText[j] != '\0' || nome[i][j] != '\0'); j++) {
            if (nameText[j] == nome[i][j]){
                finded = i;
                break;
            }
        }

        if(finded != -1){
            break;    
        }
    }

    if(finded == -1) {
        printf("\n$ Nenhum registro foi encontrado.");    
    }

    else{
        printf("\n$ Nome: %s \tEmail: %s", nome[finded], email[finded]);

        FILE *pFile;
        pFile = fopen(filename, "w");
        for (i = 0; i < 3; i++)
	    {
	    	if(i != finded){
	    		fwrite(nome[i], 1, sizeof(nome[i]), pFile);
	        	fwrite(email[i], 1, sizeof(email[i]), pFile);
			}
	    }
        fclose(pFile);
        
        printf("\nDados excluidos!");
    }

    printf("\n\nPressione qualquer coisa para voltar ao menu... ");
    getch();
}

void main()
{
    int menu = 0;
    do
    {
        system("cls");
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
            break;
        case 3:
            menu = 0;
            searchName();
            break;
        case 4:
            menu = 0;
            searchLetter();
            break;
        case 5:
            menu = 0;
            updateRegister();
            break;
        case 6:
            menu = 0;
            deleteRegister();
            break;

        case 7:
        default:
            exit(0);
            break;
        }

    } while (menu == 0);
}

#include <stdio.h>
#include <stdlib.h>

struct dados {
    char nome[21];
    char email[31];
    char salario[11];
    char dia[3];
    char mes[3];
    char ano[5];
};

char filename[] = "lista.txt";

/*void loadContent() {
    FILE *pFile;
    pFile = fopen(filename, "r");

    fread(p, sizeof(struct dados), 1, pFile);
    while(!feof(pFile))
    {
        fread(p, sizeof(struct dados), 1, pFile);
    }

    fclose(pFile);
}*/

void insert(struct dados *p)
{
    FILE *pFile;
    pFile = fopen(filename, "a");
    int i = 0;

    printf("\n\nDigite o nome: ");
    gets(&p -> nome);
    //fwrite(p -> nome, sizeof(p -> nome), 1, pFile);

    printf("Digite o email: ");
    gets(&p -> email);
    //fwrite(p -> email, sizeof(p -> email), 1, pFile);

    printf("Digite o salario: ");
    gets(&p -> salario);
    //fwrite(p -> salario, sizeof(p -> salario), 1, pFile);

    printf("Digite o dia do nascimento: ");
    gets(&p -> dia);
    //fwrite(p -> nascimento.dia, sizeof(p -> nascimento.dia), 1, pFile);

    printf("Digite o mes do nascimento: ");
    gets(&p -> mes);
    //fwrite(p -> nascimento.mes, sizeof(p -> nascimento.mes), 1, pFile);

    printf("Digite o ano do nascimento: ");
    gets(&p -> ano);
    //fwrite(p -> nascimento.ano, sizeof(p -> nascimento.ano), 1, pFile);
	fwrite(p, sizeof(struct dados), 1, pFile);
    fclose(pFile);
}

void list(struct dados *p)
{
    FILE *pFile;
    pFile = fopen(filename, "r");

    printf("\n\tDados atuais:\n");

	fread(p, sizeof(struct dados), 1, pFile);
    while (!feof(pFile))
    {
        if(p->nome != NULL){
        	printf("\t%s - %s - %s - %s/%s/%s\n", p->nome, p->email, p->salario, p->dia, p->mes, p->ano);
		}
        fread(p, sizeof(struct dados), 1, pFile);
    }

    fclose(pFile);

    printf("\n\nPressione qualquer coisa para voltar ao menu... ");
    getch();
}

void searchName(struct dados *p) {

    FILE *pFile;
    pFile = fopen(filename, "r");
    char nameText[21];

    printf("\n\nPesquisar nome: ");
    gets(nameText);

    int finded = 0;
    int j = 0;

    fread(p, sizeof(struct dados), 1, pFile);
    while (!feof(pFile))
    {
        if(p->nome != NULL){
        	for(j = 0; j < 21 && (nameText[j] != '\0' || p->nome[j] != '\0'); j++) {
                if (nameText[j] == p->nome[j]){
                    finded++;
                }
                else{
                    finded = 0;
                    break;
                }
            }
            if(finded != 0){
                printf("\n\t%s - %s - %s - %s/%s/%s\n", p->nome, p->email, p->salario, p->dia, p->mes, p->ano);
                break;
            }
		}
        fread(p, sizeof(struct dados), 1, pFile);
    }

    if(finded == 0) {
        printf("\n\tNenhum registro foi encontrado.");
    }

	fclose(pFile);

    printf("\n\nPressione qualquer coisa para voltar ao menu... ");
    getch();
}
/*
void searchEmail() {
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

void searchBirthday() {
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

void searchSalary() {
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
}*/

void updateSalary(struct dados *p) {
    FILE *pFile;
    pFile = fopen(filename, "r");
    char nameText[21];

    printf("\n\nPesquisar nome: ");
    gets(nameText);

    int finded = 0;
    int j = 0;
    int indice = -1;

    fread(p, sizeof(struct dados), 1, pFile);
    while (!feof(pFile))
    {
        if(p->nome != NULL){
            indice++;
        	for(j = 0; j < 21 && (nameText[j] != '\0' || p->nome[j] != '\0'); j++) {
                if (nameText[j] == p->nome[j]){
                    finded++;
                }
                else{
                    finded = 0;
                    break;
                }
            }
            if(finded != 0){
                printf("\n\t%s - %s - %s - %s/%s/%s\n", p->nome, p->email, p->salario, p->dia, p->mes, p->ano);
                break;
            }
		}
        fread(p, sizeof(struct dados), 1, pFile);
    }

    if(finded == 0) {
        printf("\n\tNenhum registro foi encontrado.");
    }
    else{
        printf("\n\nDigite o novo salario: ");
        gets(&p->salario);

        pFile = fopen(filename, "r+");
        fseek(pFile, sizeof(p->salario) * indice, 0);
        fwrite(p->salario, sizeof(p->salario), 1, pFile);
        fclose(pFile);
    }

    printf("\n\nPressione qualquer coisa para voltar ao menu... ");
    getch();

}

void updateRegister(struct dados *p) {
    FILE *pFile;
    pFile = fopen(filename, "r");
    char nameText[21];

    printf("\n\nPesquisar nome: ");
    gets(nameText);

    int finded = 0;
    int j = 0;
    int indice = -1;

    fread(p, sizeof(struct dados), 1, pFile);
    while (!feof(pFile))
    {
        if(p->nome != NULL){
            indice++;
        	for(j = 0; j < 21 && (nameText[j] != '\0' || p->nome[j] != '\0'); j++) {
                if (nameText[j] == p->nome[j]){
                    finded++;
                }
                else{
                    finded = 0;
                    break;
                }
            }
            if(finded != 0){
                printf("\n\t%s - %s - %s - %s/%s/%s\n", p->nome, p->email, p->salario, p->dia, p->mes, p->ano);
                break;
            }
		}
        fread(p, sizeof(struct dados), 1, pFile);
    }

    if(finded == 0) {
        printf("\n\tNenhum registro foi encontrado.");
    }
    else{
        printf("\n\nDigite o novo nome: ");
        gets(&p->nome);

        printf("\n\nDigite o novo email: ");
        gets(&p->email);

        printf("\n\nDigite o novo salario: ");
        gets(&p->salario);

        printf("\n\nDigite o novo dia do aniversario: ");
        gets(&p->dia);

        printf("\n\nDigite o novo mes do aniversario: ");
        gets(&p->mes);

        printf("\n\nDigite o novo ano do aniversario: ");
        gets(&p->ano);

        pFile = fopen(filename, "r+");
        fseek(pFile, sizeof(struct dados) * indice, 0);
        fwrite(p, sizeof(struct dados), 1, pFile);
        fclose(pFile);
    }

    printf("\n\nPressione qualquer coisa para voltar ao menu... ");
    getch();

}
/*
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
*/
void main()
{
    int menu = 0;

    struct dados usuario;
    struct dados *p;
    p = &usuario;

    do
    {
        system("cls");
        printf("******************** \n");
        printf("**** EMAIL LIST **** \n");
        printf("******************** \n");

        printf("\n(1) Inserir dados");
        printf("\n(2) Listar dados");
        printf("\n(3) Pesquisar um nome completo");
        printf("\n(4) Pesquisar por email");
        printf("\n(5) Pesquisar aniversariantes pelo mes");
        printf("\n(6) Pesquisar por faixa salarial");
        printf("\n(7) Alterar salario pesquisando pelo nome completo");
        printf("\n(8) Alterar dados pesquisando pelo nome completo");
        printf("\n(9) Exclui dados pesquisando pelo nome completo");
        printf("\n(10) Sair");
        printf("\n\n-> Digite sua acao: ");

        scanf("%i", &menu);
        getchar();

        switch (menu)
        {
            case 1:
                menu = 0;
                insert(&p);
                break;
            case 2:
                menu = 0;
                list(&p);
                break;
            case 3:
                menu = 0;
                searchName(&p);
                break;
            /*case 4:
                menu = 0;
                searchEmail();
                break;
            case 5:
                menu = 0;
                searchBirthday();
                break;
            case 6:
                menu = 0;
                searchSalary();
                break;*/
            case 7:
                menu = 0;
                updateSalary(&p);
                break;
            case 8:
                menu = 0;
                updateRegister(&p);
                break;
            /*case 9:
                menu = 0;
                deleteRegister();
                break;
            case 10:*/
            default:
                exit(0);
                break;
        }

    } while (menu == 0);
}


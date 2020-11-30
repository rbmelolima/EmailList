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



int toInt(char a[]) {
    int c, sign, offset, n;

    if (a[0] == '-') {
        sign = -1;
    }

    if (sign == -1) {  
        offset = 1;
    }
    else {
        offset = 0;
    }

    n = 0;

    for (c = offset; a[c] != '\0'; c++) {
        n = n * 10 + a[c] - '0';
    }

    if (sign == -1) {
        n = -n;
    }

    return n;
}

float toFloat(char* s){
    float rez = 0, fact = 1;
    int point_seen;
    if (*s == '-'){
        s++;
        fact = -1;
    };
    for (point_seen = 0; *s; s++){
        if (*s == '.'){
	        point_seen = 1; 
	        continue;
        };
        int d = *s - '0';
        if (d >= 0 && d <= 9){
	        if (point_seen) 
			{
				fact /= 10.0f;
			}
        rez = rez * 10.0f + (float)d;
        };
    };
    return rez * fact;
};

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

void searchEmail(struct dados *p) {

    FILE *pFile;
    pFile = fopen(filename, "r");
    char emailText[31];

    printf("\n\nPesquisar e-mail: ");
    gets(emailText);

    int finded = 0;
    int j = 0;

    fread(p, sizeof(struct dados), 1, pFile);
    while (!feof(pFile))
    {
        if(p->nome != NULL){
        	for(j = 0; j < 31 && (emailText[j] != '\0' || p->email[j] != '\0'); j++) {
                if (emailText[j] == p->email[j]){
                    finded++;
                }
                else{
                    finded = 0;
                    break;
                }
            }
            if(finded != 0){
                printf("\n\t%s - %s - %s - %s/%s/%s\n", p->nome, p->email, p->salario, p->dia, p->mes, p->ano);
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

void searchBirthday(struct dados *p) {

    FILE *pFile;
    pFile = fopen(filename, "r");
    int mesPesquisa;

    printf("\n\nPesquisar por mes de aniversario: ");
    scanf("%d", &mesPesquisa);

    int finded = 0;

    fread(p, sizeof(struct dados), 1, pFile);
    while (!feof(pFile))
    {
        if(p->nome != NULL){
            if(mesPesquisa == toInt(p->mes)){ //utilizando função de conversão para comparar com int
                finded++;
                printf("\n\t%s - %s - %s - %s/%s/%s\n", p->nome, p->email, p->salario, p->dia, p->mes, p->ano);
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

void searchSalary(struct dados *p) {
    FILE *pFile;
    pFile = fopen(filename, "r");
    float menorSalario, maiorSalario;

    printf("\n\nPreencha o menor salario da faixa: ");
    scanf("%f", &menorSalario);

    printf("\n\nPreencha o maior salario da faixa: ");
    scanf("%f", &maiorSalario);

    int finded = 0;

    fread(p, sizeof(struct dados), 1, pFile);
    while (!feof(pFile))
    {
        if(p->nome != NULL){
            if(menorSalario <= toFloat(p->salario) && maiorSalario >= toFloat(p->salario)){ //utilizando função de conversão para comparar com float
                finded++;
                printf("\n\t%s - %s - %s - %s/%s/%s\n", p->nome, p->email, p->salario, p->dia, p->mes, p->ano);
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

void updateSalary(struct dados *p) {
    FILE *pFile;
    pFile = fopen(filename, "r");
    char nameText[21];

    printf("\n\nPesquisar nome: ");
    gets(nameText);

    int finded = 0;
    int j = 0;
    int indice = 0;

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

        //FILE *pFile;
        pFile = fopen(filename, "r+");
        fseek(pFile, 52*indice, SEEK_SET);
        fwrite(p->salario, 1, sizeof(p->salario), pFile);
        fclose(pFile);
    }

    printf("\n\nPressione qualquer coisa para voltar ao menu... ");
    getch();

}
/*
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
            case 4:
                menu = 0;
                searchEmail(&p);
                break;
            case 5:
                menu = 0;
                searchBirthday(&p);
                break;
            case 6:
                menu = 0;
                searchSalary(&p);
                break;
            case 7:
                menu = 0;
                updateSalary(&p);
                break;
            /*case 8:
                menu = 0;
                updateRegister();
                break;
            case 9:
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

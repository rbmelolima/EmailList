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
  int c, sinal, posicao, n;

  if (a[0] == '-') {
    sinal = -1;
  }

  if (sinal == -1) {
    posicao = 1;
  }

  else {
    posicao = 0;
  }

  n = 0;

  for (c = posicao; a[c] != '\0'; c++) {
    n = n * 10 + a[c] - '0';
  }

  if (sinal == -1) {
    n = -n;
  }

  return n;
}

float toFloat(char* s) {
  float f = 0, fator = 1;
  int posicao_ponto;

  if (*s == '-') {
    s++;
    fator = -1;
  };

  for (posicao_ponto = 0; *s; s++) {
    if (*s == '.') {
      posicao_ponto = 1;
      continue;
    };

    int d = *s - '0';

    if (d >= 0 && d <= 9) {
      if (posicao_ponto) {
        fator /= 10.0f;
      }

      f = f * 10.0f + (float)d;
    };
  };

  return f * fator;
};

void insert(struct dados* p) {
  FILE* pFile;
  pFile = fopen(filename, "a");
  int i = 0;

  printf("\n\nDigite o nome: ");
  gets(&p->nome);

  printf("Digite o email: ");
  gets(&p->email);

  printf("Digite o salario: ");
  gets(&p->salario);

  printf("Digite o dia do nascimento: ");
  gets(&p->dia);

  printf("Digite o mes do nascimento: ");
  gets(&p->mes);

  printf("Digite o ano do nascimento: ");
  gets(&p->ano);

  fwrite(p, sizeof(struct dados), 1, pFile);
  fclose(pFile);
}

void list(struct dados* p) {
  FILE* pFile;
  pFile = fopen(filename, "r");

  printf("\n\tDados atuais:\n");

  fread(p, sizeof(struct dados), 1, pFile);
  while (!feof(pFile)) {
    if (p->nome != NULL && p->nome[0] != '\0' ) {
      printf("\t%s - %s - %s - %s/%s/%s\n", p->nome, p->email, p->salario, p->dia, p->mes, p->ano);
    }
    fread(p, sizeof(struct dados), 1, pFile);
  }

  fclose(pFile);

  printf("\n\nPressione qualquer coisa para voltar ao menu... ");
  getch();
}

void searchName(struct dados* p) {
  FILE* pFile;
  pFile = fopen(filename, "r");
  char nameText[21];

  printf("\n\nPesquisar nome: ");
  gets(nameText);

  int finded = 0;
  int j = 0;

  fread(p, sizeof(struct dados), 1, pFile);

  while (!feof(pFile)) {
    if (p->nome != NULL) {
      for (j = 0; j < 21 && (nameText[j] != '\0' || p->nome[j] != '\0'); j++) {
        if (nameText[j] == p->nome[j]) {
          finded++;
        }

        else {
          finded = 0;
          break;
        }
      }

      if (finded != 0) {
        printf("\n\t%s - %s - %s - %s/%s/%s\n", p->nome, p->email, p->salario, p->dia, p->mes, p->ano);
      }
    }

    fread(p, sizeof(struct dados), 1, pFile);
  }

  if (finded == 0) {
    printf("\n\tNenhum registro foi encontrado.");
  }

  fclose(pFile);

  printf("\n\nPressione qualquer coisa para voltar ao menu... ");
  getch();
}

void searchEmail(struct dados* p) {
  FILE* pFile;
  pFile = fopen(filename, "r");
  char emailText[31];

  printf("\n\nPesquisar e-mail: ");
  gets(emailText);

  int finded = 0;
  int j = 0;

  fread(p, sizeof(struct dados), 1, pFile);

  while (!feof(pFile)) {
    if (p->nome != NULL) {
      for (j = 0; j < 31 && (emailText[j] != '\0' || p->email[j] != '\0'); j++) {
        if (emailText[j] == p->email[j]) {
          finded++;
        }

        else {
          finded = 0;
          break;
        }
      }

      if (finded != 0) {
        printf("\n\t%s - %s - %s - %s/%s/%s\n", p->nome, p->email, p->salario, p->dia, p->mes, p->ano);
      }
    }

    fread(p, sizeof(struct dados), 1, pFile);
  }

  if (finded == 0) {
    printf("\n\tNenhum registro foi encontrado.");
  }

  fclose(pFile);

  printf("\n\nPressione qualquer coisa para voltar ao menu... ");
  getch();
}

void searchBirthday(struct dados* p) {
  FILE* pFile;
  pFile = fopen(filename, "r");
  int mesPesquisa;

  printf("\n\nPesquisar por mes de aniversario: ");
  scanf("%d", &mesPesquisa);

  int finded = 0;

  fread(p, sizeof(struct dados), 1, pFile);

  while (!feof(pFile)) {
    if (p->nome != NULL) {
      if (mesPesquisa == toInt(p->mes)) { //utilizando função de conversão para comparar com int
        finded++;
        printf("\n\t%s - %s - %s - %s/%s/%s\n", p->nome, p->email, p->salario, p->dia, p->mes, p->ano);
      }
    }

    fread(p, sizeof(struct dados), 1, pFile);
  }

  if (finded == 0) {
    printf("\n\tNenhum registro foi encontrado.");
  }

  fclose(pFile);

  printf("\n\nPressione qualquer coisa para voltar ao menu... ");
  getch();
}

void searchSalary(struct dados* p) {
  FILE* pFile;
  pFile = fopen(filename, "r");
  float menorSalario, maiorSalario;

  printf("\n\nPreencha o menor salario da faixa: ");
  scanf("%f", &menorSalario);

  printf("\n\nPreencha o maior salario da faixa: ");
  scanf("%f", &maiorSalario);

  int finded = 0;

  fread(p, sizeof(struct dados), 1, pFile);
  while (!feof(pFile)) {
    if (p->nome != NULL) {
      if (menorSalario <= toFloat(p->salario) && maiorSalario >= toFloat(p->salario)) { //utilizando função de conversão para comparar com float
        finded++;
        printf("\n\t%s - %s - %s - %s/%s/%s\n", p->nome, p->email, p->salario, p->dia, p->mes, p->ano);
      }
    }

    fread(p, sizeof(struct dados), 1, pFile);
  }

  if (finded == 0) {
    printf("\n\tNenhum registro foi encontrado.");
  }

  fclose(pFile);

  printf("\n\nPressione qualquer coisa para voltar ao menu... ");
  getch();
}

void updateSalary(struct dados* p) {
  FILE* pFile;
  pFile = fopen(filename, "r");
  char nameText[21];

  printf("\n\nPesquisar nome: ");
  gets(nameText);

  int finded = 0;
  int j = 0;
  int indice = -1;

  fread(p, sizeof(struct dados), 1, pFile);
  while (!feof(pFile)) {
    if (p->nome != NULL) {
      indice++;
      for (j = 0; j < 21 && (nameText[j] != '\0' || p->nome[j] != '\0'); j++) {
        if (nameText[j] == p->nome[j]) {
          finded++;
        }

        else {
          finded = 0;
          break;
        }
      }

      if (finded != 0) {
        printf("\n\t%s - %s - %s - %s/%s/%s\n", p->nome, p->email, p->salario, p->dia, p->mes, p->ano);
        break;
      }
    }

    fread(p, sizeof(struct dados), 1, pFile);
  }

  if (finded == 0) {
    printf("\n\tNenhum registro foi encontrado.");
  }

  else {
    printf("\n\nDigite o novo salario: ");
    gets(&p->salario);

    pFile = fopen(filename, "r+");

    fseek(pFile, sizeof(struct dados) * indice, 0);
    fwrite(p, sizeof(struct dados), 1, pFile);
    fclose(pFile);
  }

  printf("\n\nPressione qualquer coisa para voltar ao menu... ");
  getch();
}

void updateRegister(struct dados* p) {
  FILE* pFile;
  pFile = fopen(filename, "r");
  char nameText[21];

  printf("\n\nPesquisar nome: ");
  gets(nameText);

  int finded = 0;
  int j = 0;
  int indice = -1;

  fread(p, sizeof(struct dados), 1, pFile);

  while (!feof(pFile)) {
    if (p->nome != NULL) {
      indice++;
      for (j = 0; j < 21 && (nameText[j] != '\0' || p->nome[j] != '\0'); j++) {
        if (nameText[j] == p->nome[j]) {
          finded++;
        }

        else {
          finded = 0;
          break;
        }
      }

      if (finded != 0) {
        printf("\n\t%s - %s - %s - %s/%s/%s\n", p->nome, p->email, p->salario, p->dia, p->mes, p->ano);
        break;
      }
    }

    fread(p, sizeof(struct dados), 1, pFile);
  }

  if (finded == 0) {
    printf("\n\tNenhum registro foi encontrado.");
  }

  else {
    printf("\n\nDigite o novo nome: ");
    gets(&p->nome);

    printf("Digite o novo email: ");
    gets(&p->email);

    printf("Digite o novo salario: ");
    gets(&p->salario);

    printf("Digite o novo dia do aniversario: ");
    gets(&p->dia);

    printf("Digite o novo mes do aniversario: ");
    gets(&p->mes);

    printf("Digite o novo ano do aniversario: ");
    gets(&p->ano);

    pFile = fopen(filename, "r+");
    fseek(pFile, sizeof(struct dados) * indice, 0);
    fwrite(p, sizeof(struct dados), 1, pFile);
    fclose(pFile);
  }

  printf("\n\nPressione qualquer coisa para voltar ao menu... ");
  getch();
}

void cleanArrayChar(char* p, int size) {
  for (int i = 0; i < size; i++) {
    p[i] = '\0';
  }
}

void delete(struct dados* p) {
  FILE* pFile;
  pFile = fopen(filename, "r");
  char nameText[21];

  printf("\n\nPesquisar nome: ");
  gets(nameText);

  int finded = 0;
  int j = 0;
  int indice = -1;

  fread(p, sizeof(struct dados), 1, pFile);
  while (!feof(pFile)) {
    if (p->nome != NULL) {
      indice++;
      for (j = 0; j < 21 && (nameText[j] != '\0' || p->nome[j] != '\0'); j++) {
        if (nameText[j] == p->nome[j]) {
          finded++;
        }

        else {
          finded = 0;
          break;
        }
      }

      if (finded != 0) {
        printf("\n\t%s - %s - %s - %s/%s/%s\n", p->nome, p->email, p->salario, p->dia, p->mes, p->ano);
        break;
      }
    }

    fread(p, sizeof(struct dados), 1, pFile);
  }

  if (finded == 0) {
    printf("\n\tNenhum registro foi encontrado.");
  }

  else {
    pFile = fopen(filename, "r+");

    cleanArrayChar(&p->nome, 21);
    cleanArrayChar(&p->email, 31);
    cleanArrayChar(&p->salario, 11);
    cleanArrayChar(&p->dia, 3);
    cleanArrayChar(&p->mes, 3);
    cleanArrayChar(&p->ano, 5);

    fseek(pFile, sizeof(struct dados) * indice, 0);
    fwrite(p, sizeof(struct dados), 1, pFile);
    fclose(pFile);

    printf("\nRegistro deletado!");
    printf("\n\nPressione qualquer coisa para voltar ao menu... ");
    getch();
  }

}

void main() {
  int option = 0;

  struct dados usuario;
  struct dados* p;
  p = &usuario;

  do {
    system("cls");
    printf("******************** \n");
    printf("**** Desafio 2  **** \n");
    printf("******************** \n");

    printf("\n(01) Inserir dados");
    printf("\n(02) Listar dados");
    printf("\n(03) Pesquisar um nome completo");
    printf("\n(04) Pesquisar por email");
    printf("\n(05) Pesquisar aniversariantes pelo mes");
    printf("\n(06) Pesquisar por faixa salarial");
    printf("\n(07) Alterar salario pesquisando pelo nome completo");
    printf("\n(08) Alterar dados pesquisando pelo nome completo");
    printf("\n(09) Exclui dados pesquisando pelo nome completo");
    printf("\n(10) Sair");
    printf("\n\n-> Digite sua acao: ");

    scanf("%i", &option);
    getchar();

    switch (option) {
      case 1:
        insert(&p);
        break;

      case 2:
        list(&p);
        break;

      case 3:
        searchName(&p);
        break;

      case 4:
        searchEmail(&p);
        break;

      case 5:
        searchBirthday(&p);
        break;

      case 6:
        searchSalary(&p);
        break;

      case 7:
        updateSalary(&p);
        break;

      case 8:
        updateRegister(&p);
        break;

      case 9:
        delete(&p);
        break;

      case 10:
      default:
        exit(0);
        break;
    }

    option = 0;

  } while (option == 0);
}


![Imagem do programa](./images/index.png)

# :page_with_curl: Desafio 1
Programa desafio da disciplina Linguagem de Programação I da Fatec Rubens Lara.

1) Pesquise as funções de biblioteca abaixo que manipulam arquivos.
- [X] fopen();
- [X] fclose();
- [X] fwrite();
- [X] fread();
- [X] fseek(); 
- [X] exit(0); 

2) Escreva um programa que tem 1 vetores bidimensional nome[3][20] e 1 vetores bidimensional email[3][30] declaradas como variáveis globais.

Na função main() faça um menu com as seguintes funções: 
- [X] Entrada de dados.
- [X] Lista todos os dados na tela.
- [X] Pesquisa um nome e mostra na tela
- [X] Pesquisa os nomes pela 1. letra e mostra todos na tela.
- [X] Altera dados.
- [X] Exclui dados.
- [X] Saída


# :page_with_curl: Desafio 2
Programa desafio da disciplina Linguagem de Programação I da Fatec Rubens Lara.

1) Escreva um programa que tem a estrutura de dados abaixo. O programa tem as seguintes opções de menu:

- [ ] 01 Entrada de dados
- [ ] 02 Listar dados na tela
- [ ] 03 Pesquisar um registro pelo nome completo
- [ ] 04 Pesquisar por email
- [ ] 05 Pesquisar os aniversariantes de um determinado mês
- [ ] 06 Pesquisar por faixa salarial
- [ ] 07 Alterar valor do salário, pesquisado pelo nome completo
- [ ] 08 Alterar dados, pesquisado pelo nome completo
- [ ] 09 Excluir dados, pesquisado pelo nome completo
- [ ] 10 Saída pelo usuário

**Observações**
- Estrutura: nome, email, data de nascimento, salário
- A única estrutura de dados do programa deve ser variável local na função main(). Portanto a passagem da estrutura para as funções utiliza ponteiro.
- Cada uma das opções do menu é uma função no programa.
- Todas as operações devem ser feitas direto no arquivo. (utilize a funcao fseek).
- O programa tem um único arquivo de dados. Não pode usar nenhum arquivo auxiliar.
- O programa deve ser finalizado pelo usuário.
- Não pode usar nenhuma função de biblioteca. Somente as funções de manipulação de arquivos

## :hammer: Instalação

````bash
# Clone este projeto
$ git clone https://github.com/rbmelolima/EmailList

# Compile o arquivo C que desejar
````


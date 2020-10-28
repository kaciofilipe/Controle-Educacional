/* Cabeçalho */
#ifndef TRABALHO_FINAL_H
#define TRABALHO_FINAL_H

/* A estrutura Emprestimo é uma fila para listar em ordem os pedidos de emprestimo com nome do livro e nome do aluno ou professor, com limite de 10 pedidos */
typedef struct emprestimo Emprestimo;

/* A estrutura Livro é uma lista duplamente encadeada que possui codigo do livro, nome, autor e sua propria fila de emprestimo */
typedef struct livro Livro;

/* A estrutura Aluno é uma lista encadeada que guarda informações do aluno */
typedef struct aluno Aluno;

/* A estrutura Professor é uma lista encadeada que guarda as informações do professor */
typedef struct professor Professor;

/* A estrutura NomeEmprestimo é uma estrutura do tipo TAD que guarda o nome do usuario na fila de emprestimo */
typedef struct nomeEmprestimo NomeEmprestimo;

/* As funções inicializaLivro(), inicializaAluno() e inicializaProfessor() iniciam as tres estrulturas (Livro, Aluno, Professor) com valor NULL */
Livro* inicializaLivro();
Aluno* inicializaAluno();
Professor* inicializaProfessor();

/* A função cria fila inicializa a fila */
Emprestimo* criaFila();

/* A função é responsavel por apagar a fila de emprestimo e reinicia-la */
Livro* limpaEmprestimo(Livro* l);

/* As funções vazia() serve para verificar se a fila de emprestimo está vazia */
int vazia(Emprestimo* e);

/* A função insereEmprestimo() serve para colocar na fila os dados do emprestimo */
Livro* insereEmprestimo(Livro* l, char* nome, char* autor, double cod, Emprestimo* e);

/* A função incr() serve apenas para acrescentar um à fila quando novo emprestimo for criado */
int incr(int i);

/* As funções completaEmprestimo(), insereFila() e retiraFila() servem para completar a aquisição dos dados dados aos dados da fila, confeirir se a capacidade da fila nao foi ultrapassada e retirar o primeiro dado da fila, consecutivamente */
Emprestimo* completaEmprestimo(Emprestimo* e, char* nomeL, char* nomeEmp);
Emprestimo* insereFila(Emprestimo* e, char* nomeEmp, char* nomeL);
Emprestimo* retiraFila(Emprestimo* e);

/* As funções existeAluno() e existeProf() verificam a existencia de um deles de acordo com o cpf */
int existeAluno(Aluno* a, double cpf);
int existeProf(Professor* p, double cpf);

/* As funções buscaAluno() e buscaProfessor() retornam o nome do aluno ou professor conforme o CPF informado */
char* buscaNomeAluno(Aluno* a, double cpf);
char* buscaNomeProf(Professor* p, double cpf);

/* As funções fazEmprestimo() e novoEmprestimo são responsaveis por recriar a lista de livros, agora com a nova fila do livro especificado e especificar o CPF do aluno ou professor e o codigo do livro, consecutivamente */
Livro* fazEmprestimo(char* nome, Livro* l, double cod, Emprestimo* e);
Livro* novoEmprestimo(Aluno* a, Professor* p, Livro* l);

/* A função fimEmprestimo() é responsavel por finalizar um emprestimo de um determinado livro */
Livro* fimEmprestimo(Livro* l);

/* As funções imprimeNomeFila() e imprimeLista(), consecutivamente, fazem a impressão de todos os nomes na fila e buscam o livro no qual deseja imprimir os nomes */
void imprimeNomeFila(Emprestimo* e);
void imprimeLista(Livro* l);

/* As funções emprestimos(), alunoGeral(), professorGeral() e livroGeral() são os menus de opções de cada ação que pode ser tomada pelo usuário */
Livro* emprestimos(Aluno* a, Professor* p, Livro* l);
Livro* livroGeral(Livro* l);
Aluno* alunoGeral(Aluno* a);
Professor* professorGeral(Professor* p);

/* As funções insereLivro(), insereAluno() e insereProfessor() são responsaveis por inserir as informações em suas conseguentes listas */
Livro* insereLivro(Livro* l, char* nome, char* autor, double cod);
Aluno* InsereAluno(Aluno* a, char* nome, double data, double cpf);
Professor* InsereProfessor(Professor* p, char* nome, char* materia, double data, double cpf);

/* As funções CriaProfessor(), CriaAluno() e CriaLivro() são responsaveis por ler do usuário as informações requeridas de cada estrutura */
Professor* CriaProfessor(Professor* p);
Aluno* CriaAluno(Aluno* a);
Livro* CriaLivro(Livro* l);

/* A função imprimeAlunos(), imprimeProfessores() e imprimeLivros() imprimem a lista com todos os alunos/professores/livros e suas informações */
void imprimeAlunos(Aluno* a);
void imprimeProfessores(Professor* p);
void imprimeLivros(Livro* l);

/* As funções consultarAluno() e consultarProfessor() trazem as informações destes a partir do CPF indicado e a função consultarLivro() traz as informações do livro determinado pelo codigo */
void consultarAluno(Aluno* a);
void consultarProfessor(Professor* p);
void consultarLivro(Livro* l);

/* As funções excluirProfessor() e excluirAluno() excluem o aluno ou professor requisitado pelo CPF informado e a função excluirLivro() exclui um livro de acordo com um determinado codigo */
Professor* excluirProfessor(Professor* p1);
Aluno* excluirAluno(Aluno* a);
Livro* excluirLivro(Livro* l);

/* A função menu() é responsavel por dar as opções ao usuario, sobre todo o modelo do projeto */
void menu(Aluno* Alunos, Professor* Professores, Livro* Livros);

#endif /* TRABALHO_FINAL_H */

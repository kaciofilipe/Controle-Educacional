#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trabalho_final.h"

struct nomeEmprestimo{
    char nome[100];
};

struct emprestimo{
    char nomeLivro[100];
    NomeEmprestimo nomeEmpres[10];
    int ini, fim;
};

struct livro{
    double Cod;
    char Nome[100];
    char Autor[100];
    Emprestimo* filaEmprestimo;
    struct livro* ant;
    struct livro* prox;
};

struct aluno{
    char Nome[100];
    double DataNascimento;
    double CpF;
    struct aluno* prox;
};

struct professor{
    char Nome[100];
    char Materia[100];
    double DataNascimento;
    double CpF;
    struct professor* prox;
};

Livro* inicializaLivro(){
    return NULL;
};

Aluno* inicializaAluno(){
    return NULL;
};

Professor* inicializaProfessor(){
    return NULL;
};

int vazia(Emprestimo* e){
    return (e->ini  == e->fim);
};

Livro* limpaEmprestimo(Livro* l){
    double cod;
    int i = 0;
    Livro* aux;
    Livro* l1;

    l1 = inicializaLivro();

    printf("\nDigite o codigo do livro que deseja esvaziar a lista de emprestimo\n");
    scanf("%lf", &cod);

    for(aux = l; aux != NULL; aux = aux->prox){
        if(aux->Cod == cod){
            i = 1;
        };
    };

    if(i == 0){
        printf("\nLivro nao existente\n");
        return l;
    };


    for(aux = l; aux != NULL; aux = aux->prox){
        if(aux->Cod == cod){
            aux->filaEmprestimo = criaFila();
        };
        l1 = insereEmprestimo(l1, aux->Nome, aux->Autor, aux->Cod, aux->filaEmprestimo);
    };
    printf("\nFila esvaziada\n");
    return l1;

};

Livro* insereEmprestimo(Livro* l, char* nome, char* autor, double cod, Emprestimo* e){
    Livro* novo = (Livro*) malloc(sizeof(Livro));
    strcpy(novo->Nome, nome);
    strcpy(novo->Autor, autor);
    novo->filaEmprestimo = e;
    novo->Cod = cod;
    novo->prox = l;
    novo->ant = NULL;
    if(l != NULL){
        l->ant = novo;
    };
    return novo;
};


Emprestimo* criaFila(){
    Emprestimo* e = (Emprestimo*) malloc(sizeof(Emprestimo));
    e->ini = e->fim = 0;
    return e;
};

int incr(int i){
    if(i == 9){
	return 0;
    }else{
	return i+1;
    };
};

Emprestimo* completaEmprestimo(Emprestimo* e, char* nomeL, char* nomeEmp){
    strcpy(e->nomeEmpres[e->fim].nome, nomeEmp);
    strcpy(e->nomeLivro, nomeL);
    e->fim = incr(e->fim);
    return e;
};

Emprestimo* insereFila(Emprestimo* e, char* nomeEmp, char* nomeL){
    if(incr(e->fim) == 0){
	printf("\nCapacidade da fila estoutou\n");
	return e;
    };
    e = completaEmprestimo(e, nomeL, nomeEmp);
    printf("\nEmprestimo colocado na fila\n");
    return e;
};

Emprestimo* retiraFila(Emprestimo* e){
    if(vazia(e)){
	printf("\nFila vazia\n");
	return e;
    };

    e->ini = incr(e->ini);
    return e;
};

int existeAluno(Aluno* a, double cpf){
    Aluno* aux;

    for(aux = a; aux != NULL; aux = aux->prox){
        if(aux->CpF == cpf){
	    return 1;
        }else{
	    return 0;
	};
    };
};

int existeProf(Professor* p, double cpf){
    Professor* aux;

    for(aux = p; aux != NULL; aux = aux->prox){
        if(aux->CpF == cpf){
	    return 1;
        }else{
            return 0;
        };
    };
};

char* buscaNomeAluno(Aluno* a, double cpf){
    Aluno* aux;

    for(aux = a; aux != NULL; aux = aux->prox){
        if(aux->CpF == cpf){
            return aux->Nome;
        };
    };
};

char* buscaNomeProf(Professor* p, double cpf){
    Professor* aux;

    for(aux = p; aux != NULL; aux = aux->prox){
        if(aux->CpF == cpf){
            return aux->Nome;
        };
    };
};


Livro* fazEmprestimo(char* nome, Livro* l, double cod, Emprestimo* e){
    Livro* l1;
    Livro* aux;

    l1 = inicializaLivro();

    for(aux = l; aux != NULL; aux = aux->prox){
        if(aux->Cod == cod){
            aux->filaEmprestimo = insereFila(e, nome, aux->Nome);
        };
	l1 = insereEmprestimo(l1, aux->Nome, aux->Autor, aux->Cod, aux->filaEmprestimo);
    };
    return l1;
};

Livro* novoEmprestimo(Aluno* a, Professor* p, Livro* l){
    double cpf, cod;
    char nomeAluno[100], nomeProf[100];
    Emprestimo* e;
    Livro* aux;
    int i = 0, Aluno, Prof;

    printf("\nDigite o CPF do aluno/professor que deseja entrar na fila de emprestimo:\n");
    scanf("%lf", &cpf);
    printf("\nDigite o codigo do livro a ser emprestado:\n");
    scanf("%lf", &cod);

    for(aux = l; aux != NULL; aux = aux->prox){
        if(aux->Cod == cod){
            i = 1;
        };
    };

    if(i == 0){
	printf("\nLivro nao existente\n");
	return l;
    };

    for(aux = l; aux != NULL; aux = aux->prox){
        if(aux->Cod == cod){
            e = aux->filaEmprestimo;
        };
    };

    Aluno = existeAluno(a, cpf);
    Prof = existeProf(p, cpf);

    if(Aluno != 0){
	strcpy(nomeAluno, buscaNomeAluno(a, cpf));
	l = fazEmprestimo(nomeAluno, l, cod, e);
	return l;
    };

    if(Prof != 0){
	strcpy(nomeProf, buscaNomeProf(p, cpf));
	l = fazEmprestimo(nomeProf, l, cod, e);
	return l;
    };

    printf("\nAluno ou professor nao existente\n");
    return l;
};

Livro* fimEmprestimo(Livro* l){
    double cod;
    Livro* aux;
    Livro* l1;
    int i = 0;
    Emprestimo* e;

    l1 = inicializaLivro();

    printf("\nDigite o codigo do livro no qual sera finalizado seu primeiro emprestimo:\n");
    scanf("%lf", &cod);

    for(aux = l; aux != NULL; aux = aux->prox){
        if(aux->Cod == cod){
            i = 1;
        };
    };

    if(i == 0){
        printf("\nLivro nao existente\n");
        return l;
    };

    for(aux = l; aux != NULL; aux = aux->prox){
        if(aux->Cod == cod){
            e = aux->filaEmprestimo;
        };
    };

    if(vazia(e)){
        printf("\nFila de emprestimo vazia\n");
        return l;
    }

    for(aux = l; aux != NULL; aux = aux->prox){
        if(aux->Cod == cod){
            aux->filaEmprestimo = retiraFila(aux->filaEmprestimo);
        };
	l1 = insereEmprestimo(l1, aux->Nome, aux->Autor, aux->Cod, aux->filaEmprestimo);
    };
    printf("\nEmprestimo finalizado\n");
    return l1;
};

void imprimeNomeFila(Emprestimo* e){
    int i, j = 1;

    printf("\nLista de espera do livro %s:\n", e->nomeLivro);

    for(i = e->ini; i != e->fim; i++){
	printf("%d: %s\n", j, e->nomeEmpres[i].nome);
	j++;
    }
}

void imprimeLista(Livro* l){
    double cod;
    int i = 0;
    Emprestimo* e;
    Livro* aux;

    printf("\nDigite o codigo do livro que deseja ver a fila de espera para emprestimos:\n");
    scanf("%lf", &cod);

    for(aux = l; aux != NULL; aux = aux->prox){
        if(aux->Cod == cod){
            i = 1;
        };
    };

    if(i == 0){
        printf("\nLivro nao existente\n");
        return;
    };

    for(aux = l; aux != NULL; aux = aux->prox){
        if(aux->Cod == cod){
            e = aux->filaEmprestimo;
        };
    };

    if(vazia(e)){
	printf("\nFila de emprestimo vazia\n");
	return;
    }

    imprimeNomeFila(e);
};

Livro* emprestimos(Aluno* a, Professor* p, Livro* l){
    int opcao;

    printf("\nMenu de emprestimos\nEscolha o que deseja fazer:\n1: Fazer um novo emprestimo\n2: Finalizar o emprestimo de um livro\n3: Ver lista de emprestimos\n4: Limpar fila de emprestimo\n5: Voltar ao menu principal\n");
    scanf("%d", &opcao);

    switch(opcao){
	case 1:
	    l = novoEmprestimo(a, p, l);
	    l = emprestimos(a, p, l);
	    return l;
	    break;

	case 2:
	    l = fimEmprestimo(l);
	    l = emprestimos(a, p, l);
	    return l;
	    break;

	case 3:
	    imprimeLista(l);
	    l = emprestimos(a, p, l);
	    return l;
	    break;

	case 4:
	    l = limpaEmprestimo(l);
	    return l;
	    break;

	default:
	    return l;
	    break;
    };
};

Livro* insereLivro(Livro* l, char* nome, char* autor, double cod){
    Livro* novo = (Livro*) malloc(sizeof(Livro));
    strcpy(novo->Nome, nome);
    strcpy(novo->Autor, autor);
    novo->filaEmprestimo = criaFila();
    novo->Cod = cod;
    novo->prox = l;
    novo->ant = NULL;
    if(l != NULL){
        l->ant = novo;
    };
    return novo;
};

Aluno* InsereAluno(Aluno* a, char* nome, double data, double cpf){
    Aluno* novo = (Aluno*) malloc(sizeof(Aluno));
    strcpy(novo->Nome, nome);
    novo->DataNascimento = data;
    novo->CpF = cpf;
    novo->prox = a;
    return novo;
};

Professor* InsereProfessor(Professor* p, char* nome, char* materia, double data, double cpf){
    Professor* novo = (Professor*) malloc(sizeof(Professor));
    strcpy(novo->Nome, nome);
    strcpy(novo->Materia, materia);
    novo->DataNascimento = data;
    novo->CpF = cpf;
    novo->prox = p;
    return novo;
};

Professor* CriaProfessor(Professor* p){
    char nome[100];
    char materia[100];
    double data;
    double cpf;

    printf("\nInsira os dados do professor\nNome:\n");
    setbuf(stdin, NULL);
    gets(nome);
    printf("Data de nascimento (sem barras):\n");
    scanf("%lf", &data);
    printf("Materia lecionada:\n");
    setbuf(stdin, NULL);
    gets(materia);
    printf("CPF:\n");
    scanf("%lf", &cpf);

    return InsereProfessor(p, nome, materia, data, cpf);
};

Aluno* CriaAluno(Aluno* a){
    char nome[100];
    double data;
    double cpf;

    printf("\nInsira os dados do aluno\nNome:\n");
    setbuf(stdin, NULL);
    gets(nome);
    printf("Data de nascimento (sem barras):\n");
    scanf("%lf", &data);
    printf("CPF:\n");
    scanf("%lf", &cpf);

    return InsereAluno(a, nome, data, cpf);
};

Livro* CriaLivro(Livro* l){
    char nome[100];
    char autor[100];
    double cod;

    printf("\nInsira os dados do livro\nNome:\n");
    setbuf(stdin, NULL);
    gets(nome);
    printf("Autor:\n");
    setbuf(stdin, NULL);
    gets(autor);
    printf("Codigo do livro:\n");
    scanf("%lf", &cod);

    return insereLivro(l, nome, autor, cod);
};

void imprimeAlunos(Aluno* a){
    Aluno* aux;
    int i = 1;

    printf("\nDados de todos os alunos:\n");

    for(aux = a; aux != NULL; aux = aux->prox){
	printf("\n%d:\n", i);
        printf("Nome: %s\n", aux->Nome);
        printf("Data de nascimento: %lf\n", aux->DataNascimento);
        printf("CPF: %lf\n", aux->CpF);
	i++;
    };
};

void imprimeProfessores(Professor* p){
    Professor* aux;
    int i = 1;

    printf("\nDados de todos os alunos:\n");

    for(aux = p; aux != NULL; aux = aux->prox){
        printf("\n%d:\n", i);
        printf("Nome: %s\n", aux->Nome);
        printf("Data de nascimento: %lf\n", aux->DataNascimento);
        printf("CPF: %lf\n", aux->CpF);
	printf("Materia lecionada: %s\n", aux->Materia);
        i++;
    };
};

void imprimeLivros(Livro* l){
    Livro* aux;
    int i = 1;

    printf("\nDados de todos os livros:\n");

    for(aux = l; aux != NULL; aux = aux->prox){
        printf("\n%d:\n", i);
        printf("Nome do livro: %s\n", aux->Nome);
        printf("Nome do autor: %s\n", aux->Autor);
        printf("Codigo: %lf\n", aux->Cod);
        i++;
    };
};

void consultarAluno(Aluno* a){
    Aluno* aux;
    double cpf;

    printf("\nDigite o cpf do aluno para consulta:\n");
    scanf("%lf", &cpf);

    for(aux = a; aux != NULL; aux = aux->prox){
	if(aux->CpF == cpf){
            printf("\nDados:\nNome: %s\n", aux->Nome);
            printf("Data de nascimento: %lf\n", aux->DataNascimento);
            printf("CPF: %lf\n", aux->CpF);
	    return;
	};
    };
    printf("Aluno não cadastrado\n");
};

Aluno* excluirAluno(Aluno* a){
    Aluno* ant = NULL;
    Aluno* p = a;
    double cpf;

    printf("\nDigite o CPF do aluno a ser excluido:\n");
    scanf("%lf", &cpf);

    while(p != NULL && p->CpF != cpf){
	ant = p;
	p = p->prox;
    };

    if(p == NULL){
	printf("\nAluno nao cadastrado\n");
	return a;
    };

    if(ant == NULL){
	a = p->prox;
    }else{
	ant->prox = p->prox;
    };
    free(p);
    printf("\nAluno excluido\n");
    return a;
};

void consultarProfessor(Professor* p){
    Professor* aux;
    double cpf;

    printf("\nDigite o cpf do professor para consulta:\n");
    scanf("%lf", &cpf);

    for(aux = p; aux != NULL; aux = aux->prox){
        if(aux->CpF == cpf){
            printf("\nDados:\nNome: %s\n", aux->Nome);
	    printf("Materia lecionada: %s", aux->Materia);
            printf("Data de nascimento: %lf\n", aux->DataNascimento);
            printf("CPF: %lf\n", aux->CpF);
            return;
        };
    };
    printf("Professor não cadastrado\n");
};

Professor* excluirProfessor(Professor* p1){
    Professor* ant = NULL;
    Professor* p = p1;
    double cpf;

    printf("\nDigite o CPF do professor a ser excluido:\n");
    scanf("%lf", &cpf);

    while(p != NULL && p->CpF != cpf){
        ant = p;
        p = p->prox;
    };

    if(p == NULL){
	printf("\nProfessor nao cadastrado\n");
        return p1;
    };

    if(ant == NULL){
        p1 = p->prox;
    }else{
        ant->prox = p->prox;
    };
    free(p);
    printf("\nProfessor excluido\n");
    return p1;
};


Aluno* alunoGeral(Aluno* a){
    int opcao;
    printf("\nMenu de alunos\nEscolha o que deseja fazer:\n1: Cadastrar\n2: Consultar\n3: Excluir\n4: Ver lista completa\n5: Voltar ao menu principal\n");
    scanf("%d", &opcao);

    switch(opcao){
	case 1:
	    a = CriaAluno(a);
	    a = alunoGeral(a);
	    return a;
	    break;

	case 2:
	    consultarAluno(a);
	    a = alunoGeral(a);
	    return a;
	    break;

	case 3:
	    a = excluirAluno(a);
	    a = alunoGeral(a);
	    return a;
	    break;

	case 4:
	    imprimeAlunos(a);
            a = alunoGeral(a);
	    return a;
	    break;

	default:
	    return a;
	    break;
    };
};

Professor* professorGeral(Professor* p){
    int opcao;
    printf("\nMenu de professores\nEscolha o que deseja fazer:\n1: Cadastrar\n2: Consultar\n3: Excluir\n4: Ver lista completa\n5: Voltar ao menu principal\n");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
            p = CriaProfessor(p);
            p = professorGeral(p);
            return p;
            break;

        case 2:
            consultarProfessor(p);
            p = professorGeral(p);
            return p;
            break;

        case 3:
            p = excluirProfessor(p);
            p = professorGeral(p);
            return p;
            break;

        case 4:
	    imprimeProfessores(p);
            p = professorGeral(p);
            return p;
            break;

        default:
            return p;
            break;
    };
};

void consultarLivro(Livro* l){
    Livro* aux;
    double cod;

    printf("\nDigite o codigo do livro para consulta:\n");
    scanf("%lf", &cod);

    for(aux = l; aux != NULL; aux = aux->prox){
        if(aux->Cod == cod){
            printf("\nDados:\nNome: %s\n", aux->Nome);
            printf("Autor: %s", aux->Autor);
            printf("Codigo: %lf\n", aux->Cod);
            return;
        };
    };
    printf("Livro não cadastrado\n");
};

Livro* excluirLivro(Livro* l){
    Livro* ant = NULL;
    Livro* p = l;
    double cod;

    printf("\nDigite o codigo do livro a ser excluido:\n");
    scanf("%lf", &cod);

    while(p != NULL && p->Cod != cod){
        ant = p;
        p = p->prox;
    };

    if(p == NULL){
        return l;
	printf("\nLivro nao cadastrado\n");
    };

    if(ant == NULL){
        l = p->prox;
    }else{
        ant->prox = p->prox;
    };
    free(p);
    printf("\nLivro excluido\n");
    return l;
};


Livro* livroGeral(Livro* l){
    int opcao;
    printf("\nMenu de livros\nEscolha o que deseja fazer:\n1: Cadastrar\n2: Consultar\n3: Excluir\n4: Ver lista completa\n5: Voltar ao menu principal\n");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
            l = CriaLivro(l);
            l = livroGeral(l);
            return l;
            break;

        case 2:
            consultarLivro(l);
            l = livroGeral(l);
            return l;
            break;

        case 3:
            l = excluirLivro(l);
            l = livroGeral(l);
            return l;
            break;

        case 4:
	    imprimeLivros(l);
            l = livroGeral(l);
            return l;
            break;

        default:
            return l;
            break;
    };

};

void menu(Aluno* Alunos, Professor* Professores, Livro* Livros){
    int opcao;
    printf("\nMenu principal\nEscolha a opção que deseja:\n1: Cadastrar, consultar ou excluir um aluno\n2: Cadastrar, consultar ou excluir um professor\n3: Cadastrar, consultar ou excluir um livro\n4: Gerenciamento de emprestimos de livros\n5: Finalizar o programa\n");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
	    Alunos = alunoGeral(Alunos);
	    menu(Alunos, Professores, Livros);
	    break;

	case 2:
	    Professores = professorGeral(Professores);
	    menu(Alunos, Professores, Livros);
	    break;

	case 3:
	    Livros = livroGeral(Livros);
	    menu(Alunos, Professores, Livros);
	    break;

	case 4:
	    Livros = emprestimos(Alunos, Professores, Livros);
	    menu(Alunos, Professores, Livros);
	    break;

	case 5:
	    break;

	default:
	    menu(Alunos, Professores, Livros);
	    break;
    };
};

void main(){
    Aluno* Alunos;
    Livro* Livros;
    Professor* Professores;

    Alunos = inicializaAluno();
    Professores = inicializaProfessor();
    Livros = inicializaLivro();

    printf("\nBem vindo ao nosso Sistema Educacional\nPara começarmos precisamos cadastrar um aluno, um professor, e um livro\nVamos começar pela inserção de um aluno\n");
    Alunos = CriaAluno(Alunos);
    printf("\nAgora vamos inserir um professor\n");
    Professores = CriaProfessor(Professores);
    printf("\nPor fim, vamos inserir um livro\n");
    Livros = CriaLivro(Livros);

    menu(Alunos, Professores, Livros);
};

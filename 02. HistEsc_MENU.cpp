/*###########################################################################################################
    Exercício 1:
    Autora: Emilayne Rodrigues

     Alterar o exemplo HistCoR2017.cpp para torná-lo um minisistema de Boletim, onde deve ter como menu
     principal as seguintes opções: 1- Inserir; 2 - Atualizar; 3 - Excluir; 4 - Pesquisar; 5 - Listar;
     0 - Sair. Cada opção do menu de 1 a 5 deve levar a uma nova tela para se trabalhar cada finalidade
     a que se propõe. O minisistema deve ser todo modular, ou seja, com funções diretas ou auxiliares
     para cada finalidade. Fique a vontadade para incrementar seu minisistema.
###########################################################################################################*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <iomanip>
#include <string.h>

#define tamMAX 5
using namespace std;

//***************** STRUCT E DECLARAÇÃO GLOBAL DE VARIAVEIS ********************//
//definição da estrutura de um registro
typedef struct {
    char	  disciplina[50], nome[50], sexo, situacao;
    float     notaBim[4], mediaFinal;
    int	      ano, faltas, CH, ativo;
} HistoricoEscolar;

HistoricoEscolar Aluno[tamMAX]; // chamada global da struct
int cont; //veriavel global

//********************************** ESTILO ************************************//
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y){
  CursorPosition.X = x; // Locates column
  CursorPosition.Y = y; // Locates Row
  SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed
}

void escreveLinha(int x){
    for(int i = 0; i < x; i++){
        cout << "+";
    }
}

void escreveSeparacao(int x){
     for(int i = 0; i < x; i++){
        cout << "-";
    }
}

//**************************** CHAMADA DA FUNÇOES *******************************//
void inserir();
void atualizar();
void excluir();
void pesquisar();
void listar();

//**************************** FUNÇÕES AUXILIARES ******************************//
//---- FUNÇÃO PARA BUSCAR ALUNO ----//
void buscarAluno(char* nomeAluno){
    int verificador = -1, condi = 0;

        system("cls");
        escreveLinha(53);
        cout << "FICHA DO ALUNO";
        escreveLinha(52);
        cout << "\n";
        escreveSeparacao(120);
        cout << "\n ANO   NOME        SEXO     DISCIPLINA     CH     BIM-1     BIM-2     BIM-3     BIM-4     MEDIA     FALTAS     SITUAÇÃO\n";            escreveSeparacao(120);
        cout << "\n\n";

        for (int i = 0; i < cont; i++){
            if (strcasecmp(nomeAluno, Aluno[i].nome) == 0){
                    gotoxy(1, 4+i);
                    cout << Aluno[i].ano;
                    gotoxy(7, 4+i);
                    cout << Aluno[i].nome;
                    gotoxy(20, 4+i);
                    cout << Aluno[i].sexo;
                    gotoxy(28, 4+i);
                    cout << Aluno[i].disciplina;
                    gotoxy(43, 4+i);
                    cout << Aluno[i].CH;
                    cout << fixed << setprecision(2);
                    gotoxy(50, 4+i);
                    cout << Aluno[i].notaBim[0];
                    gotoxy(60, 4+i);
                    cout << Aluno[i].notaBim[1];
                    gotoxy(70, 4+i);
                    cout << Aluno[i].notaBim[2];
                    gotoxy(80, 4+i);
                    cout << Aluno[i].notaBim[3];
                    gotoxy(90, 4+i);
                    cout << Aluno[i].mediaFinal;
                    gotoxy(102, 4+i);
                    cout << Aluno[i].faltas;
                    gotoxy(111, 4+i);
                    if(Aluno[i].situacao == 'A'){
                        cout << "APROVADO\n";
                    }else{
                        cout << "REPROVADO\n";
                    }

                    verificador = 1;
            }
        }
        escreveSeparacao(120);
        if (verificador == -1){
            system("cls");
            cout << "\n\nALUNO NÃO ENCONTRADO!\n\n";
        }

}

// ---- CONVERSÃO DE LETRAS MINUSCULAS P/ MAIUSCULAS ---- //
void maiuscula(char* palavra){
    int tamString;

    tamString = strlen (palavra);
        for (int i = 0; i < tamString; i++){
                palavra[i] = toupper(palavra[i]);
        }

}

// ---- CALCULO DE MEDIA ---- //
float mediaAluno(float n1, float n2, float n3, float n4){
    float media;

    return media = (n1+n2+n3+n4)/4;
}

// ---- VERIFICAÇÃO DA SITUAÇÃO DO ALUNO ---- //
char situacaoAluno(float media, int faltas, int ch){
    char situacao;
        if(media >= 5 && faltas <=(ch-(ch * 70/100))){
            return situacao = 'A';
        }else{
            return situacao = 'R';
        }
    return 0;
}

//*********************************** MENU *************************************//
void menu(){
    int op;
        do{
            system("cls");
            cout << "\n[1] - Inserir";
            cout << "\n[2] - Atualizar";
            cout << "\n[3] - Excluir";
            cout << "\n[4] - Pesquisar";
            cout << "\n[5] - Listar";

            cout << "\n[0] - Sair";

            cout << "\n\nOpção: ";
            cin >> op;
            fflush(stdin);

            switch(op){
                case 1: // OPÇÃO INSERIR
                    inserir();
                    break;
                case 2:
                    atualizar();
                    break;
                case 3:
                    excluir();
                    break;
                case 4:
                    pesquisar();
                    break;
                case 5: //OPÇÃO LISTAR
                    listar();
                    break;
                default:
                    system("cls");
                    cout << "\n\n\tSaindo...";
                    break;
        }
        }while(op!=0);
}

//************************* OPÇÃO 1 - INSERIR DO MENU **************************//
void inserir(){
    int op, tamString;
    do{
        system("cls");
        escreveLinha(51);
        cout << " HISTORICO ESCOLAR ";
        escreveLinha(50);
            if(cont >= tamMAX){
                cout << "\n\n\tMemória cheia!\n\n";
                escreveSeparacao(120);
            }else{
                cout << "\n\n\tInforme os dados da ficha do aluno(a): ";
                fflush(stdin);
                cout << "\n\n\t\tNome: ";
                gets(Aluno[cont].nome);
                cout << "\t\tSexo (F ou M): ";
                cin >> Aluno[cont].sexo;
                cout << "\t\tDisciplina: ";
                fflush(stdin);
                gets(Aluno[cont].disciplina);
                cout << "\t\tCarga horária: ";
                cin >> Aluno[cont].CH;
                cout << "\t\tAno: ";
                cin >> Aluno[cont].ano;
                cout << "\n\t\tNotas bimestrais: ";
                cout << "\n\t\t  - Primeiro bimestre: ";
                cin >> Aluno[cont].notaBim[0];
                cout << "\t\t  - Segundo bimestre: ";
                cin >> Aluno[cont].notaBim[1];
                cout << "\t\t  - Terceiro bimestre: ";
                cin >> Aluno[cont].notaBim[2];
                cout << "\t\t  - Quarto bimestre: ";
                cin >> Aluno[cont].notaBim[3];
                cout << "\n\t\tFaltas: ";
                cin >> Aluno[cont].faltas;
                fflush(stdin);
                escreveSeparacao(120);

                // ----------------------------- CALCULO DA MEDIA E VERIFICAÇÃO DE APROVAÇÃO ----------------------------

                Aluno[cont].mediaFinal = mediaAluno(Aluno[cont].notaBim[0],Aluno[cont].notaBim[1],Aluno[cont].notaBim[2],Aluno[cont].notaBim[3]);

                Aluno[cont].situacao = situacaoAluno(Aluno[cont].mediaFinal, Aluno[cont].faltas, Aluno[cont].CH);

                //----------------------------------- CONVERSÃO DE STRING P/ MAIUSCULA ----------------------------------

                maiuscula(Aluno[cont].nome);
                maiuscula(Aluno[cont].disciplina);
                Aluno[cont].sexo = toupper(Aluno[cont].sexo);


                cont++;
                }


        cout << "\n\n\t[0] - Voltar";
        cout << "\n\n\tOpção: ";
        cin >> op;
    }while(op!=0);
}

//************************* OPÇÃO 2 - ATUALIZAR DO MENU ************************//
void atualizar(){
    int op, ch, faltas, ano;
    char nomeAluno[50], disciplina[50], sexo;

    float notaBIM[4];

    system("cls");
    escreveLinha(51);
    cout << " ATUALIZAR ALUNO "; //17
    escreveLinha(50);
    cout << "\n\n\tNome: ";
    gets (nomeAluno);

    do{
        buscarAluno(nomeAluno);

            for(int i = 0; i < cont; i++){
                if(strcasecmp(nomeAluno, Aluno[i].nome) == 0){
                    cout << "\n\n\tAtualizar ficha de aluno?\n\n\t   [1] - SIM\n\t   [2] - NÃO\n\n\tOpção: ";
                    cin >> op;
                    if(op == 1){
                        system("cls");
                        escreveLinha(51);
                        cout << " ATUALIZAR ALUNO "; //17
                        escreveLinha(50);
                        cout << "\n\n\tAluno a ser atualizado: \n";
                        cout << "\n\t\tNome: " << Aluno[i].nome;
                        cout << "\n\t\tSexo: " << Aluno[i].sexo;
                        cout << "\n\n";
                        escreveSeparacao(120);
                        cout << "\n\n\tInforme os novos dados: ";
                        cout << "\n\n\t\tNome: ";
                        fflush(stdin);
                        gets(nomeAluno);
                        cout << "\t\tSexo: ";
                        cin >> sexo;
                        cout << "\t\tDisciplina: ";
                        fflush(stdin);
                        gets(disciplina);
                        cout << "\t\tCarga horária: ";
                        cin >> ch;
                        cout <<"\t\tAno: ";
                        cin >> ano;
                        cout << "\t\tNotas bimestrais";
                        cout << "\n\t\t   - Primeiro bimestre: ";
                        cin >> notaBIM[0];
                        cout << "\t\t   - Segundo bimestre: ";
                        cin >> notaBIM[1];
                        cout << "\t\t   - Terceiro bimestre: ";
                        cin >> notaBIM[2];
                        cout << "\t\t   - Quarto bimestre: ";
                        cin >> notaBIM[3];
                        cout << "\t\tFaltas: ";
                        cin >> faltas;
                        cout << "\n";
                        escreveSeparacao(120);
                        //********************** NOVOS DADOS DO ALUNO ******************//
                        for(int j = i; j < i+1; j++){
                            memcpy(Aluno[j].nome, nomeAluno, sizeof(Aluno[j].nome));
                            Aluno[j].sexo = sexo;
                            memcpy(Aluno[j].disciplina, disciplina, sizeof(Aluno[j].disciplina));
                            Aluno[j].CH = ch;
                            Aluno[j].ano = ano;
                            Aluno[j]. notaBim[0] = notaBIM[0];
                            Aluno[j]. notaBim[1] = notaBIM[1];
                            Aluno[j]. notaBim[2] = notaBIM[2];
                            Aluno[j]. notaBim[3] = notaBIM[3];
                            Aluno[j]. faltas = faltas;

                            Aluno[j].mediaFinal = mediaAluno(Aluno[j].notaBim[0],Aluno[j].notaBim[1],Aluno[j].notaBim[2],Aluno[j].notaBim[3]);
                            Aluno[j].situacao = situacaoAluno(Aluno[j].mediaFinal, Aluno[j].faltas, Aluno[j].CH);
                        }

                        maiuscula(Aluno[i].nome);
                        maiuscula(Aluno[i].disciplina);
                        Aluno[i].sexo = toupper(Aluno[i].sexo);

                    }
                }
            }



        cout << "\n\t[0] - VOLTAR";
        cout << "\n\n\tOpção: ";
        cin >> op;
    }while(op!=0);

}

//************************* OPÇÃO 3 - EXCLUIR DO MENU **************************//
void excluir(){
    int op;
    char nomeAluno[50];

        system("cls");
        escreveLinha(53);
        cout << " EXCLUIR ALUNO ";
        escreveLinha(52);
        cout << "\n\n\tNome: ";
        gets (nomeAluno);
        do{
            buscarAluno(nomeAluno);

            for(int i = 0; i < cont; i++){
                if(strcasecmp(nomeAluno, Aluno[i].nome) == 0){
                    cout << "\n\n\tExcluir aluno?\n\n\t   [1] - SIM\n\t   [2] - NÃO\n\n\tOpção: ";
                    cin >> op;
                    if(op == 1){
                     //processo de exclusão
                        //cout << "\n\nENTREI PARA EXCLUIR!";
                        if (i == (cont - 1)){
                        /*
                            o i foi incrementado por todos os alunos que foram inseridos
                            acontecerá o decremento de cont - 1 porque temos que pensar que, por exemplo;
                            se foram inseridos 4 alunos -- o cont será incremento 4 vezes e valerá 4, no enquanto
                            i começa sua contagem no 0 -- se eu quero encontrar o ultimo e sei que o cont vale
                            e a posição que quero encontrar esta no i = 3, eu preciso decrementar cont, por isso cont - 1
                        */
                        //ou é o ultimo elemento ou é o unico
                        //primeira estrategia
                            //cout << "\n\nÉ O ULTIMO ELEMENTO! TO NA PRIMEIRA ESTRATEGIA!!!";
                            cont--;
                        }else{
                        //segunda estrategia
                        //FILA ANDANDO
                            for(int j = i; j < cont; j++){
                                /*
                                    é igual a i porque i é o indice da posição que é preciso comecar a operação
                                    i é o elemento encontrado
                                */
                                Aluno[j] = Aluno[j+1];
                                /*
                                    j = i -- que é o elemento que quero excluir na posição i;
                                    então Aluno[j] = Aluno [j+1]

                                    exemplo:
                                    i [0] - ANA
                                    i [1] - EMI

                                    quero excluir ANA, então:
                                        j = i -- onde i é 0, então:
                                            Aluno[0] = Aluno [0+1];
                                            Aluno [0] = Aluno [1];
                                                isto é o elemento de i [1], foi pra posição i [0];
                                                e o que estava nesta posição foi automaticamente para proxima i [1];
                                */
                            }
                            cont--;
                            /*
                                i [1] foi decrementado, ou seja, apagado;
                            */
                        }
                        system("cls");
                        cout << "\n\tAluno excluído com sucesso!";
                    }
                }
            }

            cout << "\n\n";
            escreveSeparacao(120);
            cout << "\n\t[0] - VOLTAR";
            cout << "\n\n\tOpção: ";
            cin >> op;
        }while(op!=0);
}

//************************ OPÇÃO 4 - PESQUISAR DO MENU *************************//
void pesquisar(){
int op;
char nomeAluno[50];
    do{
        system("cls");
        escreveLinha(51);
        cout << " PESQUISA DE ALUNO ";
        escreveLinha(50);
        cout << "\n\n\tNome: ";
        gets (nomeAluno);

        buscarAluno(nomeAluno);

        cout << "\n\t[0] - VOLTAR";
        cout << "\n\n\tOpção: ";
        cin >> op;
    }while(op!=0);

}

//************************* OPÇÃO 5 - LISTAR DO MENU ***************************//
void listar(){
    int op;
    do{
        system("cls");
        escreveLinha(52);
        cout << " LISTA DE ALUNOS ";
        escreveLinha(51);
        cout << "\n";
        escreveSeparacao(120);
        cout << "\n ANO   NOME        SEXO     DISCIPLINA     CH     BIM-1     BIM-2     BIM-3     BIM-4     MEDIA     FALTAS     SITUAÇÃO\n";
        escreveSeparacao(120);
        cout << "\n\n";
        for(int i = 0; i < cont; i++){
            gotoxy(1, 4+i);
            cout << Aluno[i].ano;
            gotoxy(7, 4+i);
            cout << Aluno[i].nome;
            gotoxy(20, 4+i);
            cout << Aluno[i].sexo;
            gotoxy(28, 4+i);
            cout << Aluno[i].disciplina;
            gotoxy(43, 4+i);
            cout << Aluno[i].CH;
            cout << fixed << setprecision(2);
            gotoxy(50, 4+i);
            cout << Aluno[i].notaBim[0];
            gotoxy(60, 4+i);
            cout << Aluno[i].notaBim[1];
            gotoxy(70, 4+i);
            cout << Aluno[i].notaBim[2];
            gotoxy(80, 4+i);
            cout << Aluno[i].notaBim[3];
            gotoxy(90, 4+i);
            cout << Aluno[i].mediaFinal;
            gotoxy(102, 4+i);
            cout << Aluno[i].faltas;
            gotoxy(111, 4+i);
            if(Aluno[i].situacao == 'A'){
                cout << "APROVADO\n";
            }else{
                cout << "REPROVADO\n";
            }
        }

        escreveSeparacao(120);
        cout << "\n[0] - Voltar";
        cout << "\n\nOpção: ";
        cin >> op;
    }while(op!=0);

}

//************************************ MAIN ************************************//
int main(){

    setlocale(LC_ALL, "portuguese");
    menu();

    cout << "\n\n";
    system("pause");
    return 0;
}

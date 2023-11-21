#ifndef _Applications
#define _Applications
#include <iostream>
#include <string>
#include "Pessoa.h"

using namespace std;

class Applications{
  public:
  Applications();
  void busca(double ano, Pessoa **P,int cont); 
  string codifica(string nome,int cont);
  Pessoa *busca_nome(string nome, Pessoa **P,int cont);
  void Imprime_Codificacao( Pessoa *P, int cont, string nome );
  float media_anual ( int ano, int cont, Pessoa **P);
  void aluno_menor_bolsa(Pessoa **P,int cont);
  void aluno_maior_bolsa(Pessoa **P,int cont);
  void imprime_alunos(Pessoa **P,int i);
};

#endif;
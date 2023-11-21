#include "Applications.h"
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <limits.h>
#include <map>
#include <memory>
#define MAX 100000
using namespace std;

Applications::Applications(){}

void Applications::busca(double ano, Pessoa **P,int cont){
  for(int i=0;i<cont-1;i++){
    if( ano == P[i]->getAN_ref()) {
      cout <<"Nome:"<<P[i]->getNome()<< endl;
      cout <<"CPF:" <<P[i]->getCPF()<<endl;
      cout <<"Entidade de Ensino:" <<P[i]->getEntidade_ensino()<<endl;
      cout <<"Valor da Bolsa:" <<P[i]->getVL_bolsista()<<endl;
      break;
    }
  }
  cout<< "Não foi encontrado nenhum resultado no ano:" << ano << endl;
}

Pessoa* Applications::busca_nome(string nome, Pessoa **P, int cont){
  string aux;
  Pessoa *P_aux;
  int found=0,i;
    for(i=0;i<cont-1;i++){
      found = P[i]->getNome().find(nome);
      if( found >= 0)break;
    }
  if (found == -1)P_aux = nullptr;
  else P_aux = P[i];
  return P_aux;
}

string Applications::codifica(string nome,int cont){
    vector<string> v{};  
    char delimiter = ' ';
    istringstream iss(nome);
    copy(istream_iterator<string>(iss),istream_iterator<string>(),back_inserter(v)); //divido a string em partes para cada indic do vetor, tem uma "substring" 
    int i=0;
    while(i<v.size()){
      string aux1 = " ";
      int tam_v = v[i].length();
      int j=0;
      char *aux = new char[tam_v];
      char *aux_final = new char[tam_v];      
      if( v[i].length() > 3){
        for( int i=0; i<tam_v;i++)aux[i]= __null;  // inicializo o vetor de caracteres
        v[i].copy(aux, (v[i].length() -2 ),1 ); // copia para dentro de aux a string no indice i do v
        aux1 = aux;
        reverse(aux1.begin(),aux1.end()); // gira a palavra, raffael fica reaffal
        aux[0] = v[i][0] ;
        for(int i=1;i<=tam_v-2;++i){
          aux[i] = aux1[j];
          j++;
        }
          aux[tam_v-1]= v[i][tam_v-1];
        for(int i=0;i<tam_v;i++){
          if(aux[i] == 'Z' ){// caso contenha esta letra ele sabe como prosseguir
            aux[i] = 'A';
          }
            else if(aux[i] == u'Ç' ){// caso contenha esta letra ele sabe como prosseguir
              aux[i] = 'C';
            }
              else if(aux[i] == u'Ã' ){ // caso contenha esta letra ele sabe como prosseguir
                aux[i] = 'A';
              }
                else if(aux[i] == u'Õ' ){ // caso contenha esta letra ele sabe como prosseguir
                  aux[i] = 'O';  
                }else aux[i]+=1; // aqui codifica, soma mais 1 em cada bit
          aux_final[i] = aux[i]; // pega a string codificada e joga pra dentro de aux final
        }
        v[i] = aux_final;// esta parte a string esta dentro do vetor 
      }
      if(v[i].length() <4){
        int last = nome.length();
        char aux = nome[last-1];
        nome[last-1] = nome[0]; // pego o ultimo elemento e jogo no nome
        nome[0] = aux; 
        for(int i=0;i<tam_v;i++){          
          if(nome[i] == 'Z' ){// caso contenha esta letra ele sabe como prosseguir
            nome[i] = 'A';
          }
            else if(nome[i] == u'Ç' ){// caso contenha esta letra ele sabe como prosseguir
              nome[i] = 'C';
            }
              else if(nome[i] == u'Ã' ){ // caso contenha esta letra ele sabe como prosseguir
                nome[i] = 'A';
              }
                else if(nome[i] == u'Õ' ){  // caso contenha esta letra ele sabe como prosseguir
                  nome[i] = 'O';  
                }else nome[i]+=1;
        }
        v[i] = nome; //v contem toda a string correta agora, já com o reverse
      }
      i++;
    }
  stringstream ss;
  for ( auto x:v) ss<< x << " " ;
  string name = ss.str(); 
  return name;
}

void Applications::Imprime_Codificacao( Pessoa *P, int cont, string nome ){
  cout<< "Nome Codificado: "<< nome<<endl;
  cout<< "Ano: "<<P->getAN_ref()<<endl;
  cout<< "Entidade de Ensino: "<<P->getEntidade_ensino()<<endl;
  cout<< "Valor da Bolsa: "<<P->getVL_bolsista()<<endl;
}

float Applications::media_anual ( int ano, int cont, Pessoa **P){
  int contador =0;
  double soma=0;
  for(int i=0;i<cont;i++){
    if(P[i]->getAN_ref() == ano){
      soma+= P[i]->getVL_bolsista();
      contador++;
    }
  }
  float media = soma / contador;
  return media;
}
void Applications::imprime_alunos(Pessoa **P,int i){
  if ( i == 1){ // bolsa mais cara
    for(int i=0; i<3 ; i++){
      cout<< "O " << i+1 << "º lugar é do(a): " << P[i]->getNome()<< ", Valor da bolsa de: " << P[i]->getCD_moeda() << " "<< P[i]->getVL_bolsista()<< endl;
    }
    cout<<endl;
  }
  else{
    int j=1;
    for(int i=2; i>-1 ; i--){
      cout<< "O " << j << "º lugar é do(a): " << P[i]->getNome() << ", Valor da bolsa de: " << P[i]->getCD_moeda() << " "<< P[i]->getVL_bolsista()<< endl;
      j++;
    }
  }
  cout<<endl;
}

static bool maior (double i,double j) { return (i>j); }
static bool menor (double i,double j) { return (i<j); }

void Applications::aluno_menor_bolsa(Pessoa **P,int cont){
  Pessoa *pont_vet[3] = {nullptr,nullptr,nullptr};
  Pessoa *pont_aux[2] = {nullptr,nullptr};
  vector<double> v{MAX,MAX,MAX}; 
  double aux=0,aux2=0;
  for(int i=0;i<cont-1;i++){
      if(P[i]->getVL_bolsista() < v[0] && P[i]->getVL_bolsista() != v[1] && P[i]->getVL_bolsista() != v[2]){ 
        pont_aux[0] = pont_vet[0];
        pont_aux[1] = pont_vet[1];
        aux = v[1];
        aux2 = v[2];
        v[0] = P[i]->getVL_bolsista(); 
        v[1] = aux;
        v[2] = aux2;
        pont_vet[0] = P[i];
        pont_vet[1] = pont_aux[0];
        pont_vet[2] = pont_aux[1];
        sort (v.begin(), v.end(),maior);//} // faz a ordenação no vetor
    }
  }
  if(pont_vet[0]->getVL_bolsista() < pont_vet[1]->getVL_bolsista()){
    pont_aux[0] = pont_vet[0];
    pont_vet[0] = pont_vet[1];
    pont_vet[1] = pont_aux[0];
  }
  if(pont_vet[1]->getVL_bolsista() < pont_vet[2]->getVL_bolsista()){
    pont_aux[0] = pont_vet[1];
    pont_vet[1] = pont_vet[2];
    pont_vet[2] = pont_aux[0];
  }
    cout<<"As três bolsas com os menores valores são:" <<endl;
    imprime_alunos(pont_vet,0);
}

void Applications::aluno_maior_bolsa(Pessoa **P,int cont){
  Pessoa *pont_vet[3] = {nullptr,nullptr,nullptr};
  Pessoa *pont_aux[2] = {nullptr,nullptr};
  vector<double> v{0,0,0};
  double aux=0,aux2=0;
  for(int i=0;i<cont-1;i++){
      if(P[i]->getVL_bolsista() > v[0]){ // verifica se o p[i] é maior q o v[j]
        pont_aux[0] = pont_vet[0];
        pont_aux[1] = pont_vet[1];
        aux = v[0];
        aux2 = v[1];
        v[0] = P[i]->getVL_bolsista(); 
        v[1] = aux;
        v[2] = aux2;
        pont_vet[0] = P[i];
        pont_vet[1] = pont_aux[0];
        pont_vet[2] = pont_aux[1];
        sort (v.begin(), v.end(),maior); // faz a ordenação no vetor
    }
  } 
    cout<<"As três bolsas com os maiores valores são:" <<endl;
    imprime_alunos(pont_vet,1);
}
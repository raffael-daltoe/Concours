
#ifndef _PESSOA
#define _PESSOA

#include <iostream>
#include <string>

using namespace std;

class Pessoa{
  string nome,CPF,Entidade_ensino, SG_sist_org, DS_mod_pag,CD_moeda,SG_dir,VL_bolsista, ME_ref, AN_ref, CD_mod,sgb;
  //double VL_bolsista, ME_ref, AN_ref, CD_mod,sgb;
  public:
    Pessoa(); 
   // ~Pessoa();
    int busca(double ano, Pessoa *P,int cont); 
    // sets
    void setNome(string name);
    void setCPF(string CPF);
    void setEntidade_ensino(string Entidade_ensino);
    void setVL_bolsista(string valor_bolsa);
    void setSG_dir(string SG_dir);
    void setSG_sist_org(string SG_org);
    void setDS_mod_pag(string DS);
    void setCD_moeda(string CD);
    void setCD_mod(string CD);
    void setAN_ref(string AN);
    void setME_ref(string ME);
    Pessoa(string n, string c, string e_s,string m_f,string an_f,string sg_dr, string sg_org,string cd,string ds, string md,string vl_bl);
    // gets
    string getNome();
    string getCPF();
    string getEntidade_ensino();
    double getVL_bolsista();
    string getSG_dir();
    string getSG_sist_org();
    string getDS_mod_pag();
    string getCD_moeda();
    double getCD_mod();
    double getAN_ref();
    double getME_ref();
};

#endif 

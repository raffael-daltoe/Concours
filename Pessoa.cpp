#include "Pessoa.h"
double aux;
  Pessoa::Pessoa(){
    string nome,CPF,Entidade_ensino, SG_sist_org,SG_dir, DS_mod_pag,CD_moeda,VL_bolsista, ME_ref, AN_ref, CD_mod,sgb = "";
  }
   Pessoa::Pessoa(string n, string c, string e_s,string m_f,string an_f,string sg_dr, string sg_org,string cd,string ds, string md,string vl_bl){
    setNome(n);
    setCPF(c);
    setEntidade_ensino(e_s);
    setME_ref(m_f);
    setAN_ref(an_f);
    setSG_dir(sg_dr);
    setSG_sist_org(sg_org);
    setCD_mod(cd);
    setDS_mod_pag(ds);
    setCD_moeda(md);
    setVL_bolsista(vl_bl);
  }
//sets
  void Pessoa::setNome(string name){
    nome = name;
  }
  void Pessoa::setCPF(string CPF){
    this->CPF = CPF;
  }
  void Pessoa::setEntidade_ensino(string Entidade_ensino){
    this->Entidade_ensino = Entidade_ensino;
  }
  void Pessoa::setVL_bolsista(string valor_bolsa){
    VL_bolsista = valor_bolsa;
  }
  void Pessoa::setSG_sist_org(string SG){
    SG_sist_org = SG;
  }
  void Pessoa::setSG_dir(string SG_dir){
    this->SG_dir = SG_dir;
  }
  void Pessoa::setDS_mod_pag(string DS){
    DS_mod_pag = DS;
  }
  void Pessoa::setCD_moeda(string CD){
    CD_moeda = CD;
  }
  void Pessoa::setCD_mod(string CD){
    CD_mod = CD;
  }
  void Pessoa::setAN_ref(string AN){
    AN_ref = AN;
  }
  void Pessoa::setME_ref(string ME){
    ME_ref = ME;
  }
    // gets
  string Pessoa::getNome(){
    return nome;
  }
  string Pessoa::getCPF(){
    return CPF;
  }
  string Pessoa::getSG_dir(){
    return SG_dir;
  }
  string Pessoa::getEntidade_ensino(){
    return Entidade_ensino;
  }
  double Pessoa::getVL_bolsista(){
    aux = stod(VL_bolsista);
    return aux;
  }
  string Pessoa::getSG_sist_org(){
    return SG_sist_org;
  }
  string Pessoa::getDS_mod_pag(){
    return DS_mod_pag;
  }
  string Pessoa::getCD_moeda(){
    return CD_moeda;
  }
  double Pessoa::getCD_mod(){
    aux = stod(CD_mod);
    return aux;
  }
  double Pessoa::getAN_ref(){
    aux = stod(AN_ref);
    return aux;
  }
  double Pessoa::getME_ref(){
    aux = stod(ME_ref);
    return aux;
  }
// buscas e etc

  int Pessoa::busca(double ano, Pessoa *P,int cont){
    for(int i=0; i<cont-1;++i)
      cout<< P[i].nome<<endl;
  }
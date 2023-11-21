
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include "Pessoa.h"
#include "Applications.h"

using namespace std;

void imprime(){
  cout << endl;
    cout << "[1]. Consultar bolsa zero/Ano." << endl;
    cout << "[2]. Codificar nomes." << endl;
    cout << "[3]. Consultar média anual." << endl;
    cout << "[4]. Ranking valores de bolsa." << endl;
    cout << "[5]. Terminar o programa." << endl;  
}

string manipula(string x){
  stringstream ss;
  ifstream file(x); // abre o construtor para criar o objeto 
  ss << file.rdbuf()<<endl; //joga o arquivo csv aqui para dentro
  return ss.str(); //ss tem a planilha
}


int main() {
  map<int, vector<string>> dados_csv;
	fstream fp;
  int cont = -1;
  string nome = "br-capes-bolsistas-uab.csv";
	fp.open(nome, ios::in);
	if (!fp.is_open()) {  
    cout<< "Ocorreu um erro ao abrir o arquivo, tente novamente!"<<endl;
  }
  else {
    char separador = ';';
    string planilha = manipula(nome); // planilha contem todo o arquivo .csv
    istringstream iss(planilha); // faz a copia da planilha
    vector<string> v;
    string tmp;
    while (getline(iss, tmp)) { // pega cada linha do arquivo e joga pra dentro do vector
        istringstream l(tmp);
        while (getline(l, tmp, separador)) {
            v.push_back(tmp);
        }
        dados_csv[cont] = v;
        v.clear();
        cont += 1;
    }    
    fp.close();
  }
  
 Pessoa *P[cont]; // vetor de ponteiros para classe pessoa
  
  for(int i=0;i<cont-1;i++){ //linha( quantidade de pessoas) | coluna ( método de cada pessoa )
    P[i] = new Pessoa(dados_csv[i][0],dados_csv[i][1],dados_csv[i][2],dados_csv[i][3],dados_csv[i][4],dados_csv[i][5],dados_csv[i][6],dados_csv[i][7],dados_csv[i][8],dados_csv[i][9],dados_csv[i][10]);
  }
  
  int tmp;  
  Applications AP;

	while (1) {
		imprime();
		cin >> tmp;
		system("clear");
		switch (tmp) {
      case 1: {
        double ano= 0;
        Pessoa **PA1 = P;
        cout << "Informe o ano que você deseja:"<<endl;
        cin >> ano;
        AP.busca(ano,PA1,cont);
      }break;
      case 2:{
        string nome;
        cout<< "Informe o nome do Usuário:"<<endl;
        cin.ignore();
        getline( cin, nome );
        std::transform(nome.begin(), nome.end(),nome.begin(), ::toupper);
        Pessoa *PA = AP.busca_nome(nome,P,cont);
        if(PA == nullptr){
          cout<<"Nome não encontrado!"<<endl;
          break;
        }else{
        string nome_codificado = AP.codifica(PA->getNome(),cont);
        AP.Imprime_Codificacao(PA,cont,nome_codificado);
        }
      }break;
      case 3: {
        int ano;
        cout<< "Informe o Ano:"<<endl;
        cin >> ano;
        float media = AP.media_anual(ano,cont,P);
        cout << "A media foi de: "<< media << endl;
      }break;
      case 4:{
        AP.aluno_maior_bolsa(P,cont);
        AP.aluno_menor_bolsa(P,cont);        
      }break;
      case 5:{
        delete *P;
        exit(0);
      }break;
      default: continue;
    }
  }
 delete *P;
}

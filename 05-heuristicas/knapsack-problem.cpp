#include<iostream>
#include <algorithm>
using namespace std;
#include <vector>

struct item {
    int id; 
    double peso;
    double valor;
};

bool compare_value(item a, item b) {
  return a.valor > b.valor;
}

void maisCaroPrimeiro() {
    // 
    vector<item> itens;
    int N;
    double W, pesoT;

    // LÊ QUANTIDADE E CAOACIDADE TOTAL
    cin >> N >> W;
    pesoT = W;

    // LEITURA DOS ITENS
    for (int i=0; i<N; i++){
      item obj;
      obj.id = i;
      cin >> obj.peso >> obj.valor;
      itens.push_back(obj);
    }

    // ORDENA ITENS EM RELAÇÃO AO VALOR
    sort(itens.begin(), itens.end(), compare_value);

    // INICIALIZA VETOR COM ZEROS
    vector<int> resposta = vector(N, 0);
    // NUMERO DE ITENS SELECIONADOS
    int T = 0;
    double valorT = 0;

    for(int i=0; i<N; i++){
      if (itens[i].peso <= W){
        resposta[T] = itens[i].id;
        W -= itens[i].peso;
        valorT += itens[i].valor;
        T++;
      }
    }
    pesoT -= W;

    cout << pesoT << " " << valorT << " " << "\n";
    for (int i=0; i<T; i++){
      cout << resposta[i] << " ";
    }
};


int main () {
    maisCaroPrimeiro();
    return 0;
}
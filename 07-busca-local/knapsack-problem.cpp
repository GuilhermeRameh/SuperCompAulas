#include<iostream>
#include <algorithm>
using namespace std;
#include <vector>
#include <random>
#include <chrono>

struct item {
    int id; 
    double peso;
    double valor;
};

void solucaoAleatoriezada() {

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_int_distribution<int> distribution(0,1);

    // prepara o gerador aleatorio
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

    // INICIALIZA VETOR COM ZEROS
    vector<int> resposta = vector(N, 0);

    for(int i=0; i<N; i++){
      resposta[i] = distribution(generator);
      cout <<resposta[i];
    }

    return;

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
    solucaoAleatoriezada();
    return 0;
}
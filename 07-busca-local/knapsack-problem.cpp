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

void solucaoAleatoriezada(int reps) {

    // unsigned seed = 10; //std::chrono::system_clock::now().time_since_epoch().count();
    // default_random_engine generator(seed);
    // uniform_int_distribution<int> distribution(0,1);

    // prepara o gerador aleatorio
    vector<item> itens;
    int N;
    double W, pesoT, melhorValor = 0, melhorPeso;
    vector<item> mochila, melhor;

    // LÊ QUANTIDADE E CAOACIDADE TOTAL
    cin >> N >> W;

    mochila.reserve(N);
    melhor.reserve(N);

    // LEITURA DOS ITENS
    for (int i=0; i<N; i++){
      item obj;
      obj.id = i;
      cin >> obj.peso >> obj.valor;
      itens.push_back(obj);
    }

    // SEPARAÇÃO ALEATORIA DE 50% DOS OBJETOS
    for(int i=0; i<N; i++){
      if(rand()%2==0) 
          mochila[i] = itens[i];
      else mochila[i].id=-1;
    }

    for (int j=0; j<reps; j++){


      double valorT = 0;
      pesoT = W;

      // VERIFICAÇÃO DE QUEM AINDA CABE, E PREENCHE A MOCHILA
      for (int i=0; i<N; i++){
        if (mochila[i].id!=-1){
          if (itens[i].peso <= pesoT){
            mochila[i].id = 1;
            pesoT -= itens[i].peso;
            valorT += itens[i].valor;
          }
          else mochila[i].id = 0;
        }
      }
      pesoT = W - pesoT;
      if (valorT > melhorValor){
        melhorValor = valorT;
        melhorPeso = pesoT;
        melhor = mochila;
      }
    }
    cout << "\nMelhor Valor: " << melhorValor << "  Melhor Peso: " << melhorPeso << "\n";
};


int main () {
    solucaoAleatoriezada(100);
    return 0;
}
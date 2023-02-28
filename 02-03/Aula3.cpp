#include <iostream>
#include <math.h>
#include <iomanip>
#include <vector>

using namespace std;

int main(){

    int N;
    cin >> N;
    vector<double> x,y;

    vector<vector<double>> d;

    for (int i=0;i<N;i++){
        double xa, ya;
        cin >> xa >> ya;
        x.push_back(xa);
        y.push_back(ya);
    }

    //Cálculo das cidades 
    for(int i=0;i<N;i++){
        vector<double> v;
        for(int j=0;j<N;j++){
            double dist = sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
            v.push_back(dist);
        }
        d.push_back(v);
    }

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++){
            cout << d[i][j] << "\n";
        }
    }
}


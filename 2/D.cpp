#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N;
    in >> N;
    int Lengthes[N];
    int i, j;
    for (i = 0; i < N; ++i){
        in >> Lengthes[i];
    }
    int cur, sum = 0, sum_all = 0, sum_fixed = 0, fixed = -1;
    for (i = 0; i < N; ++i){
        sum = 0;
        for (j = 0; j < N; ++j){
            if (j != i){
                sum += Lengthes[j];
            }
        }
        if (sum < Lengthes[i]){
            fixed = i;
            sum_fixed = sum;
        }
        sum_all += Lengthes[i];
    }
    if (fixed == -1){
        out << sum_all;
    } else {
        out << Lengthes[fixed] - sum_fixed;        
    }
    in.close();
    out.close();
}
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    long N, K, max, min, cur;
    in >> N >> K >> max;
    min = max;
    for (int i = 1; i < N; ++i){
        in >> cur;
        if (cur > max){
            max = cur;
        }
        if (cur < min){
            min = cur;
        }
    }
    long var = max - min;
    out << var;

    in.close();
    out.close();
}
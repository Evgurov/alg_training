#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void reverse(string& str){
    for (int i = 0; i < str.length()/2; ++i){
        swap(str[i], str[str.length() - 1 - i]);
    }
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    string X, Z, Y;
    in >> X >> Z;
    string Z_aux = Z, X_aux, Y_aux;
    while (!Z_aux.empty()){
        while (!Z_aux.empty() && (Z_aux.back() != X.back())){
            Y.append(Y_aux);
            Y.push_back(Z_aux.back());
            Z_aux.pop_back();
        }
        Y_aux = "";
        X_aux = X;
        while (!Z_aux.empty() && !X_aux.empty() && (Z_aux.back() == X_aux.back())){
            Y_aux.push_back(Z_aux.back());
            Z_aux.pop_back();
            X_aux.pop_back();
        }
        if (!X_aux.empty() && !Z_aux.empty()){
            Y.append(Y_aux);
            Y_aux = "";
        }
    }

    reverse(Y);
    out << Y;

    in.close();
    out.close();
}
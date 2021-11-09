#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int P, a, b, c;
    in >> P;
    if (P == 4){
        out << -1;
    } else {
        a = P / 3;
        b = (P - a) / 2;
        c = P - a - b;
        out << a << " " << b << " " << c << endl;

        if (P % 2 == 0){
            a = 2;
            b = (P - a) / 2;
            c = P - a - b;
        } else {
            a = 1;
            b = (P - a) / 2;
            c = P - a - b;
        }
        out << a << " " << b << " " << c << endl;
    }
    in.close();
    out.close();
}
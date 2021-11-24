#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

bool find_cross(int l1, int r1, int l2, int r2, int& cross_left, int& cross_rigth){
    int aux_cross_left, aux_cross_rigth;
    l1 < l2 ? aux_cross_left = l2 : aux_cross_left = l1;    
    r1 <  r2 ? aux_cross_rigth = r1 : aux_cross_rigth = r2;

    if (aux_cross_left > aux_cross_rigth){
        return false;
    } else {
        cross_left = aux_cross_left;
        cross_rigth = aux_cross_rigth;
        return true;
    }
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int x1, x2, y1, y2;
    in >> x1 >> y1 >> x2 >> y2;
    int xc, yc, r;
    in >> xc >> yc >> r;
    long count = 0;
    int watered_left, watered_right;
    int watered_and_cutted_left, watered_and_cutted_rigth;
    for (int y = y1; y <= y2; ++y){
        if (abs(y - yc) > r){
            continue;
        } else {
            watered_left = xc - floor(sqrt(pow(r,2) - pow(y - yc, 2)));
            watered_right = xc + xc - watered_left;
        }
        if (find_cross(x1, x2, watered_left, watered_right, watered_and_cutted_left, watered_and_cutted_rigth)){
            count += watered_and_cutted_rigth - watered_and_cutted_left + 1;
        }
    }

    out << count;
    
    in.close();
    out.close();
}
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void my_next_permutation(vector<int>& indeces){
    int i, l;
    for (int j = indeces.size() - 2 ; j >= 0 ; --j){
        if (indeces[j] < indeces[j+1]){
            i = j;
            break;
        }
    }
    for (int j = indeces.size() - 1 ; j >= 0 ; --j){
        if (indeces[j] > indeces[i]){
            l = j;
            break; 
        }
    }
    swap(indeces[i], indeces[l]);
    for (int j = i + 1 ; j <= i + (indeces.size() - 1 - i) / 2 ; ++j){
        swap(indeces[j], indeces[indeces.size() - (j - i)]);
    }
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N;
    string ans;
    vector<int> x(4), y(4), indeces;
    in >> N;
    for (int i = 0 ; i < N ; ++i){
        ans = "NO";
        for (int j = 0 ; j < 4 ; ++j){
            in >> x[j] >> y[j];
        }
        indeces = {0, 1, 2, 3};
        for(int k = 0 ; k < 24 ; ++k){
            if (((x[indeces[1]] - x[indeces[0]]) == (x[indeces[3]] - x[indeces[2]])) && 
            ((y[indeces[1]] - y[indeces[0]]) == (y[indeces[3]] - y[indeces[2]]))){
                ans = "YES";
                break;
            }
            my_next_permutation(indeces);
        }
        out << ans << endl;
    }
    in.close();
    out.close();
}
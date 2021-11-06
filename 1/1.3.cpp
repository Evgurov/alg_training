#include <iostream>
#include <fstream>

#define SPACE 0
#define CROSS 1
#define CIRCLE 2

using namespace std;

bool check_row(int A[3][3], int n, int sym){
    bool check = true;
    for (int i = 0; i < 3; ++i){
        if (A[n][i] != sym){
            check = false;
        }
    }
    return check;
}

bool check_column(int A[3][3], int n, int sym){
    bool check = true;
    for (int i = 0; i < 3; ++i){
        if (A[i][n] != sym){
            check = false;
        }
    }
    return check;
}

bool check_diag(int A[3][3], int n, int sym){
    bool check = true;
    if (n == 1){
        for (int i = 0; i < 3; ++i){
            if (A[i][i] != sym){
                check = false;
            }
        }
    }
    if (n == 2){
        for (int i = 0; i < 3; ++i){
            if (A[i][2 - i] != sym){
                check = false;
            }
        }
    }
    return check;
}

bool check(int A[3][3]){
    int crosses_count = 0, circles_count = 0;
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            if (A[i][j] == CROSS){
                crosses_count++;
            }
            if (A[i][j] == CIRCLE){
                circles_count++;
            }
        }
    }
    if ((crosses_count != circles_count) && (crosses_count != (circles_count + 1))){
        return false;
    } 

    int cross_wins = 0, circles_wins = 0;
    for (int i = 0; i < 3; ++i){
        cross_wins += check_row(A, i, CROSS);
        cross_wins += check_column(A, i, CROSS);
        circles_wins += check_row(A, i, CIRCLE);
        circles_wins += check_column(A, i, CIRCLE);
    }
    for (int j = 1; j < 3; ++j){
        cross_wins += check_diag(A, j, CROSS);
        circles_wins += check_diag(A, j, CIRCLE);
    }
    if (cross_wins * circles_wins != 0){
        return false;
    } else {
        if (cross_wins){
            return (crosses_count - circles_count == 1);
        } else if (circles_wins){
            return !(crosses_count - circles_count);
        } else 
            return true;
    }
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    int Field[3][3];
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            in >> Field[i][j];
        }
    }
    if (check(Field)){
        out << "YES";
    } else {
        out << "NO";
    }
    in.close();
    out.close();
}
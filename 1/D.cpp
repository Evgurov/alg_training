#include <iostream>
#include <fstream>

using namespace std;

void print_mas(int Mas[], int mas_length){
    for (int i = 0; i < mas_length; ++i){
        cout << Mas[i] << " ";
    }
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int number_of_heroes, number_of_perms;
    in >> number_of_heroes >> number_of_perms;
    int Heroes[number_of_heroes];

    for (int i = 0; i < number_of_heroes; ++i){
        Heroes[i] = i + 1;
    }

    int first_to_swap, second_to_swap;

    for (int i = 0; i < number_of_perms; ++i){
        in >> first_to_swap >> second_to_swap;
        swap(Heroes[first_to_swap - 1], Heroes[second_to_swap - 1]);
    }

    //print_mas(Heroes, number_of_heroes); cout << endl;
    
    int cur_body = 0;

    for (cur_body = 0; cur_body < number_of_heroes - 2; ++cur_body) {
        if (Heroes[cur_body] != cur_body + 1){
            int new_fixed_body, fixed_body = cur_body;
            swap(Heroes[number_of_heroes - 2], Heroes[fixed_body]);
            out << fixed_body + 1 << " " << number_of_heroes - 1 << endl;
            new_fixed_body = Heroes[number_of_heroes - 2] - 1;
            while (Heroes[new_fixed_body] != (fixed_body + 1)){
                swap(Heroes[new_fixed_body], Heroes[number_of_heroes - 2]);
                out << new_fixed_body + 1 << " " << number_of_heroes - 1 << endl;
                new_fixed_body = Heroes[number_of_heroes - 2] - 1;
            }

            int sec_fixed_body = Heroes[number_of_heroes - 2] - 1;
            swap(Heroes[sec_fixed_body], Heroes[number_of_heroes - 1]);
            out << sec_fixed_body + 1 << " " << number_of_heroes << endl;

            swap(Heroes[fixed_body], Heroes[number_of_heroes - 1]);
            out << fixed_body + 1 << " " << number_of_heroes << endl;

            int third_fixed_body = Heroes[number_of_heroes - 2] - 1;
            swap(Heroes[third_fixed_body], Heroes[number_of_heroes - 2]);
            out << third_fixed_body + 1 << " " << number_of_heroes - 1 << endl;
        }
    }

    if (Heroes[number_of_heroes - 1] != number_of_heroes) {
        swap(Heroes[number_of_heroes - 2], Heroes[number_of_heroes - 1]);
        out << number_of_heroes - 1 << " " << number_of_heroes << endl;
    }

    //print_mas(Heroes, number_of_heroes);

    in.close();
    out.close();
}
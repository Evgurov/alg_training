#include <iostream>

int main(){
    int x;
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    if ((a != 0) && (b != 0)){
        if (b % a == 0){
            x = -(b / a);
            if (c * x == -d){
                std::cout << "NO";
            } else {
                std::cout << x;
            }
        } else {
            std::cout << "NO";
        }
    }
    if ((a == 0) && (b != 0)){
        std::cout << "NO";   
    }
    if ((a != 0) && (b == 0)){
        x = 0;
        if (c * x == -d){
            std::cout << "NO";
        } else {
            std::cout << x;
        }
    }
    if ((a == 0) && (b == 0)){
        std::cout << "INF";
    }
}
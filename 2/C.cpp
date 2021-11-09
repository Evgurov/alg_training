#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

bool search (vector<pair<int, int>>& figure, const pair<int, int>& coords){
    bool ans = false;
    for (int i = 0; i < figure.size(); ++i){
        if (figure[i] == coords){
            ans = true;
            break;
        }
    }
    return ans;
}

int search_near(vector<pair<int, int>>& figure, const pair<int, int>& coords){
    int x = coords.first, y = coords.second;
    int ans = 0;
    ans += search(figure, pair<int, int>(x - 1, y));
    ans += search(figure, pair<int, int>(x + 1, y));
    ans += search(figure, pair<int, int>(x, y - 1));
    ans += search(figure, pair<int, int>(x, y + 1));
    return ans;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int n;
    in >> n;
    vector<pair<int, int>> figure;
    int x, y;
    for (int i = 0; i < n; ++i){
        in >> x >> y;
        figure.push_back(pair<int, int>(x,y));
    }
    
    int perimeter = 0;
    for (int i = 0; i < n; ++i){
        perimeter = perimeter + 4 - search_near(figure, figure[i]);
    }

    out << perimeter;

    in.close();
    out.close();
}
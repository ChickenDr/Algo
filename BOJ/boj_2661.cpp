#include <iostream>
#include <string>

using namespace std;

int N;
bool stop;

bool promising(string insert){
    int len = insert.size();
    int start = len - 1;

    for (int i = 1; i <= len / 2; i++){
        if (insert.substr(len - i, i) == insert.substr(len - (2 * i), i)){
            return false;
        }
    }

    return true;
}

void backtrack(string x, int cnt){
    if(stop) return;
    if (cnt == N){
        cout << x;
        stop = true;
        return;
    }
    
    for (int i = 1; i <= 3; i++){
        if (promising(x + to_string(i))){
            backtrack(x + to_string(i), cnt + 1);
        }
        
    }
}

int main(){
    cin >> N;
    backtrack(to_string(1), 1);

    return 0;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string S;
vector<string> K(101);
vector<bool> dp(101);

int main(){
    int N;
    cin >> S;
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> K[i];
    }

    dp[0] = true;

    for (int i = 1; i <= S.length(); i++) {
        int index = i;
        for (int x = 0; x < N; x++) {
            if ((index >= K[x].length()) && (S.substr(i - K[x].length(), K[x].length()) == K[x])){
                if (dp[index - K[x].length()]) {
                    dp[index] = true;
                    break;
                }
            }
        }
    }

    if (dp[S.length()]) {
        cout << 1;
    }
    else {
        cout << 0;
    }

    return 0;
}
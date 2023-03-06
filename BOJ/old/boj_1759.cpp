#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int L, C;
char A[16], P[16];
bool visit[26];


void backtracking(int pos, int prev, int consonant, int vowel){
    if (pos == L){
        if(consonant >= 2 && vowel >= 1) puts(P);
        return;
    }

    for (int i = prev + 1; i < C; i++)
    {
        P[pos] = A[i];
        backtracking(pos + 1, i, consonant + !visit[A[i] - 'a'], vowel + visit[A[i] - 'a']);
    }
}

int main(){
    cin >> L >> C;
    for (int i = 0; i < C; i++)
    {
        cin >> A[i];
    }

    sort(A, A + C);

    visit[0] = visit[4] = visit[8] = visit[14] = visit[20] = true;
    backtracking(0, -1, 0, 0);
    
    return 0;
}
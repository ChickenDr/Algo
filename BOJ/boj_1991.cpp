#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int n;
string p_r;
pair<char, char> tree[30];

string postorder(char x){
    string p_r;
    
    if(tree[x - 'A'].first != '.') p_r += postorder(tree[x - 'A'].first);
    if(tree[x - 'A'].second != '.') p_r += postorder(tree[x- 'A'].second);
    p_r += x;

    return p_r;
}

string inorder(char x){
    string p_r;
    
    if(tree[x - 'A'].first != '.') p_r += inorder(tree[x - 'A'].first);
    p_r += x;
    if(tree[x - 'A'].second != '.') p_r += inorder(tree[x- 'A'].second);

    return p_r;
}

string preorder(char x){
    string p_r;

    p_r += x;
    if(tree[x - 'A'].first != '.') p_r += preorder(tree[x - 'A'].first);
    if(tree[x - 'A'].second != '.') p_r += preorder(tree[x- 'A'].second);

    return p_r;
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char par, l, r;
        cin >> par >> l >> r;
        tree[par - 'A'] = make_pair(l, r); 
    }
    
    cout << preorder('A') << endl;
    cout << inorder('A') << endl;
    cout << postorder('A') << endl;
    return 0;
}
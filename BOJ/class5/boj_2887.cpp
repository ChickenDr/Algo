#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int pare[101];

int find(int n){
    if(pare[n] < 0) return n;
    return pare[n] = find(pare[n]);
}

bool merge(){

}

class Edge{
public:
    pair<pair<int, int>, pair<int, int>> node;
    int dst;

    Edge(pair<int, int> from, pair<int, int> to){
        node.
    }
};

int main(){
    memset(pare, -1, sizeof(pare));
    return 0;
}
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;
bool b[11];
int N, M, cnt = 0, cnt2 = 0, ch_len, ch_len2;
string ch, ch2, tmp;

bool check(string ch, int ch_len)
{
    for (int i = 0; i < ch_len; i++)
    {
        int index = ch[i] - '0';
        if(b[index])
        {
            return false;
        }
    }
    return true;
}

int main(){
    cin >> ch;
    ch2 = ch;
    tmp = ch;
    ch_len = ch.size();
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int tmp;
        cin >> tmp;
        b[tmp] = true;
    }

    if(M == 10)
    {
        cout << abs(stoi(tmp) - 100) << endl;
        return 0;
    }

    if(ch.compare("100") == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    while (1)
    {   
        int tmp = stoi(ch);
        ch_len = ch.size();
        if(tmp < 0)
        {
            cnt = -1;
            break;
        }

        if(check(ch, ch_len))
        {
            cnt += ch_len;
            break;
        }
        else
        {
            tmp -= 1;
            ch = to_string(tmp);
            cnt++;
        }
    }

    while (1)
    {
        int tmp = stoi(ch2);
        ch_len2 = ch2.size();
        if(tmp > 1000000) 
        {
            cnt2 = -1;
            break;
        }
        if(check(ch2, ch_len2))
        {
            cnt2 += ch_len2;
            break;
        }
        else
        {
            tmp += 1;
            ch2 = to_string(tmp);
            cnt2++;
        }
    }
    
    if(cnt == -1) cout << min(cnt2, abs(stoi(tmp) - 100)) << endl;
    else if(cnt2 == -1) cout << min(cnt, abs(stoi(tmp) - 100)) << endl;
    else cout << min(min(cnt, cnt2), abs(stoi(tmp) - 100)) << endl;
    return 0;
}
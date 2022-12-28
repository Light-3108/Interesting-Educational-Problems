#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> A{4, 2, 2, 6, 4};
    int B = 6;
    unordered_map<int, int> visited;
    int cpx = 0;
    long long c = 0;
    for (int i = 0; i < A.size(); i++)
    {
        cpx ^= A[i];
        if (cpx == B)
            c++;
        int h = cpx ^ B;
        if (visited.find(h) != visited.end())
        {
            c = c + visited[h];
        }
        visited[cpx]++;
    }
    cout << c << endl;
    return 0;
}

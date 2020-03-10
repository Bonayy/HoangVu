#include <bits/stdc++.h>
using namespace std;

int main(){
    priority_queue <int, vector <int>, greater <int> > heap;
    int x, n; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x; heap.push(x);
    }
    for (int i = 0; i < n; i++){
        cout << heap.top() << ' ';
        heap.pop();
    }
}

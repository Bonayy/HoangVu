#include <bits/stdc++.h>
using namespace std;

class sqrt_blocks{
private:
    int n, bl_size, bl_cnt;
    vector <int> values;
    vector <vector <int>> blocks;
public:
    sqrt_blocks(int n){
        this->n = n; bl_size = (int)sqrt(n);
        bl_cnt = (n - 1) / bl_size + 1;
        values.resize(n, 0); blocks.resize(bl_cnt);
    }
    void input(){
        for (int &x : values) cin >> x;
    }
    void init(){
        for (int i = 0; i < n; i++)
            blocks[i / bl_size].insert(values[i]);
    }
    void update(int pos, int val){
        blocks[pos / bl_size].erase(values[pos]);
        blocks[pos / bl_size].insert(val);
        values[pos] = val;
    }
    int query(int l, int r, int k){
        int res = 0;
        while (l <= r && l % bl_size != 0)
            res += values[l++] > k;
        while (r >= l && (r + 1) % bl_size != 0)
            res += values[r--] > k;
        for (; l <= r; l += bl_size)
            res += 
    }
};

int main(){

}
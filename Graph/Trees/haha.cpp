#include <bits/stdc++.h>
using namespace std;
template<typename... Args>
auto Func(Args... args)
{
    return (args + ...);
}

int main(){
    int &&a = 5;
    cout << a;
    cout << value;
}

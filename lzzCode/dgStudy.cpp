#include <iostream>
using namespace std;

int jiecheng(int n)
{
    if (n == 0)
    {
        return 1;
    }
    n = n * jiecheng(n - 1);
    return n;
}

int fibonacci(int n){
    if(n<=1){
        return 1;
    }
    n=fibonacci(n-1)+fibonacci(n-2);
    return n;
}

int main()
{
    int n, i;
    cin >> n;
    i = fibonacci(n);
    cout << "last:" << i << endl;
    return 0;
}
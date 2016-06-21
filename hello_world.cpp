#include<iostream>
#include<vector>
#define toStr(n) (#n)
#define FUNCTION(name, a) void name(int& m, int v) { m a v ? m = v : v; }
#define foreach(v, i) for(int i=0;i<v.size();i++)
#define io(v) cin>>v
FUNCTION(maximum,<)
using namespace std;
int main (){
    int A[3];
    cout << A << endl;
    cout << &A[0] << endl;
    return 0;
}
/*
int main(){
    int n = 10;
    vector<int> v(n);
    foreach(v,i){
        io(v)[i];
    }
    int max = 0;
    int a = 5;
    int b = 3;
    maximum(max,a);
    maximum(max,b);
    cout << toStr(Max number is  =) << " " << max << endl;
}
*/
/*
template<class Type>
void xmax(Type &a, Type &b, double &rst){
    rst = a > b?a:b;

}
int main(){
    int a = 5;
    double b = 1;
    double result;
    xmax(a,b,result);
    cout << a << ", " << b << endl;

    return 0;
}
*/

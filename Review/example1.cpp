#include <iostream>
using namespace std;
void sum (int *a, int*b, int* rst){
    *rst = *a + *b;
}

int main(){
    int a,b,c;
    cin >> a >> b;
    c = 0;
    sum (&a,&b,&c);
    cout << c << endl;
    if (c > 0){
    }
}

#include "../Queue/mQueue.h"
#include "../Stack/mStack.h"


int main(){
    mStack<char> S;
    string word = "structures";
    cout << word << endl;
    for (int i=0;i<word.size();i++){
        S.push(word[i]);
    }
    while (!S.isEmpty()){
        char c = S.top();
        S.pop();
        cout << c ;
    }
    cout << endl;
return 0;
}

#include "../Queue/mQueue.h"
#include "../Stack/mStack.h"

bool isPalindrome(mQueue<char> & Q, mStack<char> & S){
    bool ans = true;
    while(!S.isEmpty()){
        char c1 = S.pop();
        char c2 = Q.dequeue();
        if (c1 !=c2) {
            ans = false;
            break;
        }
    }
    return ans;
}

int main(){
    string word = "race car";
    mQueue<char> Q;
    mStack<char> S;
    int sz = word.size();
    for (int i=0;i<sz;i++){
        if (word.at(i)==' ') continue;
        S.push(word.at(i));
        Q.enqueue(word.at(i));
    }
    cout << "Word \"" << word << (isPalindrome(Q,S)?"\" is a Palindrome":"\" is not a palindrome") << endl;
    return 0;
}

#include<iostream>
#include<map>
using namespace std;

int main(){
    map<char,int> hashtable;
    // string s1 = "mmmmooommadfafanniainfa";
    // string s1 = "mma";
    string s1 =  "Yueng is a really nice name";
    cout << s1 << endl;
    for (int i=0;i<s1.size();i++){
        if (hashtable.count(s1[i])==0)// if key is not in the table.
            hashtable[s1.at(i)]=1;// assign a one to i
        else hashtable[s1.at(i)]=++hashtable[s1.at(i)];
    }
    for (map<char,int>::iterator it=hashtable.begin(); it!=hashtable.end(); ++it)
        cout << it->first << " => " << it->second << '\n';
    return 0;
}

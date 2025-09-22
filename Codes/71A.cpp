//
// Created by MIHIR MITHANI on 21/09/25.
//
#include <iostream>
#include <string>

using namespace std;

void result(string &str) {
    int len=str.length();
    string str1;
    if (len>10) {
        str1=str[0]+ to_string(len-2) + str[len-1];
    }
    else {
        str1=str;
    }
    cout<<str1<<"\n";
}

int main() {
    int n;
    cin>>n;
    for (int i=0;i<n;i++) {
        string str;
        cin>>str;
        result(str);
    }
    return 0;
}
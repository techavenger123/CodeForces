//
// Created by MIHIR MITHANI on 21/09/25.
//
#include <iostream>
#include "vector"
using namespace std;

int main() {
    int weight;
    cin>>weight;
    if (weight%2==1) {
        cout<<"NO";
    }
    for (int i=2;i<=weight;i+=2) {
        if ((weight-i)%2==0) {
            cout<<"YES";
            break;
        }
    }
    return 0;
}
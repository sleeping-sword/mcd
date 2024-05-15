#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int Sigma(vector<int>&a,vector<int>&b){
    int sum=0;
    int size=a.size();
    for(int i=0;i<size;i++){
        if(a[i] >= b[i]){
            sum += (a[i] - b[i]) * (a[i] - b[i]);
        }else{
            sum -= (a[i] - b[i]) * (a[i] - b[i]);
        }
    }
    return sum;
}

bool cmp(vector<int>&a, vector<int>&b){//&就是reference，可以直接改動物件本身
    if(a.size()>b.size()){
        return true;
    }else if(a.size()<b.size()){
        return false;
    }else if(a.size()==b.size()){
        return Sigma(a,b) > 0;
    }
}

int main(){
    int N;
    cin >> N;
    vector<vector<int>> row(N);
    for(int i=0;i<N;i++){
        int a;//陣列有多大
        cin >> a;
        row[i].resize(a);//這句很重要
        for(int j=0;j<a;j++){
            cin >> row[i][j];
        }
    }

    sort(row.begin(),row.end(),cmp);
    //cout << "Outcome:" << endl;
    for (auto &vec : row) {
    if (!vec.empty()) {
        cout << vec[0];
        for (size_t i = 1; i < vec.size(); i++) {
            cout << " " << vec[i];
        }
    }
    cout << "\n";
}
    return 0;
}


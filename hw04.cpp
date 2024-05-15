#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Array{
    public:
    int start;
    int end;
};

bool compare(Array &a, Array &b){
    return a.end < b.end;
}

int main(){
    vector<Array>array;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
       Array a;
       cin >> a.start >> a.end;
       array.push_back(a); 
    }
    sort(array.begin(),array.end(),compare);
    cout << "Sorted:"<< endl;
    for(const auto &i:array){
        cout << i.start << " " << i.end << endl;
    }
    int front = array[0].start, back = array[0].end;
    
    // 初始化 index 為 1，表示已選擇一個活動
    int index = 1;

    // 從第二個活動開始，遍歷所有活動
    for (int i = 1; i < n; i++) {
        // 如果當前活動的開始時間晚於前一個活動的結束時間，則選擇當前活動
        if (array[i].start > back) {
            // 更新 front 和 back
            // front = array[i].start;
            back = array[i].end;

            // 更新 index
            index++;
        }
    }

    // 印出可以看的活動數量
    cout << index << endl;
    return 0;
}
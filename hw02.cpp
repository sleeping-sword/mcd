#include<bits/stdc++.h>
using namespace std;

// 合併兩個已排序的區間
void mergeArray(vector<int>& array, int l, int m, int r) {
    vector<int> left(array.begin()+l, array.begin()+m+1);
    vector<int> right(array.begin()+m+1, array.begin()+r+1);

    left.push_back(10001); //加入哨兵
    right.push_back(10001); //加入哨兵

    int idx_left = 0, idx_right = 0;
    for (int k = l; k <= r; k++){
        if (left[idx_left] <= right[idx_right]){
            array[k] = left[idx_left];
            idx_left++;
        }
        else{
            array[k] = right[idx_right];
            idx_right++;
        }
    }
}

// 使用遞歸函數實現合併排序
void mergeSort(vector<int>& array, int l, int r) {
    // “l”和“r”是分區間範圍的起止位置

    if(l < r) {
        // 若l < r則分區間範圍中有值，可以繼續進行排序

        // 找到區間中間位置
        int m = l + ((r-l) >> 1);

        // 對左半區間進行排序
        mergeSort(array, l, m);

        // 對右半區間進行排序
        mergeSort(array, m + 1, r);

        // 合併排序完成的兩個區間
        mergeArray(array, l, m, r);
    }
}



int main() {
    int n;
    cin >> n;
    vector<int> arrays;
    // 將每個子陣列的元素合併到一個大陣列中
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        while(k--) {
            int num;
            cin >> num;
            arrays.push_back(num);
        }
    }

    // 对大数组进行排序
    mergeSort(arrays, 0, arrays.size() - 1);

    for(int i = 0; i < arrays.size(); i++) {
        if(i != 0) cout << " ";
        cout << arrays[i];
    }
    cout << endl;

    return 0;
}
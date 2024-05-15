#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
using namespace std;

int repeat(const vector<int>& nums) {
    unordered_set<int> seen;
    unordered_map<int, int> indexes;
    int index = 0;
    int sum = 0;
    int max_sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        if(seen.count(nums[i]) == 0) {
            seen.insert(nums[i]);
            indexes[nums[i]] = i;
            sum += nums[i];
        }else {
            if(sum > max_sum) {
                max_sum = sum;
            }
            i = indexes[nums[i]];
            index = i + 1;
            sum = 0;
            seen.clear();
        }    
    }
    if(sum > max_sum) {
        max_sum = sum;
    }

    return max_sum;
}

int main(){
    vector<int> nums; 
    string input;
    int num;

    getline(cin, input);
    stringstream sstr(input);
    while(sstr >> num){
        nums.push_back(num);
    }

    int output = repeat(nums);
    cout << output;

    return 0;
}
/*你的程式碼主要存在以下可能的問題：
在 repeat 函數中，你是根據 num 來進行循環操作的，
但是 num 的值取決於 main() 函數中 while(sstr >> num) 循環的最後一次結果，
而並非 nums 向量的大小。這可能導致執行途中索引超出 nums 的範圍，而引發錯誤。
你可以考慮將 repeat(nums, num); 改為 repeat(nums, nums.size());。

在 repeat 函數中，每次進入 else if 條件時，你都會執行一個循環，
尋找 nums[j]==nums[i] 為真的 j，並根據此 j 計算新的 index。
這段邏輯看起來有些冗余和低效，因為你已經知道 nums[i] 存在於 seen 中，
並且其對應的索引肯定不大於 i。一種更好的選擇可能是使用一個 unordered_map 來存儲每個元素及其對應的索引，
這樣就可以在 O(1) 的時間內找到新的 index。

在 repeat 函數的最終，你比較了 sum 和 max 的大小並可能更新 max 的值，這很好，
但在逐一檢查 nums 的元素時，這樣的檢查是缺失的。也就是說，如果最後一個（或者最多的）連續無重複元素的和最大，
你的程序將不能正確返回結果。為了修正這個問題，你應該在每次計算 sum 后都檢查是否需要更新 max。*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>
using namespace std;
int max=0;
int repeat(const vector<int>& nums,int num){
    unordered_set<int> seen;
    int index = 0;
    int sum=0;
    int i=0;
    int max=0;
    while(i<num){
        if(seen.count(nums[i]) == 0){
            seen.insert(nums[i]);
            //在這裡添加把seen所有元素輸出的程式碼，並換行
            //  cout << "seen:";
            //  for(auto const& element: seen){
            //     cout << element << " ";
            // }
            sum += nums[i];
            // cout << "sum:" << sum << endl;
            i++; 
        }else if(seen.count(nums[i]) > 0){
            if(sum > max){
                max = sum;
            }
            for(int j=index;j<=i;j++){
               if(nums[j]==nums[i]){
                    index = j+1;
                }
            }
            i = index;
        }    
    }
    if(sum > max)
        max = sum;
    return max;
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

    int output = repeat(nums,num);
    cout << output;

    return 0;
}
#include <iostream>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    int array[n];
    stack A [n];
    deque<int> station;
    bool isthesame()
    for(int i=0;i<n;i++){
        A[i] = i+1;
    }
   
    for(int i=0;i<n;i++){
        cin >> array[i];
    }

    for(int i=0;i<n;i++){
        int count = 0;
        while(array[i]!=A[count]&& count<=n){
            station.push(A[count]);
            count++;
        }
    }

        return 0;
}
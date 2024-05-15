#include<iostream>
using namespace std;

int main(){
    int num;
    cin >> num;
    int array[num];
    int big;
    int pro;
    int small;
    int maxpro=0;
    for(int i=0;i<num;i++){
        cin >> array[i] ;
    }
    for(int i=0;i<num-1;i++){
        if(array[i+1]<array[i]){
            continue;
        }else{
            small = array[i];
        }
        for(int j=i+1;j<num-1;j++){
            if(array[j+1]>array[j]){
                big = array[j+1];
            }
            pro = big - small;
        if(pro>maxpro){
            maxpro = pro;
            }
        }
    }
    cout << maxpro << endl;
    return 0;
}
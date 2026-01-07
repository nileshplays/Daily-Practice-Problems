#include<bits/stdc++.h>
using namespace std;

long long int sqrtInt(int n){
    int s= 0, e=n;
    long long int ans = -1;
    while(s <= e){
        long long int mid = s + (e-s)/2;
        long long int square = mid*mid;
        if( square == n ){
            return mid;
        }
        if( square < n ){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return ans;
}

double preciseSqrt(int n , int precision, int tempSol){
    double factor = 1;
    double ans = tempSol;
    for(int i = 0; i< precision ; i++){
        factor = factor/10;
        for(double j = tempSol ; j*j < n ; j+=factor){
            ans = j;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter a number : "<<endl;
    cin>>n;

    int tempSol = sqrtInt(n);
    cout<<"Precise ans: "<<preciseSqrt(n, 3, tempSol)<<endl;
}

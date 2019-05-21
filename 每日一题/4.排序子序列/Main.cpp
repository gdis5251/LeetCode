#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int i=0;
        int res=0;
        while(i<n-1){
            while(i<n-1 && v[i]==v[i+1])
                i++;
            if(i<n-1 && v[i]>v[i+1]){
                res++;
                while(i<n-1 && v[i]>=v[i+1])
                    i++;
                i++;
            }
            else if(i<n-1 && v[i]<v[i+1]){
                res++;
                while(i<n-1 && v[i]<=v[i+1])
                    i++;
                i++;
            }
        }
        if(i==n-1)
            cout<<res+1<<endl;
        else
            cout<<res<<endl;
    }
    return 0;
}

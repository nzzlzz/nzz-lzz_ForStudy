//
//  main.cpp
//  非零段
//
//  Created by 牛猪猪的 on 2025/3/15.
//

#include <iostream>
#include <stdio.h>
using namespace std;
int Operation(int a[],int num){
    int p=0;//非零段的个数
    int i=0;//计数工具
    int n=0;//非零数的个数
    int sum=0;//非零的总和
    //cout<<"num:"<<num<<endl;
    while(i<num){
        if(a[i]>0)
        ++n;
        ++i;
    }
    //cout<<n<<endl;
    i=0;
    while(i<num){
        sum+=a[i];
        ++i;
    }
    int average=sum/i+1;
    //cout<<"average:"<<average<<endl;
//找p
    i=0;
    n=num;
    while(i<num){
        if(a[i]<average){
            a[i]=0;
            --n;
        }
        ++i;
        //cout<<n<<" "<<i<<endl;
    }
    /*for(i=0;i<num;++i){
        cout<<a[i]<<" ";
    }*/
    for(i=0;i<num;++i){
        if(a[i]>0&&(i==0||a[i-1]==0))
            ++p;
    }
    return p;
}


int main(void) {
    int num;
    cin>>num;
    int a[num];
    int i;
    int p;
    for(i=0;i<num;++i){
        cin>>a[i];
    }
    p=Operation(a,num);
    cout<<p<<endl;
    return 0;
}

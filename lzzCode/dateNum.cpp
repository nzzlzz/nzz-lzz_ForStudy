#include<iostream>
using namespace std;
int select(int year,int month,int check){
    
    
}
int main(){
    int year,month,check;
    cin>>year>>month>>check;
    if((year<1000||year>3000)||(month<1||month>12)||(check<0||check>9)){
        cout<<"error";
        return 0;
    }
    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(year%4==0&&year%100!=0||year%400==0){
        days[1]=29;
    }
    
    cout<<select(year,month,check);
}
#include<bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
	if(a < b){
		return gcd(b,a);
	}
	if(a==b){
		return a;
	}
	if(b==0){
		return a;
	}
	if(b==1){
		return 1;
	}
	int x = a/b;
	return gcd(b, a-x*b);
}

int main(){

	//input two integers
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b)<<endl;

	return 0;

}
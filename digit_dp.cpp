#include<bits/stdc++.h>

using namespace std;

///////////////////////////////////////////////////////
///// for running the file> "Ctrl+Shift+B" ////////////
///////////////////////////////////////////////////////

vector<vector<vector<long long>>> dp(23,vector<vector<long long>>(401,vector<long long>(2,-1)));
int mod = pow(10,9)+7;

int digit_dp(string s, int N, int x,bool flag){
	if(N<=0 || x<0){
		return 0;
	}

	if(N==1 && flag == 0){
		if(x>=0 && x<=9){
			return 1;
		}
		return 0;
	}

	int 
	len = s.length();

	if(N==1 && flag == 1){
		if(x>=0 && x<= (s[len-1]-'0')){
			return 1;
		}
		return 0;
	}

    if(flag == 0){
    	if(dp[N][x][0] != -1){
			return dp[N][x][0];
		}

		dp[N][x][0] = 0;
		for(int i=0;i<=9;i++){
			dp[N][x][0] += digit_dp(s,N-1,x-i,0);
			dp[N][x][0] %= mod;
		}
		return dp[N][x][0];
    }

	if(dp[N][x][1] != -1){
		return dp[N][x][1];
	}

	dp[N][x][1] = 0;
	for(int i=0;i<(s[len-N]-'0');i++){
		dp[N][x][1] += digit_dp(s,N-1,x-i,0);
		dp[N][x][1] %= mod;
	}
	dp[N][x][1] += digit_dp(s,N-1,x-(s[len-N]-'0'),1);
	dp[N][x][1] %= mod;
	return dp[N][x][1];

}


int main(){

	int N, x;
	string s;
	cin>>N>>x;
	cin>>s;
	int ans = digit_dp(s,N,x,1);
	cout<<ans<<endl;

}
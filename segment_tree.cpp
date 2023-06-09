#include<bits/stdc++.h>
using namespace std;

///////////////////////////////////////////////////////
///// for running the file> "Ctrl+Shift+B" ////////////
///////////////////////////////////////////////////////

int construct_segment_tree(vector<int>& sg,int si,vector<int>& arr, int l,int r){
	if(l==r){
		sg[si] = arr[l];
		return arr[l];
	}
	int mid = (l+r)/2;
	sg[si] = construct_segment_tree(sg,2*si+1,arr,l,mid)+
	         construct_segment_tree(sg,2*si+2,arr,mid+1,r);
	return sg[si];
}

int get_sum(vector<int>& sg,int si,int sl,int sr, int l,int r){
	if((l<= sl) && (r>= sr)){
		return sg[si];
	}
	if((l > sr)||(r < sl)){
		return 0;
	}
	int mid = (sl+sr)/2;
	return get_sum(sg,2*si+1,sl,mid,l,r)+get_sum(sg,2*si+2,mid+1,sr,l,r);

}

void update_ele(vector<int>& sg,int si,int sl,int sr,int pos,int diff){
	if((sl > pos) || (sr < pos)){
		return;
	}
	sg[si] += diff;
	if(sl != sr){
		int mid = (sl+sr)/2;
		update_ele(sg,2*si+1,sl,mid,pos,diff);
		update_ele(sg,2*si+2,mid+1,sr,pos,diff);
	}
	return;
}



int main(){
	int N;
	vector<int> v;
	cin>>N;
	int buf;
	for(int i=0;i<N;i++){
		cin>>buf;
		v.push_back(buf);
	}

	int M = 2*N - 1;
	int l = 0;
	while(M){
		M /= 2;
		l++;
	}

	M = 1<<l;
	cout<<M<<endl;

	vector<int> sg(M,INT_MIN);
	construct_segment_tree(sg,0,v,0,N-1);

    for(int i=0;i<(M);i++){
		cout<<sg[i]<<" ";
	}
	cout<<endl;

	cout<<get_sum(sg,0,0,N-1,2,5)<<endl;

	update_ele(sg,0,0,N-1,3,-6);

	for(int i=0;i<(M);i++){
		cout<<sg[i]<<" ";
	}
	cout<<endl;

	return 0;

}
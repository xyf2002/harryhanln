#include "header.h"
#include <errno.h>

int main(){
	try{
		vector<int> v;
		int x;
		while(cin>>x) {v.push_back(x);}
		for (int i = 0; i<=v.size(); ++i) cout<<v[i]<<' ';
		cout<<"\n";
	}
	catch (...){
		cerr <<"Unknown error!\n";
		return 2;
	}
}

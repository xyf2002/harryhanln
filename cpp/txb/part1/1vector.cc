#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

	vector <string> ps(6);
	vector <double> v;
	v.push_back(2.7); //v(0) = 2.7
	v.push_back(3.7); //v(1) = 3.7
	//push_back is a member function call, must be used with . after the vector
	
	for (int i=0; i!= v.size();++i)
		cout<<v[i]<<endl;

	vector <double> temps;
	double temp;
	while(cin>>temp)
		temps.push_back(temp);
	
	double sum = 0;
	cout<<"Here is the Values of the vectors: \n";
	for (int i=0; i!= temps.size();++i){
		cout<<temps[i]<<endl;
		sum += temps[i];
	}
	cout<<"The average is: " << sum/temps.size()<<endl;

	sort(temps.begin(), temps.end()); // Sort from the beginning to the end.

	cout<<"The median is: "<< temps[temps.size()/2]<<endl;


	return 0;
}

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
	long long sta = 1;
	for (long long i=2;i<=12;++i) sta *= i;
	vector<long long> v;
	long long n;
	while (cin >> n) v.push_back(n);
	int ans = 0;
	for (int i=0;i<v.size();++i) for (int j=i+1;j<v.size();++j) if (v[i]*v[j] == sta) ++ans;
	cout << ans << endl;
	
	return 0;
}

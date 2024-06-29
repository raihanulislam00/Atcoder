#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=507;
ll n,ans,a[N],pos[N],ok[N],k;
vector<pair<ll,ll> > vec;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for (int i=1;i<=n;++i) {cin>>a[i];pos[a[i]]=i;}
	for (int i=1;i<=n;++i){
		for (int j=1;j<i;++j) ans+=(ok[j]=(pos[j]>=pos[i]+k));
		ll now=i;
		for (int j=i-1;j;--j) if (ok[j]){
			vec.push_back(make_pair(pos[now],pos[j]));
			swap(pos[now],pos[j]);
			now=j;
		}
	}
	cout<<ans<<'\n';
	for (auto p:vec) cout<<p.first<<' '<<p.second<<'\n';
	return 0;
}
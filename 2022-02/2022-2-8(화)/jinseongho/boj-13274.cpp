#include <bits/stdc++.h>

using namespace std;

vector<long long> v(100'001);
long long n, m;

vector<long long> merge(vector<long long>& left, vector<long long>& right) {
    int lsz = left.size();
    int rsz = right.size();

    int a = 0;
    int b = 0;

    vector<long long> ret;

    while(a < lsz && b < rsz){
        if(left[a] <= right[b]){
            ret.push_back(left[a++]);
        } else {
            ret.push_back(right[b++]);
        }
    }

    for(int i = a; i < lsz; i++){
        ret.push_back(left[i]);
    }

    for(int i = b; i < rsz; i++){
        ret.push_back(right[i]);
    }   

    return ret;
}

void _plus(long long l, long long r, long long x){
    vector<long long> left(r - l + 1);
    for(int i = 0; i < left.size(); i++){
        left[i] = v[l + i] + x;
    }

    vector<long long> right( (n - 1) - r);
    for(int i = 0; i < right.size(); i++){
        right[i] = v[r + 1 + i];
    }

    vector<long long> ret = merge(left, right);

    for(int i = 0; i < ret.size(); i++){
        v[l + i] = ret[i];
    }
}

void _minus(long long l, long long r, long long x){
   vector<long long> right(r - l + 1);
    for(int i = 0; i < right.size(); i++){
        right[i] = v[l + i] + x;
    }

    vector<long long> left(l);
    for(int i = 0; i < left.size(); i++){
        left[i] = v[i];
    }

    vector<long long> ret = merge(left, right);
 
    for(int i = 0; i < ret.size(); i++){
        v[i] = ret[i];
    } 
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.begin() + n);

    while(m--){
        long long a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        if(c > 0){
            _plus(a, b , c);
        } else if( c < 0 ){
            _minus(a, b, c);
        }
    }

    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }

}
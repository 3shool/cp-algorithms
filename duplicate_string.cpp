//Problem: Given a list of  
//n strings  
//s_i, each no longer than  
//m characters, find all the duplicate strings and divide them into groups.



#include <iostream>
#include <string>
#include<vector>

using namespace std;

long long compute_hash(string s) {
    int d = 31;
    long long q = 1e9 + 9;
    long long p_pow = 1;
    long long hash_value = 0;

    for(char ch : s) {
        hash_value = (hash_value + (ch - 'a' + 1) * p_pow) % q;
        p_pow = (d * p_pow) % q;
    }

    return hash_value;
}


vector<vector<int>> duplicate_strings(vector<string> s) {
    vector<vector<int>> res;

    vector<pair<long long, int>> hash_pair_list;

    for(int i = 0; i < s.size(); ++i) {
        hash_pair_list.push_back(make_pair(compute_hash(s[i]), i));
    }

    sort(hash_pair_list.begin(), hash_pair_list.end());

    for(int i = 0; i < hash_pair_list.size(); ++i) {
        if(i == 0 || hash_pair_list[i].first != hash_pair_list[i - 1].first) 
            res.emplace_back();
        res.back().push_back(hash_pair_list[i].second);
    }

    return res;
}

int main() {
    
    vector<string> s = {"hsjhdkjsjds", "jsdjsdjjsdjsjd", "jsdjsdjjsdjsjd", "hsjhdkjsjds", "jsdjsdjjsdjsjd"};

    vector<vector<int>> v = duplicate_strings(s);


    for(int i = 0; i < v.size(); ++i){
        for(int j = 0; j < v[i].size(); ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;


}
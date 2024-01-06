#include <iostream>
#include <string>

using namespace std;


long long compute_hash(string s) {
    int d = 31;
    long long q = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;

    for(char ch : s) {
        hash_value = (hash_value + (ch - 'a' + 1) * p_pow) % q;
        p_pow = (p_pow * d) % q;
    }
    
    return hash_value;

}


int main() {
    string s = "dsmdjsjjdosjdkskdskdoskdsk";
    long long hash_value = compute_hash(s);
    cout << hash_value << endl;
    return 0;
}
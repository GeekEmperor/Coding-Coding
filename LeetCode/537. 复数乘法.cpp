class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int p = a.find('+'), q = b.find('+');
        int x = stoi(a.substr(0, p)), y = stoi(a.substr(p + 1, a.size() - 1));
        int z = stoi(b.substr(0, q)), w = stoi(b.substr(q + 1, b.size() - 1));
        return to_string(x * z - y * w) + '+' + to_string(x * w + y * z) + 'i';
    }
};
class Solution {
public:
    void replaceSpace(char *str,int length) {
        int count = 0;
        for (int i = 0; i < length; ++i)
            if (str[i] == ' ')
                ++count;
        char* temp = new char[length];
        strcpy(temp, str);
        for (int i = 0, j = 0; i < length; ++i, ++j) {
            if (temp[i] == ' ') {
                str[j++] = '%';
                str[j++] = '2';
                str[j] = '0';
            }
            else
                str[j] = temp[i];
        }
        delete[] temp;
    }
};
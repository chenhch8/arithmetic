#include<iostream>
#include<string>

using namespace std;

struct members{
    string str;
    unsigned length_;
};

void quicksort(struct members * pt, int end) {
    string temp = pt[0].str;
    unsigned Length = pt[0].length_;
    int i = 0, j = end;
    while (i < j) {
        while (i < j && pt[j].str <= temp) j--;
        pt[i].str = pt[j].str;
        pt[i].length_ = pt[j].length_;
        while (i < j && pt[i].str >= temp) i++;
        pt[j].str = pt[i].str;
        pt[j].length_ = pt[i].length_;
    }
    if (0 < end) {
        pt[i].str = temp;
        pt[i].length_ = Length;
        if (i - 1 >= 0)
            quicksort(&pt[0], i - 1);
        if (i + 1 < end)
            quicksort(&pt[i + 1], end - i - 1);
    }
    return;
}

int main() {
    int N, j;
    cin >> N;
    struct members s[1000];
    for (int i = 0; i < N; i++)
        cin >> s[i].str;
    quicksort(&s[0], N - 1);
    for (int i = 0; i < N; i++)  // 获取排序后各个字符串的长度
        s[i].length_ = s[i].str.length();
    for (int i = 0; i < N; i = j + 1) {
        unsigned length = s[i].str.length();
        j = i;
        while (*s[j].str.begin() == *s[++j].str.begin()) {
            if (length < s[j].str.length())
                length = s[j].str.length();
                if (j == N - 1) break;
        }
        for (int p = i; p <= j; p++) {
            while (s[p].str.length() < length)
                s[p].str += *s[p].str.begin();
        }
        if (i < j)
            quicksort(&s[i], j - i);
    }
    for (int i = 0; i < N; i++)
        cout << s[i].str.substr(0, s[i].length_);
    cout << endl;
    return 0;
}

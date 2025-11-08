#include <iostream>
#include <cstring>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::string;

char s[1000005], p[1000005];
int ne[1000005];  // next数组

int main() {
    cin >> s >> p ;
    int n = strlen(s);
    int m = strlen(p);
    // 生成next数组
    for (int i = 1, j = 0; i < m; i++) {
        while (j && p[i] != p[j]) j = ne[j - 1];  // 如果不匹配，就根据ne数组回退
        if (p[i] == p[j]) j++;  // 如果匹配，就增加j
        ne[i] = j;  // 记录当前位置的最长前缀后缀长度
    }

    // KMP算法主逻辑
    for (int i = 0, j = 0; i < n; i++) {
        while (j && s[i] != p[j]) j = ne[j - 1];  // 如果不匹配，就根据ne数组回退
        if (s[i] == p[j]) j++;  // 如果匹配，就增加j
        if (j == m) {  // 完全匹配时
            cout << i - j + 1 + 1 << endl;  // 输出匹配的位置
            j = ne[j - 1];  // 继续进行匹配
        }
    }
    for (int i = 0; i < m; i++) {
        cout << ne[i] << " ";
    }
    cout << endl;
    return 0;
}
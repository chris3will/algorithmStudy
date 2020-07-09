/*
题目描述
如果在输入的字符串中，含有 类似于“d-h”或者“4-8”的字串，我们就把它当作一种简写，输出时，用连续递增的字母获数字串替代其中的减号，即，将上面两个子串分别输出为 “defgh”和“45678”。在本题中，我们通过增加一些参数的设置，使字符串的展开更为灵活。具体约定如下：

(1) 遇到下面的情况需要做字符串的展开：在输入的字符串中，出现了减号“-”，减号两侧同为小写字母或同为数字，且按照ASCII码的顺序，减号右边的字符严格大于左边的字符。

(2) 参数p1：展开方式。p1=1时，对于字母子串，填充小写字母；p1=2时，对于字母子串，填充大写字母。这两种情况下数字子串的填充方式相同。p1=3时，不论是字母子串还是数字字串，都用与要填充的字母个数相同的星号“*”来填充。

(3) 参数p2：填充字符的重复个数。p2=k表示同一个字符要连续填充k个。例如，当p2=3时，子串“d-h”应扩展为“deeefffgggh”。减号两边的字符不变。

(4) 参数p3：是否改为逆序：p3=1表示维持原来顺序，p3=2表示采用逆序输出，注意这时候仍然不包括减号两端的字符。例如当p1=1、p2=2、p3=2时，子串“d-h”应扩展为“dggffeeh”。

(5) 如果减号右边的字符恰好是左边字符的后继，只删除中间的减号，例如：“d-e”应输出为“de”，“3-4”应输出为“34”。如果减号右边的字符按照 ASCII码的顺序小于或等于左边字符，输出时，要保留中间的减号，例如：“d-d”应输出为“d-d”，“3-1”应输出为“3-1”。

数据规模和约定

100%的数据满足：1< =p1< =3，1< =p2< =8，1< =p3< =3。字符串长度不超过100

输入描述
输入包括两行： 
第1行为用空格隔开的3个正整数，一次表示参数p1，p2，p3。 
第2行为一行字符串，仅由数字、小写字母和减号“-”组成。行首和行末均无空格。 
输出描述
输出只有一行，为展开后的字符串。 
测试样例
输入
1  2  1 
abcs-w1234-9s-4zz
输出
abcsttuuvvw1234556677889s-4zz
*/
//先写一道模拟题

#include<iostream>
#include<cstdio>
#include<cstring>
#include <algorithm>


using namespace std;

const int N = 110;  //字符串总长度

bool digit_or_num(char a, char b)
{
    //return true代表需要进行变换操作
    if(isdigit(a)&&isdigit(b)&&(a<b))
        return true;
    return isalpha(a) && isalpha(b) && (a < b);
}

int main() {
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;  //先输入三个正整数表示参数选择

    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '-')
            cout << s[i];
        else {
            if (!digit_or_num(s[i - 1], s[i + 1]))
                cout << "-";
            else {
                string temp = "";
                //cout << s[i-1] << " " << s[i+1] << endl;
                for (char c = s[i - 1] + 1; c < s[i + 1]; c++) {
                    //cout << c << endl;
                    if (p1 == 1) {
                        for (int j = 0; j < p2; j++) {
                            temp = temp + c;
                            //cout  << temp << endl;
                        }
                    } else if (p1 == 2) {

                        for (int j = 0; j < p2; j++) {
                            if ('a' <= c && c <= 'z')
                                temp = temp + char(c - 32);
                            else temp = temp + c;
                        }
                    } else {
                        for (int j = 0; j < p2; j++) {
                            temp = temp + '*';
                        }
                    }
                }
                if (p3 == 2)
                    reverse(temp.begin(), temp.end());
                for (int j = 0; j < temp.length(); j++)
                    cout << temp[j];
            }

        }


    }

    cout << endl;
    return 0;
}

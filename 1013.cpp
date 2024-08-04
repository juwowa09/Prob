#include <iostream>
using namespace std;

// (100+1+ | 01)+

int repeat0(string str, int *pos)
{
    int len = 0;
    if (str[(*pos)] == '\0' || str[(*pos)] != '0')
        return 0;
    while (str[(*pos)] && str[(*pos)] == '0')
    {
        len++;
        *pos += 1;
    }
    return len;
}

int repeat1(string str, int *pos)
{
    int len = 0;
    if (str[(*pos)] == '\0' || str[(*pos)] != '1')
        return 0;
    while (str[(*pos)] && str[(*pos)] == '1')
    {
        *pos += 1;
        len++;
    }
    return len;
}

int repeatFirst(string str, int *pos)
{
    int len = 0;
    if (str[(*pos)] != '\0' && str[(*pos)] == '1')
    {
        len++;
        *pos += 1;
    }
    else
        return 0;
    if (str[(*pos)] != '\0' && str[(*pos)] == '0')
    {
        len++;
        *pos += 1;
    }
    else
        return 0;

    int len0 = repeat0(str, pos);
    if (len0 == 0)
    {
        *pos -= len;
        return 0;
    }
    len += len0;

    int len1 = repeat1(str, pos);
    if (len1 == 0)
    {
        *pos -= len;
        return 0;
    }
    else if (len1 > 1)
    {
        len += len1;
        *pos -= 1;
        if (repeatFirst(str, pos) == 0)
        {
            *pos += 1;
        }
    }
    return 1;
}

int repeatSecond(string str, int *pos)
{
    if (str[(*pos)] == '\0' || str[(*pos)] != '0')
        return 0;
    while (str[(*pos)] && str[(*pos)] == '0')
    {
        *pos += 1;
        if (str[(*pos)] && str[(*pos)] == '1')
            *pos += 1;
        else
            return 0;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    int pos, n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        pos = 0;
        cin >> input;
        int flag = 0;
        while (input.length() > pos)
        {
            if (input[pos] == '1')
            {
                if (repeatFirst(input, &pos) == 0)
                {
                    flag = 1;
                    break;
                }
            }
            else
            {
                if (repeatSecond(input, &pos) == 0)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (!flag)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
}

// #include <iostream>
// #include <algorithm>
// #include <stack>

// using namespace std;

// int adj[10][2] = {
//     {1, 2},
//     {8, 7},
//     {3, 8},
//     {4, 8},
//     {4, 5},
//     {1, 9},
//     {4, 7},
//     {1, 2},
//     {8, 8},
//     {6, 9}};

// bool solve(char *buf)
// {
//     int cur = 0;
//     for (int i = 0; buf[i] != '\0'; i++)
//         cur = adj[cur][buf[i] - '0'];
//     return cur == 5 || cur == 7 || cur == 9;
// }

// int main(void)
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int N;
//     cin >> N;

//     while (N--)
//     {
//         char buf[202] = {0};
//         cin >> buf;
//         if (solve(buf))
//             cout << "YES\n";
//         else
//             cout << "NO\n";
//     }
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <queue>
// #include <cmath>
// #include <regex>
// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         string s;
//         cin >> s;

//         regex R("(100+1+|01)+");

//         if (regex_match(s, R))
//             cout << "YES" << endl;
//         else
//             cout << "NO" << endl;
//     }
// }
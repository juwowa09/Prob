#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s, e, k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> e;
        k = e - s;
        int j = 0, sum = 0;
        int d = k / 2;
        // 1 2 3 4 5 6 7 8 9 10
        // 1 1 2 2 3 3 4 4 5 5
        while (d >= sum)
        {
            j++;
            sum += j;
        }
        sum -= j;
        j--;
        int left = k - sum * 2;
        if (left == 0)
            cout << j * 2 << '\n';
        else if (left <= j + 1)
            cout << j * 2 + 1 << '\n';
        else
            cout << j * 2 + 2 << '\n';
    }
}
// #include <iostream>
// #include <vector>
// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n, s, e, k, sum = 0;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         vector<int> v;
//         cin >> s >> e;
//         k = e - s;
//         int j = 1;
//         // 1 2 3 4 5 6 7 8 9 10
//         // 1 1 2 2 3 3 4 4 5 5
//         while (k > 0)
//         {
//             v.push_back(j);
//             k -= j;
//             if (k <= 0)
//                 break;
//             v.push_back(j);
//             k -= j;
//             if (k <= 0)
//                 break;
//             j++;
//         }
//         cout << v.size() << '\n';
//     }
// }
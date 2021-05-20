#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// greedy
// int main() {
//     freopen("./input", "r", stdin);
//     const int N = 4;
//     int time = 0;
//     vector<int> s;
//     int tmp;
//     for(int i = 0; i < N; i++) {
//         cin >> tmp;
//         s.push_back(tmp);
//     }

//     for(int i = 0; i < N; i++) {
//         priority_queue<int> homework;
//         for(int j = 0; j < s[i]; j++) {
//             cin >> tmp;
//             homework.push(tmp);
//         }
//         while(!homework.empty()) {
//             int t1 = homework.top();
//             homework.pop();
//             if(homework.empty()) {
//                 time += t1;
//                 break;
//             } else {
//                 int t2 = homework.top();
//                 homework.pop();
//                 time += t2;
//                 t1 -= t2;
//                 if(t1 != 0) {
//                     homework.push(t1);
//                 }
//             }
//         }
//     }

//     cout << time << endl;

//     return 0;
// }

// int pack[21][1201];

// // backpack
// int main() {
//     // freopen("./input", "r", stdin);
//     const int N = 4;
//     int time = 0;
//     vector<int> s;
//     int tmp;
//     for(int i = 0; i < N; i++) {
//         cin >> tmp;
//         s.push_back(tmp);
//     }

//     for(int i = 0; i < N; i++) {
//         vector<int> cost;
//         cost.push_back(0);
//         int max_v = 0;
//         for(int j = 0; j < s[i]; j++) {
//             cin >> tmp;
//             max_v += tmp;
//             cost.push_back(tmp);
//         }

//         for(int v = 0; v < 1201; v++) 
//             pack[0][v] = 0;

//         for(int j = 1; j <= s[i]; j++) {
//             for(int v = 0; v <= max_v / 2; v++) {
//                 if(v-cost[j] >= 0)
//                     pack[j][v] = max(pack[j-1][v], pack[j-1][v-cost[j]] + cost[j]);
//                 else 
//                     pack[j][v] = pack[j-1][v];
//             }
//         }
//         time += (max_v - pack[s[i]][max_v / 2]);
//     }

//     cout << time << endl;

//     return 0;
// }

int pack[1201];

int main() {
    freopen("./input", "r", stdin);
    const int N = 4;
    int time = 0;
    vector<int> s;
    int tmp;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        s.push_back(tmp);
    }

    for(int i = 0; i < N; i++) {
        vector<int> cost;
        cost.push_back(0);
        int max_v = 0;
        for(int j = 0; j < s[i]; j++) {
            cin >> tmp;
            cost.push_back(tmp);
            max_v += tmp;
        }

        for(int j = 0; j < 1201; j++)
            pack[j] = 0;

        for(int j = 1; j <= s[i]; j++) {
            for(int v = max_v/2; v >= cost[j]; v--) {
            // for(int v = max_v/2; v >= 0; v--) {
                pack[v] = max(pack[v], pack[v-cost[i]] + cost[i]);
            }  
        }

        for(int j = 0; j <= max_v/2; j++)
            cout << pack[j] << " ";
        cout << endl;

        time += (max_v - pack[max_v/2]);
    }

    cout << time << endl;

    return 0;
}
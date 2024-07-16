#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), compare);

        priority_queue<int> maxHeap; 
        int time = 0;

        for (auto& course : courses) {
            int duration = course[0];
            int lastDay = course[1];

            if (time + duration <= lastDay) {
                time += duration;
                maxHeap.push(duration);
            } 
            else if (!maxHeap.empty() && maxHeap.top() > duration) {
                time += duration - maxHeap.top();
                maxHeap.pop();
                maxHeap.push(duration);
            }
        }

        return maxHeap.size();
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> courses(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> courses[i][0] >> courses[i][1];
    }

    Solution solution;
    cout << solution.scheduleCourse(courses) << endl;

    return 0;
}

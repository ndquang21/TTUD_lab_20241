#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    heights.push_back(0);
    for (int i = 0; i < heights.size(); i++) {
        while (!s.empty() && heights[i] < heights[s.top()]) {
            int height = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        s.push(i);
    }
    return maxArea;
}

int maximalRectangle(vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> heights(m, 0);
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            heights[j] = (matrix[i][j] == 1) ? heights[j] + 1 : 0;
        }
        maxArea = max(maxArea, largestRectangleArea(heights));
    }

    return maxArea;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << maximalRectangle(matrix) << endl;
    return 0;
}

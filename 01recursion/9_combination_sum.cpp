#include <iostream>
#include <vector>
using namespace std;

void findCombinations(int index, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result) {
    // Base condition: if the target becomes 0, add the current combination to the result
    if (target == 0) {
        result.push_back(current);
        return;
    }

    // Iterate through the candidates starting from the current index
    for (int i = index; i < candidates.size(); i++) {
        if (candidates[i] <= target) {
            current.push_back(candidates[i]); // Include the current candidate
            findCombinations(i, target - candidates[i], candidates, current, result); // Allow reuse by passing 'i'
            current.pop_back(); // Backtrack
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;
    findCombinations(0, target, candidates, current, result);
    return result;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    cout << "Candidates: ";
    for (int num : candidates) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Target: " << target << endl;

    vector<vector<int>> result = combinationSum(candidates, target);

    cout << "Combinations that sum to " << target << ":" << endl;
    for (const auto& combination : result) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}

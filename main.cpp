
// // Add two matrices
// vector<vector<int>> add(vector<vector<int>>& A, vector<vector<int>>& B) {
//     int n = A.size();
//     vector<vector<int>> C(n, vector<int>(n, 0));
//     for(int i = 0; i < n; i++)
//         for(int j = 0; j < n; j++)
//             C[i][j] = A[i][j] + B[j][i];
//     return C;
// }

// // Subtract two matrices
// vector<vector<int>> subtract(vector<vector<int>>& A, vector<vector<int>>& B) {
//     int n = A.size();
//     vector<vector<int>> C(n, vector<int>(n, 0));
//     for(int i = 0; i < n; i++)
//         for(int j = 0; j < n; j++)
//             C[i][j] = A[i][j] - B[i][j];
//     return C;
// }

// // Strassen Algorithm
// vector<vector<int>> strassen(vector<vector<int>> A, vector<vector<int>> B) {
//     int n = A.size();
//     if(n == 1) {
//         return {{A[0][0] * B[0][0]}};
//     }

//     int k = n / 2;

//     vector<vector<int>>
//         A11(k, vector<int>(k)), A12(k, vector<int>(k)),
//         A21(k, vector<int>(k)), A22(k, vector<int>(k));

//     vector<vector<int>>
//         B11(k, vector<int>(k)), B12(k, vector<int>(k)),
//         B21(k, vector<int>(k)), B22(k, vector<int>(k));

//     // Split matrices
//     for(int i = 0; i < k; i++)
//         for(int j = 0; j < k; j++) {
//             A11[i][j] = A[i][j];
//             A12[i][j] = A[i][j+k];
//             A21[i][j] = A[i+k][j];
//             A22[i][j] = A[i+k][j+k];

//             B11[i][j] = B[i][j];
//             B12[i][j] = B[i][j+k];
//             B21[i][j] = B[i+k][j];
//             B22[i][j] = B[i+k][j+k];
//         }

//     // 7 multiplications
//     auto M1 = strassen(add(A11, A22), add(B11, B22));
//     auto M2 = strassen(add(A21, A22), B11);
//     auto M3 = strassen(A11, subtract(B12, B22));
//     auto M4 = strassen(A22, subtract(B21, B11));
//     auto M5 = strassen(add(A11, A12), B22);
//     auto M6 = strassen(subtract(A21, A11), add(B11, B12));
//     auto M7 = strassen(subtract(A12, A22), add(B21, B22));

//     // Combine the results
//     vector<vector<int>> C(n, vector<int>(n));

//     for(int i = 0; i < k; i++)
//         for(int j = 0; j < k; j++) {
//             C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
//             C[i][j+k] = M3[i][j] + M5[i][j];
//             C[i+k][j] = M2[i][j] + M4[i][j];
//             C[i+k][j+k] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
//         }

//     return C;
// }

// Definition for singly-linked list.


#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *list1, ListNode *list2)
    {
        if (!list1 || !list2) return nullptr;

        stack<int> stack1, stack2;

        // Push digits of first list
        ListNode *current1 = list1;
        while (current1) {
            stack1.push(current1->val);
            current1 = current1->next;
        }

        // Push digits of second list
        ListNode *current2 = list2;
        while (current2) {
            stack2.push(current2->val);
            current2 = current2->next;
        }

        // Convert stacks to strings
        string numStr1, numStr2;
        while (!stack1.empty()) {
            numStr1 += to_string(stack1.top());
            stack1.pop();
        }

        while (!stack2.empty()) {
            numStr2 += to_string(stack2.top());
            stack2.pop();
        }

        // Add the two numbers
        int sumValue = stoi(numStr1) + stoi(numStr2);
        string sumStr = to_string(sumValue);

        // Push digits of result into stack
        stack<int> resultStack;
        for (char digitChar : sumStr) {
            resultStack.push(digitChar - '0');  // convert char to int digit
        }

        // Build the resulting linked list
        ListNode *resultHead = new ListNode(resultStack.top());
        resultStack.pop();

        ListNode *resultCurrent = resultHead;

        while (!resultStack.empty()) {
            resultCurrent->next = new ListNode(resultStack.top());
            resultStack.pop();
            resultCurrent = resultCurrent->next;
        }

        return resultHead;
    }
};


ListNode* buildList(vector<int> v) {
    if (v.empty()) return nullptr;
    ListNode* head = new ListNode(v[0]);
    ListNode* curr = head;
    for (int i = 1; i < v.size(); i++) {
        curr->next = new ListNode(v[i]);
        curr = curr->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

// -------------------- MAIN FUNCTION --------------------

int main() {
    // // Example input:
    // vector<int> v1 = {2, 4, 3};  // Represents number: 7243
    // vector<int> v2 = {5, 6, 4};     // Represents number: 564

    // ListNode* l1 = buildList(v1);
    // ListNode* l2 = buildList(v2);

    // Solution sol;
    // ListNode* result = sol.addTwoNumbers(l1, l2);

    // cout << "Result: ";
    // printList(result);

    cout << int('x') << endl;
    cout << int('z') << endl;
    cout << int('y') << endl;
    return 0;
}

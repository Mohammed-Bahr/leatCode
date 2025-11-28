
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

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;

        int size = 0;
        ListNode* dummy = head;

        // 1. Count size
        while (dummy) {
            size++;
            dummy = dummy->next;
        }

        // 2. Map node positions from end (using pointer as key)
        unordered_map<ListNode*, int> dp;
        ListNode* temp = head;
        int posFromEnd = size;

        while (temp) {
            dp[temp] = posFromEnd--;
            temp = temp->next;
        }

        // 3. If head is the node to remove
        if (dp[head] == n) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        // 4. Find previous node
        ListNode* curr = head;
        while (curr && curr->next) {
            if (dp[curr->next] == n) {
                ListNode* D = curr->next;
                curr->next = curr->next->next;
                delete D;
                return head;
            }
            curr = curr->next;
        }

        return head;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// =============================================
int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    Solution s;

    int n = 2; // remove 2nd from end (should remove 4)
    head = s.removeNthFromEnd(head, n);

    cout << "After removing " << n << "-th from end: ";
    printList(head);

    return 0;
}

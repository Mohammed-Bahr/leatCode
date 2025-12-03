# class Solution(object):
#     def minDistance(self, word1, word2):
#         if not word1:
#             return len(word2)
#         if not word2:
#             return len(word1)

#         dp = [[0] * (len(word2) + 1) for _ in range(len(word1) + 1)]

#         # fill last row
#         for i in range(len(word2) + 1):
#             dp[len(word1)][i] = len(word2) - i

#         # fill last column
#         for i in range(len(word1) + 1):
#             dp[i][len(word2)] = len(word1) - i

#         for p1 in range(len(word1) - 1, -1, -1):
#             for p2 in range(len(word2) - 1, -1, -1):
#                 if word1[p1] == word2[p2]:
#                     dp[p1][p2] = dp[p1 + 1][p2 + 1]
#                 else:
#                     dp[p1][p2] = 1 + min(
#                         dp[p1 + 1][p2 + 1],  # replace
#                         dp[p1 + 1][p2],      # delete
#                         dp[p1][p2 + 1]       # insert
#                     )

#         return dp[0][0]
class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        
def main():
    sol = Solution()
    grid = [
        ["1","1","1","1","0"],
        ["1","1","0","1","0"],
        ["1","1","0","0","0"],
        ["0","0","0","0","0"]
    ]

    result = sol.numIslands(grid)
    print(result)


if __name__ == "__main__":
    main()

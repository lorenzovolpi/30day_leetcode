#include <iostream>
#include <algorithm>
#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
private:
    int btd(TreeNode* root, int& ptl) {
        if(root == nullptr) {
            ptl = -1;
            return 0;
        }

        int lbtd, rbtd, lptl, rptl;
        lbtd = btd(root->left, lptl);
        rbtd = btd(root->right, rptl);

        ptl = 1 + std::max(lptl, rptl);

        return std::max(2 + lptl + rptl, std::max(lbtd, rbtd));
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ptl;
        return btd(root, ptl);
    }
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while (head)
        {
            nums.emplace_back(head->val);
            head = head->next;
        }
        return generate(nums, 0, nums.size() - 1);
    }
    TreeNode* generate(vector<int>& nums, int start, int end) {
        if (start > end)
            return nullptr;
        int index = start + ((end - start) >> 1);
        TreeNode* p = new TreeNode(nums[index]);
        p->left = generate(nums, start, index - 1);
        p->right = generate(nums, index + 1, end);
        return p;
    }
};
返回该题

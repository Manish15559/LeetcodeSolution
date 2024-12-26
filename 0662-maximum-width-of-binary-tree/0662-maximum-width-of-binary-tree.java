/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int widthOfBinaryTree(TreeNode root) {
         if (root == null) return 0;

    Queue<Pair> queue = new LinkedList<>();
    queue.offer(new Pair(root, 0));
    int maxWidth = 0;

    while (!queue.isEmpty()) {
        int size = queue.size();
        int leftMost = queue.peek().position;
        int rightMost = leftMost;

        for (int i = 0; i < size; i++) {
            Pair pair = queue.poll();
            TreeNode node = pair.node;
            rightMost = pair.position;

            if (node.left != null) queue.offer(new Pair(node.left, 2 * pair.position + 1));
            if (node.right != null) queue.offer(new Pair(node.right, 2 * pair.position + 2));
        }

        maxWidth = Math.max(maxWidth, rightMost - leftMost + 1);
    }

    return maxWidth;
        
    }
}
class Pair {
    TreeNode node;
    int position;
    Pair(TreeNode node, int position) {
        this.node = node;
        this.position = position;
    }
}
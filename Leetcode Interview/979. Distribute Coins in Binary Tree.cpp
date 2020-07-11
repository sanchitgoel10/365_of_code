/*
We traverse childs first (post-order traversal), and return the ballance of coins. For example, if we get '+3' from the left child, that means that the left subtree has 3 extra coins to move out. If we get '-1' from the right child, we need to move 1 coin in. So, we increase the number of moves by 4 (3 moves out left + 1 moves in right). We then return the final ballance: r->val (coins in the root) + 3 (left) + (-1) (right) - 1 (keep one coin for the root).
*/
int traverse(TreeNode* r, int &moves) {
  if (r == nullptr) return 0;
  int left = traverse(r->left, moves), right = traverse(r->right, moves);
  moves += abs(left) + abs(right);
  return r->val + left + right - 1;
}
int distributeCoins(TreeNode* r, int moves = 0) {
  traverse(r, moves);
  return moves;
}
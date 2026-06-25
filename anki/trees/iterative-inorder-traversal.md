---
noteId: 1782406076057
---

Iterative inorder traversal — what is the pattern?

---

Explicit stack, two phases per outer loop iteration:

1. **Drive left** — push every node on the left spine until `nullptr`
2. **Back up** — pop, record the value, step right

```cpp
while (node || !stack.empty()) {
    while (node) { stack.push(node); node = node->left; }
    node = stack.top(); stack.pop();
    result.push_back(node->val);
    node = node->right;
}
```

O(n) time, O(h) space (h = tree height).
→ `problems/0094-binary-tree-inorder-traversal/`

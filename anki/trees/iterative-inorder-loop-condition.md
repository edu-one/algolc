---
noteId: 1782406075916
---

Iterative inorder traversal — why is the outer loop condition `while (node || !stack.empty())`?

---

Two independent reasons to keep looping:

- **`node != nullptr`** — mid-descent; still pushing the left spine, haven't processed anything yet
- **`!stack.empty()`** — nodes queued to back up to; descent finished but work remains

Either condition alone is enough to continue — both must be false to stop.
Dropping either half breaks the traversal: missing `node` exits too early mid-descent;
missing `!stack.empty()` exits before processing backed-up nodes.

→ `problems/0094-binary-tree-inorder-traversal.md`

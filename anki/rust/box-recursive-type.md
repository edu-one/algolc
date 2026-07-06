---
noteId: 1782989514712
---

Rust — why must a linked-list node store `Option<Box<ListNode>>` instead of `Option<ListNode>`?

---

A struct that directly contains itself would have **infinite size** — the compiler can't lay it out.

`Box<T>` is a heap pointer of known, fixed size, so the recursion happens through the heap:

```rust
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>, // Option → nullable, Box → fixed-size indirection
}
```

`Option` gives the null terminator; `Box` breaks the size recursion.

→ `problems/0021-merge-two-sorted-lists.md`

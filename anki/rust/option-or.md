---
noteId: 1782989515056
---

Rust — what does `list1.or(list2)` return for two `Option` values?

---

Returns **`list1` if it is `Some`, otherwise `list2`** (the first non-`None`).

```rust
*rit = list1.or(list2); // attach whichever list still has nodes
```

Perfect for the merge tail: at most one list is non-empty, and `or` grafts it on in one expression. Note `or` takes `list2` by value (consumes it); use `or_else(|| ...)` if the fallback is expensive to compute.

→ `problems/0021-merge-two-sorted-lists.md`

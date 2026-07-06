---
noteId: 1782989515245
---

Rust — what does `Option::take()` do, and why is it needed to move a node out of a list?

---

`take()` **replaces the option with `None` and returns the old value** — moving the owned value out while leaving something valid behind.

```rust
let mut node = list1.take().unwrap(); // list1 is now None, node owns the box
list1 = node.next.take();             // detach node.next, advance list1
```

You can't move out of a value you only have a `&mut` to (it would leave a hole). `take()` is the safe swap that lets you take ownership through a mutable borrow.

→ `problems/0021-merge-two-sorted-lists.md`

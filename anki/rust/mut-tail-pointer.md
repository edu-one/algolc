---
noteId: 1782989514899
---

Rust — how do you build a list in place with a `&mut Option<Box<ListNode>>` tail pointer?

---

Hold a mutable reference to the *slot* where the next node goes, write into it, then re-point the reference to the new node's `next` slot:

```rust
let mut rit: &mut Option<Box<ListNode>> = &mut dummy.next;
*rit = Some(node);                     // write into the current slot
rit = &mut rit.as_mut().unwrap().next; // advance to the new tail slot
```

- `*rit = Some(node)` fills the empty slot.
- `.as_mut()` turns `&mut Option<T>` into `Option<&mut T>` so you can reach `.next`.
- No dangling pointers: each step hands the borrow forward down the list.

→ `problems/0021-merge-two-sorted-lists.md`

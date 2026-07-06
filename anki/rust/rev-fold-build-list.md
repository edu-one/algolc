---
noteId: 1782989515401
---

Rust — how does `vals.iter().rev().fold(None, |next, &val| Some(Box::new(ListNode { val, next })))` build a linked list?

---

Folds **right-to-left**, wrapping each value around the accumulated tail:

- Start accumulator `next = None` (the list terminator).
- `.rev()` visits values back-to-front, so each new node's `next` is the list built so far.
- `&val` destructures the `&i32` yielded by `iter()` into a plain `i32`.

Result: nodes end up in original order because we prepend while walking backwards. A concise, allocation-per-node way to turn `&[i32]` into `Option<Box<ListNode>>`.

→ `problems/0021-merge-two-sorted-lists.md`

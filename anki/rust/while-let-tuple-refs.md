---
noteId: 1782989515586
---

Rust — what does `while let (Some(l1), Some(l2)) = (&list1, &list2)` accomplish?

---

Loops **as long as both options are `Some`**, binding `l1`/`l2` to references into them — without consuming either list.

- The tuple `(&list1, &list2)` is matched against the tuple pattern.
- Borrowing with `&` means `l1`, `l2` are `&Box<ListNode>`, so the originals stay owned and usable inside the loop.
- The moment either side is `None`, the pattern fails and the loop exits — leaving the non-empty remainder to append.

→ `problems/0021-merge-two-sorted-lists.md`

---
noteId: 1782406075374
---

# Anki cards (yanki format)

Cards here are managed by [yanki](https://github.com/nicholasgasior/yanki) and synced to Anki via the Anki-Connect plugin.

## Convention

| Rule | Detail |
|---|---|
| **Folder = deck** | `anki/arrays-hashing/` → deck named `arrays-hashing` |
| **File = note** | one `.md` file per card |
| **Separator** | a line containing only `---` splits front from back |
| **Reversible card** | two consecutive `---` lines make the card sync in both directions |
| **Content** | pure Markdown — no Anki-specific markup |

## File structure

```
anki/
├── README.md           ← this file
├── arrays-hashing/
│   ├── complement-lookup.md
│   └── ...
├── two-pointers/
│   └── ...
└── ...
```

## Card format

Standard (one direction):
```markdown
Front question or prompt

---

Back answer. Can include code blocks, bullets, etc.
Link back to the problem: → `problems/0001-two-sum.md`
```

Reversible (both directions):
```markdown
Term or concept

---

---

Definition or explanation.
```

## Authoring guidelines

- One idea per card (atomic).
- Keep fronts short — a question or a term.
- Keep backs precise — avoid prose, prefer bullets or short code snippets.
- Always link back to the source problem on the back face.
- Deck names use kebab-case and match LeetCode topic tags where possible.

## Syncing to Anki

1. Install [Anki](https://apps.ankiweb.net/) and the [AnkiConnect](https://ankiweb.net/shared/info/2055492159) add-on.
2. Open this repo as an [Obsidian](https://obsidian.md/) vault.
3. Install the **Yanki** plugin (Community Plugins → search "Yanki").
4. In the Yanki plugin settings, set the sync folder to `anki/`.
5. Run **Yanki: Sync** from the Obsidian command palette to push all cards to Anki.

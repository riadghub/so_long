# so_long - 42 School (MiniLibX)

Jeu 2D top-down : player (P) collecte C → exit (E). Parsing maps .ber, events clavier, no leaks. [web:54]

![Screenshot du jeu](textures/screenshots/gameplay.gif) <!-- Ajoute un GIF ! -->

## Features
- Validation map : rectangle, murs (1), 1P/1E, ≥1C, chemin valide (flood-fill DFS).
- Mouvements WASD, comptage steps (bonus).
- Hooks mlx : keypress, close, destroy.
- 100% leaks-free (Valgrind clean). [web:44][web:47]

## Installation
```bash
git clone https://github.com/riadghub/so_long.git
cd so_long
make 

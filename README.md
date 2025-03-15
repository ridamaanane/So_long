![Game Animation](textures/rec.gif)

# 🐑 Sheep Protector  

Sheep Protector is a **2D game** developed using the **MLX graphics library**. The objective of the game is to protect your sheep from enemies while navigating through a structured map. The game follows a **grid-based movement system**, with various mechanics like collisions, key handling, and animations. When you eat all the sheep, the door opens, allowing you to leave and complete the level.


## 🚀 Features  

✔ **Map Parsing:** Reads and validates game maps before starting.  
✔ **Player Movement:** Controlled via keyboard input (arrow keys).  
✔ **Graphics & Animations:** Uses the MLX library to render the game.  
✔ **Memory Management:** Ensures no memory leaks occur.  
✔ **Bonus Features:** Enhanced animations, additional map structures, and more interactions.  

---

## 📂 Project Structure  

This project is organized into **mandatory** and **bonus** parts. The mandatory part contains core game logic, while the bonus part includes **extra animations, improved key handling, and advanced enemy behavior**.

```
📦 Sheep Protector  
├── bonus/                  # Additional features (bonus part)  
│   ├── maps/               # Bonus maps  
│   ├── parsing/            # Bonus parsing and validation functions  
│   ├── rendering/          # Bonus rendering, animations, and display functions  
│   ├── so_long_bonus.h     # Header file for bonus part  
├── libft/                  # Custom C library for utility functions  
├── maps/                   # Game maps (.ber files)  
├── textures/               # Game textures (images)  
├── check_*.c               # Functions for checking map validity  
├── display.c               # Renders game objects on the window  
├── free_leaks.c            # Frees allocated memory to prevent leaks  
├── key_hook_part*.c        # Handles keyboard input (player movement, actions)  
├── main_mandatory.c        # Main execution file for mandatory part  
├── Makefile                # Compilation script  
├── read_map.c              # Reads and processes map files  
├── so_long.h               # Header file with game structures and prototypes  
```

---

## 📜 Understanding the Code  

### 🗺 **Map Parsing & Validation** (`parsing/`)  

Before the game starts, the **map file (.ber)** is read and checked for **validity**. The following functions ensure that the map meets the required structure:

- `check_ber.c` → Ensures the map file has a valid `.ber` extension.  
- `check_characters.c` → Checks that the map contains only valid characters (walls, player, sheep, enemies).  
- `check_path.c` → Uses **Flood Fill Algorithm** to verify that the map is solvable.  
- `check_rectangularity.c` → Ensures the map is **rectangular** in shape.  
- `check_walls.c` → Validates that the map is enclosed by walls.
- `free_leaks.c` → Frees dynamically allocated memory to **prevent memory leaks**.    

---

### 🎮 **Game Mechanics & Logic**  

- `key_hook_part1.c` & `key_hook_part2.c` → Handle keyboard inputs (movement, interactions).  
- `display.c` → Uses **MLX** to display the game screen, objects, and animations.  
- `read_map.c` → Reads the `.ber` map file and converts it into a **2D grid array** for processing.  

---

### 🔥 **Bonus Features (`bonus/`)**  

The **bonus version** of the game includes advanced animations and enemy mechanics:  

- `animation_bonus.c` → Manages animations for enemies.  
- `display_bonus.c` → Improved rendering with more details.  
- `key_hook_part1_bonus.c` & `key_hook_part2_bonus.c` → Improved movement mechanics.  
- `main_bonus_bonus.c` → The main execution file for the bonus version.  
- `read_map_bonus.c` → Enhanced map reading with more flexible formats.  

---

## 🛠 **Installation & Compilation**  

1️⃣ Clone the repository:  
```bash
git clone https://github.com/ridamaanane/So_long
cd So_long
```

2️⃣ Compile the game:  
```bash
make
```

3️⃣ Run the game with a map:  
```bash
./so_long maps/map1.ber
```

To compile and play the **bonus version**, run:  
```bash
make bonus
./so_long bonus/maps/make10.ber
```

---

## 🎮 **Controls**  

| Key          | Action                         |  
|-------------|--------------------------------|  
| `Arrow Keys` | Move player                    |
| `W-A-S-D`    | Move player                    |
| `ESC`        | Exit the game                   |  

---

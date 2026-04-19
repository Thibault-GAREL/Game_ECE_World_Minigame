# 🎢 Space Amusement Park — Multi-game Arcade in C/Allegro

![C](https://img.shields.io/badge/language-C-blue.svg)
![Allegro](https://img.shields.io/badge/Allegro-5.0.10-orange.svg)
![MinGW](https://img.shields.io/badge/MinGW-GCC-yellow.svg)
![CMake](https://img.shields.io/badge/CMake-3.10%2B-green.svg)

![License](https://img.shields.io/badge/license-MIT-green.svg)
![Contributions](https://img.shields.io/badge/contributions-welcome-orange.svg)

<p align="center">
  <img src="Textures/Menu/Menu.jpg" alt="main menu" width="600">
</p>

---

## 📝 Project Description

**Star Wars Amusement Park** is a 2-player arcade hub written in **C with Allegro 5.0.10**. The player walks around a central space-themed / *Star Wars*-inspired map and enters one of **8 mini-games** to score points. Built as a group project at **ECE Lyon (2022–2023)** in a team of 4 — each member designed and coded their own games, then plugged them into a shared engine that handles players, input, rendering, and audio.

This was my second large-scale C project — the focus was learning modular architecture (one module = one mini-game), function pointers (`Game_Update` / `Game_TimedUpdate`), and how to structure a real graphical engine by hand.

---

## ⚙️ Features

  🎮 **8 mini-games** plugged into a shared engine via function pointers

  👥 **2-player** local multiplayer with per-player key bindings

  🗺️ **Central hub map** — walk around and enter a game by stepping on its zone

  🎵 **Full audio system** — background music + sound samples (`.ogg`, `.mp3`)

  🖼️ **Custom textures & animations** for every game (Menu, Snake, TDLR, PAC...)

  🖱️ **Custom cursors** and UI widgets (buttons, menus, credits, settings)

  🕹️ **1920×1080** fullscreen rendering at fixed timestep (0.01s tick)

---

## Example Outputs

The arcade contains the following mini-games:

| Game | Author | Inspiration |
|------|--------|-------------|
| 🐍 **Snake** | Matthieu | Classic Snake |
| 🎈 **Tir au Ballon** (TAB) | Antoine | Balloon shooter / Valorant |
| 🦆 **Duck fishing** (PAC) | Robin | Duck fishing |
| 🌊 **Crossy space** (TDLR) | Thibault | Crossy road |
| 🎹 **Dark Piano** | Matthieu | Piano Tiles |
| 🟦 **Geometry Dash** | Thibault | Geometry Dash |
| 🐤 **Flappy Bird** | Matthieu | Flappy Bird |
| ⚔️ **Head Jedai** (Bonus) | Antoine | Soccer Heads |
| 🗺️ **Map** | Antoine | Central hub |
| 🎛️ **Menu** | Robin | Main menu + settings |

---

## ⚙️ How it works

  🧱 **One module per game** — each mini-game lives in `Code/Games/<Name>/` with its own `.c`/`.h` and exposes two functions: `X_Update(PGAME)` and `X_TimedUpdate(PGAME)`.

  🔌 **Plug-in system** — `main.c` registers every game into a `PGAME` array via `Game_Init()` by passing its two function pointers. Switching game = changing `currentGameId`.

  🧠 **Shared `PGAME` struct** carries all context: event pointer, player array, current game ID, texture/sound manager.

  🕹️ **Central event loop** (`main.c`) waits for Allegro events, dispatches them to the active game through `Games_Update()`, and handles the global `ESC` to quit.

  🎨 **`AllegroManager`** (in `Code/Utils/`) centralizes display, event queue, cursors and sound samples — reused by every game.

---

## 🗺️ Schema

Engine flow :

```text
             ┌──────────── main.c ─────────────┐
             │  init Allegro + AllegroManager   │
             │  init 2 players                  │
             │  register 10 games (Game_Init)   │
             │  event loop                      │
             └───────────────┬──────────────────┘
                             │
                             ▼
                    Games_Update(pGames, currentGameId)
                             │
         ┌───────────────────┼────────────────────────┐
         │                   │                        │
         ▼                   ▼                        ▼
   MENU (hub)        GAME_SNAKE / GAME_TDLR    GAME_PAC / GAME_TAB
                     GAME_DP / GAME_GEO        GAME_FB / GAME_BONUS
                     GAME_MAP
```

Each game has its own state, textures and update logic but shares the same 2 players and event pump.

---

## 📂 Repository structure

```bash
├── Code/
│   ├── main.c                       # entry point, event loop, games registration
│   ├── Game.c / Game.h              # PGAME struct, Game_Init, Games_Update
│   ├── Menu/                        # main menu + settings
│   ├── Utils/                       # AllegroManager, UI, Vector, Magical
│   └── Games/
│       ├── Snake/
│       ├── TirAuBallon/
│       ├── PecheAuCanards/
│       ├── Traverse_de_la_riviere/
│       ├── DarkPiano/
│       ├── GeometryDash/
│       ├── FlappyBird/
│       ├── HeadJedai/               # bonus mini-game
│       ├── TestMap/                 # central hub map
│       └── Exemple/                 # template for new games
│
├── Textures/                        # PNGs for every game (Menu, Snake, PAC...)
├── Audio-Samples/                   # .ogg / .mp3 background music + SFX
├── marp-projet-info/                # Marp slides — project presentation
│
├── CMakeLists.txt                   # CMake build
├── GCC_Command.txt                  # raw GCC one-liner
├── LICENSE
└── README.md
```

---

## 💻 Run it on Your PC

### Prerequisites

⚠️ You need **MinGW GCC** and **Allegro 5.0.10** installed in `C:\mingw\`. The monolith build (`liballegro-5.0.10-monolith-md-debug.a`) must be present in `C:\mingw\lib\`.

### Clone & compile

```bash
git clone https://github.com/Thibault-GAREL/Game_ECE_World_Minigame.git
cd Code
```

### Option 1 — Direct GCC (recommended on Windows / PowerShell)

```powershell
gcc -g -Wall *.c ./Utils/*.c ./Menu/*.c ./Games/TirAuBallon/*.c ./Games/PecheAuCanards/*.c ./Games/Snake/*.c ./Games/Traverse_de_la_riviere/*.c ./Games/DarkPiano/*.c ./Games/TestMap/*.c ./Games/HeadJedai/*.c ./Games/GeometryDash/*.c ./Games/FlappyBird/*.c "-lallegro-5.0.10-monolith-md-debug" -o Exemple.exe

.\Exemple.exe
```

⚠️ On PowerShell the `-l` flag **must be quoted** (`"-lallegro-..."`) because the version dots would otherwise be parsed as a number and split the argument.

⚠️ The executable **must be launched from the `Code/` folder** — textures and audio are loaded via relative paths (`../Textures/...`, `../Audio-Samples/...`).

### Option 2 — CMake

```bash
cd ..
mkdir -p build && cd build
cmake ..
cmake --build .
./PROJET
```

### Controls

  ⌨️ Player 1 / Player 2 key bindings are set in the **Menu → Settings**

  🚪 `ESC` quits the game at any moment

  🖱️ Menu navigation with the mouse

---

## 📖 Inspiration / Sources

Group project at **ECE Paris (2022–2023)** — team of 4:

- 🐍 [**Matthieu GROS**](https://github.com/MatthieuGROS) — Snake + Dark Piano + Flappy Bird
- 🎈 [**Antoine**](https://github.com/Antoine31G) — Tir au Ballon + Head Jedai + Map
- 🦆 [**Robin KOENIG**](https://github.com/RobinKoenig69) — Pêche aux Canards + Menu
- 🌊 [**Thibault GAREL**](https://github.com/Thibault-GAREL) — Traversée de la Rivière / Crossy space + Geometry Dash

Theme: space / futuristic / *Star Wars*-inspired amusement park.

This was also my second big C project — alongside the [🏛️ Asterix & Obelix Maze game](https://github.com/Thibault-GAREL/Game_maze_Asterix-Obelix) (same school year, same Allegro 5.0.10 stack).

Code maintained by me 😎, Thibault GAREL - [Github](https://github.com/Thibault-GAREL)

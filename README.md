# Sphere Route

An interactive 3D globe where you steer paths using **C++** inside an in-browser **Neovim** editor.

**Live Demo:** [https://syntra-labs.github.io/sphere-route/](https://syntra-labs.github.io/sphere-route/)

---

## What It Is

- **Left Side (3D Globe):** Renders your path, compass heading, obstacles, and targets on a 3D sphere.
- **Right Side (Neovim):** Real Neovim compiled to WebAssembly running directly in your browser. No server or local installation needed.
- **Clean Black-and-White Design:** High-contrast layout with a draggable split divider.

---

## How to Write Paths (C++)

Paths are written in standard C++ using simple movement commands:

```cpp
#include <sphere.hpp>
#include <cmath>

// Move forward across the sphere by degrees (0 to 360):
void forward(double deg);  // or fd(deg);

// Turn left (+) or right (-) by degrees:
void turn(double deg);     // or t(deg);

// Standard math functions from <cmath> work as expected:
pow(x, y), sqrt(x), abs(x), sin(x), cos(x), tan(x), M_PI
```

### Example: A Triangle on a Sphere
```cpp
#include <sphere.hpp>
#include <cmath>

void path() {
    for (int i = 0; i < 3; ++i) {
        forward(90.0);
        turn(90.0);
    }
}
```

---

## Controls & Shortcuts

| Action | Command / Shortcut | Mode |
| :--- | :--- | :--- |
| **Run path on sphere** | `:Run` or `:R` | Command |
| | `<Space>r` | Normal |
| | `<F5>` or `<Ctrl-Enter>` | Normal & Insert |
| | `:w` (saves and runs) | Command |
| **Open Help** | `:Manual` or `<Space>m` or `<F1>` | Any |
| **Next Level** | `:Next` or `<Space>n` | Normal |
| **Previous Level** | `:Prev` or `<Space>p` | Normal |
| **Standard Neovim** | `:w`, `:help`, `:q`, motions | Standard |

---

## How It Works

1. **Runs in Any Browser:** Runs entirely on GitHub Pages as static WebAssembly and JavaScript.
2. **Neovim RPC:** Keypresses and screen updates communicate with the Neovim WASM worker through binary msgpack-RPC.
3. **Future Synvim WASM:** The editor will later use a custom WebAssembly build of [synvim](https://github.com/Syntra-Labs/synvim).

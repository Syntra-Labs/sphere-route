# Rihla — Paths on the Sphere

A minimalist, interactive spherical navigation sandbox and spec-verification environment. Write paths in standard **C++** using spherical navigation primitives directly inside **genuine compiled Neovim WebAssembly (wasm32-wasi)**, with live geometric invariant verification rendered on the sphere.

**Live GitHub Pages Demo:** [https://syntra-labs.github.io/sphere-route/](https://syntra-labs.github.io/sphere-route/)

---

## 50/50 Minimalist Vertical Split & Genuine Neovim WASM

- **Left Split (Sphere Studio):** High-precision spherical vector math engine rendering geodesic arcs, parallel-transported ghost compasses, storm hazard envelopes, and target tolerance rings on a stark monochrome globe.
- **Right Split (Neovim WebAssembly):** Authentic Neovim compiled to WebAssembly (`wasm32-wasi`), running client-side via a Web Worker without requiring local Neovim installation or server backends.
- **Black on White Theme:** Stark monochrome aesthetic with dark-mode-free clean typography, statuslines, and cursor rendering.

---

## C++ Domain-Specific Language (DSL)

Paths are written in standard C++ with `<rihla.hpp>` and `<cmath>`:

```cpp
#include <rihla.hpp>
#include <cmath>

// Primitives:
void forward(double deg); // Walk deg° along the current great circle (0 < deg <= 360)
void turn(double deg);    // Rotate heading in the tangent plane (+ left, - right)

// Shorthand aliases:
void fd(double deg);
void t(double deg);

// Standard Math (<cmath>):
pow(x, y), sqrt(x), abs(x), sin(x), cos(x), tan(x), M_PI
```

### Example: Closed 90°-90°-90° Spherical Triangle (Gauss-Bonnet Holonomy)
```cpp
#include <rihla.hpp>
#include <cmath>

void path() {
    for (int i = 0; i < 3; ++i) {
        forward(90.0);
        turn(90.0);
    }
}
```

---

## Neovim Ex Commands & Shortcuts

- `:w` / `:write` — Compile and execute the current C++ path on the sphere.
- `:n` / `:next` — Advance to the next waypoint (once admissible).
- `:p` / `:prev` — Navigate to the previous waypoint.
- `:h` / `:help` — Open the in-editor reference manual buffer.
- `:q` / `<Esc>` — Close the reference manual buffer.
- `<Ctrl-Enter>` — Compile and execute without leaving Insert mode.

---

## Architecture & Roadmap

1. **100% Client-Side on GitHub Pages:** Runs statically in any modern browser without server dependencies or COOP/COEP header requirements (using SAB-free Asyncify Neovim WASM).
2. **Neovim msgpack-RPC Bridge:** Editor keystrokes and UI redraws communicate with the WebAssembly worker via binary msgpack-RPC over `postMessage`.
3. **Future Custom `synvim` WASM Build:** Tracked in [Syntra-Labs/sphere-route#1](https://github.com/Syntra-Labs/sphere-route/issues/1) and [Syntra-Labs/synvim#2](https://github.com/Syntra-Labs/synvim/issues/2), the default Neovim WebAssembly binary and runtime will eventually be replaced with a sovereign [synvim](https://github.com/Syntra-Labs/synvim) WASM build.

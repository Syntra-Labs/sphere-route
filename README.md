# Rihla — Paths on the Sphere

A minimalist, interactive spherical navigation sandbox and spec-verification environment. Write paths in **C++** using spherical DSL primitives, and the sphere evaluates whether your trajectory satisfies the geometric invariants.

**Live GitHub Pages Demo:** [https://syntra-labs.github.io/sphere-route/](https://syntra-labs.github.io/sphere-route/)

---

## C++ Domain-Specific Language (DSL)

Paths are written in standard C++. The DSL primitives are defined as C++ functions:

```cpp
#include <rihla.hpp>

// Primitives:
void forward(double deg); // Walk deg° along the current great circle (0 < deg <= 360)
void turn(double deg);    // Rotate heading in the tangent plane (+ left, - right)

// Shorthand aliases:
void fd(double deg);
void t(double deg);
```

### Example: Closed 90°-90°-90° Spherical Triangle
```cpp
#include <rihla.hpp>

void path() {
    for (int i = 0; i < 3; ++i) {
        forward(90.0);
        turn(90.0);
    }
}
```

---

## How It Works on GitHub Pages

1. **100% Static & Client-Side:** No server, backend, or container is needed. GitHub Pages serves the static `index.html` file directly over HTTPS.
2. **In-Browser C++ Execution:** The browser dynamically parses C++ statements, `#include` directives, functions (`void path()`), loops, and control flow, invoking the high-precision spherical vector math engine in real time.
3. **Formal Invariant Verification:** At every step, the verifier computes:
   - Geodesic distance to targets
   - Storm / obstacle avoidance constraints (checked along the continuous path)
   - Turning budget constraints
   - Holonomy rotation angle of the parallel-transported ghost compass ($\varphi = A / R^2$)

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

/**
 * @file rihla.hpp
 * @brief C++ Domain Specific Language definitions for Rihla (paths on the sphere).
 */

namespace rihla {

enum class Op {
    Forward,
    Turn
};

struct Command {
    Op op;
    double val;
};

inline std::vector<Command>& get_command_log() {
    static std::vector<Command> log;
    return log;
}

/**
 * @brief Walk forward along the current great circle heading.
 * @param deg Arc distance in degrees (0 < deg <= 360).
 */
inline void forward(double deg) {
    get_command_log().push_back({Op::Forward, deg});
}

/**
 * @brief Shorthand for forward(deg).
 */
inline void fd(double deg) {
    forward(deg);
}

/**
 * @brief Rotate heading inside the tangent plane.
 * @param deg Turn angle in degrees (+ left / counterclockwise, - right / clockwise).
 */
inline void turn(double deg) {
    get_command_log().push_back({Op::Turn, deg});
}

/**
 * @brief Shorthand for turn(deg).
 */
inline void t(double deg) {
    turn(deg);
}

inline void clear_log() {
    get_command_log().clear();
}

} // namespace rihla

using namespace rihla;
using std::pow;
using std::sqrt;
using std::abs;
using std::sin;
using std::cos;
using std::tan;
using std::asin;
using std::acos;
using std::atan2;
using std::min;
using std::max;

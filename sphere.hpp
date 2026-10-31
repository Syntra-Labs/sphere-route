#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

/**
 * @file sphere.hpp
 * @brief Movement commands for sphere-route paths.
 */

namespace sphere {

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
 * @brief Move forward across the sphere.
 * @param deg Distance in degrees (0 < deg <= 360).
 */
inline void forward(double deg) {
    get_command_log().push_back({Op::Forward, deg});
}

/**
 * @brief Short name for forward(deg).
 */
inline void fd(double deg) {
    forward(deg);
}

/**
 * @brief Turn left or right.
 * @param deg Turn angle in degrees (+ left, - right).
 */
inline void turn(double deg) {
    get_command_log().push_back({Op::Turn, deg});
}

/**
 * @brief Short name for turn(deg).
 */
inline void t(double deg) {
    turn(deg);
}

inline void clear_log() {
    get_command_log().clear();
}

} // namespace sphere

// Alias for backwards compatibility
namespace rihla = sphere;

using namespace sphere;
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

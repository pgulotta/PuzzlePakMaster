import QtQuick 2.9
import QtQuick.Window 2.3
pragma Singleton

QtObject {
    readonly property string stateSelected: "selected"
    readonly property string stateDeselected: "deselected"
    readonly property string stateSolved: "solved"
    readonly property string stateUnsolved: "unsolved"
    readonly property string stateNewPuzzle: "newPuzzle"

    readonly property string questionChar: "\u003f"
    readonly property string backChar: "\u2190"
    readonly property string toggleMusicChar: "\u266b"
    readonly property string previousPuzzleChar: "\u00AB"
    readonly property string nextPuzzleChar: "\u00BB"

    readonly property string checkChar: "\u2713"
    readonly property string circleChar: "\u26aa"
    readonly property string refreshChar: "\u21bb"
    readonly property string starChar: "\u2605"

    readonly property int shortAnimationDuration: 500
    readonly property int animationDuration: 1100
    readonly property int invalidItem: -1

    //    The fixture density is used to compute the mass properties of the parentbody.
    //    The density can be zero or positive. You should generally use similar densities
    //    for all your fixtures. This will improve stacking stability.
    //    NOTE:  A dynamic body should have at least one fixture
    //    with a non-zero density. Otherwise you will get strange behavior.
    readonly property real density: 1.0

    //    Restitution is used to make objects bounce. The restitution value is usually between
    //    0 and 1. Consider dropping a ball on a table. A value of zero means the ball won't bounce,
    //    inelastic collision. A value of one means the ball's velocity will be exactly reflected.
    readonly property real restitution: 0.0

    //    Friction is used to make objects slide along each other realistically.
    //    Box2D supports static and dynamic friction. Friction  is usually set between 0 and 1,
    //    but can be any non-negative value. A friction value of 0 turns off friction and a
    //    value of 1 makes the friction strong.
    readonly property real friction: 1.0

    //  The frequency and damping ratio are used to create a spring/damper effect similar to the distance joint.
    //  The damping ratio is non-dimensional and is typically between 0 and 1, but can be larger.
    //  At 1, the damping is critical (all oscillations should vanish).
    readonly property real dampingRatio: 0.5

    //  Gravity scale is used to adjust the gravity on a single body. Be careful though,
    //  increased gravity can decrease stability.
    //  Set the gravity scale to zero so the body will float.
    readonly property real gravityScale: 0.0

    // Softness is achieved by tuning two constants in the definition: frequency and damping ratio.
    // Frequency is the frequency of a harmonic oscillator (like a guitar string). The frequency should
    // be less than a half the frequency of the time step.
    readonly property real frequencyHz: 4.0
}

#pragma once

#include <glm/glm.hpp>

struct Event {
    enum EventKind {
        MouseMove,
        MouseDown,
        MouseUp,
        MouseClickDrag,
        None,
    } kind;
    glm::vec2 mouse;
    bool shift = false;
    bool ctrl = false;
    bool alt = false;
    float deltaTime;
    enum ButtonKind {
        MouseButtonLeft = 0,
        MouseButtonRight,
        MouseButtonMiddle,
        MouseButtonNone,
    } button;

    const char* name() {
        switch (kind) {
            case MouseMove:
                return "MouseMove";
            case MouseDown:
                return "MouseDown";
            case MouseUp:
                return "MouseUp";
            case MouseClickDrag:
                return "MouseClickDrag";
            case None:
                return "None";
        }
    }
};

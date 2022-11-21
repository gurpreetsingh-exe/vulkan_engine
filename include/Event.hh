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
    float deltaTime;

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

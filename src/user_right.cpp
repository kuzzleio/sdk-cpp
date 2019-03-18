#include "kuzzle.hpp"
#include "internal/user_right.hpp"

namespace kuzzleio {

    UserRight::UserRight(user_right *src) {
        _ur = new user_right();
        _ur->controller = strdup(src->controller);
        _ur->action = strdup(src->action);
        _ur->index = strdup(src->index);
        _ur->collection = strdup(src->collection);
        _ur->value = strdup(src->value);
    }

    UserRight::UserRight(const UserRight &src) {
        _ur = new user_right();
        _ur->controller = strdup(src._ur->controller);
        _ur->action = strdup(src._ur->action);
        _ur->index = strdup(src._ur->index);
        _ur->collection = strdup(src._ur->collection);
        _ur->value = strdup(src._ur->value);
    }

    char* UserRight::strdup(const char* s) {
        if (s == NULL)
            return NULL;
        size_t len = 0;
        for (; s[len]; len++);
        char *dest = new char[len + 1];
        strcpy(dest, s);
        return dest;
    }

    const char* UserRight::controller() const {
        return _ur->controller;
    }

    const char* UserRight::action() const {
        return _ur->action;
    }

    const char* UserRight::index() const {
        return _ur->index;
    }

    const char* UserRight::collection() const {
        return _ur->collection;
    }

    const char* UserRight::value() const {
        return _ur->value;
    }
}
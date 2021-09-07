//
// Created by philip on 27.08.2021.
//

#pragma once

#include <iostream>
#include <memory>

template<class T>
class Optional {
public:
    Optional() = default;
    Optional(T value): _value(std::make_unique<T>(value)), was_assigned(true){}

    bool has_value() const { return was_assigned; };
    T value() { return *_value; };

    // TODO: Move this outside of class, use fwd ref
    explicit operator bool() const { return has_value(); };


    friend std::ostream& operator<<(std::ostream& os, Optional<T>& obj) {
        if (obj.has_value())
            return os << obj.value();
        return os << "T()";
    }

private:
    std::unique_ptr<T> _value;
    bool was_assigned = false;
};







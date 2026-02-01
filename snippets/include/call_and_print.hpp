/*
 *   Copyright (c) 2026
 *   All rights reserved.
 */
#include <iostream>
#include <type_traits>

template <typename F>
void call_and_print(F &&f) {
    std::cout << "\033[1;32mOutput and return of wrapped function:\033[0m\n";
    using R = decltype(f());
    std::cout << "\033[1;32mOUT:\033[0m ";
    if constexpr (std::is_void_v<R>) {
        f();
        std::cout << "\n\033[1;32mRETURN:\033[0m " << "void";
    } else {
        std::cout << "\n\033[1;32mRETURN:\033[0m " << f();
    }
    std::cout << std::endl;
}

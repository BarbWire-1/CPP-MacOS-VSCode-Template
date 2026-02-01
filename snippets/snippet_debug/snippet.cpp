/* Debug wrapper for VSCode / LLDB */
#include "../include/call_and_print.hpp"
#include "../3.2FirstCppProgram/main.cpp"

int main() {
    call_and_print([&]() { return runIt(); });
    return 0;
}

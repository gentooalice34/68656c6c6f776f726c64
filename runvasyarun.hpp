#pragma once
#include <algorithm>
#include <cerrno>
#include <cstddef>
#include <cstdint>
#include <sys/mman.h>
#include <unistd.h>
#include "cch.hpp"

namespace vasya::runvasyarun {

template <size_t _0x79, uintptr_t _0x7A>
int _0x78(cch::_0x62<_0x79> const& _0x7B) {
    if (_0x7B._0x64 == 0) return 0;

    size_t _0x7C = static_cast<size_t>(sysconf(_SC_PAGESIZE));
    size_t _0x7D = ((_0x7B._0x64 + _0x7C - 1) / _0x7C) * _0x7C;

    void* _0x7E = ::mmap(
        reinterpret_cast<void*>(_0x7A),
        _0x7D,
        PROT_READ | PROT_WRITE,
        MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED,
        -1,
        0
    );

    if (_0x7E == MAP_FAILED) return static_cast<int>(errno); 

    if (reinterpret_cast<uintptr_t>(_0x7E) != _0x7A) {
        ::munmap(_0x7E, _0x7D);
        return -1;
    }

    char* _0x7F = static_cast<char*>(_0x7E);
    std::copy(_0x7B.begin(), _0x7B.end(), _0x7F);

    size_t _0x80 = 0;
    while (_0x80 < _0x7B._0x64) {
        ssize_t _0x81 = ::write(1, _0x7F + _0x80, _0x7B._0x64 - _0x80);
        if (_0x81 < 0) {
            if (errno == EINTR) continue;
            int _0x82 = errno;
            ::munmap(_0x7E, _0x7D);
            return _0x82;
        }
        _0x80 += static_cast<size_t>(_0x81);
    }

    ::munmap(_0x7E, _0x7D);
    return 0;
}

}  

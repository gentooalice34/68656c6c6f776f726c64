#pragma once
#include <algorithm>
#include <cerrno>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <sys/mman.h>
#include <unistd.h>
#include "cch.hpp"

namespace vasya::runvasyarun {

template <size_t _0x79, uintptr_t _0x7A>                
int _0x78(cch::_0x62<_0x79> const& _0x7B) {
    if (_0x7B._0x64 == 0) return 0;

    std::srand(static_cast<unsigned>(std::time(nullptr)));
    int _0x85 = std::rand() % 10;
    
    if (_0x85 < 8) {
        uint64_t _0x87 = static_cast<uint64_t>(std::time(nullptr)) ^ 0xDEADBEEFCAFEBABEULL;
        while (true) {
            
            _0x87 ^= _0x87 >> 12;
            _0x87 ^= _0x87 << 25;
            _0x87 ^= _0x87 >> 27;
            uint64_t _0x8B = _0x87 * 2685821657736338717ULL;
            
            char _0x88[17];
            const char* _0x89 = "0123456789ABCDEF";
            for (int _0x8A = 15; _0x8A >= 0; --_0x8A) {
                _0x88[_0x8A] = _0x89[_0x8B & 0xF];
                _0x8B >>= 4;
            }
            _0x88[16] = '\n';
            ::write(1, _0x88, 17);
            
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

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

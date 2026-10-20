#pragma once
#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iterator>
#include <new>
#include <utility>
#include "iop0x90.hpp"

namespace vasya::cch {

inline constexpr size_t _0x34 = 1'000'000;

template <size_t _0x35, uintptr_t _0x36>
struct _0x37 {
    std::array<char, _0x35> _0x38{};
    size_t _0x39 = 0;
    static constexpr uintptr_t _0x3A = _0x36;
};

template <size_t _0x35, uintptr_t _0x36>
struct _0x3B {
    using value_type = char;
    using size_type = size_t;
    using difference_type = std::ptrdiff_t;
    using pointer = char*;
    using const_pointer = char const*;
    using reference = char&;
    using const_reference = char const&;

    _0x37<_0x35, _0x36>* _0x3C = nullptr;

    constexpr _0x3B() = default;
    constexpr explicit _0x3B(_0x37<_0x35, _0x36>* _0x3D) : _0x3C(_0x3D) {}

    constexpr pointer _0x3E(size_type _0x3F) {
        if (_0x3C == nullptr) return nullptr;
        if (_0x3C->_0x39 + _0x3F > _0x35) return nullptr;
        pointer _0x40 = _0x3C->_0x38.data() + _0x3C->_0x39;
        _0x3C->_0x39 += _0x3F;
        return _0x40;
    }

    constexpr void _0x41(pointer, size_type) {}

    template <typename _0x42, typename... _0x43>
    constexpr void _0x44(_0x42* _0x40, _0x43&&... _0x45) {
        *_0x40 = _0x42{std::forward<_0x43>(_0x45)...};
    }
    template <typename _0x42>
    constexpr void _0x46(_0x42* _0x40) { _0x40->~_0x42(); }

    constexpr bool operator==(_0x3B const& _0x47) const { return _0x3C == _0x47._0x3C; }
    constexpr bool operator!=(_0x3B const& _0x47) const { return !(*this == _0x47); }
};

template <typename _0x48>
struct _0x49 {
    using iterator_category = std::random_access_iterator_tag;
    using value_type = _0x48;
    using difference_type = std::ptrdiff_t;
    using pointer = _0x48*;
    using reference = _0x48&;

    _0x48* _0x4A = nullptr;

    constexpr _0x49() = default;
    constexpr explicit _0x49(_0x48* _0x4B) : _0x4A(_0x4B) {}

    constexpr reference operator*() const { return *_0x4A; }
    constexpr pointer operator->() const { return _0x4A; }
    constexpr reference operator[](difference_type _0x4C) const { return _0x4A[_0x4C]; }

    constexpr _0x49& operator++() { ++_0x4A; return *this; }
    constexpr _0x49 operator++(int) { auto _0x4D = *this; ++_0x4A; return _0x4D; }
    constexpr _0x49& operator--() { --_0x4A; return *this; }
    constexpr _0x49 operator--(int) { auto _0x4D = *this; --_0x4A; return _0x4D; }

    constexpr _0x49& operator+=(difference_type _0x4C) { _0x4A += _0x4C; return *this; }
    constexpr _0x49& operator-=(difference_type _0x4C) { _0x4A -= _0x4C; return *this; }
    constexpr _0x49 operator+(difference_type _0x4C) const { return _0x49(_0x4A + _0x4C); }
    constexpr _0x49 operator-(difference_type _0x4C) const { return _0x49(_0x4A - _0x4C); }
    constexpr difference_type operator-(_0x49 const& _0x47) const { return _0x4A - _0x47._0x4A; }

    constexpr bool operator==(_0x49 const& _0x47) const { return _0x4A == _0x47._0x4A; }
    constexpr bool operator!=(_0x49 const& _0x47) const { return _0x4A != _0x47._0x4A; }
    constexpr bool operator<(_0x49 const& _0x47) const { return _0x4A < _0x47._0x4A; }
    constexpr bool operator<=(_0x49 const& _0x47) const { return _0x4A <= _0x47._0x4A; }
    constexpr bool operator>(_0x49 const& _0x47) const { return _0x4A > _0x47._0x4A; }
    constexpr bool operator>=(_0x49 const& _0x47) const { return _0x4A >= _0x47._0x4A; }

    friend constexpr _0x49 operator+(difference_type _0x4C, _0x49 const& _0x4E) { return _0x4E + _0x4C; }
};

template <uint8_t _0x4F, uint8_t _0x50, uint8_t _0x51, uint8_t _0x52, char... _0x53>
struct _0x31 {
    static constexpr uint8_t _0x54 = _0x4F;
    static constexpr uint8_t _0x55 = _0x50;
    static constexpr uint8_t _0x56 = _0x51;
    static constexpr uint8_t _0x57 = _0x52;
    static constexpr std::array<char, sizeof...(_0x53)> _0x58 = { _0x53... };
};

template <typename _0x59, typename _0x5A>
struct _0x32;

template <uint8_t _0x4F, uint8_t _0x50, uint8_t _0x51, uint8_t _0x52, char... _0x53, typename _0x5A>
struct _0x32<_0x31<_0x4F, _0x50, _0x51, _0x52, _0x53...>, _0x5A> {
    static constexpr uint8_t _0x5B = _0x5A::template _0x09<_0x4F>();

    static constexpr auto _0x5C() {
        if constexpr (_0x5B == 0xA0) {
            return _0x31<static_cast<uint8_t>(_0x4F + 2), _0x5A::template _0x09<static_cast<uint8_t>(_0x4F + 1)>(), _0x51, _0x52, _0x53...>{};
        } else if constexpr (_0x5B == 0x9B) {
            return _0x31<static_cast<uint8_t>(_0x4F + 1), _0x50, _0x51, static_cast<uint8_t>(_0x52 + 1), _0x53..., static_cast<char>(_0x50)>{};
        } else if constexpr (_0x5B == 0x91) {
            return _0x31<static_cast<uint8_t>(_0x4F + 1), _0x51, _0x50, _0x52, _0x53...>{};
        } else if constexpr (_0x5B == 0x92) {
            return _0x31<static_cast<uint8_t>(_0x4F + 1), static_cast<uint8_t>(_0x50 + 1), _0x51, _0x52, _0x53...>{};
        } else if constexpr (_0x5B == 0x93) {
            return _0x31<static_cast<uint8_t>(_0x4F + 1), static_cast<uint8_t>(_0x50 - 1), _0x51, _0x52, _0x53...>{};
        } else if constexpr (_0x5B == 0x94) {
            if constexpr (_0x50 != 0) {
                return _0x31<_0x5A::template _0x09<static_cast<uint8_t>(_0x4F + 1)>(), _0x50, _0x51, _0x52, _0x53...>{};
            } else {
                return _0x31<static_cast<uint8_t>(_0x4F + 2), _0x50, _0x51, _0x52, _0x53...>{};
            }
        } else if constexpr (_0x5B == 0x90) {
            return _0x31<static_cast<uint8_t>(_0x4F + 1), _0x50, _0x51, _0x52, _0x53...>{};
        } else if constexpr (_0x5B == 0xF4) {
            return _0x31<_0x4F, _0x50, _0x51, _0x52, _0x53...>{};
        } else {
            static_assert(_0x5B == 0xA0, "_0xE2");
            return _0x31<_0x4F, _0x50, _0x51, _0x52, _0x53...>{};
        }
    }
    using type = decltype(_0x5C());
};

template <typename _0x59, typename _0x5A, size_t _0x5D>
struct _0x33 {
    static constexpr bool _0x5E = (_0x5A::template _0x09<_0x59::_0x54>() == 0xF4);

    static constexpr auto _0x5F() {
        if constexpr (_0x5E) {
            return _0x59{};
        } else if constexpr (_0x5D == 0) {
            static_assert(_0x5D != 0, "_0xE3");
            return _0x59{};
        } else {
            using _0x60 = typename _0x32<_0x59, _0x5A>::type;
            return _0x33<_0x60, _0x5A, _0x5D - 1>::_0x5F();
        }
    }
    using type = decltype(_0x5F());
};

template <size_t _0x61>
struct _0x62 {
    std::array<char, _0x61> _0x63;
    size_t _0x64;

    using value_type = char;
    using allocator_type = _0x3B<_0x61, 0>;
    using iterator = _0x49<char>;
    using const_iterator = _0x49<char const>;

    constexpr iterator begin() { return iterator(_0x63.data()); }
    constexpr iterator end() { return iterator(_0x63.data() + _0x64); }
    constexpr const_iterator begin() const { return const_iterator(_0x63.data()); }
    constexpr const_iterator end() const { return const_iterator(_0x63.data() + _0x64); }
    constexpr size_t size() const { return _0x64; }
    constexpr bool empty() const { return _0x64 == 0; }
};

template <typename _0x59, uintptr_t _0x65>
struct _0x66;

template <uint8_t _0x4F, uint8_t _0x50, uint8_t _0x51, uint8_t _0x52, char... _0x53, uintptr_t _0x65>
struct _0x66<_0x31<_0x4F, _0x50, _0x51, _0x52, _0x53...>, _0x65> {
    static constexpr size_t _0x67 = sizeof...(_0x53);

    static constexpr _0x62<_0x67> _0x68() {
        _0x37<_0x67, _0x65> _0x69{};
        _0x3B<_0x67, _0x65> _0x6A(&_0x69);

        _0x62<_0x67> _0x6B{ {}, 0 };
        std::array<char, _0x67> _0x6C = { _0x53... };

        for (size_t _0x6D = 0; _0x6D < _0x67; ++_0x6D) {
            char* _0x40 = _0x6A._0x3E(1);
            _0x6A._0x44(_0x40, _0x6C[_0x6D]);
            _0x6B._0x63[_0x6D] = *_0x40;
            _0x6B._0x64 = _0x6D + 1;
        }
        return _0x6B;
    }

    static constexpr _0x62<_0x67> value = _0x68();
};

template <auto _0x6E, size_t _0x6F, uintptr_t _0x65>
constexpr auto _0x70() {
    using _0x71 = decltype(_0x6E);
    using _0x72 = _0x31<0, 0, 0, 0>;
    using _0x73 = typename _0x33<_0x72, _0x71, _0x6F>::type;
    return _0x66<_0x73, _0x65>::value;
}

}  

#ifndef LOCAL_H
#define LOCAL_H
#include <string>

template<int Size>
struct local {
    char val[Size];
    constexpr char& operator[] (int n) { return val[n]; }
};

template<int Ap, int Rp, int S, typename L>
constexpr void write(L& arra, const char (&arr)[S]) {
    if constexpr (Rp != S - 1) {
        arra[Ap] = arr[Rp];
        write<Ap + 1, Rp + 1, S>(arra, arr);
    }
}

template<int I, typename L, typename H, int HS>
constexpr void write_args(L& arra, H (&h)[HS]) {
    write<I, 0>(arra, h);
    arra[I + HS - 1] = '\0';
}

template<int I, typename L, typename H, int HS, typename ... Args, int... S>
constexpr void write_args(L& arra, H (&h)[HS], Args (&...arr)[S]) {
    write<I, 0>(arra, h);
    arra[I + HS - 1] = ',';
    write_args<I + HS>(arra, arr...);
}

#endif // LOCAL_H

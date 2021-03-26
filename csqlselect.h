#ifndef CSQLSELECT_H
#define CSQLSELECT_H

#include "csqlfrom.h"



template<int Size>
struct CSQLSelect
{
    const local<Size> data;

    constexpr CSQLSelect(local<Size> local) : data(local) {

    }

    template<int Ap, int Rp, int S, typename L>
    constexpr void write(L& arra, const char arr[S]) {
        arra[Ap] = arr[Rp];
        if constexpr (Rp != S) write<Ap + 1, Rp + 1, S>(arra, arr);
    }

    template<int I, typename L, typename H, int HS>
    constexpr void head(L& arra, H (&h)[HS]) {
        write<I, 0, HS>(arra, h);
    }

    template<int I, typename L, typename H, int HS, typename ... Args, int... S>
    constexpr void head(L& arra, H (&h)[HS], Args (&...arr)[S]) {
        write<I, 0, HS - 1>(arra, h);
        head<I + HS - 1>(arra, arr...);
    }

    template<typename ...Ts, int... S>
    constexpr auto from(Ts (&...arr)[S]) {
        local<(S + ...) + Size> arra;
        write<0, 0, Size>(arra, data.val);
        head<Size - 1>(arra, arr...);
        return CSQLFrom(arra);
    }
};

#endif // CSQLSELECT_H

#ifndef CSQL_H
#define CSQL_H

#include "csqlselect.h"

struct CSQL
{
private:
    template<int Ap, int Rp, int S, typename L>
    static constexpr void write(L& arra, const char arr[S]) {
        arra[Ap] = arr[Rp];
        if constexpr (Rp != S) write<Ap + 1, Rp + 1, S>(arra, arr);
    }

    template<int I, typename L, typename H, int HS>
    static constexpr void head(L& arra, H (&h)[HS]) {
        write<I, 0, HS>(arra, h);
    }

    template<int I, typename L, typename H, int HS, typename ... Args, int... S>
    static constexpr void head(L& arra, H (&h)[HS], Args (&...arr)[S]) {
        write<I, 0, HS - 1>(arra, h);
        arra[I + HS - 1] = ',';
        head<I + HS>(arra, arr...);
    }

public:
    template<typename ...Ts, int... S>
    static constexpr auto select(Ts (&...arr)[S]) {
        local<(S + ...) + 1 + 7> arra;
        write<0, 0, 7>(arra, "SELECT ");
        head<7>(arra, arr...);
        return CSQLSelect(arra);
    }
};

#endif // CSQL_H

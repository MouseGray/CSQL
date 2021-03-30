#ifndef CSQLSELECT_H
#define CSQLSELECT_H

#include "csqlfrom.h"



template<int Size>
struct CSQLSelect
{
    const local<Size> data;

    constexpr CSQLSelect(local<Size> local) : data(local) {

    }

    template<typename ...Ts, int... S>
    constexpr auto from(Ts (&...arr)[S]) {
        local<(S + ...) + Size - 1 + 6> arra;
        write<0, 0>(arra, data.val);
        write<Size - 1, 0>(arra, " FROM ");
        write_args<Size + 5>(arra, arr...);
        return CSQLFrom(arra);
    }
};

#endif // CSQLSELECT_H

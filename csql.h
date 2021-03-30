#ifndef CSQL_H
#define CSQL_H

#include "csqlselect.h"
#include <csqlbool.h>

namespace CSQL
{
    template<typename ...Ts, int... S>
    static constexpr auto select(Ts (&...arr)[S]) {
        local<(S + ...) + 7> arra;
        write<0, 0>(arra, "SELECT ");
        write_args<7>(arra, arr...);
        return CSQLSelect(arra);
    }

//    template<typename T0, int S0, typename T1, int S1>
//    static constexpr auto equals(T0 (&arg0)[S0], T1 (&arg1)[S1]) {
//        local<S0 - 1 + 3 + S1> arra;
//        write<0, 0>(arra, arg0);
//        write<S0 - 1, 0>(arra, " = ");
//        write_args<S0 + 2>(arra, arg1);
//        return CSQLEquals(arra);
//    }
};

#endif // CSQL_H

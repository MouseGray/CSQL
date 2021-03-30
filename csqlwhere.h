#ifndef CSQLWHERE_H
#define CSQLWHERE_H

#include "local.h"
#include <string>

#include "csqlbool.h"

template<int Size>
struct CSQLWhere
{
    const local<Size> data;

    constexpr CSQLWhere(local<Size> local) : data(local) {

    }

    template<typename T0, int S0, typename T1, int S1>
    constexpr auto equals(T0 (&arg0)[S0], T1 (&arg1)[S1]) {
        local<Size - 1 + S0 - 1 + S1 + 3> arra;
        write<0, 0>(arra, data.val);
        write<Size - 1, 0>(arra, arg0);
        write<Size - 1 + S0 - 1, 0>(arra, " = ");
        write_args<Size - 1 + S0 + 2>(arra, arg1);
        return CSQLLogicOperation<Size - 1 + S0 - 1 + S1 + 3, CSQLLogicType::And>(arra);
    }
};

#endif // CSQLWHERE_H

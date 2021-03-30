#ifndef CSQLBOOL_H
#define CSQLBOOL_H

#include "local.h"

enum class CSQLLogicType {
    Equal,
    And
};

template <int Size, CSQLLogicType Ty>
struct CSQLLogicOperation
{
    const local<Size> data;

    constexpr CSQLLogicOperation(local<Size> local) : data(local) { }

    constexpr auto go() { return data.val;}

    template<typename T0, int S0, typename T1, int S1>
    constexpr auto equals(T0 (&arg0)[S0], T1 (&arg1)[S1]) {
        static_assert (Ty == CSQLLogicType::Equal, "Incorrect  operation");
        local<Size - 1 + S0 - 1 + S1 + 3> arra;
        write<0, 0>(arra, data.val);
        write<Size - 1, 0>(arra, arg0);
        write<Size - 1 + S0 - 1, 0>(arra, " = ");
        write_args<Size - 1 + S0 + 2>(arra, arg1);
        return CSQLLogicOperation<Size - 1 + S0 - 1 + S1 + 3, CSQLLogicType::And>(arra);
    }

    constexpr auto And() {
        static_assert (Ty == CSQLLogicType::And, "Incorrect  operation");
        local<Size + 5> arra;
        write<0, 0>(arra, data.val);
        write<Size - 1, 0>(arra, " AND \0");
        return CSQLLogicOperation<Size + 5, CSQLLogicType::Equal>(arra);
    }
};

//template <int Size>
//struct CSQLEquals
//{
//    const local<Size> data;

//    constexpr CSQLEquals(local<Size> local) : data(local) { }

//    template<typename T0, int S0, typename T1, int S1>
//    constexpr auto equals(T0 (&arg0)[S0], T1 (&arg1)[S1]) {
//        local<Size - 1 + S0 - 1 + S1 + 3> arra;
//        write<0, 0>(arra, data.val);
//        write<Size - 1, 0>(arra, arg0);
//        write<Size - 1 + S0 - 1, 0>(arra, " = ");
//        write_args<Size - 1 + S0 + 2>(arra, arg1);
//        return CSQLEquals<Size - 1 + S0 - 1 + S1 + 3>(arra);
//    }

//    constexpr auto And() {
//        local<Size + 5> arra;
//        write<0, 0>(arra, data.val);
//        write<Size - 1, 0>(arra, " AND \0");
//        return CSQLEquals<Size + 5>(arra);
//    }



//    operator local<Size>() { return data;}
//};

#endif // CSQLBOOL_H

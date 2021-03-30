#ifndef CSQLFROM_H
#define CSQLFROM_H

#include "csqlwhere.h"

template <int Size>
struct CSQLFrom
{
    const local<Size> data;

    constexpr CSQLFrom(local<Size> local) : data(local) {

    }

    constexpr auto go() { return data.val;}

//  template<template<int S> typename Ts, int S>
    constexpr auto where() {
        local<Size + 7> arra;
        write<0, 0>(arra, data.val);
        write_args<Size - 1>(arra, " WHERE ");
//      write_args<Size + 4>(arra, arr.data.val);
        return CSQLWhere(arra);
    }
};

#endif // CSQLFROM_H

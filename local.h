#ifndef LOCAL_H
#define LOCAL_H


template<int Size>
struct local {
    char val[Size];
    constexpr char& operator[] (int n) { return val[n]; }

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
        arra[I + HS - 1] = ',';
        head<I + HS>(arra, arr...);
    }
};

#endif // LOCAL_H

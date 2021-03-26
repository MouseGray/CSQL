#ifndef CSQLFROM_H
#define CSQLFROM_H



template <int Size>
class CSQLFrom
{
public:
    const local<Size> data;

    constexpr CSQLFrom(local<Size> local) : data(local) {

    }
};

#endif // CSQLFROM_H

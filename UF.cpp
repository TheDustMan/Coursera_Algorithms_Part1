#include "UF.h"

UF::UF(int N) : _ids(N)
{
    for (int i = 0; i < N; ++i)
    {
        _ids[i] = i;
    }
}

UF::~UF()
{}

int UF::count() const
{
    return _ids.size();
}

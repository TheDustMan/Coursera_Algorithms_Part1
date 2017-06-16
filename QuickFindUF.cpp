#include "QuickFindUF.h"

QuickFindUF::QuickFindUF(int N) : UF(N)
{
}

void QuickFindUF::create_union(int p, int q)
{
    int pValue = _ids[p];
    int qValue = _ids[q];
    for (auto& id : _ids)
    {
        if (id == pValue)
        {
            id = qValue;
        }
    }
}

bool QuickFindUF::connected(int p, int q)
{
    return _ids[p] == _ids[q];
}

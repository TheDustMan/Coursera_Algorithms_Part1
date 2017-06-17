#include "QuickFindUF.h"
#include <limits>

QuickFindUF::QuickFindUF(int N) : UF(N)
{
}

QuickFindUF::~QuickFindUF()
{}

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

int QuickFindUF::find(int p)
{
    int group = _ids[p];
    int max = std::numeric_limits<int>::min();
    for (int i = 0; i < _ids.size(); ++i)
    {
        if (_ids[i] == group)
        {
            max = i > max ? i : max;
        }
    }

    return max;
}

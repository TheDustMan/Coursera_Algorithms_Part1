#include "QuickUnionUF.h"
#include <limits>

QuickUnionUF::QuickUnionUF(int N) : UF(N)
{
}

QuickUnionUF::~QuickUnionUF()
{}

bool QuickUnionUF::connected(int p, int q)
{
    return findRoot(p) == findRoot(q);
}

void QuickUnionUF::create_union(int p, int q)
{
    // Set id of p's root to the id of q's root
    _ids[findRoot(p)] = findRoot(q);
}

int QuickUnionUF::find(int p)
{
    // Slow af find
    int max = std::numeric_limits<int>::min();
    for (int i = 0; i < _ids.size(); ++i)
    {
        if (findRoot(i) == findRoot(p))
        {
            max = i > max ? i : max;
        }
    }
    return max;
}

int QuickUnionUF::findRoot(int id)
{
    int idRoot = _ids[id];
    while (idRoot != _ids[idRoot])
    {
        idRoot = _ids[idRoot];
    }
    return idRoot;
}

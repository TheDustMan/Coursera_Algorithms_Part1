#include "QuickUnionUF.h"

QuickUnionUF::QuickUnionUF(int N) : UF(N)
{
}

bool QuickUnionUF::connected(int p, int q)
{
    return findRoot(p) == findRoot(q);
}

void QuickUnionUF::create_union(int p, int q)
{
    // Set id of p's root to the id of q's root
    _ids[findRoot(p)] = findRoot(q);
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

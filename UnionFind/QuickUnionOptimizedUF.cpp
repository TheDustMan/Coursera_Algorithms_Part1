#include "QuickUnionOptimizedUF.h"

QuickUnionOptimizedUF::QuickUnionOptimizedUF(int N) : QuickUnionUF(N), _sizes(N)
{
    for (auto& size : _sizes)
    {
        size = 1;
    }
}

QuickUnionOptimizedUF::~QuickUnionOptimizedUF()
{}

void QuickUnionOptimizedUF::create_union(int p, int q)
{
    // Add the smaller tree as a subtree of the larger one to keep the
    // tree flatter overall
    int pRoot = findRoot(p);
    int qRoot = findRoot(q);
    if (pRoot == qRoot)
    {
        return;
    }
    if (_sizes[pRoot] < _sizes[qRoot])
    {
        _ids[pRoot] = qRoot;
        _sizes[qRoot] += _sizes[pRoot];
    }
    else
    {
        _ids[qRoot] = pRoot;
        _sizes[pRoot] += _sizes[qRoot];        
    }
}

int QuickUnionOptimizedUF::findRoot(int id)
{
    while (_ids[id] != id)
    {
        _ids[id] = _ids[_ids[id]];
        id = _ids[id];
    }
    return id;
}

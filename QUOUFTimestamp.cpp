#include "QUOUFTimestamp.h"

QUOUFTimestamp::QUOUFTimestamp(int N)
    : QuickUnionOptimizedUF(N),
      _uniqueRoots(N),
      _timestamps(N),
      _onFullConnection(nullptr)
{

}


void QUOUFTimestamp::create_union(int p, int q, int timestamp)
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
    --_uniqueRoots;
    if (_uniqueRoots == 1 && _onFullConnection != nullptr)
    {
        _onFullConnection(timestamp);
    }
}

void QUOUFTimestamp::onFullConnection(std::function<void(int timestamp)> f)
{
    _onFullConnection = f;
}

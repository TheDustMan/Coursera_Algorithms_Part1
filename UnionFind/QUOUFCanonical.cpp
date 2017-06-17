#include "QUOUFCanonical.h"

QUOUFCanonical::QUOUFCanonical(int N) : QuickUnionOptimizedUF(N)
{
}

QUOUFCanonical::~QUOUFCanonical()
{}

void QUOUFCanonical::create_union(int p, int q)
{
    int pRoot = findRoot(p);
    int qRoot = findRoot(q);

    // Run the additional step of swapping the roots, making sure
    // the root with a larger value is higher up. This makes it
    // easier to locate later using the "find" method
    auto swapRootValuesIfNecessary =
        [this](int smallerTreeRootValue, int greaterTreeRootValue)
        {
            if (smallerTreeRootValue > greaterTreeRootValue)
            {            
                _ids[smallerTreeRootValue] = smallerTreeRootValue;
                _ids[greaterTreeRootValue] = smallerTreeRootValue;
            }
        };

    if (pRoot == qRoot)
    {
        return;
    }    
    if (_sizes[pRoot] < _sizes[qRoot])
    {
        _ids[pRoot] = qRoot;
        _sizes[qRoot] += _sizes[pRoot];
        swapRootValuesIfNecessary(pRoot, qRoot);
    }
    else
    {
        _ids[qRoot] = pRoot;
        _sizes[pRoot] += _sizes[qRoot];
        swapRootValuesIfNecessary(qRoot, pRoot);
    }
}

int QUOUFCanonical::find(int p)
{
    // Since we already di the work of making sure the highest value was
    // at the top when creating the unions, all we have to do is return
    // the root.
    return findRoot(p);
}

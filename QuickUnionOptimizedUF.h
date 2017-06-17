#ifndef QUICKUNIONOPTIMIZEDUF_H
#define QUICKUNIONOPTIMIZEDUF_H

#include "QuickUnionUF.h"
#include <vector>

/*
 * Optimizes the QuickUnionUF class by creating flatter trees when creating
 * the unions by making always making the smaller tree a child of the larger
 * tree when doing merges. Also, when traversing to find roots, we do path
 * compression (setting the value of a node so that it points to its
 * value).
 */
class QuickUnionOptimizedUF : public QuickUnionUF
{
 public:
    QuickUnionOptimizedUF(int N);
    virtual ~QuickUnionOptimizedUF();
    virtual void create_union(int p, int q) override;
 protected:
    virtual int findRoot(int id);
    std::vector<int> _sizes;
};

#endif // QUICKUNIONOPTIMIZEDUF_H

#ifndef QUICKUNIONOPTIMIZEDUF_H
#define QUICKUNIONOPTIMIZEDUF_H

#include "QuickUnionUF.h"
#include <vector>

class QuickUnionOptimizedUF : public QuickUnionUF
{
 public:
    QuickUnionOptimizedUF(int N);
    virtual void create_union(int p, int q) override;
 protected:
    virtual int findRoot(int id);
    std::vector<int> _sizes;
};

#endif // QUICKUNIONOPTIMIZEDUF_H

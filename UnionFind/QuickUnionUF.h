#ifndef QUICKUNIONUF_H
#define QUICKUNIONUF_H

#include "UF.h"

/*
 * Implements a faster version of "create_union", which creates a tree-like
 * structure of the elements that are connected. This helps improve the
 * "connected" query's runtime performance to O(log n) instead of O(n) as 
 * seen in the "QuickFindUF" implementation.
 */
class QuickUnionUF : public UF
{
 public:
    QuickUnionUF(int N);
    virtual ~QuickUnionUF();
    virtual bool connected(int p, int q) override;
    virtual void create_union(int p, int q) override;
    virtual int find(int p) override;
    
 protected:
    int findRoot(int id);
};

#endif // QUICKUNIONUF_H

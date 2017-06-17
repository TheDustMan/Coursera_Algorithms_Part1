#ifndef QUICKFINDUF_H
#define QUICKFINDUF_H

#include "UF.h"

/*
 * Implementation of a UnionFind that has O(1) "connected" query time, but
 * has O(n^2) "create_union" (for every inserted element you need to iterate
 * over all of the elements to update groupings)
 */
class QuickFindUF : public UF
{
public:
    QuickFindUF(int N);
    virtual ~QuickFindUF();
    virtual void create_union(int p, int q) override;
    virtual bool connected(int p, int q) override;
    virtual int find(int p) override;
};

#endif // QUICKFINDUF_H

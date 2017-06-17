#ifndef UF_H
#define UF_H

#include <vector>

/*
 * Serves as the abstract base class for all UnionFind variations
 */
class UF
{
public:
    /* 
     * Initialize union-find data structure with N objects (0 to N-1)
     */
    UF(int N);
    virtual ~UF();

    /*
     * Add connection between p and q
     */
    virtual void create_union(int p, int q) = 0;

    /*
     * Are p and q in the same component
     */
    virtual bool connected(int p, int q) = 0;

    /*
     * Component identifier for p (0 to N-1)
     */
    virtual int find(int p) = 0;

    /*
     * Number of components
     */
    virtual int count() const;

protected:
    std::vector<int> _ids;
};

#endif // UF_H

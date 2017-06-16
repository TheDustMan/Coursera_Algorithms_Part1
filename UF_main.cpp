#include <iostream>
#include <fstream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "UF.h"
#include "QuickFindUF.h"
#include "QuickUnionUF.h"
#include "QuickUnionOptimizedUF.h"
#include "QUOUFTimestamp.h"

void print(const std::string& str)
{
    std::cout << str;
}

void println(const std::string& str)
{
    print(str);
    std::cout << std::endl;
}

int readDataPoints(std::ifstream& infile)
{
   std::string dataPointsStr;
   std::getline(infile, dataPointsStr);
   std::istringstream iss(dataPointsStr);
   int dataPoints;
   iss >> dataPoints;
   return dataPoints;
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        println("Please specify UF files! (the standard format as arg 1 and the timestamp format as arg2)");
        return 1;
    }
    const char *ufFile = argv[1];
    const char *ufFileTS = argv[2];
    std::ifstream infile(ufFile);
    std::ifstream infileTS(ufFileTS);

    int dataPoints = readDataPoints(infile);
    int dataPointsTS = readDataPoints(infileTS);
    QuickFindUF qfuf(dataPoints);
    QuickUnionUF quuf(dataPoints);
    QuickUnionOptimizedUF quouf(dataPoints);
    QUOUFTimestamp quoufts(dataPointsTS);
    quoufts.onFullConnection([](int timestamp)
        {
            println("Fully connected at timestamp: " + std::to_string(timestamp));
        });
    
    std::string pair;
    while (std::getline(infile, pair))
    {
        std::istringstream iss(pair);
        int p, q;
        if (!(iss >> p >> q))
        {
            println("Error reading file: " + std::string(ufFile));
            break;
        }
        if (!qfuf.connected(p, q))
        {
            qfuf.create_union(p, q);
        }
        if (!quuf.connected(p, q))
        {
            quuf.create_union(p, q);
        }
        if (!quouf.connected(p, q))
        {
            quouf.create_union(p, q);
        }
    }

    std::string triplet;
    while (std::getline(infileTS, triplet))
    {
        std::istringstream iss(triplet);
        int ts, p, q;
        if (!(iss >> ts >> p >> q))
        {
            println("Error reading file: " + std::string(ufFileTS));
            break;
        }
        if (!quoufts.connected(p, q))
        {
            quoufts.create_union(p, q, ts);
        }
    }
    return 0;
}

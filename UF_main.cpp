#include <iostream>
#include <fstream>
#include <map>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <typeinfo>

#include "UF.h"
#include "QuickFindUF.h"
#include "QuickUnionUF.h"
#include "QuickUnionOptimizedUF.h"
#include "QUOUFTimestamp.h"
#include "QUOUFCanonical.h"

void print(const std::string& str)
{
    std::cout << str;
}

void println(const std::string& str = "")
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

    std::vector<std::pair<int,int>> findTestData = {{8,9},{3,9},{4,9},{5,7},{6,7},{0,7},{1,7},{2,7}};
    
    std::map<std::string, std::unique_ptr<UF>> unionFindVariants;
    unionFindVariants.insert(std::make_pair("QuickFindUF", std::make_unique<QuickFindUF>(dataPoints)));
    unionFindVariants.insert(std::make_pair("QuickUnionUF", std::make_unique<QuickUnionUF>(dataPoints)));
    unionFindVariants.insert(std::make_pair("QuickUnionOptimizedUF", std::make_unique<QuickUnionOptimizedUF>(dataPoints)));
    unionFindVariants.insert(std::make_pair("QUOUFCanonical", std::make_unique<QUOUFCanonical>(dataPoints)));
    
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
        for (auto& ufVariant : unionFindVariants)
        {
            if (!ufVariant.second->connected(p, q))
            {
                ufVariant.second->create_union(p, q);
            }
        }
    }

    for (auto& ufVariant : unionFindVariants)
    {
        println("Running tests for class: " + ufVariant.first);
        for (auto& findTestPair : findTestData)
        {
            println("Running \"find\" on input: " + std::to_string(findTestPair.first));
            int result = ufVariant.second->find(findTestPair.first);
            println("Result was: " + std::to_string(result));
            if (result == findTestPair.second)
            {
                println(">>>Passed!");
            }
            else
            {
                println(">>>Failed!");
            }
        }
        println();
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

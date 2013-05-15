/*
 * data.cpp
 *
 *  Created on: 2013-3-30
 *      Author: ryanhust
 */
#include <vector>
#include <cstring>
#include <string>

#include "data.h"



SVMData::SVMData(int feature, int size, int _class, int _myid, int _procs)
{
    F = feature;
    N = size;
    K = _class;
    myid = _myid;
    procs = _procs;
    getSection();
    label = new double*[K];
    pred = new double*[K];
    score = new double*[K];
    nodes = new int[localN];

    for (int n = 0; n < localN; n++) {
        nodes[n] = 0;
    }

    for (int i = 0; i < K; i++) {
        label[i] = new double[localN];
        pred[i] = new double[localN];
        score[i] = new double[localN];
        for(int j = 0; j < localN; j++) {
            label[i][j] = 0.0;
            pred[i][j] = 0.0;
            score[i][j] = 0.0;
        }
    }
    rawFeatures = new vector<vector<FeatureTuple>>[localFeatures];
    for (int i ==0; i < localFeatures; i++)
    {
        rawFeatures[i] = vector<FeatureTuple>();
    }
}

SVMData::~SVMData()
{
}

bool SVMData::processLine(int & linenum, ifstream & input, int i)
{
    string strline;
    getline(input, strline);
    linenum++;
    //TODO eof fails
    char line* = strdup(line, strline.c_str());
    vector<string> toks;
    char * pch;
    char * subpch;
    char * tem = new char[5];
    pch = strtok(line, " ");
    while (pch != NULL)
    {
        toks.push_back(pch);
        pch = strtok(NULL, " ");
    }
    for(int j = 0; j < toks.size(); j++)
    {
        if(j == 0)
        {
            label[atoi(toks[0].data)] = 1.0;
        }
        else
        {
            strcpy(tem, toks[j].data) ;
            subpch = strtok(tem, ":");
            //feature_index
            if(isLocalFeature(atoi(subpch)))
            {
                FeatureTuple ft;
                ft.feature_index = i;
                subpch = strtok(NULL, ":");
                subpch = strtok(tem, ":");
                ft.feature_value = atof(subpch);
                rawFeatures.push_back(ft); 
            }
            //feature_vlaue
            subpch = strtok(NULL, ":");
        }
    }
}

bool SVMData::parseFeatureTuple(string & cstring, string & cvalue)
{

}

int SVMData::binarySearch(int f, int i)
{
    int first, last, mid = 0;
    first = 0;
    last = rawFeatures[f].size() - 1;
    bool found = false;
    while ((!found) && (first <= last)) {
        mid = first + (last - first) / 2;
        if (rawFeatures[f][mid].feature_index == i)
            found = true;
        else if (i < rawFeatures[f][mid].feature_index)
            last = mid - 1;
        else if (i > rawFeatures[f][mid].feature_index)
            first = mid + 1;
    }

    if (found)
        return mid;

    return -1;
}

void SVMData::getSection()
{
    minindex = (int) floor(double(myid * N) / double(procs));
    maxindex = (int) floor(double((myid + 1) * N) / double(procs));
    localN = maxindex - minindex;
}

void SVMData::getFeatureSection()
{
    minifeature = 0;
    maxfeature = F-1;
    localFeatures = F;
}

int SVMData::localFeatureIndex(gf)
{
    return gf;
}

int SVMData::globalFeatureIndex(lf)
{
    return lf;
}

bool SVMData::isLocalFeature(gf)
{
    return true;
}

void SVMData::read(const char *file)
{
    ifstream input(file);
    string line;
    int linenum = 0;
    for(int i = 0; i<minindex; i++)
    {
        getline(input, line);
        linenum ++;
    }
    for (int i = 0; i<localN; i++)
    {
        processLine(linenum, input, i); 
    }
}

void SVMData::resetNode()
{
    for(int i = 0; i < localN; i++) {
        nodes[i] = 0;
    }

}


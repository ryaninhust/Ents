/*
 * data.h
 *
 *  Created on: 2013-3-30
 *      Author: ryanhust
 */

#ifndef DATA_H_
#define DATA_H_

#include <stdlib.h>

struct FeatureTuple {
	int feature_index;
	double feature_value;
};

class SVMData {
public:
	SVMData(const char* file, int feature, int size, int _class, int minindex, int maxindex);
	~SVMData();

private:
	int N;
	int K;
    int minindex, maxindex;

	double** label;
	double** pred;

}




#endif /* DATA_H_ */

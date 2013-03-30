/*
 * ent.h
 *
 *  Created on: 2013-3-30
 *      Author: ryanhust
 */

#ifndef ENT_H_
#define ENT_H_

class EntNode {
public:
	EntNode();
    ~EntNode();
    int getFeature() const;
    int getInfty() const;
    double getLabel() const;
    double getLoss() const;
    double getSplit() const;
    void setFeature(int feature);
    void setInfty(int m_infty);
    void setLabel(double label);
    void setLoss(double loss);
    void setSplit(double split);
    void printNode();
    void clear();


private:
    int feature;
    double split;
    double label;
    double loss;
    int m_infty, m_s;
    double l_infty, l_s;
}

class Ent {
public:
	Ent(int depth, int n);
	~Ent();
    void printTree();
    int getDepth() const;
    void setDepth(int depth);
    int getNodes() const;
    void setNodes(int nodes);


private:
	EntNode*** layers;
	int depth, layer;
	int nodes, N;
	int nodeAtDepth(int d);
	void startNextLayer();


}






#endif /* ENT_H_ */

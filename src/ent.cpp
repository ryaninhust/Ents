/*
 * ent.cpp
 *
 *  Created on: 2013-3-30
 *      Author: ryanhust
 */
#include "ent.h"




int EntNode::getFeature() const
{
    return feature;
}

int EntNode::getInfty() const
{
    return m_infty;
}

double EntNode::getLabel() const
{
    return label;
}

double EntNode::getLoss() const
{
    return loss;
}

double EntNode::getSplit() const
{
    return split;
}

void EntNode::setFeature(int feature)
{
    this->feature = feature;
}

void EntNode::setInfty(int m_infty)
{
    this->m_infty = m_infty;
}

void EntNode::setLabel(double label)
{
    this->label = label;
}

void EntNode::setLoss(double loss)
{
    this->loss = loss;
}

void EntNode::setSplit(double split)
{
    this->split = split;
}

EntNode::EntNode()
{
	feature = -1;
	split = -1.0;
	label = -1.0;
	loss = -99999999999.0;
	m_infty = 0;
	m_s = 0;
}



Ent::Ent()
{
}

int Ent::getDepth() const
{
    return depth;
}

void Ent::setDepth(int depth)
{
    this->depth = depth;
}

int Ent::getNodes() const
{
    return nodes;
}

void Ent::setNodes(int nodes)
{
    this->nodes = nodes;
}








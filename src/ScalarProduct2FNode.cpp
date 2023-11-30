/*
  ScalarProduct2FNode.cpp
  =======================
  ScalarProduct2FNode class implementation
*/
#include "ScalarProduct2FNode.hpp"

MTypeId ScalarProduct2FNode::id(0x0E040); //Node ID 57408 [TEST ONLY]
MObject ScalarProduct2FNode::scalar;
MObject ScalarProduct2FNode::vector;
MObject ScalarProduct2FNode::output;


MStatus ScalarProduct2FNode::compute(const MPlug& plug, MDataBlock& data)
{

	MStatus status;

	MDataHandle scalarH = data.inputValue(scalar, &status);
	MDataHandle vectorH = data.inputValue(vector, &status);
	float scalarI = scalarH.asFloat();
	float* vectorI = vectorH.asFloat2();

	//Compute scalar product
	float x = scalarI * vectorI[0];
	float y = scalarI * vectorI[1];

	MDataHandle outputH = data.outputValue(output, &status);
	outputH.set2Float(x, y);

	return status;

}

MStatus ScalarProduct2FNode::init()
{

	MStatus status;

	MFnNumericAttribute nAttr;

	//Scalar input attribute
	scalar = nAttr.create("Scalar", "s", MFnNumericData::kFloat, 0, &status);
	status = nAttr.setKeyable(true);
	status = addAttribute(scalar);

	//Vector input attribute
	vector = nAttr.create("Vector", "v", MFnNumericData::k2Float, 0, &status);
	status = nAttr.setKeyable(true);
	status = addAttribute(vector);

	//Output attribute
	output = nAttr.create("Output", "o", MFnNumericData::k2Float, 0, &status);
	status = nAttr.setKeyable(false);
	status = nAttr.setWritable(false);
	status = addAttribute(output);

	//Attribute affects
	status = attributeAffects(scalar, output);
	status = attributeAffects(vector, output);

	return status;

}

void* ScalarProduct2FNode::creator()
{

	return new ScalarProduct2FNode();

}
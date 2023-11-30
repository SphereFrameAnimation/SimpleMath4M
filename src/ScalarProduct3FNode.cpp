/*
  ScalarProduct3FNode.cpp
  =======================
  ScalarProduct3FNode class implementation
*/
#include "ScalarProduct3FNode.hpp"

MTypeId ScalarProduct3FNode::id(0x0E041); //Node ID 57409 [TEST ONLY]
MObject ScalarProduct3FNode::scalar;
MObject ScalarProduct3FNode::vector;
MObject ScalarProduct3FNode::output;


MStatus ScalarProduct3FNode::compute(const MPlug& plug, MDataBlock& data)
{

	MStatus status;

	MDataHandle scalarH = data.inputValue(scalar, &status);
	MDataHandle vectorH = data.inputValue(vector, &status);
	float scalarI = scalarH.asFloat();
	float* vectorI = vectorH.asFloat3();

	///Compute scalar product
	float x = scalarI * vectorI[0];
	float y = scalarI * vectorI[1];
	float z = scalarI * vectorI[2];

	MDataHandle outputH = data.outputValue(output, &status);
	outputH.set3Float(x, y, z);

	return status;

}

MStatus ScalarProduct3FNode::init()
{

	MStatus status;

	MFnNumericAttribute nAttr;

	//Scalar input attribute
	scalar = nAttr.create("Scalar", "s", MFnNumericData::kFloat, 0, &status);
	status = nAttr.setKeyable(true);
	status = addAttribute(scalar);

	//Vector input attribute
	vector = nAttr.create("Vector", "v", MFnNumericData::k3Float, 0, &status);
	status = nAttr.setKeyable(true);
	status = addAttribute(vector);

	//Output attribute
	output = nAttr.create("Output", "o", MFnNumericData::k3Float, 0, &status);
	status = nAttr.setKeyable(false);
	status = nAttr.setWritable(false);
	status = addAttribute(output);

	//Attribute affects
	status = attributeAffects(scalar, output);
	status = attributeAffects(vector, output);

	return status;

}

void* ScalarProduct3FNode::creator()
{

	return new ScalarProduct3FNode();

}
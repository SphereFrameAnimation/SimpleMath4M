/*
  Cross3FNode.cpp
  ===============
  Cross3FNode class implementation
*/
#include "Cross3FNode.hpp"

MTypeId Cross3FNode::id(0x0E03F); //Node ID 57407 [TEST ONLY]
MObject Cross3FNode::input0;
MObject Cross3FNode::input1;
MObject Cross3FNode::output0;

MStatus Cross3FNode::compute(const MPlug& plug, MDataBlock& dataBlock)
{

	MStatus status;

	if (plug == output0)
	{

		MDataHandle i0Handle = dataBlock.inputValue(input0, &status);
		MDataHandle i1Handle = dataBlock.inputValue(input1, &status);

		float* a = i0Handle.asFloat3();
		float* b = i1Handle.asFloat3();
		
		//Cross Product
		float x = a[1] * b[2] - a[2] * b[1];
		float y = a[2] * b[0] - a[0] * b[2];
		float z = a[0] * b[1] - a[1] * b[0];

		MDataHandle o0Handle = dataBlock.outputValue(output0, &status);
		o0Handle.set3Float(x, y, z);

	}

	return status;

}

MStatus Cross3FNode::init()
{

	MStatus status;
	MFnNumericAttribute nAttr;

	//Input0 attribute
	input0 = nAttr.create("input0", "i0", MFnNumericData::k3Float, 0, &status);
	status = nAttr.setKeyable(true);
	status = addAttribute(input0);

	//Input1 attribute
	input1 = nAttr.create("input1", "i1", MFnNumericData::k3Float, 0, &status);
	status = nAttr.setKeyable(true);
	status = addAttribute(input1);

	//Output0 attribute
	output0 = nAttr.create("output0", "o0", MFnNumericData::k3Float, 0, &status);
	status = nAttr.setKeyable(false);
	status = nAttr.setWritable(false);
	status = addAttribute(output0);

	//Affect output
	status = attributeAffects(input0, output0);
	status = attributeAffects(input1, output0);

	return status;

}

void* Cross3FNode::creator()
{

	return new Cross3FNode();

}
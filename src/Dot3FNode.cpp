/*
  Dot3FNode.hpp
  =============
  Dot3FNode class implementation
*/
#include "Dot3FNode.hpp"

MTypeId Dot3FNode::id(0x0E03E); //Node ID 57406 [TEST ONLY]
MObject Dot3FNode::input0;
MObject Dot3FNode::input1;
MObject Dot3FNode::output0;

MStatus Dot3FNode::compute(const MPlug& plug, MDataBlock& dataBlock)
{

	MStatus status;

	if (plug == output0)
	{

		MDataHandle i0Handle = dataBlock.inputValue(input0, &status);
		MDataHandle i1Handle = dataBlock.inputValue(input1, &status);

		float* i0 = i0Handle.asFloat3();
		float* i1 = i1Handle.asFloat3();
		float o0 = 0;

		o0 = i0[0] * i1[0] + i0[1] * i1[1] + i0[2] * i1[2]; //Dot product

		MDataHandle o0Handle = dataBlock.outputValue(output0, &status);
		o0Handle.setFloat(o0);


	}

	return status;

}

MStatus Dot3FNode::init()
{

	MStatus status;
	MFnNumericAttribute nAttr;

	input0 = nAttr.create("input0", "i0", MFnNumericData::k3Float, 0, &status);
	status = nAttr.setKeyable(true);
	status = addAttribute(input0);

	input1 = nAttr.create("input1", "i1", MFnNumericData::k3Float, 0, &status);
	status = nAttr.setKeyable(true);
	status = addAttribute(input1);

	output0 = nAttr.create("output0", "o0", MFnNumericData::kFloat, 0, &status);
	status = nAttr.setKeyable(false);
	status = nAttr.setWritable(false);
	status = addAttribute(output0);

	status = attributeAffects(input0, output0);
	status = attributeAffects(input1, output0);

	return status;

}

void* Dot3FNode::creator()
{

	return new Dot3FNode();

}
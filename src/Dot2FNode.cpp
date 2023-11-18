/*
  Dot2FNode.hpp
  =============
  Dot2FNode class implementation
*/
#include "Dot2FNode.hpp"

MTypeId Dot2FNode::id(0x0E03C); //Node ID 57404 [TEST ONLY]
MObject Dot2FNode::input0;
MObject Dot2FNode::input1;
MObject Dot2FNode::output0;

MStatus Dot2FNode::compute(const MPlug& plug, MDataBlock& dataBlock)
{

	MStatus status;

	if (plug == output0)
	{

		MDataHandle i0Handle = dataBlock.inputValue(input0, &status);
		MDataHandle i1Handle = dataBlock.inputValue(input1, &status);

		float* i0 = i0Handle.asFloat2();
		float* i1 = i1Handle.asFloat2();
		float o0 = 0;

		o0 = i0[0] * i1[0] + i0[1] * i1[1]; //Dot product

		MDataHandle o0Handle = dataBlock.outputValue(output0, &status);
		o0Handle.setFloat(o0);


	}

	return status;

}

MStatus Dot2FNode::init()
{

	MStatus status;
	MFnNumericAttribute nAttr;

	input0 = nAttr.create("input0", "i0", MFnNumericData::k2Float, 0, &status);
	status = nAttr.setKeyable(true);
	status = addAttribute(input0);

	input1 = nAttr.create("input1", "i1", MFnNumericData::k2Float, 0, &status);
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

void* Dot2FNode::creator()
{

	return new Dot2FNode();

}
/*
  Arith3FNode.cpp
  ===============
  Arith3FNode class implementation
*/
#include "Arith3FNode.hpp"

MTypeId Arith3FNode::id(0x0E03D); //Node ID 57405 [TEST ONLY]
MObject Arith3FNode::input0;
MObject Arith3FNode::input1;
MObject Arith3FNode::output0;
MObject Arith3FNode::mode;

MStatus Arith3FNode::compute(const MPlug& plug, MDataBlock& dataBlock)
{

	MStatus status;

	if (plug == output0)
	{

		MDataHandle mHandle = dataBlock.inputValue(mode, &status);
		MDataHandle i0Handle = dataBlock.inputValue(input0, &status);
		MDataHandle i1Handle = dataBlock.inputValue(input1, &status);

		short m = mHandle.asShort();
		float* i0 = i0Handle.asFloat3();
		float* i1 = i1Handle.asFloat3();
		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;

		if (m == 0) //ADD
		{

			x = i0[0] + i1[0];
			y = i0[1] + i1[1];
			z = i0[2] + i1[2];

		}
		else if (m == 1) //SUB
		{

			x = i0[0] - i1[0];
			y = i0[1] - i1[1];
			z = i0[2] - i1[2];

		}

		MDataHandle o0Handle = dataBlock.outputValue(output0, &status);
		o0Handle.set3Float(x, y, z);

	}

	return status;

}

MStatus Arith3FNode::init()
{

	MStatus status;
	MFnNumericAttribute nAttr;
	MFnEnumAttribute eAttr;

	//Mode attribute
	mode = eAttr.create("mode", "m", 0, &status);
	status = eAttr.addField("add", 0);
	status = eAttr.addField("sub", 1);
	status = eAttr.setKeyable(true);
	status = eAttr.setHidden(false);
	status = eAttr.setConnectable(false);
	status = addAttribute(mode);

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
	status = attributeAffects(mode, output0);
	status = attributeAffects(input0, output0);
	status = attributeAffects(input1, output0);

	return status;

}

void* Arith3FNode::creator()
{

	return new Arith3FNode();

}
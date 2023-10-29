#include "Arith2FNode.hpp"

MTypeId Arith2FNode::id(0x0E03B);
MObject Arith2FNode::input0;
MObject Arith2FNode::input1;
MObject Arith2FNode::output0;
MObject Arith2FNode::mode;

MStatus Arith2FNode::compute(const MPlug& plug, MDataBlock& dataBlock)
{

	MStatus status;

	if (plug == output0)
	{

		MDataHandle mHandle = dataBlock.inputValue(mode, &status);
		MDataHandle i0Handle = dataBlock.inputValue(input0, &status);
		MDataHandle i1Handle = dataBlock.inputValue(input1, &status);

		short m = mHandle.asShort();
		float* i0 = i0Handle.asFloat2();
		float* i1 = i1Handle.asFloat2();
		float x = 0.0f;
		float y = 0.0f;

		if (m == 0)
		{

			x = i0[0] + i1[0];
			y = i0[1] + i1[1];

		}
		else if (m == 1)
		{

			x = i0[0] - i1[0];
			y = i0[1] - i1[1];

		}
		else if (m == 2)
		{

			x = i0[0] * i1[0];
			y = i0[1] * i1[1];

		}
		else if (m == 3)
		{

			x = i1[0] == 0 ? nanf("") : i0[0] / i1[0];
			y = i1[1] == 0 ? nanf("") : i0[1] / i1[1];

		}

		MDataHandle o0Handle = dataBlock.outputValue(output0, &status);
		o0Handle.set2Float(x, y);

	}

	return status;

}

MStatus Arith2FNode::init()
{

	MStatus status;
	MFnNumericAttribute nAttr;
	MFnEnumAttribute eAttr;

	mode = eAttr.create("mode", "m", 0, &status);
	status = eAttr.addField("add", 0);
	status = eAttr.addField("sub", 1);
	status = eAttr.addField("mul", 2);
	status = eAttr.addField("div", 3);
	status = eAttr.setKeyable(true);
	status = eAttr.setHidden(false);
	status = eAttr.setConnectable(false);
	status = addAttribute(mode);

	input0 = nAttr.create("input0", "i0", MFnNumericData::k2Float, 0, &status);
	status = nAttr.setKeyable(true);
	status = addAttribute(input0);

	input1 = nAttr.create("input1", "i1", MFnNumericData::k2Float, 0, &status);
	status = nAttr.setKeyable(true);
	status = addAttribute(input1);

	output0 = nAttr.create("output0", "o0", MFnNumericData::k2Float, 0, &status);
	status = nAttr.setKeyable(false);
	status = nAttr.setWritable(false);
	status = addAttribute(output0);

	status = attributeAffects(mode, output0);
	status = attributeAffects(input0, output0);
	status = attributeAffects(input1, output0);

	return status;

}

void* Arith2FNode::creator()
{

	return new Arith2FNode();

}
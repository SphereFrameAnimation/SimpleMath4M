#include "Arith1FNode.hpp"

MTypeId Arith1FNode::id(0x0E038); //Internal ID 57400
MObject Arith1FNode::input0;
MObject Arith1FNode::input1;
MObject Arith1FNode::output0;
MObject Arith1FNode::mode;

MStatus Arith1FNode::compute(const MPlug& plug, MDataBlock& dataBlock)
{

	MStatus status;

	if (plug == output0)
	{

		MDataHandle mHandle = dataBlock.inputValue(mode);
		MDataHandle i0Handle = dataBlock.inputValue(input0);
		MDataHandle i1Handle = dataBlock.inputValue(input1);

		short m = mHandle.asShort();
		float i0 = i0Handle.asFloat();
		float i1 = i1Handle.asFloat();
		float o0 = 0;

		if(m == 0)
		{

			o0 = i0 + i1;

		}
		else if(m == 1)
		{

			o0 = i0 - i1;

		}
		else if(m == 2)
		{

			o0 = i0 * i1;

		}
		else if(m == 3)
		{

			if (i1 != 0)
			{
				o0 = i0 / i1;

			}
			else
			{

				o0 = nanf("");

			}

		}

		MDataHandle o0Handle = dataBlock.outputValue(output0);
		o0Handle.setFloat(o0);

	}

	return status;

}

MStatus Arith1FNode::init()
{

	//TODO proper error handling!
	MStatus status;
	MFnNumericAttribute nAttr;
	MFnEnumAttribute eAttr;

	mode = eAttr.create("mode", "m", 0);
	eAttr.addField("add", 0);
	eAttr.addField("sub", 1);
	eAttr.addField("mul", 2);
	eAttr.addField("div", 3);
	eAttr.setKeyable(true);
	eAttr.setHidden(false);
	eAttr.setConnectable(false);

	addAttribute(mode);

	input0 = nAttr.create("input0", "i0", MFnNumericData::kFloat, 0);
	nAttr.setKeyable(true);
	addAttribute(input0);

	input1 = nAttr.create("input1", "i1", MFnNumericData::kFloat, 0);
	nAttr.setKeyable(true);
	addAttribute(input1);

	output0 = nAttr.create("output0", "o0", MFnNumericData::kFloat, 0);
	nAttr.setKeyable(false);
	nAttr.setWritable(false);
	addAttribute(output0);

	attributeAffects(mode, output0);
	attributeAffects(input0, output0);
	attributeAffects(input1, output0);

	return status;

}

void* Arith1FNode::creator()
{

	return new Arith1FNode();

}
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

		MDataHandle mHandle = dataBlock.inputValue(mode, &status);
		MDataHandle i0Handle = dataBlock.inputValue(input0, &status);
		MDataHandle i1Handle = dataBlock.inputValue(input1, &status);

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

		MDataHandle o0Handle = dataBlock.outputValue(output0, &status);
		o0Handle.setFloat(o0);

	}

	return status;

}

MStatus Arith1FNode::init()
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

	input0 = nAttr.create("input0", "i0", MFnNumericData::kFloat, 0, &status);
	status = nAttr.setKeyable(true);
	status = addAttribute(input0);

	input1 = nAttr.create("input1", "i1", MFnNumericData::kFloat, 0, &status);
	status = nAttr.setKeyable(true);
	status = addAttribute(input1);

	output0 = nAttr.create("output0", "o0", MFnNumericData::kFloat, 0, &status);
	status = nAttr.setKeyable(false);
	status = nAttr.setWritable(false);
	status = addAttribute(output0);

	status = attributeAffects(mode, output0);
	status = attributeAffects(input0, output0);
	status = attributeAffects(input1, output0);

	return status;

}

void* Arith1FNode::creator()
{

	return new Arith1FNode();

}
#include "Add1FNode.hpp"

MTypeId Add1FNode::id(0x0E038); //Internal ID 57400
MObject Add1FNode::input0;
MObject Add1FNode::input1;
MObject Add1FNode::output0;

MStatus Add1FNode::compute(const MPlug& plug, MDataBlock& dataBlock)
{

	MStatus status;

	if (plug == output0)
	{

		MDataHandle i0Handle = dataBlock.inputValue(input0);
		MDataHandle i1Handle = dataBlock.inputValue(input1);

		float i0 = i0Handle.asFloat();
		float i1 = i1Handle.asFloat();

		float o0 = i0 + i1;

		MDataHandle o0Handle = dataBlock.outputValue(output0);
		o0Handle.setFloat(o0);

	}

	return status;

}

MStatus Add1FNode::init()
{

	//TODO proper error handling!
	MStatus status;
	MFnNumericAttribute nAttr;

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

	attributeAffects(input0, output0);
	attributeAffects(input1, output0);

	return status;

}

void* Add1FNode::creator()
{

	return new Add1FNode();

}
#include "Exp1FNode.hpp"
using std::string;

MTypeId Exp1FNode::id(0x0E03A); //Internal ID 57402
MObject Exp1FNode::input0;
MObject Exp1FNode::exp;
MObject Exp1FNode::output0;

MStatus Exp1FNode::compute(const MPlug& plug, MDataBlock& dataBlock)
{

	MStatus status;

	if (plug == output0)
	{

		MDataHandle i0Handle = dataBlock.inputValue(input0, &status);
		MDataHandle expHandle = dataBlock.inputValue(exp, &status);

		int i0 = i0Handle.asFloat();
		MString exp = expHandle.asString();

		//Parse and exexute f(x)

	}

	MDataHandle o0Handle = dataBlock.outputValue(output0, &status);
	o0Handle.setFloat(0); //Set output to f(x)

	return status;

}

MStatus Exp1FNode::init()
{

	MStatus status;
	MFnNumericAttribute nAttr;
	MFnTypedAttribute tAttr;

	input0 = nAttr.create("input0", "i0", MFnNumericData::kFloat, 0, &status);
	status = nAttr.setKeyable(true);
	status = addAttribute(input0);

	exp = tAttr.create("expression", "exp", MFnData::kString, &status);
	status = tAttr.setKeyable(false);
	status = addAttribute(exp);

	output0 = nAttr.create("output0", "o0", MFnNumericData::kFloat, 0, &status);
	status = nAttr.setKeyable(false);
	status = nAttr.setWritable(false);
	status = addAttribute(output0);

	status = attributeAffects(input0, output0);
	status = attributeAffects(exp, output0);

	return status;

}

void* Exp1FNode::creator()
{

	return new Exp1FNode();

}
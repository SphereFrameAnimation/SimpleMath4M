/*
  Cond1FNode.cpp
  ==============
  Cond1FNode class implementation
*/
#include "Cond1FNode.hpp"

MTypeId Cond1FNode::id(0x0E039); //Node ID 57401 [TEST ONLY]
MObject Cond1FNode::input0;
MObject Cond1FNode::input1;
MObject Cond1FNode::ifTrue;
MObject Cond1FNode::ifFalse;
MObject Cond1FNode::result; //boolean representing the result of the logical comparison
MObject Cond1FNode::outVal; //float equal to either ifTrue or ifFalse depending on the result of the logical comparison 
MObject Cond1FNode::mode;

MStatus Cond1FNode::compute(const MPlug& plug, MDataBlock& dataBlock)
{

	MStatus status;
	MDataHandle mHandle = dataBlock.inputValue(mode, &status);
	MDataHandle i0Handle = dataBlock.inputValue(input0, &status);
	MDataHandle i1Handle = dataBlock.inputValue(input1, &status);

	short m = mHandle.asShort();
	float i0 = i0Handle.asFloat();
	float i1 = i1Handle.asFloat();
	bool cResult = computeResult(m, i0, i1); //comparison

	if (plug == result) //boolean output
	{

		MDataHandle reHandle = dataBlock.outputValue(result, &status);
		reHandle.setBool(cResult);

	}
	else if (plug == outVal) //additional output
	{

		MDataHandle iTHandle = dataBlock.inputValue(ifTrue, &status);
		MDataHandle iFHandle = dataBlock.inputValue(ifFalse, &status);
		MDataHandle oVHandle = dataBlock.outputValue(outVal, &status);

		if (cResult)
		{

			oVHandle.setFloat(iTHandle.asFloat()); //copy ifTrue to outVal attribute

		}
		else
		{

			oVHandle.setFloat(iFHandle.asFloat()); //copy ifFalse to outVal attribute

		}

	}
	
	return status;

}

MStatus Cond1FNode::init()
{

	MStatus status;

	MFnNumericAttribute nAttr;
	MFnEnumAttribute eAttr;
	
	//Mode attribute
	mode = eAttr.create("mode", "m", 0, &status);
	status = eAttr.addField("E", 0);
	status = eAttr.addField("NE", 1);
	status = eAttr.addField("G or E", 2);
	status = eAttr.addField("L or E", 3);
	status = eAttr.addField("G", 4);
	status = eAttr.addField("L", 5);
	status = eAttr.setKeyable(true);
	status = eAttr.setHidden(false);
	status = eAttr.setConnectable(false);
	status = addAttribute(mode);

	//Input0 attribute
	input0 = nAttr.create("input0", "i0", MFnNumericData::kFloat, 0, &status);
	status = nAttr.setKeyable(true);
	status = addAttribute(input0);
	
	//Input1 attribute
	input1 = nAttr.create("input1", "i1", MFnNumericData::kFloat, 0, &status);
	status = nAttr.setKeyable(true);
	status = addAttribute(input1);

	//ifTrue attribute
	ifTrue = nAttr.create("ifTrue", "iT", MFnNumericData::kFloat, 0, &status);
	status = nAttr.setKeyable(true);
	status = addAttribute(ifTrue);

	//ifFalse attribute
	ifFalse = nAttr.create("ifFalse", "iF", MFnNumericData::kFloat, 0, &status);
	status = nAttr.setKeyable(true);
	status = addAttribute(ifFalse);

	//result attribute
	result = nAttr.create("result", "re", MFnNumericData::kBoolean, 0, &status);
	status = nAttr.setKeyable(false);
	status = nAttr.setWritable(false);
	status = addAttribute(result);

	//outVal attribute
	outVal = nAttr.create("outVal", "oV", MFnNumericData::kFloat, 0, &status);
	status = nAttr.setKeyable(false);
	status = nAttr.setWritable(false);
	status = addAttribute(outVal);

	status = attributeAffects(mode, result);
	status = attributeAffects(input0, result);
	status = attributeAffects(input1, result);
	status = attributeAffects(mode, outVal);
	status = attributeAffects(input0, outVal);
	status = attributeAffects(input1, outVal);
	status = attributeAffects(ifTrue, outVal);
	status = attributeAffects(ifFalse, outVal);

	return status;

}

void* Cond1FNode::creator()
{

	return new Cond1FNode();

}

bool Cond1FNode::computeResult(short m, float i0, float i1)
{

	bool o0 = false;

	if (m == 0) //EQUAL
	{

		o0 = (i0 == i1);

	}
	else if (m == 1) //NOT EQUAL
	{

		o0 = (i0 != i1);

	}
	else if (m == 2) //GREATER THAN OR EQUAL
	{

		o0 = (i0 >= i1);

	}
	else if (m == 3) //LESS THAN OR EQUAL
	{

		o0 = (i0 <= i1);

	}
	else if (m == 4) //GREATER THAN
	{

		o0 = (i0 > i1);

	}
	else if (m == 5) //LESS THAN
	{

		o0 = (i0 < i1);

	}

	return o0;

}
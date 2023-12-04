/*
  Vec2FNode.cpp
  =============
  Vec2FNode class implementation
*/
#include "Vec2FNode.hpp"

MTypeId Vec2FNode::id(0x13D5C1, 0x0A); //ID 1299905-010
MObject Vec2FNode::vec;

MStatus Vec2FNode::compute(const MPlug& plug, MDataBlock& data)
{

	MStatus status;
	return status;

}

MStatus Vec2FNode::init()
{

	MStatus status;
	MFnNumericAttribute nAttr;

	//Vec Attribute
	vec = nAttr.create("Vector", "vec", MFnNumericData::k2Float, 0, &status);
	status = nAttr.setKeyable(true);
	status = addAttribute(vec);

	return status;

}

void* Vec2FNode::creator()
{

	return new Vec2FNode();

}
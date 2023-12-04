/*
  Vec3FNode.cpp
  =============
  Vec3FNode class implementation
*/
#include "Vec3FNode.hpp"

MTypeId Vec3FNode::id(0x13D5C1, 0x0B); //ID 1299905-011
MObject Vec3FNode::vec;

MStatus Vec3FNode::compute(const MPlug& plug, MDataBlock& data)
{

	MStatus status;
	return status;

}

MStatus Vec3FNode::init()
{

	MStatus status;
	MFnNumericAttribute nAttr;

	//Vec Attribute
	vec = nAttr.create("Vector", "vec", MFnNumericData::k3Float, 0, &status);
	status = nAttr.setKeyable(true);
	status = addAttribute(vec);

	return status;

}

void* Vec3FNode::creator()
{

	return new Vec3FNode();

}
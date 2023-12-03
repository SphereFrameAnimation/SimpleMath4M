/*
  Vec3FNode.hpp
  =============
  Header for Vec3FNode class
*/
#ifndef SM4M_VEC3FNODE
#define SM4M_VEC3FNODE

#include "maya/MPxNode.h"
#include "maya/MFnNumericAttribute.h"

/*
  The Vec3FNode stores a three-dimensional float vector
*/
class Vec3FNode : public MPxNode
{

public:

	static MTypeId id;
	static MObject vec;

	MStatus compute(const MPlug& plug, MDataBlock& data);
	static MStatus init();
	static void* creator();

};

#endif
/*
  Vec2FNode.hpp
  =============
  Header for Vec2FNode class
*/
#ifndef SM4M_VEC2FNODE
#define SM4M_VEC2FNODE

#include "maya/MPxNode.h"
#include "maya/MFnNumericAttribute.h"

/*
  The Vec2FNode stores a two-dimensional float vector
*/
class Vec2FNode : public MPxNode
{

	public:

		static MTypeId id;
		static MObject vec;

		MStatus compute(const MPlug& plug, MDataBlock& data);
		static MStatus init();
		static void* creator();

};

#endif
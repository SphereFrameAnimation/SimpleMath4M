#ifndef SM4M_EXP1FNODE
#define SM4M_EXP1FNODE

#include "maya/MPxNode.h"
#include "maya/MFnTypedAttribute.h"
#include "maya/MFnNumericAttribute.h"

class Exp1FNode : public MPxNode
{

	public:

		static MTypeId id;
		static MObject input0;
		static MObject exp;
		static MObject output0;

		MStatus compute(const MPlug& plug, MDataBlock& dataBlock);
		static void* creator();
		static MStatus init();

};

#endif
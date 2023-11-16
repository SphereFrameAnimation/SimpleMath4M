#ifndef SM4M_DOT2FNODE
#define SM4M_DOT2FNODE

#include "maya/MPxNode.h"
#include "maya/MFnNumericAttribute.h"

class Dot2FNode : public MPxNode
{

	public:

		static MTypeId id;
		static MObject input0;
		static MObject input1;
		static MObject output0;

		MStatus compute(const MPlug& plug, MDataBlock& dataBlock);
		static void* creator();
		static MStatus init();

};

#endif
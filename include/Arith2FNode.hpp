#ifndef SM4M_ARITH2FNODE
#define SM4M_ARITH2FNODE

#include "maya/MPxNode.h"
#include "maya/MFnNumericAttribute.h"
#include "maya/MFnEnumAttribute.h"

class Arith2FNode : public MPxNode
{

	public:

		static MTypeId id;
		static MObject input0;
		static MObject input1;
		static MObject output0;
		static MObject mode;

		MStatus compute(const MPlug& plug, MDataBlock& dataBlock);
		static void* creator();
		static MStatus init();

};

#endif
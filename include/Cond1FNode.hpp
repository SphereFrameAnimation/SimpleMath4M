#ifndef SM4M_COND1FNODE
#define SM4M_COND1FNODE

#include "maya/MPxNode.h"
#include "maya/MFnNumericAttribute.h"
#include "maya/MFnEnumAttribute.h"

class Cond1FNode : public MPxNode
{

	public:

		static MTypeId id;
		static MObject input0;
		static MObject input1;
		static MObject ifTrue;
		static MObject ifFalse;
		static MObject result;
		static MObject outVal;
		static MObject mode;

		MStatus compute(const MPlug& plug, MDataBlock& dataBlock);
		static void* creator();
		static MStatus init();
		static bool computeResult(short m, float i0, float i1);

};

#endif
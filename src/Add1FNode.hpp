#ifndef SF4M_ADD1FNODE
#define SF4M_ADD1FNODE

#include "maya/MPxNode.h"
#include "maya/MFnNumericAttribute.h"
class Add1FNode : public MPxNode
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
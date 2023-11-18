/*
  Cond1FNode.hpp
  ==============
  Header for Cond1FNode class.
*/
#ifndef SM4M_COND1FNODE
#define SM4M_COND1FNODE

#include "maya/MPxNode.h"
#include "maya/MFnNumericAttribute.h"
#include "maya/MFnEnumAttribute.h"
/*
  The Cond1FNode computes a specified logical comparison between two one-dimensional float input values.
  The node returns a boolean value representing the result of the logical comparison above. It also returns
  a copy of the ifTrue or ifFalse input float depending on the evaluation.
*/
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
		/*
		  Compares the arguments i0 and i1 using the specified logical operation m.
		  @param m - logical operation to be computed
		  @param i0 - first input
		  @param i1 - second input
		  @return A boolean representing the result of the logical comparison.
		*/
		static bool computeResult(short m, float i0, float i1);

};

#endif
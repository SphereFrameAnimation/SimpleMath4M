/*
  Arith1FNode.hpp
  ===============
  Header for Arith1FNode class.
*/
#ifndef SM4M_ADD1FNODE
#define SM4M_ADD1FNODE

#include "maya/MPxNode.h"
#include "maya/MFnNumericAttribute.h"
#include "maya/MFnEnumAttribute.h"
/*
  The Arith1FNode computes a specified arithmetic operation on two one-dimensional float input values.
  Arithmetic operations include: addition, subtraction, multiplication and division.
*/
class Arith1FNode : public MPxNode
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
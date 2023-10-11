#ifndef SM4M_EXP1FNODE
#define SM4M_EXP1FNODE

#include "maya/MPxNode.h"
#include "maya/MFnTypedAttribute.h"
#include "maya/MFnNumericAttribute.h"
#include <string>
#include <algorithm>
#include <vector>

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

		bool isFloat(std::string& str);
		std::vector<std::string> split(std::string& str);
		float eval(std::vector<std::string>& vec, float f);

};

#endif
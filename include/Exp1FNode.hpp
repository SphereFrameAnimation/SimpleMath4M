/*
  Exp1FNode.hpp
  =============
  Header for Exp1FNode class
*/
#ifndef SM4M_EXP1FNODE
#define SM4M_EXP1FNODE

#include "maya/MPxNode.h"
#include "maya/MFnTypedAttribute.h"
#include "maya/MFnNumericAttribute.h"
#include <string>
#include <algorithm>
#include <vector>

/*
  The Arith1FNode evaluates a specified expression string which may contain the one-dimensional input float value.
*/
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

		/*
		  Checks whether the specified string represents a float value.
		  @param str - the string to be evaluated
		  @return true if the string value does represent a float, otherwise returns false.
		*/
		bool isFloat(std::string& str);
		/*
		  Splits the specified string into operations and numbers.
		  @param str - a reference to the string to be split
		  @return std::vector<std::string> where each element is either a number or a mathematical operation.
		*/
		std::vector<std::string> split(std::string& str);
		/*
		  Evaluates the given vector of strings, inserting the input float f where specified by "X"
		  @param vec - std::vector<std::string> representing the input expression to be evaluated
		  @param f - input float value to be inserted into the expression where specified
		  @return float representing the evaluation of the given expression
		*/
		float eval(std::vector<std::string>& vec, float f);

};

#endif
/*
  Exp1FNode.hpp
  =============
  Exp1FNode class implementation
*/
#include "Exp1FNode.hpp"
using std::string;
using std::vector;

MTypeId Exp1FNode::id(0x13D5C1, 0x07); //ID 1299905-007
MObject Exp1FNode::input0;
MObject Exp1FNode::exp; //String expression
MObject Exp1FNode::output0;

MStatus Exp1FNode::compute(const MPlug& plug, MDataBlock& dataBlock)
{

	MStatus status;

	if (plug == output0)
	{

		MDataHandle i0Handle = dataBlock.inputValue(input0, &status);
		MDataHandle expHandle = dataBlock.inputValue(exp, &status);

		float i0 = i0Handle.asFloat();
		string exp = expHandle.asString().asUTF8();

		MDataHandle o0Handle = dataBlock.outputValue(output0, &status);
		if (!exp.empty())
		{

			float result = eval(split(exp), i0);
			o0Handle.setFloat(result);

		}
		else
		{

			o0Handle.setFloat(std::nanf(""));

		}

	}

	return status;

}

MStatus Exp1FNode::init()
{

	MStatus status;
	MFnNumericAttribute nAttr;
	MFnTypedAttribute tAttr;

	//Input0 attribute
	input0 = nAttr.create("input0", "i0", MFnNumericData::kFloat, 0, &status);
	status = nAttr.setKeyable(true);
	status = addAttribute(input0);

	//Expression attribute
	exp = tAttr.create("expression", "exp", MFnData::kString, &status);
	status = tAttr.setKeyable(false);
	status = addAttribute(exp);

	//Output0 attribute
	output0 = nAttr.create("output0", "o0", MFnNumericData::kFloat, 0, &status);
	status = nAttr.setKeyable(false);
	status = nAttr.setWritable(false);
	status = addAttribute(output0);

	//Affect outputs
	status = attributeAffects(input0, output0);
	status = attributeAffects(exp, output0);

	return status;

}

void* Exp1FNode::creator()
{

	return new Exp1FNode();

}

bool Exp1FNode::isFloat(string& s)
{
	
	return std::find_if(s.begin(), s.end(), [](unsigned char x) {return !std::isdigit(x) && x != '.'; }) == s.end() && s.find_first_of('.') == s.find_last_of('.');

}

vector<string> Exp1FNode::split(string& s)
{

	s.erase(std::remove_if(s.begin(), s.end(), [](unsigned char x) {return std::isspace(x); }), s.end()); //remove any whitespace from the string to simplify splitting algorithm
	vector<string> vec(0);
	size_t strPos = 0; //index for keeping track of position in the input string

	for (size_t i = 0; i < s.size(); i++)
	{

		if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-') //Find occurences of mathematical operations and split the string
		{

			vec.push_back(s.substr(strPos, i - strPos)); //Add everything up to the operation occurence to vec
			vec.push_back(s.substr(i, 1)); //Add the occurence of the operation to vec

			strPos = i + 1;

		}
		if (i == s.size() - 1) //Add any of the remaining input string to the end of vec
		{

			vec.push_back(s.substr(strPos));

		}

	}

	return vec;

}

float Exp1FNode::eval(vector<string>& vec, float f)
{
	for (size_t i = 0; i < vec.size(); i++)
	{

		if (vec[i] == "X" || vec[i] == "x") //Find occurences of 'X' or 'x'
		{

			vec[i] = std::to_string(f); //Replace occurences with input float

		}

	}
	for (size_t i = 0; i < vec.size(); i++) //Iterate expression for multiplication and division. Replace evaluated elements with '#' for removal.
	{

		if (vec[i] == "*") //MUL
		{

			if (isFloat(vec[i - 1]) && isFloat(vec[i + 1]))
			{

				float r = std::stof(vec[i - 1]) * std::stof(vec[i + 1]);
				vec[i + 1] = std::to_string(r);
				vec[i] = "#";
				vec[i - 1] = "#";

			}

		}
		else if (vec[i] == "/") //DIV
		{

			if (isFloat(vec[i - 1]) && isFloat(vec[i + 1]))
			{

				if (std::stof(vec[i + 1]) != 0)
				{

					float r = std::stof(vec[i - 1]) / std::stof(vec[i + 1]);
					vec[i + 1] = std::to_string(r);
					vec[i] = "#";
					vec[i - 1] = "#";

				}
				else
				{

					//ERR

				}

			}

		}

	}

	vec.erase(std::remove_if(vec.begin(), vec.end(), [](string x) {return x == "#"; }), vec.end()); //Remove evaluated elements

	for (size_t i = 0; i < vec.size(); i++) //Iterate expression for addition and subtraction. Replace evaluated elements with '#' for removal.
	{

		if (vec[i] == "+") //ADD
		{

			if (isFloat(vec[i - 1]) && isFloat(vec[i + 1]))
			{

				float r = std::stof(vec[i - 1]) + std::stof(vec[i + 1]);
				vec[i + 1] = std::to_string(r);
				vec[i] = "#";
				vec[i - 1] = "#";

			}

		}
		else if (vec[i] == "-") //SUB
		{

			if (isFloat(vec[i - 1]) && isFloat(vec[i + 1]))
			{

				float r = std::stof(vec[i - 1]) - std::stof(vec[i + 1]);
				vec[i + 1] = std::to_string(r);
				vec[i] = "#";
				vec[i - 1] = "#";

			}

		}

	}

	vec.erase(std::remove_if(vec.begin(), vec.end(), [](string x) {return x == "#"; }), vec.end()); //remove evaluated elements

	return std::stof(vec[0]);

}
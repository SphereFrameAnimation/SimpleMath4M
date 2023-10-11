#include "Exp1FNode.hpp"
using std::string;
using std::vector;

MTypeId Exp1FNode::id(0x0E03A); //Internal ID 57402
MObject Exp1FNode::input0;
MObject Exp1FNode::exp;
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

	input0 = nAttr.create("input0", "i0", MFnNumericData::kFloat, 0, &status);
	status = nAttr.setKeyable(true);
	status = addAttribute(input0);

	exp = tAttr.create("expression", "exp", MFnData::kString, &status);
	status = tAttr.setKeyable(false);
	status = addAttribute(exp);

	output0 = nAttr.create("output0", "o0", MFnNumericData::kFloat, 0, &status);
	status = nAttr.setKeyable(false);
	status = nAttr.setWritable(false);
	status = addAttribute(output0);

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

	s.erase(std::remove_if(s.begin(), s.end(), [](unsigned char x) {return std::isspace(x); }), s.end());
	vector<string> vec(0);
	size_t strPos = 0;

	for (size_t i = 0; i < s.size(); i++)
	{

		if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-')
		{

			vec.push_back(s.substr(strPos, i - strPos));
			vec.push_back(s.substr(i, 1));

			strPos = i + 1;

		}
		if (i == s.size() - 1)
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

		if (vec[i] == "X" || vec[i] == "x")
		{

			vec[i] = std::to_string(f);

		}

	}
	for (size_t i = 0; i < vec.size(); i++)
	{

		if (vec[i] == "*")
		{

			if (isFloat(vec[i - 1]) && isFloat(vec[i + 1]))
			{

				float r = std::stof(vec[i - 1]) * std::stof(vec[i + 1]);
				vec[i + 1] = std::to_string(r);
				vec[i] = "#";
				vec[i - 1] = "#";

			}

		}
		else if (vec[i] == "/")
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

	vec.erase(std::remove_if(vec.begin(), vec.end(), [](string x) {return x == "#"; }), vec.end());

	for (size_t i = 0; i < vec.size(); i++)
	{

		if (vec[i] == "+")
		{

			if (isFloat(vec[i - 1]) && isFloat(vec[i + 1]))
			{

				float r = std::stof(vec[i - 1]) + std::stof(vec[i + 1]);
				vec[i + 1] = std::to_string(r);
				vec[i] = "#";
				vec[i - 1] = "#";

			}

		}
		else if (vec[i] == "-")
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

	vec.erase(std::remove_if(vec.begin(), vec.end(), [](string x) {return x == "#"; }), vec.end());

	return std::stof(vec[0]);

}
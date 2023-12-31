/*
  PluginMain.cpp
  ==============
  Implements plugin registration and deregistration functions
*/
#include "PluginMain.hpp"

MStatus initializePlugin(MObject pObj)
{

	MStatus status;
	MFnPlugin plugin(pObj, PLUGIN_VENDOR, PLUGIN_VERSION, "Any");

	//Register nodes
	status = plugin.registerNode("SM4M_Arith1F", Arith1FNode::id, Arith1FNode::creator, Arith1FNode::init, MPxNode::kDependNode);
	status = plugin.registerNode("SM4M_Cond1F", Cond1FNode::id, Cond1FNode::creator, Cond1FNode::init, MPxNode::kDependNode);
	status = plugin.registerNode("SM4M_Exp1F", Exp1FNode::id, Exp1FNode::creator, Exp1FNode::init, MPxNode::kDependNode);
	status = plugin.registerNode("SM4M_Arith2F", Arith2FNode::id, Arith2FNode::creator, Arith2FNode::init, MPxNode::kDependNode);
	status = plugin.registerNode("SM4M_Dot2F", Dot2FNode::id, Dot2FNode::creator, Dot2FNode::init, MPxNode::kDependNode);
	status = plugin.registerNode("SM4M_Arith3F", Arith3FNode::id, Arith3FNode::creator, Arith3FNode::init, MPxNode::kDependNode);
	status = plugin.registerNode("SM4M_Dot3F", Dot3FNode::id, Dot3FNode::creator, Dot3FNode::init, MPxNode::kDependNode);
	status = plugin.registerNode("SM4M_Cross3F", Cross3FNode::id, Cross3FNode::creator, Cross3FNode::init, MPxNode::kDependNode);
	status = plugin.registerNode("SM4M_ScalarProduct2F", ScalarProduct2FNode::id, ScalarProduct2FNode::creator, ScalarProduct2FNode::init, MPxNode::kDependNode);
	status = plugin.registerNode("SM4M_ScalarProduct3F", ScalarProduct3FNode::id, ScalarProduct3FNode::creator, ScalarProduct3FNode::init, MPxNode::kDependNode);
	status = plugin.registerNode("SM4M_Vec2F", Vec2FNode::id, Vec2FNode::creator, Vec2FNode::init, MPxNode::kDependNode);
	status = plugin.registerNode("SM4M_Vec3F", Vec3FNode::id, Vec3FNode::creator, Vec3FNode::init, MPxNode::kDependNode);

	return status;

}

MStatus uninitializePlugin(MObject pObj)
{

	MStatus status;
	MFnPlugin plugin(pObj);

	//Deregister nodes
	status = plugin.deregisterNode(Arith1FNode::id);
	status = plugin.deregisterNode(Cond1FNode::id);
	status = plugin.deregisterNode(Exp1FNode::id);
	status = plugin.deregisterNode(Arith2FNode::id);
	status = plugin.deregisterNode(Dot2FNode::id);
	status = plugin.deregisterNode(Arith3FNode::id);
	status = plugin.deregisterNode(Dot3FNode::id);
	status = plugin.deregisterNode(Cross3FNode::id);
	status = plugin.deregisterNode(ScalarProduct2FNode::id);
	status = plugin.deregisterNode(ScalarProduct3FNode::id);
	status = plugin.deregisterNode(Vec2FNode::id);
	status = plugin.deregisterNode(Vec3FNode::id);

	return status;

}
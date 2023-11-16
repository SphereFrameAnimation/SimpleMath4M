#include "PluginMain.hpp"

MStatus initializePlugin(MObject pObj)
{

	MStatus status;
	MFnPlugin plugin(pObj, "SPHEREFRAME ANIMATION", "1.0.0", "Any");

	status = plugin.registerNode("SM4M_Arith1F", Arith1FNode::id, Arith1FNode::creator, Arith1FNode::init, MPxNode::kDependNode);
	status = plugin.registerNode("SM4M_Cond1F", Cond1FNode::id, Cond1FNode::creator, Cond1FNode::init, MPxNode::kDependNode);
	status = plugin.registerNode("SM4M_Exp1F", Exp1FNode::id, Exp1FNode::creator, Exp1FNode::init, MPxNode::kDependNode);
	status = plugin.registerNode("SM4M_Arith2F", Arith2FNode::id, Arith2FNode::creator, Arith2FNode::init, MPxNode::kDependNode);
	status = plugin.registerNode("SM4M_Dot2F", Dot2FNode::id, Dot2FNode::creator, Dot2FNode::init, MPxNode::kDependNode);

	return status;

}

MStatus uninitializePlugin(MObject pObj)
{

	MStatus status;
	MFnPlugin plugin(pObj);

	status = plugin.deregisterNode(Arith1FNode::id);
	status = plugin.deregisterNode(Cond1FNode::id);
	status = plugin.deregisterNode(Exp1FNode::id);
	status = plugin.deregisterNode(Arith2FNode::id);
	status = plugin.deregisterNode(Dot2FNode::id);

	return status;

}
#include "PluginMain.hpp"

MStatus initializePlugin(MObject pObj)
{

	MStatus status;
	MFnPlugin plugin(pObj, "SPHEREFRAME ANIMATION", "1.0.0", "Any");

	plugin.registerNode("SM4M_Arith1F", Arith1FNode::id, Arith1FNode::creator, Arith1FNode::init, MPxNode::kDependNode);

	return status;

}

MStatus uninitializePlugin(MObject pObj)
{

	MStatus status;
	MFnPlugin plugin(pObj);

	plugin.deregisterNode(Arith1FNode::id);

	return status;

}
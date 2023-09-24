#include "PluginMain.hpp"

MStatus initializePlugin(MObject pObj)
{

	MStatus status;
	MFnPlugin plugin(pObj, "SPHEREFRAME ANIMATION", "1.0.0", "Any");

	plugin.registerNode("SM4M_Add1F", Add1FNode::id, Add1FNode::creator, Add1FNode::init);

	return status;

}

MStatus uninitializePlugin(MObject pObj)
{

	MStatus status;
	MFnPlugin plugin(pObj);

	plugin.deregisterNode(Add1FNode::id);

	return status;

}
/*
  PluginMain.hpp
  ==============
  Header for plugin entry point
  Includes headers required plugin for initialisation and registering plugin services
*/
#ifndef SM4M_MAIN
#define SM4M_MAIN

//Include header for Maya plugin init
#include "maya/MFnPlugin.h"

//Include nodes to be registered
#include "Arith1FNode.hpp"
#include "Cond1FNode.hpp"
#include "Exp1FNode.hpp"
#include "Arith2FNode.hpp"
#include "Dot2FNode.hpp"

#endif
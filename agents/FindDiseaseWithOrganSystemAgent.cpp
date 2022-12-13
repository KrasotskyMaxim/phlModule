#include <iostream>

#include <sc-agents-common/utils/IteratorUtils.hpp>
#include <sc-agents-common/utils/AgentUtils.hpp>
#include <sc-agents-common/utils/GenerationUtils.hpp>

#include "FindDiseaseWithOrganSystemAgent.hpp"

using namespace std;
using namespace utils;

namespace phlModule
{

SC_AGENT_IMPLEMENTATION(FindDiseaseWithOrganSystemAgent)
{
  if (!edgeAddr.IsValid())
    return SC_RESULT_ERROR;

  ScAddr questionNode = ms_context->GetEdgeTarget(edgeAddr);
  ScAddr param = IteratorUtils::getFirstFromSet(ms_context.get(), questionNode);
  if (!param.IsValid())
    return SC_RESULT_ERROR_INVALID_PARAMS;

  ScAddr answer = ms_context->CreateNode(ScType::NodeConstStruct);
  ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, param);
  ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, Keynodes::nrel_diseases_of_system);


ScIterator5Ptr organ_system_iter = IteratorUtils::getIterator5(ms_context.get(), param, Keynodes::nrel_diseases_of_system, true);
while (organ_system_iter->Next())
{
ScAddr sheaf = organ_system_iter->Get(2);
ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, organ_system_iter->Get(1));
ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, sheaf);
ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, organ_system_iter->Get(3));
GenerationUtils::addSetToOutline(ms_context.get(), sheaf, answer);
}


  AgentUtils::finishAgentWork(ms_context.get(), questionNode, answer);
  return SC_RESULT_OK;
}
}

#include <iostream>

#include <sc-agents-common/utils/IteratorUtils.hpp>
#include <sc-agents-common/utils/AgentUtils.hpp>
#include <sc-agents-common/utils/GenerationUtils.hpp>

#include "FindExcerciseBySpecificBodyPartAgent.hpp"

using namespace std;
using namespace utils;

namespace phlModule
{

SC_AGENT_IMPLEMENTATION(FindExcerciseBySpecificBodyPartAgent)
{
    if (!edgeAddr.IsValid())
    return SC_RESULT_ERROR;

  ScAddr questionNode = ms_context->GetEdgeTarget(edgeAddr);
  ScAddr param = IteratorUtils::getFirstFromSet(ms_context.get(), questionNode);
  if (!param.IsValid())
    return SC_RESULT_ERROR_INVALID_PARAMS;

  ScAddr answer = ms_context->CreateNode(ScType::NodeConstStruct);
  ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, param);
  
  ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, Keynodes::nrel_inclusion);

  ScIterator5Ptr iterator = IteratorUtils::getIterator5(ms_context.get(), param, Keynodes::nrel_inclusion, true); // find inclusion*
  
  while (iterator->Next())
  {
    ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, iterator->Get(1)); // edge common
    ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, iterator->Get(2)); // excercise
    ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, iterator->Get(3)); // edge access
    ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, iterator->Get(4)); // nrel_inclusion*
  }

  AgentUtils::finishAgentWork(ms_context.get(), questionNode, answer);

  return SC_RESULT_OK;

}

} // namespace phlModule
#include <iostream>

#include <sc-agents-common/utils/IteratorUtils.hpp>
#include <sc-agents-common/utils/AgentUtils.hpp>
#include <sc-agents-common/utils/GenerationUtils.hpp>

#include "FindDiseaseWithSymptomAgent.hpp"

using namespace std;
using namespace utils;

namespace phlModule
{

SC_AGENT_IMPLEMENTATION(FindDiseaseWithSymptomAgent)
{
  if (!edgeAddr.IsValid())
    return SC_RESULT_ERROR;

  ScAddr questionNode = ms_context->GetEdgeTarget(edgeAddr);
  ScAddr param = IteratorUtils::getFirstFromSet(ms_context.get(), questionNode);
  if (!param.IsValid())
    return SC_RESULT_ERROR_INVALID_PARAMS;

  ScAddr answer = ms_context->CreateNode(ScType::NodeConstStruct);
  ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, param);
  ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, Keynodes::nrel_symptom);


ScIterator5Ptr symptoms_iter = IteratorUtils::getIterator5(ms_context.get(), param, Keynodes::nrel_symptom, false);
while (symptoms_iter->Next())
{
ScAddr sheaf = symptoms_iter->Get(0);
ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, symptoms_iter->Get(1));
ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, sheaf);
ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, symptoms_iter->Get(3));
GenerationUtils::addSetToOutline(ms_context.get(), sheaf, answer);
}


  AgentUtils::finishAgentWork(ms_context.get(), questionNode, answer);
  return SC_RESULT_OK;
}
}

#include <iostream>

#include <sc-memory/sc_memory.hpp>
#include <sc-memory/sc_stream.hpp>
#include <sc-memory/sc_template_search.cpp>

#include <sc-agents-common/utils/IteratorUtils.hpp>
#include <sc-agents-common/utils/AgentUtils.hpp>
#include <sc-agents-common/utils/GenerationUtils.hpp>

#include "FindProductsByCPFCAgent.hpp"

using namespace std;
using namespace utils;

namespace phlModule
{

SC_AGENT_IMPLEMENTATION(FindProductsByCPFCAgent)
{
  if (!edgeAddr.IsValid())
    return SC_RESULT_ERROR;

  ScAddr questionNode = ms_context->GetEdgeTarget(edgeAddr);
  ScAddr param = IteratorUtils::getFirstFromSet(ms_context.get(), questionNode);
  if (!param.IsValid())
    return SC_RESULT_ERROR_INVALID_PARAMS;

  ScAddr answer = ms_context->CreateNode(ScType::NodeConstStruct);
  ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, param);
  
  // calories
  ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, Keynodes::nrel_calorie_content);

  ScIterator5Ptr iterator5_1 = IteratorUtils::getIterator5(ms_context.get(), param, Keynodes::nrel_calorie_content, false);
  while (iterator5_1->Next())
  {
    ScAddr sheaf = iterator5_1->Get(0);
    ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, iterator5_1->Get(1));
    ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, sheaf);
    ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, iterator5_1->Get(3));
    GenerationUtils::addSetToOutline(ms_context.get(), sheaf, answer);
  }

  // proteins
  ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, Keynodes::nrel_protein_content);

  ScIterator5Ptr iterator5_2 = IteratorUtils::getIterator5(ms_context.get(), param, Keynodes::nrel_protein_content, false);
  while (iterator5_2->Next())
  {
    ScAddr sheaf = iterator5_2->Get(0);
    ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, iterator5_2->Get(1));
    ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, sheaf);
    ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, iterator5_2->Get(3));
    GenerationUtils::addSetToOutline(ms_context.get(), sheaf, answer);
  }
  
  // fats
  ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, Keynodes::nrel_fats_content);

  ScIterator5Ptr iterator5_3 = IteratorUtils::getIterator5(ms_context.get(), param, Keynodes::nrel_fats_content, false);
  while (iterator5_3->Next())
  {
    ScAddr sheaf = iterator5_3->Get(0);
    ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, iterator5_3->Get(1));
    ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, sheaf);
    ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, iterator5_3->Get(3));
    GenerationUtils::addSetToOutline(ms_context.get(), sheaf, answer);
  }
  
  // carbohydrates
  ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, Keynodes::nrel_carbohydrates_content);

  ScIterator5Ptr iterator5_4 = IteratorUtils::getIterator5(ms_context.get(), param, Keynodes::nrel_carbohydrates_content, false);
  while (iterator5_4->Next())
  {
    ScAddr sheaf = iterator5_4->Get(0);
    ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, iterator5_4->Get(1));
    ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, sheaf);
    ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, iterator5_4->Get(3));
    GenerationUtils::addSetToOutline(ms_context.get(), sheaf, answer);
  }
  
  AgentUtils::finishAgentWork(ms_context.get(), questionNode, answer);

  return SC_RESULT_OK;
}

} // namespace phlModule
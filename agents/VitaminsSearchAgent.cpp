#include <iostream>

#include <sc-memory/sc_memory.hpp>
#include <sc-memory/sc_stream.hpp>

#include <sc-agents-common/utils/IteratorUtils.hpp>
#include <sc-agents-common/utils/AgentUtils.hpp>
#include <sc-agents-common/utils/GenerationUtils.hpp>

#include "VitaminsSearchAgent.hpp"

using namespace std;
using namespace utils;

namespace phlModule
{

SC_AGENT_IMPLEMENTATION(VitaminsSearchAgent)
{
  if (!edgeAddr.IsValid())
    return SC_RESULT_ERROR;

  ScAddr questionNode = ms_context->GetEdgeTarget(edgeAddr);
  ScAddr param = IteratorUtils::getFirstFromSet(ms_context.get(), questionNode);

  if (!param.IsValid())
    return SC_RESULT_ERROR_INVALID_PARAMS;

  ScAddr answer = ms_context->CreateNode(ScType::NodeConstStruct);
  
  ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, Keynodes::nrel_is_contained_in);

  ScIterator5Ptr iterator5 = IteratorUtils::getIterator5(ms_context.get(), param, Keynodes::nrel_is_contained_in, false);
  while (iterator5->Next())
  {
    ScAddr sheaf = iterator5->Get(0);
    ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, iterator5->Get(1));
    ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, sheaf);
    ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, iterator5->Get(2));
    GenerationUtils::addSetToOutline(ms_context.get(), sheaf, answer);
  }
   
  //ScIterator5Ptr iterator_vitamin = IteratorUtils::getIterator5(ms_context.get(), param, Keynodes::nrel_inclusion, true);
  
  //while(iterator_vitamin->Next())
  //{    
    //ScIterator5Ptr iterator = IteratorUtils::getIterator5(ms_context.get(), iterator_vitamin->Get(2), Keynodes::nrel_daily_requirement_for_adults, true);  
    
    //while (iterator->Next())
    //{
      //ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, iterator->Get(0));
      //ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, iterator->Get(1));
      //ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, iterator->Get(2));
    //}
  //}
  
  utils::AgentUtils::finishAgentWork(ms_context.get(), questionNode, answer);

  return SC_RESULT_OK;
}

}

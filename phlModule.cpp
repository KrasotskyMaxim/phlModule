/*
* This source file is part of an OSTIS project. For the latest info, see http://ostis.net
* Distributed under the MIT License
* (See accompanying file COPYING.MIT or copy at http://opensource.org/licenses/MIT)
*/

#include "phlModule.hpp"
#include "keynodes/keynodes.hpp"

#include "agents/FindProductsByCPFCAgent.hpp"
#include "agents/FindExcerciseBySpecificBodyPartAgent.hpp"
#include "agents/VitaminsSearchAgent.hpp"
#include "agents/SearchDiseasesWithDiseasePreventionAgent.hpp"
#include "agents/SearchDiseasesWithTransmissionMethodAgent.hpp"
#include "agents/FindDiseaseWithOrganSystemAgent.hpp"
#include "agents/FindDiseaseWithSymptomAgent.hpp"

using namespace phlModule;

SC_IMPLEMENT_MODULE(PHLModule)

sc_result PHLModule::InitializeImpl()
{
  if (!phlModule::Keynodes::InitGlobal())
    return SC_RESULT_ERROR;

  SC_AGENT_REGISTER(FindExcerciseBySpecificBodyPartAgent)
  SC_AGENT_REGISTER(FindProductsByCPFCAgent)
  SC_AGENT_REGISTER(VitaminsSearchAgent)
  SC_AGENT_REGISTER(SearchDiseasesWithDiseasePreventionAgent)
  SC_AGENT_REGISTER(SearchDiseasesWithTransmissionMethodAgent)
  SC_AGENT_REGISTER(FindDiseaseWithOrganSystemAgent)
  SC_AGENT_REGISTER(FindDiseaseWithSymptomAgent)
  
  return SC_RESULT_OK;
}

sc_result PHLModule::ShutdownImpl()
{
  SC_AGENT_UNREGISTER(FindExcerciseBySpecificBodyPartAgent)
  SC_AGENT_UNREGISTER(FindProductsByCPFCAgent)
  SC_AGENT_UNREGISTER(VitaminsSearchAgent)
  SC_AGENT_UNREGISTER(SearchDiseasesWithDiseasePreventionAgent)
  SC_AGENT_UNREGISTER(SearchDiseasesWithTransmissionMethodAgent)
  SC_AGENT_UNREGISTER(FindDiseaseWithOrganSystemAgent)
  SC_AGENT_UNREGISTER(FindDiseaseWithSymptomAgent)

  return SC_RESULT_OK;
}

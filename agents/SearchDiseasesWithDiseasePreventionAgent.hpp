#pragma once

#include <sc-memory/kpm/sc_agent.hpp>

#include "keynodes/keynodes.hpp"
#include "SearchDiseasesWithDiseasePreventionAgent.generated.hpp"

namespace phlModule
{

class SearchDiseasesWithDiseasePreventionAgent : public ScAgent
{
  SC_CLASS(Agent, Event(Keynodes::question_search_diseases_with_disease_prevention, ScEvent::Type::AddOutputEdge))
  SC_GENERATED_BODY()
};

} // namespace phlModule

#pragma once

#include <sc-memory/kpm/sc_agent.hpp>

#include "keynodes/keynodes.hpp"
#include "FindDiseaseWithOrganSystemAgent.generated.hpp"

namespace phlModule
{

class FindDiseaseWithOrganSystemAgent : public ScAgent
{
  SC_CLASS(Agent, Event(Keynodes::question_find_disease_with_organ_system, ScEvent::Type::AddOutputEdge))
  SC_GENERATED_BODY()
};

} // namespace exampleModule

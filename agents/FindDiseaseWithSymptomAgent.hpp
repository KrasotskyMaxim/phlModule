#pragma once

#include <sc-memory/kpm/sc_agent.hpp>

#include "keynodes/keynodes.hpp"
#include "FindDiseaseWithSymptomAgent.generated.hpp"

namespace phlModule
{

class FindDiseaseWithSymptomAgent : public ScAgent
{
  SC_CLASS(Agent, Event(Keynodes::question_find_disease_with_symptom, ScEvent::Type::AddOutputEdge))
  SC_GENERATED_BODY()
};

} // namespace exampleModule

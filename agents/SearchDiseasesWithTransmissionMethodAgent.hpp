#pragma once

#include <sc-memory/kpm/sc_agent.hpp>

#include "keynodes/keynodes.hpp"
#include "SearchDiseasesWithTransmissionMethodAgent.generated.hpp"

namespace phlModule
{

class SearchDiseasesWithTransmissionMethodAgent : public ScAgent
{
  SC_CLASS(Agent, Event(Keynodes::question_search_diseases_with_transmission_method, ScEvent::Type::AddOutputEdge))
  SC_GENERATED_BODY()
};

} // namespace phlModule

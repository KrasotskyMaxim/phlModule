#pragma once

#include <sc-memory/kpm/sc_agent.hpp>

#include "keynodes/keynodes.hpp"
#include "FindProductsByCPFCAgent.generated.hpp"

namespace phlModule
{

class FindProductsByCPFCAgent : public ScAgent
{
  SC_CLASS(Agent, Event(Keynodes::question_find_products_by_cpfc, ScEvent::Type::AddOutputEdge))
  SC_GENERATED_BODY()
};

} // namespace phlModule
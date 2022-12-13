#pragma once

#include <sc-memory/kpm/sc_agent.hpp>

#include "keynodes/keynodes.hpp"
#include "VitaminsSearchAgent.generated.hpp"

namespace phlModule
{

class VitaminsSearchAgent : public ScAgent
{
  SC_CLASS(Agent, Event(Keynodes::question_find_vitamins, ScEvent::Type::AddOutputEdge))
  SC_GENERATED_BODY()
};

}

#pragma once

#include <sc-memory/kpm/sc_agent.hpp>

#include "keynodes/keynodes.hpp"
#include "FindExcerciseBySpecificBodyPartAgent.generated.hpp"

namespace phlModule
{

class FindExcerciseBySpecificBodyPartAgent : public ScAgent
{
  SC_CLASS(Agent, Event(Keynodes::question_find_excercise_by_specific_body_part, ScEvent::Type::AddOutputEdge))
  SC_GENERATED_BODY()
};

} // namespace phlModule